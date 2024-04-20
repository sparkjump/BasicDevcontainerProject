/**
 *  @file CCalculator.hpp
 */

#pragma once

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
// Forward Declarations
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Namespace Declarations
//------------------------------------------------------------------------------
namespace example::library {

//------------------------------------------------------------------------------
// Class Declaration
//------------------------------------------------------------------------------

/**
 *  @brief Short Description.
 *  Detailed Description.
 */
class CCalculator : public example::library::ICalculator
{
    CCalculator(const CCalculator&) = delete;
    CCalculator(CCalculator&&) = delete;
    CCalculator& operator=(const CCalculator&) = delete;
    CCalculator& operator=(CCalculator&&) = delete;

  public:

    /** Constructor. */
    CCalculator();

    /** Destructor. */
    virtual ~CCalculator() override;

  private:

    /** @see example::library::ICalculator::add() */
    virtual int add(int aOperand1, int aOperand2) const override;

    /** @see example::library::ICalculator::mul() */
    virtual int mul(int aOperand1, int aOperand2) const override;
};

}  // namespace example::library
