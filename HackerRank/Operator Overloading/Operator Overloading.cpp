/*
 * @file Overload Operator.cpp
 * @author Vipul Kumar Singh ( https://github.com/vipul-2003/ACM-PROJECT)
 * @brief  (https://www.hackerrank.com/challenges/overload-operators/problem)
 * @version 0.1
 * @date 2021-10-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};

//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"

Complex operator + ( Complex A , Complex B ) 
{
    Complex output;
    output.a = A.a + B.a;
    output.b = A.b + B.b;

    return output;
}

ostream& operator<<(ostream& os, const Complex C) 
{
    return os << C.a << "+" << "i" << C.b;
}

int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}
