#include <iostream>
#include "Packet.h"
#include "utils.h"

Packet::Packet(double time_arrival) {
    this->time_arrival = time_arrival;
}

void Packet::set_time_departure(double time) {
    this->time_departure = time;
}

double Packet::get_time_in_system() {
    return this->time_departure - this->time_arrival;
}