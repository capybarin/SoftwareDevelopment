#ifndef CVECTOR_H
#define CVECTOR_H

#include <string>
#include <sstream>

using namespace std;

template <typename T>
class CVector {
private:
    T* data;
    int size{};
public:
    CVector(int size);
    CVector(const CVector& vector);
    CVector(T array[], int length);

    int getSize();
    int setSize(int newSize);

    string toString();

    int add(T element);
    int remove(int index);

    CVector& operator=(const CVector& vector);
    bool operator==(CVector& vector);
    T& operator[](int index);

    template <T> friend CVector<T> operator+(CVector<T>& a, CVector<T>& b);
    template <T> friend int operator+(CVector<T>& a, T b);
    template <T> friend int operator+(T a, CVector<T>& b);

    template <T> friend CVector<T> operator-(CVector<T>& a, CVector<T>& b);
    template <T> friend int operator-(CVector<T>& a, T b);
    template <T> friend int operator-(T a, CVector<T>& b);

    template <T> friend CVector<T> operator*(CVector<T>& a, CVector<T>& b);
    template <T> friend CVector<T> operator*(CVector<T>& a, T b);
    template <T> friend CVector<T> operator*(T a, CVector<T>& b);

    template <T> friend CVector<T> operator/(CVector<T>&a, CVector<T>& b);
    template <T> friend CVector<T> operator/(CVector<T>& a, T b);
    template <T> friend CVector<T> operator/(T a, CVector<T>& b);

    template <T> friend ostream& operator <<(ostream& output, CVector<T>& vector);
    template <T> friend istream& operator >>(istream& input, CVector<T>& vector);

    ~CVector();
};



#endif
