#pragma once

#include <cassert>
#include <string>
#include <vector>

#include "exceptions/no_update_history_found_exception.hpp"

/**
 * Values history storage.
 * Stores values with timestamps to maintain history of value updates.
 *
 * @tparam V The data type of value to be stored.
 */
template <class V>
class ValueTimestampTuple {
   private:
    /// List of values.
    std::vector<V> values;
    /// List of timestamps corresponding to values index-wise.
    std::vector<int> timestamps;

    /**
     * To get the index of corresponding value in values list, updated at or just before given timestamp.
     * Returns -1 if no such value history exists.
     *
     * @param timestamp The timestamp at or just before which the value update history is required.
     * @return int The index of corresponding value update history in values list.
     */
    int searchFloorTimestampIndex(const int &timestamp);

   public:
    /// ctor
    ValueTimestampTuple();
    /// dtor
    ~ValueTimestampTuple();

    /**
     * Set the value at given timestamp.
     *
     * @param value The value to be set.
     * @param timestamp The timestamp corresponding to which value is to be set.
     */
    void setValueAtTimestamp(const V &value, const int &timestamp);

    /**
     * Get the value updated at or just before given timestamp.
     *
     * @param timestamp The timestamp value.
     * @return V The value required.
     *
     * @throws NoUpdateHistoryFoundException Thrown if no such value exists.
     */
    V getValueAtTimestamp(const int &timestamp);

    /**
     * Get the length of value update histories stored.
     *
     * @return int The length of value update histories stored.
     */
    int size();
};

template <class V>
ValueTimestampTuple<V>::ValueTimestampTuple() {
    // default ctor
}

template <class V>
ValueTimestampTuple<V>::~ValueTimestampTuple() {
    // Release the memory used to store the value updates histories.
    this->values.clear();
    this->timestamps.clear();
}

template <class V>
int ValueTimestampTuple<V>::size() {
    // The size of timestamps and values list should be same.
    assert(this->timestamps.size() == this->values.size());

    return this->timestamps.size();
}

template <class V>
int ValueTimestampTuple<V>::searchFloorTimestampIndex(const int &timestamp) {
    // Using binary search two pointer method for efficient search.
    int leftPointer = 0, rightPointer = this->size() - 1;

    while (leftPointer <= rightPointer) {
        int middleIndex = (rightPointer - leftPointer) / 2 + leftPointer;
        // case 1: timestamp value to be found is in left half.
        if (timestamp < timestamps[middleIndex]) {
            // restrict search to left half of list.
            rightPointer = middleIndex - 1;
        }
        // case 2: timestamp value to be found is in right half.
        else if (timestamp > timestamps[middleIndex]) {
            // restrict search to right half of the list.
            leftPointer = middleIndex + 1;
        }
        // case 3: we found exact match for timestamp required.
        else {
            // return the exact index match for timestamp.
            return middleIndex;
        }
    }
    // At end, we are returning the right pointer, which will represent
    // the index for value update timestamp just less than required timestamp.
    // Note: rightPoint==-1 when no such floor index exists.
    return rightPointer;
}

template <class V>
void ValueTimestampTuple<V>::setValueAtTimestamp(const V &value, const int &timestamp) {
    // The size of timestamps and values list should be same.
    assert(this->timestamps.size() == this->values.size());
    // Add value update history with timestamp to corresponding lists.
    this->values.push_back(value), this->timestamps.push_back(timestamp);
}

template <class V>
V ValueTimestampTuple<V>::getValueAtTimestamp(const int &timestamp) {
    // Get the index for corresponding value update history.
    int index = this->searchFloorTimestampIndex(timestamp);
    // See if index is valid or not.
    if (index < 0 or index >= timestamps.size()) {
        // If index is not valid, throw error.
        std::string message = "No value update history exists for or before given timestamp " + std::to_string(timestamp);
        throw NoUpdateHistoryFoundException(message);
    }
    // Return value corresponding to the index.
    return this->values[index];
}