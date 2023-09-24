#pragma once

#include <list>
#include <iterator>

class List {
private:
    std::list<int> list_;
public:
    List();
    void insertFront(int number);
    void insertMiddle(int number);
};