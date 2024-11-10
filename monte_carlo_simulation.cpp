#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

// Function to simulate particle paths and count how many reach the target area
int simulateParticles(int numParticles, double radius) {
    int particlesWithinRadius = 0;

    for (int i = 0; i < numParticles; ++i) {
        // Generate random x, y coordinates between -1 and 1
        double x = (static_cast<double>(rand()) / RAND_MAX) * 2 - 1;
        double y = (static_cast<double>(rand()) / RAND_MAX) * 2 - 1;

        // Check if the particle is within the target radius
        if (sqrt(x * x + y * y) <= radius) {
            particlesWithinRadius++;
        }
    }

    return particlesWithinRadius;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int numParticles;
    double radius = 1.0;

    std::cout << "Enter the number of particles to simulate: ";
    std::cin >> numParticles;

    int particlesWithin = simulateParticles(numParticles, radius);
    double estimate = static_cast<double>(particlesWithin) / numParticles;

    std::cout << "Approximate fraction of particles within the target area: " << estimate << std::endl;

    return 0;
}