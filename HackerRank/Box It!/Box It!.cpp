/**
 * @file Box It!.cpp
 * @author Vipul Kumar Singh ( https://github.com/vipul-2003/ACM-PROJECT)
 * @brief  (https://www.hackerrank.com/challenges/box-it/problem)
 * @version 0.1
 * @date 2021-10-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <bits/stdc++.h>

using namespace std;
//Implement the class Box
//l,b,h are integers representing the dimensions of the box
class Box
{
private:
    int l, b, h;

public:
    Box() //default constructor
    {
        l = 0;
        b = 0;
        h = 0;
    }

    Box(int length, int breadth, int height) //parameterized constructor accpeting length (l) , breadth (b) , height (h)
    {
        l = length;
        b = breadth;
        h = height;
    }

    Box(Box &B) // copy constructor
    {
        l = B.l;
        b = B.b;
        h = B.h;
    }

    int getLength() // to return length
    {
        return (l);
    }

    int getBreadth() // to return breadth
    {
        return (b);
    }

    int getHeight() // to return height
    {
        return (h);
    }

    long long CalculateVolume() // to calculate the volume of the object using its length , breadth and height
    {
        long long volume = l;
        volume *= b;
        volume *= h;

        return (volume);
    }

    friend bool operator<(Box &A, Box &B)
    {
        if ((A.l < B.l) || ((A.b < B.b) && (A.l == B.l)) || ((A.h < B.h) && (A.b == B.b) && (A.l == B.l)))
            return true;
        else
            return false;
    }
    friend ostream &operator<<(ostream &out, Box &B)
    {
        out << B.l << " " << B.b << " " << B.h;
        return out;
    }
};

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

void check2()
{
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1) // we might also use switch as well as alternate
        {
            cout << temp << endl;
        }
        if (type == 2)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                cout << "Lesser\n";
            }
            else
            {
                cout << "Greater\n";
            }
        }
        if (type == 4)
        {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

int main()
{
    check2();

    return 0;
}