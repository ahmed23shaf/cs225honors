#pragma once

#include <vector>
#include <iterator>

class List {
private:
    std::vector<int> list_;
public:
    List();
    void insertFront(int number);
    void insertMiddle(int number);
};