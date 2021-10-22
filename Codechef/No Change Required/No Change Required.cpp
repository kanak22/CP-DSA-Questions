/*
Problem Link:  https://www.codechef.com/FEB20B/problems/NOCHANGE

Problem Statement: You are given N different coin types, the ii-th worth D_iD i ​ cents.
Find any multiset of coins (or report that none exist) which has a sum greater than P and
when we remove any coin in the multiset, the sum becomes smaller than P.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t, n, i, j;
    cin >> t;
    while (t--)
    {
        ll f = 0, p, q = 0;
        cin >> n >> p;
        ll a[n], c[n];
        // array c contains the count of each denomination of coin
        // if the answer exists
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            c[i] = 0;
            if (p % a[i] != 0) //we check if there is an element which is not a multiple of p
                f = 1;
        }
        if (f == 1)
        {
            //Case:  There is an element which is not a multiple of p
            // In this case, the count of this element will be ceil((double)p / a[i])
            // and that of other coins will be zero.
            q = 0;
            cout << "YES ";
            for (i = 0; i < n; i++)
            {
                if (p % a[i] != 0)
                {
                    c[i] = ceil((double)p / a[i]);
                    break;
                }
            }
            for (i = 0; i < n; i++)
                cout << c[i] << " ";
            cout << "\n";
        }
        else
        {
            //Case:  All elements are multiple of p.
            //Solution: All the coin denominations are sorted i.e. a[i] < a[i+1]
            //We traverse from the end of array and if suppose p/a[i]==x, then we subtract p by (x-1)*a[i] such that p doesn't becomes 0.
            //We continue till p doesn't becomes zero or if we find an element a[i] such that p%a[i]!=0. If this happens, the answer is Yes
            //In rest of the cases, the answer is no.
            q = 0;
            for (i = n - 1; i >= 0; i--)
            {
                if (p % a[i] == 0)
                {
                    c[i] = p / a[i] - 1;
                    p = p - c[i] * a[i];
                }
                else
                {
                    q = 1;
                    c[i] = ceil((double)p / a[i]);
                    break;
                }
            }
            if (q == 1)
            {
                cout << "YES ";
                for (i = 0; i < n; i++)
                    cout << c[i] << " ";
                cout << "\n";
            }
            else
                cout << "NO\n";
        }
    }

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
