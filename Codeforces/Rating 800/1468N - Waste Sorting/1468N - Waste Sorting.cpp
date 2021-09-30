/*It is quite obvious that if c1<a1, c2<a2 or c3<a3, the answer is NO because it is impossible to fit even the items that fit only into one container. 
Otherwise, let's get rid of a1, a2, a3 by decreasing ci by ai (1≤i≤3).

Now we have a problem with 3 containers and only 2 item types (4-th and 5-th), the fourth item type fits only into the first and into the third container, 
the fifth item type — into the second and into the third container. 
Since the first container accepts only items of type 4, we should fit the maximum possible number of items of type 4 there — that is, min(a4,c1) items. Similarly, 
we should fit the maximum possible number of items of type 5 into the second container (min(a5,c2) items). 
After that, we only have to check that all the remaining items can be fit into the third container.
*/


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
