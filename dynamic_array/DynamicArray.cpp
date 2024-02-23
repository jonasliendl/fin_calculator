//
// Created by Jonas Liendl on 23.02.24.
//

#include "DynamicArray.h"

template<typename T>
DynamicArray<T>::DynamicArray() {
    this->size = 1;
    this->arrayPointer = new T[this->size];
}

template<typename T>
[[maybe_unused]] DynamicArray<T>::DynamicArray(unsigned int size) {
    this->size = size;
    this->arrayPointer = new T[size];
}

template<typename T>
DynamicArray<T>::~DynamicArray() = default;

template<typename T>
DynamicArray<T>* DynamicArray<T>::add(T element) {
    if (this->size + 1 > this->size) {
        this->size = this->size + 1;
        T (*this->arrayPointer)[this->size];
        return nullptr;
    }
    return nullptr;
}
