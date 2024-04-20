/**
 *  @file CFileTemplate.hpp
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
namespace example::application {

//------------------------------------------------------------------------------
// Class Declaration
//------------------------------------------------------------------------------

/**
 *  @brief Short Description.
 *  Detailed Description.
 */
class CFileTemplate
{
    CFileTemplate(const CFileTemplate&) = delete;
    CFileTemplate(CFileTemplate&&) = delete;
    CFileTemplate& operator=(const CFileTemplate&) = delete;
    CFileTemplate& operator=(CFileTemplate&&) = delete;

  public:

    /** Constructor. */
    CFileTemplate();

    /** Destructor. */
    ~CFileTemplate() = default;

  protected:
  private:
};

}  // namespace example::application
