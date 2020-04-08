#include <iostream>

using namespace std;


class MyComplex {

    friend MyComplex operator+(MyComplex v1, MyComplex v2);
    friend MyComplex operator+(MyComplex v1, double v2);
    friend MyComplex operator+(double v1, MyComplex v2);
    friend MyComplex operator+(MyComplex v1, int v2);
    friend MyComplex operator+(int v1, MyComplex v2);
    friend MyComplex operator-(MyComplex v1, MyComplex v2);
    friend MyComplex operator-(MyComplex v1, double v2);
    friend MyComplex operator-(double v1, MyComplex v2);
    friend MyComplex operator-(MyComplex v1, int v2);
    friend MyComplex operator-(int v1, MyComplex v2);
    friend MyComplex operator*(MyComplex v1, MyComplex v2);
    friend MyComplex operator*(MyComplex v1, double v2);
    friend MyComplex operator*(double v1, MyComplex v2);
    friend MyComplex operator*(MyComplex v1, int v2);
    friend MyComplex operator*(int v1, MyComplex v2);
    friend ostream& operator<<(ostream &o, MyComplex B);
    friend istream& operator>>(istream &i, MyComplex &B);

private:
    double Im, Re;

public:

    MyComplex (double Re, double Im){
        this->Re=Re;
        this->Im=Im;
    }
    
    MyComplex (){
        this->Re=0;
        this->Im=0;
    }


    MyComplex operator= ( MyComplex A){
        Re = A.Re;
        Im = A.Im;
        return *this;
    }
    
    double getRe(){
        return Re;
    }
    double getIm(){
        return Im;
    }
    void setRe(double nRe){
        Re = nRe;
    }
    void setIm(double nIm){
        Im = nIm;
    }
};

MyComplex operator+(MyComplex v1, MyComplex v2){
    MyComplex C;
    C.setRe(v1.getRe()+v2.getRe());
    C.setIm(v1.getIm()+v2.getIm());
    return C;
}

MyComplex operator+(MyComplex v1, double v2){
    MyComplex C;
    C.setRe(v1.getRe()+v2);
    C.setIm(v1.getIm());
    return C;
}

MyComplex operator+(int v1, MyComplex v2){
    return (v2+v1);
}

MyComplex operator+(MyComplex v1, int v2){
    MyComplex C;
    C.setRe(v1.getRe()+v2);
    C.setIm(v1.getIm());
    return C;
}

MyComplex operator+(double v1, MyComplex v2){
    return (v2+v1);
}

MyComplex operator-(MyComplex v1, MyComplex v2){
    MyComplex C;
    C.setRe(v1.getRe()-v2.getRe());
    C.setIm(v1.getIm()-v2.getIm());
    return C;
}

MyComplex operator-(MyComplex v1, double v2){
    MyComplex C;
    C.setRe(v1.getRe()-v2);
    C.setIm(v1.getIm());
    return C;
}

MyComplex operator-(double v1, MyComplex v2){
    return (v2-v1);
}

MyComplex operator-(MyComplex v1, int v2){
    MyComplex C;
    C.setRe(v1.getRe()-v2);
    C.setIm(v1.getIm());
    return C;
}

MyComplex operator-(int v1, MyComplex v2){
    return (v2-v1);
}

MyComplex operator*(MyComplex v1, MyComplex v2){
    MyComplex C;
    C.setRe(v1.getRe()*v2.getRe()-v1.getIm()*v2.getIm());
    C.setIm(v1.getRe()*v2.getIm()+v1.getIm()*v2.getRe());
    return C;
}

MyComplex operator*(MyComplex v1, double v2){
    MyComplex C;
    C.setRe(v1.getRe()*v2);
    C.setIm(v1.getIm()*v2);
    return C;
}

MyComplex operator*(double v1, MyComplex v2){
    return (v2*v1);
}

MyComplex operator*(int v1, MyComplex v2){
    return (v2*v1);
}

MyComplex operator*(MyComplex v1, int v2){
    MyComplex C;
    C.setRe(v1.getRe()*v2);
    C.setIm(v1.getIm()*v2);
    return C;
}



ostream& operator<<(ostream  &o, MyComplex B){
    if(B.getIm()<0)
        o<<B.getRe()<<B.getIm()<<"i";
    if(B.getIm()>0)
        o<<B.getRe()<<"+"<<B.getIm()<<"i";
    if(B.getIm()==0)
        o<<B.getRe();
}

istream& operator>>(istream &i, MyComplex &B){
    i>>B.Re;
    i>>B.Im;
    return i;
}


int main()
{
    MyComplex A;
    MyComplex B;
    cout<<"A = "<<endl;
    cin>>A;
    cout<<"B = "<<endl;
    cin>>B;
    MyComplex C;
    C=A+B;
    cout<<C<<endl;
    cout<<A+5<<endl;
    cout<<A*2<<endl;
    return 0;
}
