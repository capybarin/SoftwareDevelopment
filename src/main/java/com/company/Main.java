package com.company;

import com.company.ComplexLab.Complex;

public class Main {

    public static void main(String[] args) {
        Complex c1 = new Complex(12,5);
        Complex c2 = new Complex(c1.getReal()+4, c1.getImag());
        System.out.println(c1.add(c2));
        System.out.println(c1.multiply(4));
        System.out.println(c1.subtract(4.6));
    }
}
