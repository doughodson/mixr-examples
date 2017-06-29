

#include <iostream>
#include <cstdio>

#include "mixr/base/Statistic.hpp"

#include "mixr/base/Rng.hpp"
#include "mixr/base/distributions/Uniform.hpp"
#include "mixr/base/distributions/Pareto.hpp"
#include "mixr/base/distributions/Lognormal.hpp"
#include "mixr/base/distributions/Exponential.hpp"

// this test is to match original Mersenne Twister output
void testValidation()
{
  const unsigned int init[4] = {0x123, 0x234, 0x345, 0x456}, length = 4;
  mixr::base::Rng irand(init, length); // 32-bit int generator
  mixr::base::Rng drand; // double in [0, 1) generator, already init

  std::printf("1000 32-bit integer random numbers:\n");
  for (int i = 0; i < 1000; ++i) {
    std::printf("%10u ", irand.drawInt32());
    if ((i % 5) == 4) std::printf("\n");
  }
  std::printf("\n1000 random numbers in [0, 1):\n");
  for (int i = 0; i < 1000; ++i) {
    std::printf("%10.8f ", drand.drawHalfOpen());
    if ((i % 5) == 4) std::printf("\n");
  }
  return;
}

//
void testUniform()
{
  mixr::base::Uniform rng;
  rng.setMin(0.0);
  rng.setMax(10.0);

  for (int i = 0; i < 5000; ++i) {
    std::printf("%10.8f ", rng.draw());
    std::printf("\n");
  }
  return;
}

void testPareto()
{
  mixr::base::Pareto rng;
  rng.setAlpha(5.0);
  rng.setBeta(8.0);

  for (int i = 0; i < 5000; ++i) {
    std::printf("%10.8f ", rng.draw());
    std::printf("\n");
  }
  return;
}

void testLognormal()
{
  mixr::base::Lognormal rng;
  rng.setSigma(1.0);
  rng.setMu(4.0);
  rng.setGamma(5.0);     // location

  for (int i = 0; i < 5000; ++i) {
    std::printf("%10.8f ", rng.draw());
    std::printf("\n");
  }
  return;
}

void testExponential()
{
  mixr::base::Exponential rng;
  mixr::base::Statistic stats;

  //rng.setMean(10);       // 1/lambda
  rng.setLambda(1);
  rng.setGamma(0);     // location

  stats.clear();
  for (int i = 0; i < 1000; ++i) {
    double draw = rng.draw();
    //std::printf("%10.8f ", draw);
    //std::printf("\n");
    stats.sigma(draw);
  }

  std::cout << "Mean     : " << stats.mean() << std::endl;
  std::cout << "Variance : " << stats.variance() << std::endl;
  std::cout << "StdDev   : " << stats.stdDev() << std::endl;
  double ci = (1.96*stats.stdDev()) / std::sqrt(static_cast<double>(stats.getN()));
  std::cout << "CI : " << ci << std::endl;

  return;
}

int main(int argc, char* argv[])
{
  testValidation();
  //testLognormal();
  //testPareto();
  //testExponential();
  return 0;
}
