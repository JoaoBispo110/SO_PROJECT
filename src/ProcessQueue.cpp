#include "../include/ProcessQueue.hpp"

// Insert a process in the queue according to it's priority.
// Returns a boolean indicating if the process was inserted.
bool ProcessQueue::push_process(Process process) {
    if (quantity == kMaxQuantity) {
        return false;
    }
    queues[process.get_priority()].push(process);
    return true;
}

// Returns a std::optional<Process> with the first element
// of the highest priority non-empty queue.
// Returns std::nullopt if all the queues are empty.
// Example:
// auto opt = Queue.get_process();
// if (opt) { Process process = opt.value(); }
// else { // the queue was empty }
std::optional<Process> ProcessQueue::get_process() {
    for (int priority = 0; priority < 4; priority ++) {
        if (!queues[priority].empty()) {
            Process process = queues[priority].front();
            queues[priority].pop();
            quantity --;
            return process;
        }
    }
    return std::nullopt;
}