#include <iostream>
#include <algorithm>
#include "buffer.hpp"

int main() {
    circular_buffer<int> buffer(6);
    buffer.push_back(07);
    buffer.push_back(06);
    buffer.push_back(2003);

    buffer.push_front(111);
    buffer.push_front(4001);
    buffer.push_front(704);

    std::sort(buffer.begin(), buffer.end());

    for (int &i : buffer) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    buffer.get_data();

    return 0;
}