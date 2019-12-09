#include <iostream>
#include "utils.h"
#include "Simulation.h"
#include <iomanip>

Simulation::Simulation(double lambda, double mu, unsigned int capacity, double time_total) {
    this->lambda = lambda;
    this->mu = mu;
    this->system_capacity = capacity;
    this->time_total = time_total;
}

double Simulation::generate_interarrival() {
    return get_exponential_random_value(this->lambda);
}

double Simulation::generate_service() {
    return get_exponential_random_value(this->mu);
}

bool Simulation::is_queue_full() {
    return this->packets.size() >= this->system_capacity;
}

bool Simulation::is_arrival() {
    return this->time_arrival < get_time_departure();
}

double Simulation::get_time_departure() {
    double time_departure = (!this->packets.empty()) ? this->packets.front().get_time_departure() : this->time_total;
    return time_departure;
}

void Simulation::update_time_current() {
    this->time_current = std::min(this->time_arrival, get_time_departure());
}

void Simulation::add_packet(double time) {
    Packet packet(time);
    this->packets.push(packet);
}

void Simulation::handle_arrival_event(double time) {
    ++this->n_pkt_total;

    if (!is_queue_full()) {
        add_packet(time);

        if (this->packets.size() == 1) {
            set_next_departure();
        }
    } else {
        ++this->n_pkt_dropped;
    }

    this->time_arrival += generate_interarrival();
}

void Simulation::set_next_departure() {
    if (!this->packets.empty()) {
        this->time_pkts_queue_total += this->time_current - this->packets.front().get_time_arrival();
        
        double next_departure = this->time_current + generate_service();
        this->packets.front().set_time_departure(next_departure);
    }
}

void Simulation::handle_depart_event() {
    this->time_pkts_system_total += this->packets.front().get_time_in_system();

    this->packets.pop();
    set_next_departure();
}

void Simulation::simulate() {
    double time_total, time_departure;

    while (this->time_current < this->time_total) {
        double time_last_event = this->time_current;
        update_time_current();
        this->sum_n_pkt_system += this->packets.size() * (this->time_current - time_last_event);

        if (is_arrival()) {
            handle_arrival_event(this->time_arrival);
        } else {
            handle_depart_event();
        }
    }
}
