#include "list.h"

List::List()
{
    list_.clear();
}

void List::insertFront(int number)
{
    list_.push_front(number);
}

void List::insertMiddle(int number)
{
    int middle = list_.size()/2;

    std::list<int>::iterator it = list_.begin();

    for (int i = 0; i < middle; i++)
    {
        it++;
    }

    list_.insert(it, number);
}
// class List {
// private:
//     std::list<int> list_;
// public:
// };