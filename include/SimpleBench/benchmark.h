#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <string>
#include <vector>

#include "benchmarkcase.h"

#define REGISTER_BENCHMARK(benchmark, fn)                                      \
  benchmark.registerBenchmark(#fn, &fn)

class Benchmark {
private:
  unsigned int benchmark_repetitions;
  std::string benchmark_out;
  std::vector<std::string> whitelist;
  std::vector<BenchmarkCase> cases;
  TimeKeeper timeKeeper;

  auto parseOptions(int argc, char *argv[]);

public:
  Benchmark(int argc, char *argv[]);

  void registerBenchmark(std::string name,
                         std::function<void(TimeKeeper &timeKeeper)> fn);

  void run();

  std::vector<std::vector<double>> getTimes() const;
  std::string getTimesString() const;
};

#endif // BENCHMARK_H
