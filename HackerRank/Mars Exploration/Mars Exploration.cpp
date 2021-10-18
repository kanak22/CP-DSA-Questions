#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'marsExploration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int marsExploration(string s) {

    int i, count=0;
    
    //checking for a triplet of 'SOS' at a time, if the character doesn't match count it
    for(int i=0;s[i]!='\0';i=i+3){

      if(s[i]!='\0' && s[i]!='S') count++;
      if(s[i+1]!='\0' && s[i+1]!='O') count++;
      if(s[i+2]!='\0' && s[i+2]!='S') count++;

    }

    //return the wrong no of characters in the message
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
