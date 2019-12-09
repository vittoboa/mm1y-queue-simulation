#include <iostream>

class Packet {
    private:
        double time_arrival, time_departure;

    public:
        Packet(double);
        double get_time_arrival() { return time_arrival; }
        double get_time_departure() { return time_departure; }
        void set_time_departure(double);
        double get_time_in_system();
};
