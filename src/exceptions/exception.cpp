#include "exceptions/exception.hpp"

Exception::Exception(const std::string &message) : message(message) {
    // ctor
}

std::string Exception::getMessage() {
    return this->message;
}
