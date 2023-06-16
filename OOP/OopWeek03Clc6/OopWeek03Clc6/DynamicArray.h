#pragma once
#include <iostream>
#include <exception>
using namespace std;

// Declaration
template <class BatKi>
class DynamicArray {
public:
    int size() { return _currentSize; }

public:
    DynamicArray() {
        const int INITIAL_SIZE = 4;
        _a = new BatKi[INITIAL_SIZE];
        _max = INITIAL_SIZE;
        _currentSize = 0;
    }

    // Deep copy
    // Copy constructor = Tao sao chep
    DynamicArray(const DynamicArray& other) {
        cout << "Ham tao sao chep" << endl;
        this->_max = other._max;
        this->_currentSize = other._currentSize;

        this->_a = new BatKi[_max];

        for (int i = 0; i < _currentSize; i++) {
            this->_a[i] = other._a[i];
        }
    }

    DynamicArray& operator=(const DynamicArray& other) {
        this->_a = other._a;
        this->_max = other._max;
        this->_currentSize = other._currentSize;

        this->_a = new BatKi[_max];

        for (int i = 0; i < _currentSize; i++) {
            this->_a[i] = other._a[i];
        }

        return *this;
    }

    ~DynamicArray() {
        cout << "Ham huy" << endl;
        delete[] _a;
    }

public:
    void push_back(BatKi value) {
        if (_currentSize + 1 > _max) {
            const int STEP = 100;
            _max = _max + STEP;
            BatKi* temp = new BatKi[_max];

            for (int i = 0; i < _currentSize; i++) {
                temp[i] = _a[i];
            }

            delete[] _a;
            _a = temp;
        }

        _a[_currentSize] = value;
        _currentSize++;
    }

    BatKi getAt(int i) {
        if (i >= _currentSize) {
            throw exception("Index out of range");
        }
        return _a[i];
    }

    BatKi operator [](int i) {
        return getAt(i);
    }

private:
    BatKi* _a = NULL;
    int _max;
    int _currentSize;
};
