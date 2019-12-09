#include <iostream>
#include "Simulation.h"

int main() {
    Simulation simulation(6, 10, 5, 100000);
    simulation.simulate();

    return 0;
}
