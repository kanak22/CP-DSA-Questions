#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter number of elements of your array = ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
cout<<"your resversed array is = ";
    for (int i = n - 1; i >= 0; i--)
    {
        cout << a[i] << " ";
    }
    return 0;
}