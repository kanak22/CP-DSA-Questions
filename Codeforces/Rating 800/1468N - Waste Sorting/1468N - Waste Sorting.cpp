#include <bits/stdc++.h>
using namespace std;




int main()
{
	// #ifdef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{

		int c1, c2, c3;
		int a1, a2, a3, a4, a5;
		cin >> c1 >> c2 >> c3;
		cin >> a1 >> a2 >> a3 >> a4 >> a5;

		if (a1 <= c1 && a2 <= c2 && a3 <= c3)
		{



			if (a4 <= (c1 - a1) + (c3 - a3)) {
				if (a4 - (c1 - a1) >=  0)
				{
					if (a5 <= (c2 - a2) + ((c3 - a3) - (a4 - (c1 - a1))))
					{
						cout << "YES";
					}
					else {
						cout << "NO";
					}
				}


				if (a4 - (c1 - a1) <  0) {
					if (a5 <= (c2 - a2) + ((c3 - a3)))
					{
						cout << "YES";
					}
					else {
						cout << "NO";
					}
				}
			}


			else
				cout << "NO";


		}

		else {
			cout << "NO";
		}




		cout << endl;


	}



	return 0;

}