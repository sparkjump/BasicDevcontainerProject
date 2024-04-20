/**
 *  @file CFileExample.cpp
 */

//------------------------------------------------------------------------------
// Header Files: Environment
//------------------------------------------------------------------------------
#include <iostream>
//------------------------------------------------------------------------------
// Header Files: Used Components
//------------------------------------------------------------------------------
#include "example/library/CCalculator.hpp"
#include "example/library/CPythagoras.hpp"

//------------------------------------------------------------------------------
// Header Files: Own Component
//------------------------------------------------------------------------------
#include "example/application/CFileTemplate.hpp"

//------------------------------------------------------------------------------
// Definitions of Functions
//------------------------------------------------------------------------------

int main(void)
{
  const example::application::CFileTemplate lFileTemplate;

  const example::library::CCalculator lCalculator;
  const example::library::CPythagoras lPythagoras(lCalculator);
  const example::library::IPythagoras& lPythagoras_r = lPythagoras;

  const int lOperand1 = 3;
  const int lOperand2 = 4;
  const int lResult = lPythagoras_r.calculate(lOperand1, lOperand2);

  std::cout << "Pythagoras from " << lOperand1 << " and " << lOperand2 << " is " << lResult << std::endl;

  return 0;
}
