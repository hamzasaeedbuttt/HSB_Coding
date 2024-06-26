#include <iostream>

using namespace std;

struct Complex
{
    private:
    int real;
    int imag;

    public:
    Complex()
    {
        real = 0;
        imag = 0;
    }
    Complex(int real, int imag)
    {
        this->real=real;
        this->imag=imag;
    }

    void setReal(int r)
    {
        real = r;
    }
    void setImaginary(int i)
    {
        imag = i;
    } 
    int getReal()
    {
        return real;
    }
    int getImaginary()
    {
        return imag;
    }

    void print()
    {
        cout<<real<<" + "<<imag<<"i"<<endl;
    }

    Complex sum(Complex &c)
    {
        Complex d((real+c.real), (imag+c.imag));
        // cout<<(real+c.real)<<" + "<<(imag+c.imag)<<"i"<<endl;
        return d;
        // d.print();
    }

    Complex multiply(Complex &c)
    {
        Complex d(((real*c.real)-(imag*c.imag)), ((real*c.imag)+(imag*c.real)));
        // cout<<((real*c.real)-(imag*c.imag))<<" + "<<((real*c.imag)+(imag*c.real))<<"i"<<endl;
        // d.print();
        return d;
    }

};

int main()
{
    int r1, r2, i1, i2;
    cout<<"Enter the real part of the first number: ";
    cin>>r1;
    cout<<"Enter the imaginary part of the first number: ";
    cin>>i1;
    cout<<"Enter the real part of the second number: ";
    cin>>r2;
    cout<<"Enter the imaginary part of the second number: ";
    cin>>i2;

    Complex c1(r1, i1);
    Complex c2;
    c2.setReal(r2);
    c2.setImaginary(i2);
    Complex c3 = c1.sum(c2);
    Complex c4 = c1.multiply(c2);
    Complex c5 = c1.multiply(c1);

    c1.print();
    c2.print();
    c3.print();
    c4.print();
    c5.print();
}