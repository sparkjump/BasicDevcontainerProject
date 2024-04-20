/**
 *  @file ICalculator.hpp
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
 * @brief Provides some basic math operations.
 * Provides operations for adding and multiplying two integers
 */
class ICalculator
{
    ICalculator(const ICalculator&) = delete;
    ICalculator(ICalculator&&) = delete;
    ICalculator& operator=(const ICalculator&) = delete;
    ICalculator& operator=(ICalculator&&) = delete;

  protected:

    /** Constructor. */
    ICalculator() = default;

  public:

    /** Destructor. */
    virtual ~ICalculator() = default;

    /**
     * Adds two integer values.
     * @param aOperand1 The Operand1.
     * @param aOperand2 The Operand2.
     * @return The sum of Operand1 and Operand2.
     */
    virtual int add(int aOperand1, int aOperand2) const = 0;

    /**
     * Multiplies two integer values.
     * @param aOperand1 The Operand1.
     * @param aOperand2 The Operand2.
     * @return The product of Operand1 and Operand2.
     */
    virtual int mul(int aOperand1, int aOperand2) const = 0;
};

}  // namespace example::library
