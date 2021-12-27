#include <iostream>
#include <string>

#include "console_io.hpp"
#include "timebased_key_value_store.hpp"

int main() {
    char optionSelected;
    do {
        ConsoleIO::println("Timebased Key-Value Database Store");
        ConsoleIO::println("A. Add/Update");
        ConsoleIO::println("B. Retrieve");
        ConsoleIO::println("Q. Quit");
        ConsoleIO::print("Select option: ");
        optionSelected = ConsoleIO::input<char>();
        //

    } while (optionSelected != 'Q');

    return EXIT_SUCCESS;
}
