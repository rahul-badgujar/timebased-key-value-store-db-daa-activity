#include <iostream>
#include <string>

#include "console_io.hpp"
#include "timebased_key_value_store.hpp"

using std::string;

int main() {
    TimeBasedKeyValueStore<string, int> db;
    char optionSelected;
    do {
        // show menu
        ConsoleIO::println("Timebased Key-Value Database Store");
        ConsoleIO::println("A. Add/Update");
        ConsoleIO::println("B. Retrieve");
        ConsoleIO::println("Q. Quit");
        ConsoleIO::print("Select option: ");
        optionSelected = ConsoleIO::input<char>();
        // convert to upper case
        optionSelected = toupper(optionSelected);
        // act on chosen option
        switch (optionSelected) {
            case 'Q':
                // exit program case
                ConsoleIO::println("Ok byeee!");
                break;
            case 'A':

                break;
            case 'B':

                break;
            default:
                ConsoleIO::println("Wrong option selected!");
                break;
        }

    } while (optionSelected != 'Q');

    return EXIT_SUCCESS;
}
