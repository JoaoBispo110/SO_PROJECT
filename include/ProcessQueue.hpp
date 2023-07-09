#ifndef PROCESS_QUEUE_HPP
#define PROCESS_QUEUE_HPP

#include <queue>
#include <optional>
#include "../include/Process.hpp"

const int kMaxQuantity = 1000;

class ProcessQueue {
private:
    // real time queue - priority 0
    // user queue      - priority [1, 3]
    std::queue<Process> queues[4];
    int quantity = 0; // Number of processes in the queues.

public:
    bool push_process(Process process);
    std::optional<Process> get_process();
};

#endif // PROCESS_QUEUE_HPP