#ifndef UTILS_H_
#define UTILS_H_

#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>
#include <random>

using namespace std;

const double infinity = numeric_limits<double>::infinity();
const double pi = 3.14159265358979323846;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

// inline double random_double() {
//     return rand() / (RAND_MAX + 1.0);
// }

inline double random_double() {
    static uniform_real_distribution<double> distribution(0.0, 1.0);
    static mt19937 generator;
    return distribution(generator);
}

inline double random_double(double min, double max) {
    return min + (max - min) * random_double();
}

inline double clamp(double x, double min, double max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

#include "ray.hpp"
#include "vec3.hpp"

#endif