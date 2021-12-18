#pragma once
#include <unordered_map>

#include "value_timestamp_tuple.hpp"

template <class K, class V>
class TimeBasedKeyValueStore {
   private:
    std::unordered_map<K, ValueTimestampTuple<V>> keysToValueTimestampTupleMapping;

   public:
    TimeBasedKeyValueStore();
    ~TimeBasedKeyValueStore();
    void set(K key, V value, int timestamp);
    V get(K key, int timestamp);
};

template <class K, class V>
TimeBasedKeyValueStore<K, V>::~TimeBasedKeyValueStore() {
    this->keysToValueTimestampTupleMapping.clear();
}

template <class K, class V>
V TimeBasedKeyValueStore<K, V>::get(K key, int timestamp) {
    V ans = this->keysToValueTimestampTupleMapping[key].getValueAtTimestamp(timestamp);
    return ans;
}

template <class K, class V>
void TimeBasedKeyValueStore<K, V>::set(K key, V value, int timestamp) {
    this->keysToValueTimestampTupleMapping[key].setValueAtTimestamp(value, timestamp);
}