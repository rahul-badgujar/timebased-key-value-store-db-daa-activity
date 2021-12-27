#pragma once

#include <algorithm>
#include <list>
#include <unordered_map>

#include "utility_functions.hpp"
#include "value_timestamp_tuple.hpp"

using std::list;
using std::reverse;

/**
 * A Timebased Key Value Database Store.
 *
 * Stores the history of values assigned to a particular key using timestamps.
 * Allows retrieval of value assigned to a key at or just before a particular timestamp.
 *
 * @tparam K Data Type for Key
 * @tparam V Data Type for Value
 */
template <class K, class V>
class TimeBasedKeyValueStore {
   private:
    /// Key-Value mapped relations. Values are stored as (Value,Timestamp) Tuples.
    std::unordered_map<K, ValueTimestampTuple<V>> keysToValueTimestampTupleMapping;

   public:
    /// ctor
    TimeBasedKeyValueStore();
    /// dtor
    ~TimeBasedKeyValueStore();

    /**
     * Set the value for the given key, storing update timestamp info as well and
     * returns the timestamp at which value update is stored.
     *
     * @param key The key for which value is to be updated/set.
     * @param value The value to be updated for given key.
     * @param timestamp The timestamp at which the set/update operation is being performed.
     *
     * @returns int Returns the timestamp at which value update is stored.
     * */
    int set(const K &key, const V &value, const int &timestamp);

    /**
     * Set the value for the given key, storing update timestamp info as well  and
     * returns the timestamp at which value update is stored.
     * Current timestamp (as seconds since epoch) is considered here by default.
     * To specify custom timestamp, use set(key,value,timestamp) method.
     *
     * @param key The key for which value is to be updated/set.
     * @param value The value to be updated for given key.
     *
     * @returns int Returns the timestamp at which value update is stored.
     * */
    int set(const K &key, const V &value);

    /**
     * Get the value associated with key updated at or just before given timestamp.
     *
     * @param key The key for which corresponding value required.
     * @param timestamp The upper bound on timestamp on or just before which the value updated is required.
     * @return V: The value corresponding to given key and timestamp upper bound.
     *
     * @throws NoUpdateHistoryFoundException Thrown if no any value matches the given requirements, exception is thrown.
     */
    pair<V, int> get(const K &key, const int &timestamp);

    /**
     * Get the history of value updates as list of [value,timestamp] in descending order, associated with key.
     *
     * @param key The key for which corresponding value required.
     * @return list<pair<V,int>>: Returns the list of value-timestamp pairs.
     *
     */
    list<pair<V, int>> getValueUpdatesHistory(const K &key);
};

template <class K, class V>
TimeBasedKeyValueStore<K, V>::TimeBasedKeyValueStore() {
    // default ctor
}

template <class K, class V>
TimeBasedKeyValueStore<K, V>::~TimeBasedKeyValueStore() {
    // release the memory taken to store key value tuple relations.
    this->keysToValueTimestampTupleMapping.clear();
}

template <class K, class V>
pair<V, int> TimeBasedKeyValueStore<K, V>::get(const K &key, const int &timestamp) {
    // Get the value-timestamp tuple corresponding to given key.
    auto &valueTimestampTupleCorrespondingGivenKey = this->keysToValueTimestampTupleMapping[key];
    // Get the required value and timestamp; and return
    return valueTimestampTupleCorrespondingGivenKey.getValueAtTimestamp(timestamp);
}

template <class K, class V>
int TimeBasedKeyValueStore<K, V>::set(const K &key, const V &value, const int &timestamp) {
    // Get the value-timestamp tuple corresponding to given key.
    auto &valueTimestampTupleCorrespondingGivenKey = this->keysToValueTimestampTupleMapping[key];
    // Set the value at timestamp.
    return valueTimestampTupleCorrespondingGivenKey.setValueAtTimestamp(value, timestamp);
}

template <class K, class V>
int TimeBasedKeyValueStore<K, V>::set(const K &key, const V &value) {
    // Get the current timestamp (seconds since epoch)
    auto timestamp = getSecondsSinceEpochTillNow();
    return this->set(key, value, timestamp);
}

template <class K, class V>
list<pair<V, int>> TimeBasedKeyValueStore<K, V>::getValueUpdatesHistory(const K &key) {
    // check if key exists in db
    auto keyExists = this->keysToValueTimestampTupleMapping.find(key) == this->keysToValueTimestampTupleMapping.end();
    if (!keyExists) {
        // return empty list
        return {};
    }

    // get the corresponding value timestamp tuple
    auto valueTimestampTuple = this->keysToValueTimestampTupleMapping[key];

    return valueTimestampTuple.getValueUpdatesHistoryWithTimestamps(true);
}