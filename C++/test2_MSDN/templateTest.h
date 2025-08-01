#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
T sum(T x1, T x2){
    return (x1 + x2);
}

template <typename... Args>
auto sumN(Args... args) {
    return (args + ...);
}

template <typename... Args>
bool allTrue(Args... args){
    return (args && ...);
}

