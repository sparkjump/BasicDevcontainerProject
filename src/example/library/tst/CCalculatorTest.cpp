/**
 *  @file CFooMath.test.cpp
 */

//------------------------------------------------------------------------------
// Own Header File
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Header Files: Environment
//------------------------------------------------------------------------------
#include "gmock/gmock.h"
#include "gtest/gtest.h"

//------------------------------------------------------------------------------
// Header Files: Used Components
//------------------------------------------------------------------------------
#include "example/library/CCalculator.hpp"

//------------------------------------------------------------------------------
// Header Files: Own Component
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Test Declarations
//------------------------------------------------------------------------------

TEST(CCalculatorTest, test_CCalculator_add)
{
  const example::library::CCalculator lCalculator;
  const example::library::ICalculator& lCalculator_r = lCalculator;
  auto lResult = lCalculator_r.add(5, 6);
  EXPECT_EQ(lResult, 11);
}

TEST(CCalculatorTest, test_CCalculator_mul)
{
  const example::library::CCalculator lCalculator;
  const example::library::ICalculator& lCalculator_r = lCalculator;
  auto lResult = lCalculator_r.mul(5, 6);
  EXPECT_EQ(lResult, 30);
}
