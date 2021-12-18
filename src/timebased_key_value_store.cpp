#include "timebased_key_value_store.h"

template <class K, class V>
TimeBasedKeyValueStore<K, V>::TimeBasedKeyValueStore() {
    // default ctor
}

template <class K, class V>
TimeBasedKeyValueStore<K, V>::~TimeBasedKeyValueStore() {
    this->keysToValueTimestampTupleMapping.clear();
}

template <class K, class V>
V TimeBasedKeyValueStore<K, V>::get(K key, int timestamp) {
    V ans = this->keysToValueTimestampTupleMapping[key].get(timestamp);
    return ans;
}

template <class K, class V>
void TimeBasedKeyValueStore<K, V>::set(K key, V value, int timestamp) {
    this->keysToValueTimestampTupleMapping[key].set(value, timestamp);
}