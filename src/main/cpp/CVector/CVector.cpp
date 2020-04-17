#include "CVector.h"


template<typename T>
CVector<T>::CVector(int size) {
    this->size = size > 0 ? size : 5;
    this->data = new T[this->size];

    for (int i = 0; i < this->size; i++) {
        this->data[i] = 0;
    }
}

template<typename T>
CVector<T>::CVector(const CVector<T> &vector) {
    this->size = vector.size;
    for (int i = 0; i < vector.size; i++) {
        this->data[i] = vector.data[i];
    }
}

template<typename T>
CVector<T>::CVector(T *array, int length) {
    this->size = length;
    this->data = new T[length];

    for (int i = 0; i < this->size; i++) {
        this->data[i] = array[i];
    }
}

template<typename T>
int CVector<T>::getSize() {
    return this->size;
}

template<typename T>
int CVector<T>::setSize(int newSize) {
    T *newData = new T[newSize];
    if (newData == nullptr) {
        throw runtime_error("no memory");
    }

    for (int i = 0; i < newSize; i++) {
        newData[i] = i > this->size ? 0 : data[i];
    }

    this->size = newSize;
    delete[] this->data;
    this->data = newData;

    return 1;
}

template<typename T>
string CVector<T>::toString() {
    stringstream ss;
    ss << "{" << this->getSize() << "} ";
    ss << "[";
    for (int i = 0; i < this->getSize(); i++) {
        ss << this->data[i];
        ss << ((i == this->getSize() - 1) ? "" : ", ");
    }
    ss << "]";
    return ss.str();
}

template<typename T>
int CVector<T>::add(T element) {
    T *newData = new T[this->size + 1];
    for (int i = 0; i < this->size; i++) {
        newData[i] = this->data[i];
    }
    newData[this->size] = element;

    this->size += 1;

    delete this->newData;
    this->newData = newData;

    return 1;
}

template<typename T>
int CVector<T>::remove(int index) {
    if (this->size == 0 || this->size <= index) {
        return -1;
    }

    T *newData = new T[this->getSize() - 1];
    bool less = false;
    for (int i = 0; i < this->getSize(); i++) {
        if (i == index) {
            less = true;
            continue;
        }
        newData[less ? i - 1 : i] = this->data[i];
    }

    this->size -= 1;
    this->data = newData;

    return 1;
}

template<typename T>
CVector<T> &CVector<T>::operator=(const CVector &vector) {
    if (this == &vector) {
        return *this;
    }

    this->size = vector.size;
    delete[] this->data;
    this->data = new T[vector.size];
    if (this->data == nullptr) {
        throw runtime_error("no memory");
    }

    for (int i = 0; i < vector.size; i++) {
        this->data[i] = vector.data[i];
    }

    return *this;
}

template<typename T>
bool CVector<T>::operator==(CVector &vector) {
    if (this->data == vector.data) {
        return true;
    }

    if (this->size != vector.size) {
        return false;
    }

    for (int i = 0; i < vector.size; i++) {
        if (this->data[i] != vector.data[i]) {
            return false;
        }
    }

    return true;
}

template<typename T>
T &CVector<T>::operator[](int index) {
    if (index >= this->size) {
        throw runtime_error("2 of range");
    }
    return this->data[index];
}

template<typename T>
ostream &operator<<(ostream &output, CVector<T> &vector) {
    output << vector.toString();
    return output;
}

template<typename T>
istream &operator>>(istream &input, CVector<T> &vector) {
    for (int i = 0; i < vector.getSize(); i++) {
        input >> vector[i];
    }

    return input;
}

template<typename T>
CVector<T> operator+(CVector<T> &a, CVector<T> &b) {
    int newSize = min(a.getSize(), b.getSize());
    CVector<T> result(newSize);
    for (int i = 0; i < newSize; i++) {
        result[i] = a[i] + b[i];
    }
    return result;
}

template<typename T>
CVector<T> operator+(CVector<T> &a, T b) {
    CVector<T> result(a.getSize());
    for (int i = 0; i < a.getSize(); i++) {
        result[i] = a[i] + b;
    }
    return result;
}

template<typename T>
CVector<T> operator+(T a, CVector<T> &b) {
    return b + a;
}

template<typename T>
CVector<T> operator-(CVector<T> &a, CVector<T> &b) {
    int newSize = min(a.getSize(), b.getSize());
    CVector<T> result(newSize);
    for (int i = 0; i < newSize; i++) {
        result[i] = a[i] - b[i];
    }
    return result;
}

template<typename T>
CVector<T> operator-(CVector<T> &a, T b) {
    CVector<T> result(a.getSize());
    for (int i = 0; i < a.getSize(); i++) {
        result[i] = a[i] - b;
    }
    return result;
}

template<typename T>
CVector<T> operator-(T a, CVector<T> &b) {
    return (-1)*b + a;
}

template<typename T>
CVector<T> operator*(CVector<T> &a, CVector<T> &b) {
    int newSize = min(a.getSize(), b.getSize());
    CVector<T> result(newSize);
    for (int i = 0; i < newSize; i++) {
        result[i] = a[i] * b[i];
    }
    return result;
}

template<typename T>
CVector<T> operator*(CVector<T> &a, T b) {
    CVector<T> result(a.getSize());
    for (int i = 0; i < a.getSize(); i++) {
        result[i] = a[i] * b;
    }
    return result;
}

template<typename T>
CVector<T> operator*(T a, CVector<T> &b) {
    return b * a;
}

template<typename T>
CVector<T> operator/(CVector<T> &a, CVector<T> &b) {
    int newSize = min(a.getSize(), b.getSize());
    CVector<T> result(newSize);
    for (int i = 0; i < newSize; i++) {
        result[i] = a[i] / b[i];
    }
    return result;
}

template<typename T>
CVector<T> operator/(CVector<T> &a, T b) {
    CVector<T> result(a.getSize());
    for (int i = 0; i < a.getSize(); i++) {
        result[i] = a[i] / b;
    }
    return result;
}

template<typename T>
CVector<T> operator/(T a, CVector<T> &b) {
    return b / a;
}

template<typename T>
CVector<T>::~CVector() {
    delete[] this->data;
}
