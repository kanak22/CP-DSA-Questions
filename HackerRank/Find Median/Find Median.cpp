/*
Programming Link:
https://www.hackerrank.com/challenges/find-the-median/problem

Ques.
The median of a list of numbers is essentially its middle element after 
rting. The same number of elements occur after it as before. Given a list 
of numbers with an odd number of elements, find the median?

Example.
arr= [5,3,1,2,4]
The sorted array arr' =[1,2,3,4,5]. The middle element and the median is 3.

Sample Input 0:
7
0 1 2 4 6 5 3

Sample Output 0:
3

Explanation 0:
The sorted arr'=[0,1,2,3,4,5,6]. It's middle element is at 3.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'findMedian' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int findMedian(vector<int> arr) {
    
    int med;

    //sort the array 
    sort(arr.begin(),arr.end());

    int size=arr.size();

    //if size of array  is odd
    if(size%2!=0){
        med=arr[size/2];    //median is in middle of arr ,i.e, index: size/2
    }

    //else if size of array is even 
    else{
        med= (arr[size/2]+ arr[(size/2)+1])/2;    //take the average of the two middle values, i.e index size/2 and (size/2)+1
    }
    return med;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = findMedian(arr);

    fout << result << "\n";

    fout.close();

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
