#include "timekeeper.h"

void TimeKeeper::increment() {
  times->at(index) = std::chrono::high_resolution_clock::now();
  ++index;
}

TimeKeeper::TimeKeeper(std::size_t iterations)
    : times(new std::vector<std::chrono::high_resolution_clock::time_point>(
          iterations + 1)),
      index(0) {}

TimeKeeper::TimeKeeper(
    std::shared_ptr<std::vector<std::chrono::high_resolution_clock::time_point>>
        times,
    std::size_t index)
    : times(times), index(index) {}

void TimeKeeper::resize(std::size_t size) {
  times->resize(size + 1);
  index = 0;
}

std::vector<double> TimeKeeper::getTimes() const {
  std::vector<double> result;

  for (unsigned int i = 1; i < times->size(); ++i)
    result.emplace_back(std::chrono::duration_cast<std::chrono::nanoseconds>(
                            times->at(i) - times->at(i - 1))
                            .count());
  return result;
}

std::chrono::high_resolution_clock::time_point TimeKeeper::operator*() const {
  return (*times)[index];
}

TimeKeeper TimeKeeper::begin() {
  index = 0;
  increment();
  return TimeKeeper(times, index);
}

TimeKeeper TimeKeeper::end() { return TimeKeeper(times, times->size()); }

bool TimeKeeper::operator!=(const TimeKeeper &other) const {
  return (times != other.times) || (index != other.index);
}

TimeKeeper &TimeKeeper::operator++() {
  increment();
  return *this;
}

TimeKeeper TimeKeeper::operator++(int) {
  TimeKeeper ret = TimeKeeper(times, index);
  increment();
  return ret;
}
