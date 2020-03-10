package com.company.ComplexLab;

public class Complex {
    private double real;
    private double imag;

    public Complex(double real, double imag) {
        this.real = real;
        this.imag = imag;
    }

    public Complex() {
        this(0.0, 0.0);
    }

    public Complex (Complex c){
        this(c.real, c.imag);
    }

    public double getReal() {
        return real;
    }

    public void setReal(double real) {
        this.real = real;
    }

    public double getImag() {
        return imag;
    }

    public void setImag(double imag) {
        this.imag = imag;
    }

    public Complex multiply(Complex c) {
        return new Complex((this.real*c.getReal()) - (this.imag* c.getImag()),
                (this.real*c.getImag()) + (this.imag* c.getReal()));
    }

    public Complex multiply(int a)
    {
        return new Complex(this.real*a, this.imag*a);
    }

    public Complex multiply(long a)
    {
        return new Complex(this.real*a, this.imag*a);
    }

    public Complex multiply(double a)
    {
        return new Complex(this.real*a, this.imag*a);
    }

    public Complex add(Complex c)
    {
        return new Complex(this.real + c.getReal(), this.imag + c.getImag());
    }

    public Complex add(double a)
    {
        return new Complex(this.real + a, this.imag);
    }

    public Complex add(int a)
    {
        return new Complex(this.real + a, this.imag);
    }

    public Complex add(long a)
    {
        return new Complex(this.real + a, this.imag);
    }

    public Complex subtract(Complex c)
    {
        return new Complex(this.real - c.getReal(), this.imag - c.getImag());
    }

    public Complex subtract(int a)
    {
        return new Complex(this.real - a, this.imag);
    }

    public Complex subtract(long a)
    {
        return new Complex(this.real - a, this.imag);
    }

    public Complex subtract(double a)
    {
        return new Complex(this.real - a, this.imag);
    }

    @Override
    public String toString() {
        return "Complex{" +
                "real=" + real +
                ", imag=" + imag +
                '}';
    }
}
