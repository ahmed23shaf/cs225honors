#include "list.h"

#include <iostream>
#include <algorithm>

void List::insert(int number) {
    list_.insert(std::upper_bound( list_.begin(), list_.end(), number), number);
}

void List::remove(int index) {
    auto it = list_.begin();
    
    while(index-- > 0) {
        ++it;
    }

    list_.erase(it);
}

void List::print() {

    for( int num : list_) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}