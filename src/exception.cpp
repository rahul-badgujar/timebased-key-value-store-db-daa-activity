#include "exception.hpp"

Exception::Exception(std::string message) : message(message) {
    // ctor
}

std::string Exception::getMessage() {
    return this->message;
}
