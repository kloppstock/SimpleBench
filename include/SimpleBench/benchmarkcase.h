#ifndef BENCHMARKCASE_H
#define BENCHMARKCASE_H

#include <functional>
#include <string>

#include "timekeeper.h"

class BenchmarkCase {
private:
  std::string name;
  TimeKeeper timeKeeper;
  std::function<void(TimeKeeper &timeKeeper)> fn;

public:
  BenchmarkCase(std::string name,
                std::function<void(TimeKeeper &timeKeeper)> fn,
                std::size_t benchmarking_repetitions);

  void run();

  std::vector<double> getTimes() const;
  std::string getTimesString() const;
};

#endif // BENCHMARKCASE_H
