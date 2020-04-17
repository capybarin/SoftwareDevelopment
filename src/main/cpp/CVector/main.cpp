#include <iostream>
#include "CVector.cpp"
using namespace std;


int main() {
    CVector<int> vec(10);
    cin>>vec;
    int p[] = {1, 2, 3, 4, 5};
    CVector<int> vec2(p, 5);
    CVector<int> sum = vec + vec2;
    cout << "Sum: " << sum;

    CVector<int> multiply = vec * vec2;
    cout << endl << "Multiply: " << multiply;

    int v1[] = {4, 6 ,8};
    int v2[] = {2, 2 ,2};
    CVector<int> vv1(v1, 3);
    CVector<int> vv2(v2, 3);

    CVector<int> divide = vv1/vv2;
    cout<<endl<<"Divide: "<< divide;

    int v11[] = {7, 10 ,12};
    int v22[] = {5, 5 ,5, 5, 5};
    CVector<int> vv11(v11, 3);
    CVector<int> vv22(v22, 5);

    CVector<int> _minus = vv11-vv22;
    cout<<endl<<"Subtract: "<<_minus;

    return 0;
}
