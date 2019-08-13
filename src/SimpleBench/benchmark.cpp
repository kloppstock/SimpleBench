#include "benchmark.h"

#include <cstring>
#include <fstream>

auto Benchmark::parseOptions(int argc, char *argv[]) {
  benchmark_out = "";
  for (int i = 0; i < argc; ++i) {
    if (!memcmp("--benchmark_repetitions=", argv[i], 24)) {
      benchmark_repetitions =
          static_cast<unsigned int>(std::atoi(&argv[i][24]));
    } else if (!memcmp("--benchmark_out=", argv[i], 16)) {
      benchmark_out = std::string(&argv[i][16]);
    } else if (!memcmp("--benchmark_enable=", argv[i], 19)) {
      whitelist.emplace_back(&argv[i][19]);
    }
  }

  return std::make_tuple(benchmark_repetitions, benchmark_out, whitelist);
}

Benchmark::Benchmark(int argc, char *argv[])
    : benchmark_repetitions(10), timeKeeper(benchmark_repetitions) {
  auto [benchmark_repetitions, benchmark_out, whitelist] =
      parseOptions(argc, argv);
}

void Benchmark::registerBenchmark(
    std::string name, std::function<void(TimeKeeper &timeKeeper)> fn) {
  if (whitelist.empty() ||
      std::find(whitelist.begin(), whitelist.end(), name) != whitelist.end())
    cases.emplace_back(name, fn, benchmark_repetitions);
}

void Benchmark::run() {
  for (BenchmarkCase &c : cases)
    c.run();

  if (benchmark_out != "") {
    std::ofstream out(benchmark_out.c_str());
    if (out.is_open()) {
      out << getTimesString();
      out.flush();
      out.close();
    }
  }
}

std::vector<std::vector<double>> Benchmark::getTimes() const {
  std::vector<std::vector<double>> result;
  result.reserve(cases.size());

  for (const auto &c : cases)
    result.emplace_back(c.getTimes());

  return result;
}

std::string Benchmark::getTimesString() const {
  std::string result = "";

  for (const auto &c : cases)
    result += c.getTimesString() + "\n";

  return result;
}
