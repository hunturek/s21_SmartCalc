#include "gtest/gtest.h"
#include "../calc2/model.h"
#include <cstdlib>
#include <ctime>
#define LOW -1000.
#define HIGH +1000.
#define pi2 1.57

TEST(notation_tests, plus_test) {
  Model test;
  srand (static_cast <unsigned> (time(0)));
  double n1, n2;
  for(size_t i = 0; i < 100; i++){
    n1 = LOW + static_cast<double>(rand()) / static_cast<double>(RAND_MAX/(HIGH-LOW));
    n2 = LOW + static_cast<double>(rand()) / static_cast<double>(RAND_MAX/(HIGH-LOW));
    ASSERT_NEAR(test.calculate(QString("%1+(%2)").arg(n1).arg(n2), -1, 1, 0, 0)[0], n1+n2, 0.001);
  }
}

TEST(notation_tests, minus_test) {
  Model test;
  srand (static_cast <unsigned> (time(0)));
  double n1, n2;
  for(size_t i = 0; i < 100; i++){
    n1 = LOW + static_cast<double>(rand()) / static_cast<double>(RAND_MAX/(HIGH-LOW));
    n2 = LOW + static_cast<double>(rand()) / static_cast<double>(RAND_MAX/(HIGH-LOW));
    ASSERT_NEAR(test.calculate(QString("%1-(%2)").arg(n1).arg(n2), -1, 1, 0, 0)[0], n1-n2, 0.001);
  }
}

TEST(notation_tests, multi_test) {
  Model test;
  srand (static_cast <unsigned> (time(0)));
  double n1, n2;
  for(size_t i = 0; i < 100; i++){
    n1 = LOW + static_cast<double>(rand()) / static_cast<double>(RAND_MAX/(HIGH-LOW));
    n2 = LOW + static_cast<double>(rand()) / static_cast<double>(RAND_MAX/(HIGH-LOW));
    ASSERT_NEAR(test.calculate(QString("%1*(%2)").arg(n1).arg(n2), -1, 1, 0, 0)[0], n1*n2, 1.);
  }
}

TEST(notation_tests, div_test) {
  Model test;
  srand (static_cast <unsigned> (time(0)));
  double n1, n2;
  for(size_t i = 0; i < 100; i++){
    n1 = LOW + static_cast<double>(rand()) / static_cast<double>(RAND_MAX/(HIGH-LOW));
    n2 = LOW + static_cast<double>(rand()) / static_cast<double>(RAND_MAX/(HIGH-LOW));
    ASSERT_NEAR(test.calculate(QString("%1/(%2)").arg(n1).arg(n2), -1, 1, 0, 0)[0], n1/n2, 0.001);
  }
}

TEST(notation_tests, mod_test) {
  Model test;
  srand (static_cast <unsigned> (time(0)));
  double n1, n2;
  for(size_t i = 0; i < 100; i++){
    n1 = LOW + static_cast<double>(rand()) / static_cast<double>(RAND_MAX/(HIGH-LOW));
    n2 = LOW + static_cast<double>(rand()) / static_cast<double>(RAND_MAX/(HIGH-LOW));
    ASSERT_NEAR(test.calculate(QString("%1mod(%2)").arg(n1).arg(n2), -1, 1, 0, 0)[0], fmod(n1,n2), 1.);
  }
}

TEST(notation_tests, cos_test) {
  Model test;
  srand (static_cast <unsigned> (time(0)));
  double n1;
  for(size_t i = 0; i < 100; i++){
    n1 = LOW + static_cast<double>(rand()) / static_cast<double>(RAND_MAX/(HIGH-LOW));
    ASSERT_NEAR(test.calculate(QString("cos(%1)").arg(n1), -1, 1, 0, 0)[0], cos(n1), 0.001);
  }
}

TEST(notation_tests, sin_test) {
  Model test;
  srand (static_cast <unsigned> (time(0)));
  double n1;
  for(size_t i = 0; i < 100; i++){
    n1 = LOW + static_cast<double>(rand()) / static_cast<double>(RAND_MAX/(HIGH-LOW));
    ASSERT_NEAR(test.calculate(QString("sin(%1)").arg(n1), -1, 1, 0, 0)[0], sin(n1), 0.001);
  }
}

TEST(notation_tests, tan_test) {
  Model test;
  srand (static_cast <unsigned> (time(0)));
  double n1;
  for(size_t i = 0; i < 100; i++){
    n1 = -10 + static_cast<double>(rand()) / static_cast<double>(RAND_MAX/(10));
    ASSERT_NEAR(test.calculate(QString("tan(%1)").arg(n1), -1, 1, 0, 0)[0], tan(n1), 1);
  }
}

TEST(notation_tests, acos_test) {
  Model test;
  srand (static_cast <unsigned> (time(0)));
  double n1;
  for(size_t i = 0; i < 100; i++){
    n1 = -1 + static_cast<double>(rand()) / static_cast<double>(RAND_MAX/(1));
    ASSERT_NEAR(test.calculate(QString("acos(%1)").arg(n1), -1, 1, 0, 0)[0], acos(n1), 0.001);
  }
}

TEST(notation_tests, asin_test) {
  Model test;
  srand (static_cast <unsigned> (time(0)));
  double n1;
  for(size_t i = 0; i < 100; i++){
    n1 = -1 + static_cast<double>(rand()) / static_cast<double>(RAND_MAX/(1));
    ASSERT_NEAR(test.calculate(QString("asin(%1)").arg(n1), -1, 1, 0, 0)[0], asin(n1), 0.001);
  }
}

TEST(notation_tests, atan_test) {
  Model test;
  srand (static_cast <unsigned> (time(0)));
  double n1;
  for(size_t i = 0; i < 100; i++){
    n1 = static_cast<double>(rand()) / static_cast<double>(RAND_MAX/(pi2));
    ASSERT_NEAR(test.calculate(QString("atan(%1)").arg(n1), -1, 1, 0, 0)[0], atan(n1), 0.001);
  }
}

TEST(notation_tests, sqrt_test) {
  Model test;
  srand (static_cast <unsigned> (time(0)));
  double n1;
  for(size_t i = 0; i < 100; i++){
    n1 = static_cast<double>(rand()) / static_cast<double>(RAND_MAX/(HIGH-LOW));
    ASSERT_NEAR(test.calculate(QString("sqrt(%1)").arg(n1), -1, 1, 0, 0)[0], sqrt(n1), 0.001);
  }
}

TEST(notation_tests, ln_test) {
  Model test;
  srand (static_cast <unsigned> (time(0)));
  double n1;
  for(size_t i = 0; i < 100; i++){
    n1 = static_cast<double>(rand()) / static_cast<double>(RAND_MAX/(HIGH));
    ASSERT_NEAR(test.calculate(QString("ln(%1)").arg(n1), -1, 1, 0, 0)[0], log(n1), 0.001);
  }
}

TEST(notation_tests, log_test) {
  Model test;
  srand (static_cast <unsigned> (time(0)));
  double n1;
  for(size_t i = 0; i < 100; i++){
    n1 = static_cast<double>(rand()) / static_cast<double>(RAND_MAX/(HIGH));
    ASSERT_NEAR(test.calculate(QString("log(%1)").arg(n1), -1, 1, 0, 0)[0], log10(n1), 0.001);
  }
}

TEST(notation_tests, brackets_test) {
  Model test;
  ASSERT_DOUBLE_EQ(test.calculate("(2+4)*(11-8)", -1, 1, 0, 0)[0], 18);
}

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


