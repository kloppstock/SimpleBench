# SimpleBench
A very simple and minimalistic benchmarking library

## Usage

Implement your benchmarking caes as follows:
```c++
#include "benchmark.h"

// ...

void BM_Fn(TimeKeeper &tk) {
  setUp();
  for(auto _ : tk)
    runBenchmarkFunctino();
}
```

The benchmark case can then be registered and run in the main function like this:
```c++
int maint(int argc, char* argv[]) {
  Benchmark benchmark(argcm argv);

  REGISTER_BENCHMARK(benchmark, BM_Fn);
  
  // register more functions here if needed
  
  benchmark.run();
  
  // ...
}
```

The number of benchmark repetitions can be set via the command line using ```--benchmark_repetitions=NUM```. 

If the results need to be stored in a CSV file, use the argument ```--benchmark_out=FILENAME.csv```.

Additionally, if only certain cases should be executed, select each one using ```--benchmark_enable=FUNCTION```.

An example of this is implemented in the [src/main.cpp](src/main.cpp) file. A possible execution might look like this:
```
./bench --benchmark_repetitions=3 --benchmark_enable=BM_std_cout --benchmark_enable=BM_monteCarloPi --benchmark_out=out.csv
```

## License

This software is licensed under the MIT license. For more information see [LICENSE](LICENSE). 
