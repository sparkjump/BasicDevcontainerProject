/**
 *  @file CPythagoras.cpp
 */

//------------------------------------------------------------------------------
// Own Header File
//------------------------------------------------------------------------------
#include "example/library/CPythagoras.hpp"

//------------------------------------------------------------------------------
// Header Files: Environment
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Header Files: Used Components
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Header Files: Own Component
//------------------------------------------------------------------------------
#include "example/library/ICalculator.hpp"

//------------------------------------------------------------------------------
// Namespace Declarations
//------------------------------------------------------------------------------
namespace example::library {

//------------------------------------------------------------------------------
// Initialization of Static Class Variables
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Definitions of Class Methods
//------------------------------------------------------------------------------

CPythagoras::CPythagoras(const example::library::ICalculator& aCalculator_r)
: mCalculator_r(aCalculator_r)
{
}

int CPythagoras::calculate(int aOperand1, int aOperand2) const
{
  auto lOperand1 = mCalculator_r.mul(aOperand1, aOperand1);
  auto lOperand2 = mCalculator_r.mul(aOperand2, aOperand2);
  return mCalculator_r.add(lOperand1, lOperand2);
}

}  // namespace example::library
