#include "montecarlopi.h"

#include <random>

double monteCarloPi(unsigned int iterations) {
  // init variables
  unsigned int in = 0;

  // init RNG
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 1.0);

  // iterate
  for (unsigned int i = 0; i < iterations; ++i) {
    // generate position
    double x = dis(gen);
    double y = dis(gen);

    // check if the position is inside of the unit circle
    if (x * x + y * y <= 1.0)
      ++in;
  }

  // calculate and return pi
  return static_cast<double>(in) / static_cast<double>(iterations) * 4.0;
}
