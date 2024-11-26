#ifndef ARRAY_VECTOR_HPP
#define ARRAY_VECTOR_HPP

#include <iostream>
#include <stdexcept>
#include <utility>

typedef std::pair<int, std::string> Elem;

class ArrayVector {
public:
    ArrayVector();
    int size() const;
    bool empty() const;
    Elem& operator[](int i);
    const Elem& operator[](int i) const;
    Elem& at(int i);
    const Elem& at(int i) const;
    void erase(int i);
    void insert(int i, const Elem& e);
    void reserve(int N);

private:
    int capacity;
    int n;
    Elem* A;
};

#endif