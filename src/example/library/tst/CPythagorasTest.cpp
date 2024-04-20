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
#include "example/library/CPythagoras.hpp"

//------------------------------------------------------------------------------
// Header Files: Own Component
//------------------------------------------------------------------------------
#include "CCalculatorMock.hpp"

//------------------------------------------------------------------------------
// Test Declarations
//------------------------------------------------------------------------------

TEST(CPythagorasTest, test_CPythagoras_calculate)
{
  std::string lLogString;
  const example::library::test::CCalculatorMock lCCalculatorMock(lLogString);
  const example::library::CPythagoras lPythagoras(lCCalculatorMock);
  const example::library::IPythagoras& lPythagoras_r = lPythagoras;

  EXPECT_EQ(lPythagoras_r.calculate(3, 4), 25);
  EXPECT_EQ(lLogString, "CCalculatorMock::mul:3:3 CCalculatorMock::mul:4:4 CCalculatorMock::add:9:16 ");
  lLogString.clear();

  EXPECT_EQ(lPythagoras_r.calculate(4, 5), 41);
  EXPECT_EQ(lLogString, "CCalculatorMock::mul:4:4 CCalculatorMock::mul:5:5 CCalculatorMock::add:16:25 ");
  lLogString.clear();
}
