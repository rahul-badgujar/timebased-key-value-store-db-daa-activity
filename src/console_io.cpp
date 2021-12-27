#include "console_io.hpp"

using std::cout;
using std::endl;
using std::string;

void ConsoleIO::print(string message) {
    cout << message;
}

void ConsoleIO::println(string message) {
    cout << message << endl;
}