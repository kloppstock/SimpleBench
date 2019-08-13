#ifndef TIMEKEEPER_H
#define TIMEKEEPER_H

#include <chrono>
#include <memory>
#include <vector>

class TimeKeeper {
private:
  std::shared_ptr<std::vector<std::chrono::high_resolution_clock::time_point>>
      times;
  std::size_t index;

  void increment();

public:
  explicit TimeKeeper(std::size_t iterations);

  explicit TimeKeeper(
      std::shared_ptr<
          std::vector<std::chrono::high_resolution_clock::time_point>>
          times,
      std::size_t index);

  void resize(std::size_t size);

  std::vector<double> getTimes() const;

  std::chrono::high_resolution_clock::time_point operator*() const;

  TimeKeeper begin();
  TimeKeeper end();

  bool operator!=(const TimeKeeper &other) const;

  TimeKeeper &operator++();
  TimeKeeper operator++(int);
};
#endif // TIMEKEEPER_H
