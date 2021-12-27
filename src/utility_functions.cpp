#include "utility_functions.hpp"

int getSecondsSinceEpochTillNow() {
    time_t now = time(nullptr);
    return (int)now;
}