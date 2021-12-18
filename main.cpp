#include <iostream>
#include <string>

#include "timebased_key_value_store.hpp"

int main() {
    TimeBasedKeyValueStore<std::string, int> db;
    db.set("key101", 5, 1);
    db.set("key102", 8, 2);
    db.set("key101", 6, 3);
    try {
        int ans = db.get("key102", 1);
        std::cout << "Value found is: " << ans << std::endl;
    } catch (NoUpdateHistoryFoundException exception) {
        std::cout << exception.getMessage() << std::endl;
    }
    return 0;
}
