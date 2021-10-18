/* September Lunchtime 2021- Division 3- Interesting Representation (INTREP)*/

#include <iostream>
using namespace std;
#define ll long long

/*Array of all prime numbers from 1 to 100*/
int v[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int main() {
	
	int t;
	cin >> t; /*Input number of test cases*/
	for (int i = 0; i < t; i++) {
		ll n;
		cin >> n; /*Input n*/
		
		/*For even numbers*/
		if (n % 2 == 0) {
			ll a = 2 * n;
			ll b = n;
			cout << a << " " << b; /*Print the two numbers*/
		}
		/*For odd numbers*/
		else {
			int j = 0;
			while (n % v[j] == 0)
				j++;
			ll a = n * v[j];
			ll b = n * (v[j] - 1);
			cout << a << " " << b; /*Print the two numbers*/
		}
		cout << "\n";
	}
	return 0;
}
