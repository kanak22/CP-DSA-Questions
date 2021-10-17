// Link to the question -> https://www.codechef.com/MAY21C/problems/XOREQUAL

#include <iostream>
#include <cmath>
using namespace std;

#define mod (1000000000 + 7)    // Modulo the question asked to take to store big numbers...

void solve(long long int n)
{
    long long int temp, i = 2, d = 1;
    n = n - 1;
    while (n > 0)
    {
        if (n & 1)      // if (n & 1) is true that means n is odd.
        {
            d = (d * i) % mod;      // Taking mod because x will be 2^(n-1) which is not possible to store.
        }
        i = (i * i) % mod;
        n = n >> 1;
    }
    cout << d << endl;      // d will be the number of possible ways of x can be taken.
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
            cout << 2 << endl;    // For n = 2, there will always have only two values 0, 2.
        }
        else
        {
            solve(n);
        }
    }
    return 0;
}
