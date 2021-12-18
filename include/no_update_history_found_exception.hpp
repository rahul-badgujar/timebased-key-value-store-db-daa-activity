#pragma once

#include "exception.hpp"

/**
 * The exception for situation when No value update history exists for given key and timestamp.
 */
class NoUpdateHistoryFoundException : public Exception {
   private:
   public:
    /// The default error message.
    static const std::string DEFAULT_MESSAGE;

    /// Default ctor, uses DEFAULT_MESSAGE as error message.
    NoUpdateHistoryFoundException();

    /// Ctor accepting custom error message.
    NoUpdateHistoryFoundException(std::string message);
};
