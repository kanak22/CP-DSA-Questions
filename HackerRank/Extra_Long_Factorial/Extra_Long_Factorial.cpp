/*
Question link:
https://www.hackerrank.com/challenges/extra-long-factorials/problem 
Idea:
The main idea of this approach is to create an array and 
store the initial values in them i.e declaring arr[0] as 1
Then we pass the array to an function where it each and every position will be multiplied by the 
next number and the last digit of the produt is taken and written as the value in the current index of the array
and if any carry occurs we multiply and do the same process as mentioned above in the last
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

//The below function does the caluclation of extra long factorials using arrays to store them
int func(int x,int res[],int rsize)
            {//initializing carry as 0 and traversing through the array and updating values accordingly

                int carry=0;
                for(int i=0;i<rsize;i++)
            {
                int prod=res[i]*x+carry;
                res[i]=prod%10;
                carry=prod/10;
            }
//here when carry is present we multiply and increment the size of the array after doing so
            while(carry)
            {
                res[rsize++]=carry%10;
                carry/=10;
            }
// finally the resultant size is returned so that we can access the value in it
            return rsize;
            }
void extraLongFactorials(int n) {
            //creating an resultant array of size 1000
            int res[1000];
            int rsize=1;
            res[0]=1;
            for(int i=2;i<=n;i++)
            {
                rsize=func(i,res,rsize);
            }
/*as the values are stored from the starting index the actual value would be reversed of the stored version of the value so we display it from the rear*/
            for(int i=0;i<rsize;i++)
            {
                cout<<res[rsize-i-1];
            }
            
           
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
//Sample output
/*
input value=25
output value=15511210043330985984000000
 input value=45
output value=119622220865480194561963161495657715064383733760000000000
*/
