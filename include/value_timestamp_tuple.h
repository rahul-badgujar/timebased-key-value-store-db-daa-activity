#pragma once
#include <vector>

template <typename V>
class ValueTimestampTuple {
   private:
    std::vector<V> values;
    std::vector<int> timestamps;

    int searchFloorTimestampIndex(int timestamp);

   public:
    ValueTimestampTuple();
    void setValueAtTimestamp(V value, int timestamp);
    V getValueAtTimestamp(int timestamp);
    int size();
};