/**
 *  @file CCalculatorMock.hpp
 */

#pragma once

//------------------------------------------------------------------------------
// Header Files: Environment
//------------------------------------------------------------------------------
#include <string>

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
namespace example::library::test {

//------------------------------------------------------------------------------
// Class Declaration
//------------------------------------------------------------------------------

/**
 *  @brief Short Description.
 *  Detailed Description.
 */
class CCalculatorMock : public example::library::ICalculator
{
    CCalculatorMock(const CCalculatorMock&) = delete;
    CCalculatorMock(CCalculatorMock&&) = delete;
    CCalculatorMock& operator=(const CCalculatorMock&) = delete;
    CCalculatorMock& operator=(CCalculatorMock&&) = delete;

  public:

    /**
     * Constructor.
     * @param aLogString_r [use:~CCalculatorMock()] The LogString;
     */
    explicit CCalculatorMock(std::string& aLogString_r);

    /** Destructor. */
    virtual ~CCalculatorMock() override = default;

  private:

    /** @see example::library::ICalculator::add() */
    virtual int add(int aOperand1, int aOperand2) const override;

    /** @see example::library::ICalculator::mul() */
    virtual int mul(int aOperand1, int aOperand2) const override;

    /** The LogString. */
    std::string& mLogString_r;
};

}  // namespace example::library::test
