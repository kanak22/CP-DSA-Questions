#include <bits/stdc++.h>
#ifdef mlocal
#include "./Competitive-Code-Library/snippets/prettyprint.h"
#endif
using namespace std;
#define for_(i, s, e) for (int i = s; i < (int) e; i++)
#define for__(i, s, e) for (ll i = s; i < e; i++)
typedef long long ll;
typedef vector<int> vi;
typedef array<int, 2> ii;
#define endl '\n'

const int INF = 1e6;

/**
 * Find the the highest ancestor which currently points to my parent (of which I am the only child) by using binary lifting + segment tree + euler tour
 * Propagate the change going up from it until a deeper (or equal) node is encountered in the subtree
 * From the topmost changed node add the ladder length to the answer
 * For all the other 'ladder break' operations add the length of the broken ladder starting at the previous correct child
**/

const int N = 8e5+1;  // limit for array size
int n;  // array size
ii tr[2 * N];

void build() {  // build the tree
	for (int i = n - 1; i > 0; --i) tr[i] = {-INF, -INF};
}

void modify(int p, ii &value) {  // set value at position p
	for (tr[p += n] = value; p > 1; p >>= 1) tr[p >> 1] = max(tr[p], tr[p ^ 1]);
}

ii query(int l, int r) {  // sum on interval [l, r)
	r++;
	ii res = {-INF, -INF};
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = max(res, tr[l++]);
		if (r&1) res = max(res, tr[--r]);
	}
	
	return res;
}

int main() {
#ifdef mlocal
	freopen("test.in", "r", stdin);
#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		cin >> n;
		vi par(n);
		vector<vi> adj(n);
		for_(i, 1, n) {
			cin >> par[i];
			par[i] -= 1;
			adj[par[i]].push_back(i);
		}
		
		vi tin(n), tout(n);
		vector<ll> dep(n);
		const int lg = __lg(n)+1;
		vector<vi> up(n, vi(lg+1));
		int tim = 0;
		function<void(int)> dfs = [&] (int p) {
			tin[p] = tim++;
			for_(i, 1, lg+1) up[p][i] = up[up[p][i-1]][i-1];
			
			for (auto i: adj[p]) {
				dep[i] = dep[p]+1;
				up[i][0] = p;
				dfs(i);
			}
			tout[p] = tim-1;
		};
		
		dfs(0);
//		MaxSegmentTree tree(n);
		vector<ll> ans(n);
		ans[0] = 0;
		
		vi chCount(n);
		for_(i, 0, n) tr[n+i] = {-INF, -INF};
		build();
		function<int(int)> findPointingParent = [&] (int i) {
			int farParent = i; // stores farthest parent that currently points to i's subtree
			for (int l = lg; l >= 0; l--) {
//				int pt = tree.mx(tin[up[farParent][l]], tout[up[farParent][l]])[1];
				int pt = query(tin[up[farParent][l]], tout[up[farParent][l]])[1];
				if (tin[pt] >= tin[i] and tout[pt] <= tout[i]) farParent = up[farParent][l];
			}
			
			return farParent;
		};
		
		ll val = 0;
		
		// update a part of an existing ladder to remove the old pointer and return the top of the ladder, given a middle node
		function<int(int)> updateSegment = [&] (int d) {
			int u = findPointingParent(d);
//			cout << "found segment " << d+1 << " " << u+1 << endl;
//			ll deepest = tree.mx(tin[u], tout[u])[0];
			ll deepest = query(tin[u], tout[u])[0];
			val += (max(deepest-dep[d]-1, 0LL) * max(deepest-dep[d]-1, 0LL)) - ((deepest-dep[u]) * (deepest-dep[u]));
			
			return u;
		};
		
		for_(i, 0, n) {
//			cout << "------------------- " << endl;
//			cout << "starting " << i+1 << endl;
//			cout << "------------------- " << endl;
			if (i) {
				if (chCount[par[i]] == 0) {
					int curr = par[i];
					while (true) {
						int u = updateSegment(curr);
//						if (!u or tree.mx(tin[par[u]], tout[par[u]])[0] >= dep[i]) {
						if (!u or query(tin[par[u]], tout[par[u]])[0] >= dep[i]) {
							curr = u;
							break;
						}
						curr = par[u];
					}
					
//					cout << "chain ends at " << curr+1 << " and has length " << dep[i]-dep[curr] << endl;
//					cout << val << " -> ";
					val += (dep[i]-dep[curr]) * (dep[i]-dep[curr]);
				}
				
				chCount[par[i]]++;
			}
			
			ans[i] = val;
//			cout << ans << endl;
			ii curr = {dep[i], i};
//			tree.update(tin[i], curr);
			modify(tin[i], curr);
		}
		
		for (auto i: ans) cout << i << " ";
		cout << endl;
	}
}
