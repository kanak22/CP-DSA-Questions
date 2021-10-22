#include <bits/stdc++.h>
using namespace std;
int main()
{
    // variable declartion
    int cost, change;
    // taking inputs
    cin >> cost >> change;
    int lastNum = cost % 10;
 
   //    handling edge case
    if (lastNum == change || lastNum==0)
        cout << 1;
    else
    {
        int i = 1;
        int temp = cost;
        while (lastNum != change || lastNum != 0)
        {
 
            cost += temp;
            i++;
            lastNum = cost % 10;
            if (lastNum == 0 || lastNum == change)
            {
                cout << i << endl;
                break;
            }
        }
    }
}