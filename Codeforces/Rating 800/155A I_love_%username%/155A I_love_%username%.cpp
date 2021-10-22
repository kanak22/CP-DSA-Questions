#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, worst, best, amazing = 0;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
        {
            worst = best = a[i];
        }
        else if (a[i] > best || a[i] < worst)
        {
            amazing++;
            if (a[i] > best)
                best = a[i];
            else if (a[i] < worst)
                worst = a[i];
        }
    }
    cout << amazing;
}