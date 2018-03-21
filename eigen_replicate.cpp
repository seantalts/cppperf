#include <benchmark/benchmark.h>
#include <Eigen/Dense>
#include <vector>
#include "util.hpp"

using namespace Eigen;

template <int S>
static void BM_EigenReplicateFirst(benchmark::State& state) {
  auto v = VectorXd::Random(S);
  std::vector<double> v2(S * S);
  for (auto _ : state) {
    MatrixXd r = v.replicate(1, S).unaryExpr([](auto x) {return exp(x);});
    escape(v2.data());
    for (int i = 0; i < r.size(); ++i) {
      v2[i] = r(i);
    }
    clobber();
  }
}

BENCHMARK_TEMPLATE(BM_EigenReplicateFirst, 16);
BENCHMARK_TEMPLATE(BM_EigenReplicateFirst, 256);
BENCHMARK_TEMPLATE(BM_EigenReplicateFirst, 1024);

template <int S>
static void BM_EigenReplicateAfter(benchmark::State& state) {
  auto v = VectorXd::Random(S);
  std::vector<double> v2(S * S);
  for (auto _ : state) {
    MatrixXd r = v.unaryExpr([](auto x) {return exp(x);}).replicate(1, S);
    escape(v2.data());
    for (int i = 0; i < r.size(); ++i) {
      v2[i] = r(i);
    }
    clobber();
  }
}

BENCHMARK_TEMPLATE(BM_EigenReplicateAfter, 16);
BENCHMARK_TEMPLATE(BM_EigenReplicateAfter, 256);
BENCHMARK_TEMPLATE(BM_EigenReplicateAfter, 1024);

BENCHMARK_MAIN();
