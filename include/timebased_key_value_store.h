#pragma once
#include <unordered_map>

#include "value_timestamp_tuple.h"

template <class K, class V>
class TimeBasedKeyValueStore {
   private:
    std::unordered_map<K, ValueTimestampTuple<V>> keysToValueTimestampTupleMapping;

   public:
    TimeBasedKeyValueStore();
    void set(K key, V value, int timestamp);
    V get(K key, int timestamp);
};