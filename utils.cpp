#include "utils.h"
#include "math.h"

double get_exponential_random_value(double param) {
    double uniform_random_value = ((double) rand() + 1) / ((double) (RAND_MAX) + 1);
    double exponential_random_value = (double)(-(log(1 - uniform_random_value)) / param);

    return exponential_random_value;
}
