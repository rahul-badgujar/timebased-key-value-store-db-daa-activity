#include <iostream>
#include <string>

#include "console_io.hpp"
#include "timebased_key_value_store.hpp"

using std::string;
using std::to_string;

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
            case 'Q': {  // exit program case
                ConsoleIO::println("Ok byeee!");
                break;
            }
            case 'A': {
                ConsoleIO::print("Enter the key: ");
                string key = ConsoleIO::input<string>();
                ConsoleIO::print("Enter the value: ");
                int value = ConsoleIO::input<int>();
                int timestamp = db.set(key, value);
                ConsoleIO::println("The value got updated for key " + key + " as " + to_string(value) + " (at " + to_string(timestamp) + ")");
                break;
            }
            case 'B': {
                try {
                    ConsoleIO::print("Enter the key: ");
                    string key = ConsoleIO::input<string>();
                    ConsoleIO::print("Enter the timestamp: ");
                    int timestamp = ConsoleIO::input<int>();
                    auto [value, timestamp] = db.get(key, timestamp);
                    ConsoleIO::println("Value = " + to_string(value) + " (was updated at " + to_string(timestamp) + ")");
                } catch (const string& error) {
                    ConsoleIO::println(error);
                } catch (const char* error) {
                    ConsoleIO::println(string(error));
                }

                break;
            }
            default: {
                ConsoleIO::println("Wrong option selected!");
                break;
            }
        }

    } while (optionSelected != 'Q');

    return EXIT_SUCCESS;
}
