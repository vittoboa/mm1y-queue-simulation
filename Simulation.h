#include <iostream>
#include <queue>
#include "Packet.h"

class Simulation {
    private:
        double lambda, mu;
        double time_current = 0, time_arrival = 0, time_total;
        unsigned int n_pkt_total = 0, n_pkt_dropped = 0;
        unsigned int system_capacity;
        double time_pkts_system_total = 0, time_pkts_queue_total = 0;
        std :: queue<Packet> packets;
        bool is_queue_full();
        bool is_arrival();
        double get_time_departure();
        void update_time_current();
        void set_next_departure();
        void add_packet(double);
        void handle_arrival_event(double);
        void handle_depart_event();
        double generate_interarrival();
        double generate_service();

        double sum_n_pkt_system = 0;

    public:
        Simulation(double, double, unsigned int, double);
        void simulate();
        void overview();
};
