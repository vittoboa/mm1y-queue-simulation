#include <iostream>
#include <queue>
#include "Packet.h"

class Simulation {
    private:
        const double time_total = 100000;
        double time_current = 0, time_arrival = 0;
        double time_pkts_system_total = 0, time_pkts_queue_total = 0, sum_n_pkt_system = 0;
        unsigned int n_pkt_total = 0, n_pkt_dropped = 0;
        std :: queue<Packet> packets;
        bool is_queue_full();
        bool is_arrival();
        double generate_interarrival();
        double generate_service();
        double get_time_departure();
        void update_time_current();
        void set_next_departure();
        void add_packet(double);
        void handle_arrival_event(double);
        void handle_depart_event();

    public:
        Simulation(double, double, unsigned int);
        unsigned int system_capacity;
        double lambda, mu;
        double probability_dropped_pkt;
        double avg_n_pkt_system, avg_time_pkt_system, avg_time_pkt_queue;
        void simulate();
};
