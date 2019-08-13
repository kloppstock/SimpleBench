#include <iostream>

#include "benchmark.h"
#include "montecarlopi.h"

void BM_std_cout(TimeKeeper &tk) {
  for (auto _ : tk)
    std::cout << "Hello World!" << std::endl;
}

void BM_monteCarloPi(TimeKeeper &timeKeeper) {
  for (auto _ : timeKeeper)
    std::cout << std::to_string(monteCarloPi(1000000)) << std::endl;
}

int main(int argc, char *argv[]) {
  Benchmark benchmark(argc, argv);

  REGISTER_BENCHMARK(benchmark, BM_std_cout);
  REGISTER_BENCHMARK(benchmark, BM_monteCarloPi);

  benchmark.run();

  std::cout << benchmark.getTimesString();

  return 0;
}
