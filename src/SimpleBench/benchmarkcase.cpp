#include "benchmarkcase.h"

BenchmarkCase::BenchmarkCase(std::string name,
                             std::function<void(TimeKeeper &timeKeeper)> fn,
                             std::size_t benchmarking_repetitions)
    : name(name), timeKeeper(benchmarking_repetitions), fn(fn) {}

void BenchmarkCase::run() { fn(timeKeeper); }

std::vector<double> BenchmarkCase::getTimes() const {
  return timeKeeper.getTimes();
}

std::string BenchmarkCase::getTimesString() const {
  std::string result = name + ", ";
  for (const auto &time : timeKeeper.getTimes()) {
    result += std::to_string(time) + ", ";
  }

  // remove trailing space and comma
  result.pop_back();
  result.pop_back();

  return result;
}
