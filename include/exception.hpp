#pragma once

#include <string>

/**
 * An exception with error message.
 *
 */
class Exception {
   private:
    /// The error message.
    std::string message;

   public:
    // parameterized ctor
    Exception(std::string message);

    /**
     * Get the error message for details about exception.
     *
     * @return std::string The error message.
     */
    std::string getMessage();
};
