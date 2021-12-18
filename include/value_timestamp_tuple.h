#pragma once
#include <vector>

template <class V>
class ValueTimestampTuple {
   private:
    std::vector<V> values;
    std::vector<int> timestamps;

    int searchFloorTimestampIndex(int timestamp);

   public:
       void setValueAtTimestamp(V value, int timestamp);
    V getValueAtTimestamp(int timestamp);
    int size();
};