#include "timebased_key_value_store.h"

template <typename K, typename V>
TimeBasedKeyValueStore<K, V>::TimeBasedKeyValueStore() = default;

template <typename K, typename V>
V TimeBasedKeyValueStore<K, V>::get(K key, int timestamp) {
    V ans = this->keysToValueTimestampTupleMapping[key].get(timestamp);
    return ans;
}

template <typename K, typename V>
void TimeBasedKeyValueStore<K, V>::set(K key, V value, int timestamp) {
    this->keysToValueTimestampTupleMapping[key].set(value, timestamp);
}