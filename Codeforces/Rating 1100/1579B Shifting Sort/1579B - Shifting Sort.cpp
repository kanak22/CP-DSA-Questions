// Code contributed by Saurav Sharma (Username -> sauravs0)

// Question Link - https://codeforces.com/problemset/problem/1579/B

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = (int)1e9 + 7;

// Logic is to arrange the elements of an array by finding the greatest element and putting that element to its respective position
// that is at the end by rotating the cycle by 1 by putting left index at that element and right index at its respective position
// and then doing the same work for smaller elements until we arrive to the smallest elements by decreasing the program work space by 1
// after every iteration because the largest element will come to its respective position after every iteration hence we can decrease our
// work space by 1 and continue to do this until we just left with no element.

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

        // Using multiset to easily obtain the max value in O(1) time to perform our operations
        multiset<int, greater<int>> help;

        // Taking input
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            help.insert(a[i]);
        }

        // Vector to store final output asked by our problem
        vector<tuple<int, int, int>> result;

        //Initial size of workspace on which we have to perform our operations
        int size = n;

        // Operating on given array n times which is the size of our workspace for which we have to perform operations
        for (int i = 1; i <= n; i++, size--)
        {
            // Storing maximum value
            int value = *(help.begin());

            // l represents left index of cycle
            // r represents right index of cycle
            // k represents no of turns to be performed on our cycle
            // According to our logic k will always be 1 because we only need one left turn to place highest element at the end of a cycle
            int l = 0, r = 0, k = 1;

            // Performing linear search on given array to find maximum element
            for (int j = 1; j <= n; j++)
            {
                // When largest element is found then we assign l to that index of array and r to the current size of workspace which represents
                // that in the given workspace found element is largest hence we have to place largest element to rightmost index of current workspace
                if (a[j] == value)
                {
                    l = j;
                    r = size;

                    // Checking whether the largest element in current workspace is already at its correct position or not
                    // If not, then we have to perform one turn to bring it to the end of a cycle that is its required position where it should be to make array sorted
                    if (abs(l - r) >= 1)
                    {
                        result.push_back(tie(l, r, k));
                        int x = a[j];

                        // Performing turn by assigning values of 'index + 1' to 'index'
                        for (int m = j; m < size; m++)
                        {
                            a[m] = a[m + 1];
                        }

                        // Assigning largest value in current workspace to its respective position
                        a[size] = x;
                    }
                    break;
                }
            }

            // Erasing the largest value in workspace because we already assigned that to its respective position in previous operation
            help.erase(help.lower_bound(value));
        }

        // Output
        cout << result.size() << "\n";
        for (int i = 0; i < result.size(); i++)
        {
            cout << get<0>(result[i]) << " " << get<1>(result[i]) << " " << get<2>(result[i]) << "\n";
        }
    }
    return 0;
}
