/**
 *  @file CPythagoras.hpp
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
#include "example/library/IPythagoras.hpp"

//------------------------------------------------------------------------------
// Forward Declarations
//------------------------------------------------------------------------------
namespace example::library {
class ICalculator;
}

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
class CPythagoras : public example::library::IPythagoras
{
    CPythagoras(const CPythagoras&) = delete;
    CPythagoras(CPythagoras&&) = delete;
    CPythagoras& operator=(const CPythagoras&) = delete;
    CPythagoras& operator=(CPythagoras&&) = delete;

  public:

    /**
     * Constructor.
     * @param aCalculator_r [use:~CPythagoras()] The Calculator.
     */
    explicit CPythagoras(const example::library::ICalculator& aCalculator_r);

    /** Destructor. */
    virtual ~CPythagoras() override = default;

  private:

    /** @see example::library::IPythagoras::calculate() */
    virtual int calculate(int aOperand1, int aOperand2) const override;

    /** The Calculator. */
    const example::library::ICalculator& mCalculator_r;
};

}  // namespace example::library
