/**
 *  @file IPythagoras.hpp
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
 *  @brief Short Description.
 *  Detailed Description.
 */
class IPythagoras
{
    IPythagoras(const IPythagoras&) = delete;
    IPythagoras(IPythagoras&&) = delete;
    IPythagoras& operator=(const IPythagoras&) = delete;
    IPythagoras& operator=(IPythagoras&&) = delete;

  protected:

    /** Constructor. */
    IPythagoras() = default;

  public:

    /** Destructor. */
    virtual ~IPythagoras() = default;

    /**
     * Calculates aOperand1^2 + aOperand2^2.
     * @param aOperand1 The Operand1.
     * @param aOperand2 The Operand2.
     * @return The result.
     */
    virtual int calculate(int aOperand1, int aOperand2) const = 0;
};

}  // namespace example::library
