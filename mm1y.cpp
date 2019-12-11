#include <iostream>
#include "Simulation.h"
#include <iomanip>
#include <fstream>


void print(double lambda, double mu, unsigned int system_capacity) {
    Simulation simulation(lambda, mu, system_capacity);
    simulation.simulate();

    std::cout << std::fixed << std::setprecision(5);
    std::cout << std::endl << "                  M/M/1/" << simulation.system_capacity << " Queue Simulation" << std::endl << std::endl;
    std::cout << "Description                   |   Variable    |   Value   " << std::endl << std::endl;
    std::cout << "Probability dropping packet         P" << simulation.system_capacity << "           " << simulation.probability_dropped_pkt << std::endl;
    std::cout << "Average num of pkts in system      E{k}          " << simulation.avg_n_pkt_system << std::endl;
    std::cout << "Pkt's average time in system       E{T}          " << simulation.avg_time_pkt_system << std::endl;
    std::cout << "Pkt's average time in queue       E{Tq}          " << simulation.avg_time_pkt_queue  << std::endl;
}

void save_trend(double mu, unsigned int system_capacity) {
    std::ofstream output_file;
    output_file.open ("mm1y_output.csv");
    // write headers
    output_file << "rho, Pkt's average time in system, Pkt's average time in queue" << std::endl;
    
    for (double lambda = 0.1; lambda < mu; lambda += 0.5) {
        Simulation simulation(lambda, mu, system_capacity);
        simulation.simulate();

        output_file << simulation.lambda / simulation.mu << "," << simulation.avg_time_pkt_system << "," << simulation.avg_time_pkt_queue << std::endl;
    }

    output_file.close();
}

void output(unsigned int mode, double lambda, double mu, unsigned int system_capacity) {
    switch (mode) {
        case 1:
            print(lambda, mu, system_capacity);
            break;
        case 2:
            save_trend(mu, system_capacity);
            break;
    }
}


int main (int argc, char *argv[]) {
    /*
    mode 1 (deafult): print results to console given lambda, mu and queue capacity
    mode 2          : save results in file given queue capacity
    */
    const unsigned int output_mode_print = 1, output_mode_save_trend = 2, output_mode_default = output_mode_print;
    const unsigned int output_mode = (argc == 1) ? output_mode_default : atoi(argv[1]);


    /* parameters input */
    double lambda = 0, mu = 10;
    int system_capacity;
    switch (output_mode) {
        case output_mode_print:
            std::cout << "lambda: ";
            std::cin >> lambda;
            std::cout << "mu: ";
            std::cin >> mu;
        case output_mode_save_trend:
            std::cout << "capacity: ";
            std::cin >> system_capacity;
            break;
    }


    /* output simulation's results */
    output(output_mode, lambda, mu, system_capacity);

    return 0;
}
