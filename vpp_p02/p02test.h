#pragma once

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include "./fraesung.h"
#include "./delist.h"
using namespace testing;

using std::cout;
using std::endl;

TEST(KomponenteTest, ConstructorDefaultArguments) {
  Komponente k0{0.0, 0.0};
  ASSERT_EQ(0.0, k0.getX());
  ASSERT_EQ(0.0, k0.getY());

  Komponente k1{3.0, 4.0};
  EXPECT_DOUBLE_EQ(3.0, k1.getX());
  EXPECT_DOUBLE_EQ(4.0, k1.getY());
}

TEST(KomponenteTest, Output) {
  Komponente k{2.3, 45.7};
  const char* sk = "(2.3, 45.7)";
  std::ostringstream oss;
  k.output(oss);
  EXPECT_STREQ(sk, oss.str().c_str());
}

TEST(BohrungTest, ConstructorDefaultArguments) {
  Bohrung b0;
  ASSERT_EQ(0.0, b0.getX());
  ASSERT_EQ(0.0, b0.getY());
  ASSERT_EQ(6.0, b0.getDiameter());

  Bohrung b1{3., 4., 3.};
  EXPECT_DOUBLE_EQ(3.0, b1.getX());
  EXPECT_DOUBLE_EQ(4.0, b1.getY());
  EXPECT_DOUBLE_EQ(3.0, b1.getDiameter());

  Bohrung b2{3., 4., 0.0};
  EXPECT_DOUBLE_EQ(6.0, b2.getDiameter());

  Bohrung b3{3., 4., -2.1};
  EXPECT_DOUBLE_EQ(6.0, b3.getDiameter());
}

TEST(BohrungTest, Output) {
  Bohrung b{33.21, 47.02, 6.5};
  const char* sb = "Bohrung: (33.21, 47.02), Durchmesser: 6.5";
  std::ostringstream oss;
  b.output(oss);
  EXPECT_STREQ(sb, oss.str().c_str());
}

TEST(FraesungTest, Constructor) {
  Fraesung f0{0., 0., 0., -2.};
  ASSERT_EQ(0.0, f0.getX());
  ASSERT_EQ(0.0, f0.getY());
  ASSERT_EQ(6.0, f0.getDiameter());
  ASSERT_EQ(0.0, f0.getLength());
  ASSERT_EQ(0.0, f0.getAngle());

  Fraesung f1{3, 4, 2.0, 5, M_PI_4};
  EXPECT_DOUBLE_EQ(3.0, f1.getX());
  EXPECT_DOUBLE_EQ(4.0, f1.getY());
  EXPECT_DOUBLE_EQ(2.0, f1.getDiameter());
  EXPECT_DOUBLE_EQ(5.0, f1.getLength());
  EXPECT_DOUBLE_EQ(M_PI_4, f1.getAngle());
}

TEST(FraesungTest, EndPoints) {
  Fraesung f0{0., 0., 0., -3.5};
  EXPECT_DOUBLE_EQ(0.0, f0.getEndX());
  EXPECT_DOUBLE_EQ(0.0, f0.getEndY());

  Fraesung f1{3, 4, 8., 5, M_PI_4};
  EXPECT_DOUBLE_EQ(3.0 + 2.5 * sqrt(2), f1.getEndX());
  EXPECT_DOUBLE_EQ(4.0 + 2.5 * sqrt(2), f1.getEndY());
}

TEST(FraesungTest, Output) {
  Fraesung f{3, 4, 8., 5, M_PI_4};
  const char* sf =
      "Fraesung mit Start: (3, 4) und Endpunkt: (6.53553, 7.53553),"
      " Durchmesser: 8";
  std::ostringstream oss;
  f.output(oss);
  EXPECT_STREQ(sf, oss.str().c_str());
}

TEST(DeListTest, ConstructEntries) {
  DeList kl;
  ASSERT_EQ(nullptr, *kl.begin());
  EXPECT_TRUE(0 == kl.size());
  Bohrung b;
  kl.push_back(&b);
  ASSERT_NE(nullptr, *kl.begin());
  EXPECT_TRUE(1 == kl.size());
  Fraesung f{1, 0, 2, 3, 4};
  kl.push_back(&f);
  EXPECT_TRUE(2 == kl.size());
  auto it = Iterator(kl.begin());
  while (it != kl.end()) {
    ASSERT_NE(nullptr, *it);
    ++it;
  }
}

TEST(DeListTest, DeleteEntries) {
  DeList kl;
  Bohrung b;
  Fraesung f{1, 0, 1, 1};
  kl.push_back(&b);
  kl.push_back(&f);
  auto it = Iterator(kl.begin());
  EXPECT_NE(nullptr, *(it = kl.erase(it)));
  EXPECT_NE(nullptr, *kl.begin());
  EXPECT_TRUE(1 == kl.size());
  EXPECT_TRUE(nullptr == *kl.erase(it));
  EXPECT_TRUE(0 == kl.size());
}

TEST(DeListTest, DeleteEmptyList) {
  DeList kl;
  auto it = Iterator(kl.begin());
  EXPECT_TRUE(0 == kl.size());
  EXPECT_TRUE(kl.begin() == kl.end());
  EXPECT_EQ(nullptr, *kl.begin());
  EXPECT_TRUE(nullptr == *kl.erase(it));
}