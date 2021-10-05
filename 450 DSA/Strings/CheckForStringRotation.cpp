// 	Write a Program to check whether a string is a valid shuffle of two strings or not
// Question link: https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/

#include <bits/stdc++.h>
#pragma GCC optimize ("03")              //For CP optimize
#pragma GCC target ("sse4")              //For CP optimize
using namespace std;
typedef long long ll;                   //Define ll for long long int

int main()
{
    string inp_str;
    cout<<"Enter 1st string - "; cin>>inp_str;
    string test_str;
    cout<<"Enter the test string - "; cin>>test_str;

    if (inp_str.length() != test_str.length())
        cout<<"Enter the strings with equal length"<<endl;

    
    string temp = inp_str + inp_str;
    
    int found = temp.find(test_str);

    if (found != string::npos)
        cout<<"Strings are rotation of each other "<<endl;
    else
        cout<<"Strings are not rotations of each other "<<endl;
}