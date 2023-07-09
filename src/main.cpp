#include "../include/ProcessQueue.hpp"
#include "../include/Process.hpp"
#include <bits/stdc++.h>

int main(){
	ProcessQueue queue;

    if (!queue.get_process()) {
        std::cout << "fila vazia" << std::endl;
    }
    queue.push_process(Process(123, 1));
    auto opt_process = queue.get_process();
    if (opt_process) {
        Process process = opt_process.value();
        std::cout << "id_processo: " << process.get_id() << std::endl;
    }


	return 0;
}