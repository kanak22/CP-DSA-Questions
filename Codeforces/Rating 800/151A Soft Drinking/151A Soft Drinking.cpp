#include <iostream>
 
using namespace std;
 
int main()
{  
    // variables declaration
    int n, k, l, c, d, p, nl, np;
    // taking input
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    // checking condition to fulfill the minumum criteria for the drink
    cout << min(min(k * l / nl, c * d), p / np) / n << endl;
    return 0;
}