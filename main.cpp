#include <iostream>
#include <string>

#include "timebased_key_value_store.hpp"

int main() {
    char optionSelected;
    do {
        std::cout << "Timebased Key-Value Database Store" << std::endl;
        std::cout << "A. Add/Update" << std::endl;
        std::cout << "B. Retrieve" << std::endl;
        std::cout << "Q. Quit" << std::endl;

    } while (optionSelected != 'Q');
    return 0;
}
