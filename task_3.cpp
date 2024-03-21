#include <iostream>
#include <cmath>

double function(double x, double y) {
    return x*x - 4 + y*y + 6*x*y;
}

int main() {
    double minX = -10, maxX = 10;
    double minY = -10, maxY = 10;
    double step = 0.01; // Шаг перебора

    double minF = function(minX, minY);
    double bestX = minX, bestY = minY;

    for(double x = minX; x <= maxX; x += step) {
        for(double y = minY; y <= maxY; y += step) {
            double currentF = function(x, y);
            if(currentF < minF) {
                minF = currentF;
                bestX = x;
                bestY = y;
            }
        }
    }

    std::cout << "Minimum of function is " << minF << " at x = " << bestX << ", y = " << bestY << std::endl;

    return 0;
}
