#include <iostream>

#include "timebased_key_value_store.h"

int main() {
    TimeBasedKeyValueStore<std::string, int> db;
    db.set("key1", 5, 1);
    db.set("key2", 8, 2);
    db.set("key1", 6, 3);
    int ans = db.get("key1", 2);
    std::cout << "Value found is: " << ans << std::endl;
    return 0;
}
