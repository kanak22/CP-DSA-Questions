/**
 * @file Virtual Function.cpp
 * @author Vipul Kumar Singh 
 * @brief  (https://www.hackerrank.com/challenges/virtual-functions/problem)
 * @version 0.1
 * @date 2021-10-02
 * @copyright Copyright (c) 2021
 **/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Person
{
    protected : 
    
    string name ;
    int age ; 
    
    public :
    
    virtual void getdata(){};
    virtual void putdata(){};

    
};

class Professor : public Person
{
    private : 
    
    int publications ;
    static int  cur_id ;
    
    public :
    
    void getdata()
    {
        cin>> name ;
        cin>> age ;
        cin>> publications;
    }
    
    void putdata()
    {
        cout << name<<" " ;
        cout << age<<" "<<publications<<" ";
        cout << cur_id<<" " <<endl ;
        
        cur_id += 1 ;
        
    }
};

class Student  : public Professor 
{
    private : 
    
    int marks[6] ;
    static int cur_id2 ;
    
    int total_marks = 0 ; // to display the sum of marks of 6 subjects
    
    public :
    
    void getdata()
    {
        cin >> name;
        cin >> age ;
        
       
        
        for ( int i = 0 ; i < 6 ; i++)
        {
            cin >> marks [i];
            total_marks += marks[i]; 
        }
    }
    
    void putdata()
    {
        cout <<name <<" "<<age <<" "<<total_marks <<" " <<cur_id2 <<endl ;
        cur_id2 += 1 ;  
    }
    
    
};

int Student :: cur_id2 = 1;
int Professor :: cur_id  = 1;




int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
