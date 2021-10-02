/*
Program Link:
https://www.hackerrank.com/challenges/pangrams/problem

Ques.
A pangram is a string that contains every letter of the alphabet. 
Given a sentence determine whether it is a pangram in the English alphabet. 
Ignore case. Return either pangram or not pangram as appropriate.

Example
s= "The quick brown fox jumps over the lazy dog"
The string contains all letters in the English alphabet, so return pangram.

Sample Input 0:
We promptly judged antique ivory buckles for the next prize

Sample Output 0:
pangram

Sample Explanation 0:
All of the letters of the alphabet are present in the string.

Sample Input 1:
We promptly judged antique ivory buckles for the prize

Sample Output 1:
not pangram

Sample Explanation 1:
The string lacks an x.

*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {

 int letters[26]={0};
 int i,j;

 //tranform the string to lowercase characters
 transform(s.begin(), s.end(), s.begin(), ::tolower);

 for(i=0;s[i]!='\0';i++){
     j= s[i]-'a';
     letters[j]++;   //storing the characters in temporary array created
 }

 //if any of the letters is not present, it is not pangram
 for(i=0;i<26;i++){
     if(letters[i]==0) return "not pangram"; 
     else continue;
 }

 return "pangram";   //else it is a pangram

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
