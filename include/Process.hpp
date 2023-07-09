#ifndef PROCESS_HPP
#define PROCESS_HPP

// Represents a process of the OS.
class Process {
    private:
        int id_;
        int priority_;    // real time queue = 0 / user queue = [1, 3]
        bool preemptive_;
        int quantum_;     // in nano seconds

        int initialization_time_;
        int cpu_time_;
        int memory_blocks_;
        int requested_printer_code_number_;
        int scanner_request_;
        int modem_request_;
        int disk_code_number_;

    public:
        Process(int id, int priority)
            : id_(id), priority_(priority) {
            
            preemptive_ = (priority != 0);  // the real time queue is non preemptive.
            if (preemptive_) {
                quantum_ = 1000; // 1 ms
            }
        }

        inline int get_id() { return id_; }
        inline int get_priority() { return priority_; }
};

#endif // PROCESS_HPP