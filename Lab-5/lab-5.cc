#include <iostream>
#include <math.h>
#include <stdexcept>


double computeValue(double x);

int main() {
    double x;
    std::cout << "Enter value for x:  ";
    std::cin >> x;
    try {
        double result = computeValue(x);
        std::cout << "Result is " << result << std::endl;
    }
    catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

double computeValue(double x) {
    if (x < 3.0) {
        throw std::invalid_argument("x must be >= 3.0");
    }
    return 0.5 * sqrt(x - 3.0);
}