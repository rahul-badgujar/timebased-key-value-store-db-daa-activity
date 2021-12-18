#include "no_update_history_found_exception.hpp"

const std::string NoUpdateHistoryFoundException::DEFAULT_MESSAGE = "No update history could be found for given key and timestamp combination.";

NoUpdateHistoryFoundException::NoUpdateHistoryFoundException() : Exception(NoUpdateHistoryFoundException::DEFAULT_MESSAGE) {
    // default ctor
}

NoUpdateHistoryFoundException::NoUpdateHistoryFoundException(const std::string &message) : Exception(message) {
    // ctor
}