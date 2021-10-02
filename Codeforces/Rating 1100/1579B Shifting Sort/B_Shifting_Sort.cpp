#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = (int)1e9 + 7;

// Logic is to arrange the elements of an array by finding the greatest element and putting that element to its respective position
// that is at the end by rotating the cycle by 1 by putting left index at that element and right index at its respective position
// and then doing the same work for smaller elements until we arrive to the smallest elements.

// Since in this question we have to do our work with atmost n cycles, and through the above logic we are checking every element of an array
// and hence our program will run n cycles in worst condition which also satisfies problem's condition

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        multiset<int, greater<int>> help;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            help.insert(a[i]);
        }
        vector<tuple<int, int, int>> result;
        int size = n;
        for (int i = 1; i <= n; i++, size--)
        {
            int value = *(help.begin());
            // cout<<"value "<<value<<"\n";
            int l = 0, r = 0, k = 1;
            for (int j = 1; j <= n; j++)
            {
                if (a[j] == value)
                {
                    l = j;
                    r = size;
                    if (abs(l - r) >= 1)
                    {
                        result.push_back(tie(l, r, k));
                        int x = a[j];
                        for (int m = j; m < size; m++)
                        {
                            a[m] = a[m + 1];
                        }
                        a[size] = x;
                    }
                    break;
                }
            }
            help.erase(help.lower_bound(value));
        }
        cout << result.size() << "\n";
        for (int i = 0; i < result.size(); i++)
        {
            cout << get<0>(result[i]) << " " << get<1>(result[i]) << " " << get<2>(result[i]) << "\n";
        }
    }
    return 0;
}
