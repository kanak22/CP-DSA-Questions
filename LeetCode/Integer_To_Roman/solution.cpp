#include<bits/stdc++.h>

using namespace std;

// Function to convert the number to roman numeral
string intToRoman(int number) {

    const int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    // Possible Roman Alphabets
    const string sym[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int i = 13;
    string ans = "";

    while(number) {
        int div = number/num[i];
        number = number%num[i];
        while(div--) {
            ans += sym[i];
        }
        i--;
    }

    return ans;
}

// Driver Code
int main() {

    int N;
    cout << "Enter the number: ";
    cin >> N;
    cout << intToRoman(N) << "\n";

    return 0;
}
