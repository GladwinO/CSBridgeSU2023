// gto219_hw16_2.cpp :

#include <iostream>
#include <vector>
//is size getting updated automatically in the private section or do i need to update size every push and pop?
template <class T>
class Queue {
private:
    std::vector<T> vector;
    int beginPos = 0;
    int vecSize = vector.size() - beginPos;
public:
    void push(T newData) { vector.push_back(newData); }
    T pop();
    T front() const;
    T back() const;
    int size() const { return vecSize; }
    bool isEmpty() const { return vecSize == 0 };
    void clear();

};

int main()
{
    std::cout << "Hello World!\n";
}



template<class T>
T Queue<T>::pop() {
    if (!isEmpty()) {
        beginPos = beginPos + 1;
        return vector[beginPos - 1];
    }
    return T();
}

template<class T>
T Queue<T>::front() const{
    if (!isEmpty()) {
        return vector[beginPos];
    }
    return T();
}

template<class T>
T Queue<T>::back() const {
    if (!isEmpty()) {
        return vector[vector.size() - 1];
    }
    return T();
}

template<class T>
void Queue<T>::clear() {
    vecSize = 0;
    beginPos = 0;
    vector.clear();//the clear function will remove the data but not shrink the size of the array
}