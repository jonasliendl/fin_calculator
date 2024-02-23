//
// Created by Jonas Liendl on 23.02.24.
//

#ifndef FIN_CALCULATOR_DYNAMICARRAY_H
#define FIN_CALCULATOR_DYNAMICARRAY_H

#include<array>
using namespace std;

template <typename T>
class DynamicArray {
public:
    DynamicArray();

    [[maybe_unused]] explicit DynamicArray(unsigned int size);
    ~DynamicArray();
    DynamicArray<T>* add(T element);
    DynamicArray<T>* remove(unsigned int position);
    T* getArray();
    T getElement(unsigned int position);
    T find(T elementValue);
    T pop();
private:
    T* arrayPointer;
    int size;
};

#endif //FIN_CALCULATOR_DYNAMICARRAY_H
