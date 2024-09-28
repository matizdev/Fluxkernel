#include <math.h>

double pow(double x, double y) {
    double result = 1;
    while (y--) {
        result *= x;
    }
    return result;
}