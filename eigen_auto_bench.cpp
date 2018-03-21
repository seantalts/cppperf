#include <benchmark/benchmark.h>
#include <Eigen/Dense>
#include <vector>
#include "util.hpp"

using namespace Eigen;

template<int S>
static void BM_EigenAuto(benchmark::State& state) {
  MatrixXd m1(S, S);
  MatrixXd m2(S, S);
  std::vector<double> v;
  v.reserve(S*S);
  escape(v.data());
  for (auto _ : state) {
    auto r = m1.transpose() * m2 * 3.0;
    for (int i = 0; i < S*S; ++i)
      v[i] = r(i);
    clobber();
  }
}
BENCHMARK_TEMPLATE(BM_EigenAuto, 1);
BENCHMARK_TEMPLATE(BM_EigenAuto, 2);
BENCHMARK_TEMPLATE(BM_EigenAuto, 10);
BENCHMARK_TEMPLATE(BM_EigenAuto, 100);

template<int S>
static void BM_EigenExplicit(benchmark::State& state) {
  MatrixXd m1(S, S);
  MatrixXd m2(S, S);
  std::vector<double> v;
  v.reserve(S*S);
  escape(v.data());
  for (auto _ : state) {
    MatrixXd r = m1.transpose() * m2 * 3.0;
    for (int i = 0; i < S*S; ++i)
      v[i] = r(i);
    clobber();
  }
}
BENCHMARK_TEMPLATE(BM_EigenExplicit, 1);
BENCHMARK_TEMPLATE(BM_EigenExplicit, 2);
BENCHMARK_TEMPLATE(BM_EigenExplicit, 10);
BENCHMARK_TEMPLATE(BM_EigenExplicit, 100);

template<int S>
static void BM_EigenAutoFixed(benchmark::State& state) {
  Matrix<double, S, S> m1;
  Matrix<double, S, S> m2;
  for (int i = 0; i < S*S; ++i) {
    m1(i) = i + 1;
    m2(i) = S*S - i;
  }
  std::vector<double> v;
  v.reserve(S*S);
  escape(v.data());
  for (auto _ : state) {
    auto r = m1.transpose() * m2 * 3.0;
    for (int i = 0; i < S*S; ++i)
      v[i] = r(i);
    clobber();
  }
}
BENCHMARK_TEMPLATE(BM_EigenAutoFixed, 1);
BENCHMARK_TEMPLATE(BM_EigenAutoFixed, 2);
BENCHMARK_TEMPLATE(BM_EigenAutoFixed, 10);
BENCHMARK_TEMPLATE(BM_EigenAutoFixed, 100);

template<int S>
static void BM_EigenExplicitFixed(benchmark::State& state) {
  Matrix<double, S, S> m1;
  Matrix<double, S, S> m2;
  for (int i = 0; i < S*S; ++i) {
    m1(i) = i + 1;
    m2(i) = S*S - i;
  }
  std::vector<double> v;
  v.reserve(S*S);
  escape(v.data());
  for (auto _ : state) {
    Matrix<double, S, S> r = m1.transpose() * m2 * 3.0;
    for (int i = 0; i < S*S; ++i)
      v[i] = r(i);
    clobber();
  }
}
BENCHMARK_TEMPLATE(BM_EigenExplicitFixed, 1);
BENCHMARK_TEMPLATE(BM_EigenExplicitFixed, 2);
BENCHMARK_TEMPLATE(BM_EigenExplicitFixed, 10);
BENCHMARK_TEMPLATE(BM_EigenExplicitFixed, 100);

template<int S>
static void BM_EigenAutoVector(benchmark::State& state) {
  Matrix<double, S, 1> m1;
  for (int i = 0; i < S; ++i) {
    m1(i) = i + 1;
  }
  std::vector<double> v;
  v.reserve(S);
  escape(v.data());
  for (auto _ : state) {
    auto r = m1.transpose() * 3.0;
    for (int i = 0; i < S; ++i)
      v[i] = r(i);
    clobber();
  }
}
BENCHMARK_TEMPLATE(BM_EigenAutoVector, 1);
BENCHMARK_TEMPLATE(BM_EigenAutoVector, 2);
BENCHMARK_TEMPLATE(BM_EigenAutoVector, 10);
BENCHMARK_TEMPLATE(BM_EigenAutoVector, 100);
BENCHMARK_TEMPLATE(BM_EigenAutoVector, 1000);

template<int S>
static void BM_EigenExplicitVector(benchmark::State& state) {
  Matrix<double, S, 1> m1;
  for (int i = 0; i < S; ++i) {
    m1(i) = i + 1;
  }
  std::vector<double> v;
  v.reserve(S);
  escape(v.data());
  for (auto _ : state) {
    Matrix<double, S, 1> r = m1.transpose() * 3.0;
    for (int i = 0; i < S; ++i)
      v[i] = r(i);
    clobber();
  }
}
BENCHMARK_TEMPLATE(BM_EigenExplicitVector, 1);
BENCHMARK_TEMPLATE(BM_EigenExplicitVector, 2);
BENCHMARK_TEMPLATE(BM_EigenExplicitVector, 10);
BENCHMARK_TEMPLATE(BM_EigenExplicitVector, 100);
BENCHMARK_TEMPLATE(BM_EigenExplicitVector, 1000);


BENCHMARK_MAIN();
