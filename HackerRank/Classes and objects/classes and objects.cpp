/**
 * @file Box It!.cpp
 * @author Vipul Kumar Singh
 * @brief  (https://www.hackerrank.com/challenges/classes-objects/problem)
 * @version 0.1
 * @date 2021-10-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Write your Student class here
class Student 
{
    private :
    int scores[5], sum = 0;
    
    public :
    void input()
    {
        for (int i = 0; i < 5; i++)
        {
            cin>>scores[i];
        }
    }
    int  calculateTotalScore()
    {
        for (int j = 0; j<5 ; j++)
        {
            sum = sum + scores[j];
        }
        return sum;
    }
};

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}
