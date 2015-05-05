#include <iostream>
#include <math.h>

using namespace std;

double computeValue(double x);

int main() {
    double x;
    std::cout << "Enter value for x:  ";
    std::cin >> x;
    try {
        double result = computeValue(x);
        std::cout << "Result is " << result << std::endl;
    }
    catch (invalid_argument) {
        std::cout << "An invalid value was entered." << std::endl;
    }
} 

double computeValue(double x) {
    if (x < 3.0) {
        throw invalid_argument("x must be >= 3.0");
        return 0.5 * sqrt(x - 3.0);
    }
}