#include "vector.h"

List::List()
{
    list_.clear();
}

void List::insertFront(int number)
{
    std::vector<int>::iterator it = list_.begin();

    list_.insert(it, number);
}

void List::insertMiddle(int number)
{
    int middle = list_.size()/2;

    std::vector<int>::iterator it = list_.begin();

    for (int i = 0; i < middle; i++)
    {
        it++;
    }

    list_.insert(it, number);
}

// #include <vector>

// class List {
// private:
//     std::vector<int> list_;
// public:
// };