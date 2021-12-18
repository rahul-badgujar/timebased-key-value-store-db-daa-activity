#include "value_timestamp_tuple.h"

#include <cassert>
#include <string>

template <class V>
ValueTimestampTuple<V>::ValueTimestampTuple() = default;

template <class V>
int ValueTimestampTuple<V>::size() {
    assert(this->timestamps.size() == this->values.size());
    return this->timestamps.size();
}

template <class V>
int ValueTimestampTuple<V>::searchFloorTimestampIndex(int timestamp) {
    int leftPointer = 0, rightPointer = this->size() - 1;
    while (leftPointer <= rightPointer) {
        int middleIndex = (rightPointer - leftPointer) / 2 + leftPointer;
        if (timestamp < timestamps[middleIndex]) {
            rightPointer = middleIndex - 1;
        } else if (timestamp > timestamps[middleIndex]) {
            leftPointer = middleIndex + 1;
        } else {
            return middleIndex;
        }
    }
    return rightPointer;
}

template <class V>
void ValueTimestampTuple<V>::setValueAtTimestamp(V value, int timestamp) {
    assert(this->timestamps.size() == this->values.size());
    this->values.push_back(value), this->timestamps.push_back(timestamp);
}

template <class V>
V ValueTimestampTuple<V>::getValueAtTimestamp(int timestamp) {
    int index = this->searchFloorTimestampIndex(timestamp);
    if (index < 0 or index >= timestamps.size()) {
        throw "No value exists for or before given timestamp " + std::to_string(timestamp);
    }
    return this->values[index];
}