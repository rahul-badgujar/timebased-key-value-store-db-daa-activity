#pragma once

#include "exception.hpp"

class NoUpdateHistoryFoundException : public Exception {
   private:
   public:
    static const std::string DEFAULT_MESSAGE;
    NoUpdateHistoryFoundException();
    NoUpdateHistoryFoundException(std::string message);
};
