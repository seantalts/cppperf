# Results
2018-03-19 16:20:38
Running ./eigen_auto_bench
Run on (8 X 2900 MHz CPU s)
CPU Caches:
  L1 Data 32K (x4)
  L1 Instruction 32K (x4)
  L2 Unified 262K (x4)
  L3 Unified 8388K (x1)
-------------------------------------------------------------
Benchmark                      Time           CPU Iterations
-------------------------------------------------------------
BM_EigenAuto<1>               97 ns         97 ns    6665207
BM_EigenAuto<2>              462 ns        461 ns    1498214
BM_EigenAuto<10>           43613 ns      43539 ns      15236
BM_EigenAuto<100>      509915691 ns  508834500 ns          2
BM_EigenExplicit<1>          223 ns        222 ns    3146789
BM_EigenExplicit<2>          234 ns        234 ns    2860015
BM_EigenExplicit<10>         638 ns        637 ns    1163815
BM_EigenExplicit<100>      57227 ns      57170 ns      12588
