/**
 *  @file CCalculatorMock.cpp
 */

//------------------------------------------------------------------------------
// Own Header File
//------------------------------------------------------------------------------
#include "CCalculatorMock.hpp"

//------------------------------------------------------------------------------
// Header Files: Environment
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Header Files: Used Components
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Header Files: Own Component
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Namespace Declarations
//------------------------------------------------------------------------------
namespace example::library::test {

//------------------------------------------------------------------------------
// Initialization of Static Class Variables
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Definitions of Class Methods
//------------------------------------------------------------------------------

CCalculatorMock::CCalculatorMock(std::string& aLogString_r)
: mLogString_r(aLogString_r)
{
}

int CCalculatorMock::add(int aOperand1, int aOperand2) const
{
  mLogString_r += "CCalculatorMock::add:" + std::to_string(aOperand1) + ":" + std::to_string(aOperand2) + " ";
  return aOperand1 + aOperand2;
}

int CCalculatorMock::mul(int aOperand1, int aOperand2) const
{
  mLogString_r += "CCalculatorMock::mul:" + std::to_string(aOperand1) + ":" + std::to_string(aOperand2) + " ";
  return aOperand1 * aOperand2;
}

}  // namespace example::library::test
