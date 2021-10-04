#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);                            //for fast input & output

	const long long int mod = 1000000007;


	int n,k;
	cin>>n>>k;

	long long int a[n], d[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	priority_queue<pair<double , int> , vector<pair<double , int > > ,
     greater<pair<double , int > > > pq;

	d[0] = a[0]%mod;
	pq.push({log(a[0]), 0});

	for (int i = 1; i < n; ++i)
	{// find the cheapest accessible queue entry
		while(i-pq.top().second > k)
		{
			pq.pop();
		}
        
		pair<double , int> t = pq.top();
		d[i] = (a[i]*d[t.second])%mod;
		pq.push({pq.top().first+log(a[i]), i});
	}


	cout<<d[n-1]%mod<<endl;
	

	return 0;
}
