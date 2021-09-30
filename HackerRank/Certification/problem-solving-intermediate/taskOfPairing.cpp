long taskpairing(vector<long> freq)
{

	//map<long, long>mp;
	vector<pair<int, int>>mp;
	long n = freq.size();
	long c = 0;
	long st = 1;
	for (int i = 0; i < freq.size(); i++)
	{
		mp.push_back({i + 1, freq[i]});

	}
	for (int i = 1; i <= n; i++)
	{
		//cout << mp[i - 1].first << " " << mp[i - 1].second << endl;
		c += mp[i - 1].second / 2;
		if ((mp[i - 1].first - mp[i].first) <= 1 && mp[i - 1].second % 2 != 0)
		{
			mp[i].second++;
		}
	}
  return c;

}
