//Problem

/*Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.*/

/*Test case
Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.
*/

//Solution:

#include <iostream>
#include <string.h>
using namespace std;

//function which return the value of longest common subsequence between two strings.
int lcs(string s1, string s2)
{
    int m = s1.length(), n = s2.length();   //m and n define length of 2 strings 
    
    int dp[m+1][n+1];  //declaration of an dp array
    
    for(int i=0;i<=m;i++)
        dp[i][0]=0;        //filling first column of dp array with value 0
    
    for(int j=0;j<=n;j++)
        dp[0][j]=0;      //filling first column of dp array with value 0.
        
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)    
        {
            if(s1[i-1]==s2[j-1])   //comparing the corresponding characters of  strings s1 and s2
                dp[i][j] = 1 + dp[i-1][j-1];    //storing values in dp array
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    return dp[m][n];   //returning the value of longest common subsequence in two strings
    
}

int main() {
	
	
	string s1,s2;  //declaring strings
    cin>>s1;  //Taking input for string1
    cin>>s2;   //Taking input for string2
	
	
	cout<<lcs(s1,s2);  //calling function to find longest common subsequence
	

}