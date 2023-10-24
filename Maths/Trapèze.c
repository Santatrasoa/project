#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x) {
    return exp(x);
}

double rectangle(double a, double b) {
    double solution = 0.0;
    double division = 0.1;

    for (double i = a; i < b; i += division) {
        solution += f((i + i + division) / 2) * division;
    }

    return solution;
}

int main() {
    double a = 1, b = 5;

    printf("%lg\n", rectangle(a, b));

    return 0;
}
