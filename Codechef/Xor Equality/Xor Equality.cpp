// Link to the question -> https://www.codechef.com/MAY21C/problems/XOREQUAL

#include <iostream>
#include <cmath>
using namespace std;

#define mod (1000000000 + 7)

void solve(long long int n)
{
    long long int temp, i = 2, d = 1;
    n = n - 1;
    while (n > 0)
    {
        if (n & 1)
        {
            d = (d * i) % mod;
        }
        i = (i * i) % mod;
        n = n >> 1;
    }
    cout << d << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)     // Test cases
    {
        long long int n;
        cin >> n;
        if (n == 2)
        {
            cout << 2 << endl;
        }
        else
        {
            solve(n);
        }
    }
    return 0;
}
