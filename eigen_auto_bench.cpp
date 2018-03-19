#include <benchmark/benchmark.h>
#include <Eigen/Dense>
#include <vector>

using namespace Eigen;

template<int S>
static void BM_EigenAuto(benchmark::State& state) {
  MatrixXd m1(S, S);
  MatrixXd m2(S, S);
  std::vector<double> v;
  for (auto _ : state) {
    auto r = m1 * m2 * 3.0;
    v.reserve(S*S);
    for (int i = 0; i < S*S; ++i)
      v[i] = r(i);
  }
}
// Register the function as a benchmark
BENCHMARK_TEMPLATE(BM_EigenAuto, 1);
BENCHMARK_TEMPLATE(BM_EigenAuto, 2);
BENCHMARK_TEMPLATE(BM_EigenAuto, 10);
BENCHMARK_TEMPLATE(BM_EigenAuto, 100);

template<int S>
static void BM_EigenExplicit(benchmark::State& state) {
  MatrixXd m1(S, S);
  MatrixXd m2(S, S);
  std::vector<double> v;
  for (auto _ : state) {
    MatrixXd r = (m1 * m2) * 3.0;
    v.reserve(S*S);
    for (int i = 0; i < S*S; ++i)
      v[i] = r(i);
  }
}
BENCHMARK_TEMPLATE(BM_EigenExplicit, 1);
BENCHMARK_TEMPLATE(BM_EigenExplicit, 2);
BENCHMARK_TEMPLATE(BM_EigenExplicit, 10);
BENCHMARK_TEMPLATE(BM_EigenExplicit, 100);

BENCHMARK_MAIN();
