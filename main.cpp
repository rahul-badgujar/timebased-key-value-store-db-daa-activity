#include <iostream>
#include <string>

#include "timebased_key_value_store.hpp"

int main() {
    TimeBasedKeyValueStore<int, int> db;
    db.set(101, 5, 1);
    db.set(102, 8, 2);
    db.set(101, 6, 3);
    int ans = db.get(101, 2);
    std::cout << "Value found is: " << ans << std::endl;
    return 0;
}

template <class K, class V>
TimeBasedKeyValueStore<K, V>::TimeBasedKeyValueStore() {
    // default ctor
}
