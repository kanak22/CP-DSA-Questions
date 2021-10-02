#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second

using namespace std;
vector<long long> parent;
vector<vector<long long>> child;
vector<long long> glb, heavyChild, len;
vector<pair<long long, long long>> segment;
//set<pair<pair<long long, long long>, long long>> st;
long long dfsCur = 1;
long long n;
ll wyn = 0;

void dfs(long long x, long long lvl = 0){
	segment[x].f = dfsCur;
	dfsCur++;
	glb[x] = lvl;
	for(auto it:child[x]){
		dfs(it, lvl+1);
		dfsCur++;
	}
	segment[x].s = dfsCur;
}

long long pot(long long x){
	long long tmp = 1;
	while(x){
		x/=2;
		tmp*=2;
	}
	return tmp;
}

vector<set<long long>> tree;
long long treeSize;

void dodaj(long long x){
	long long a = segment[x].f;
	long long b = segment[x].s;
	a+=treeSize;
	b+=treeSize;
	tree[a].insert(x);
	tree[b].insert(x);
	while(a/2!=b/2){
		if(a%2==0) tree[a+1].insert(x);
		if(b%2==1) tree[b-1].insert(x);
		a/=2; b/=2;
	}
}

void usun(long long x){
	long long a = segment[x].f;
	long long b = segment[x].s;
	a+=treeSize;
	b+=treeSize;
	tree[a].erase(x);
	tree[b].erase(x);
	while(a/2!=b/2){
		if(a%2==0) tree[a+1].erase(x);
		if(b%2==1) tree[b-1].erase(x);
		a/=2; b/=2;
	}
}

long long getPath(long long v){
	v = segment[v].f;
	v+=treeSize;
	ll maksi = -1, idx = -1;
	while(v){
		for(auto it:tree[v]){
			//cout<<v<<" ------ "<<it<<'\n';
			if(it>=0&&it<n){
				if(glb[it]>maksi){
					idx = it;
					maksi = glb[it];
				}
			}//else cout<<"---- "<<v<<'\n';
		}
		v/=2;
	}
	//cout<<v<<" "<<idx<<'\n';
	assert(idx>=0);
	return idx;
}

void init(){
	wyn = 0;
	tree.resize(0);
	treeSize = pot(8*n);
	tree.resize(2*treeSize+10);
	heavyChild.resize(0);
	heavyChild.resize(n, -1);
	parent.resize(0);
	parent.resize(n);
	child.resize(0);
	child.resize(n);
	glb.resize(0);
	glb.resize(n);
	segment.resize(0);
	segment.resize(n);
	len.resize(0);
	len.resize(n);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	long long t; cin>>t;
	while(t--){
		cin>>n;
		init();
		parent[0] = -1;
		for(long long i = 1; i < n; i++){
			long long a; cin>>a;
			a--;
			parent[i] = a;
			child[a].push_back(i);
		}
		dfs(0);
		dodaj(0);
		cout<<0<<' ';
		for(long long i = 1; i<n; i++){
			long long v = parent[i];
			long long p = getPath(v);
			long long it = i;
			/*
			cout<<"--------\n";
			for(auto coc:st) cout<<1+coc.second<<" ";
			cout<<"\n--------\n";
			*/
			//cout<<i<<" "<<v<<" "<<p<<'\n';
			if(len[p]<glb[v]-glb[p]+len[it]+1){
				//wydluzamy
				//cout<<"DZIalamy\n";
				while(len[p]<glb[v]-glb[p]+len[it]+1){
					//cout<<p+1<<" "<<v+1<<" "<<it+1<<'\n';
					long long u = heavyChild[v];
					if(u!=-1) {
						len[u] = len[p]-(glb[v]-glb[p])-1;
						wyn+=len[u]*len[u];
						dodaj(u);
					}
					heavyChild[v] = it;

					wyn-=len[p]*len[p];
					len[p]=glb[v]-glb[p]+len[it]+1;
					wyn+=len[p]*len[p];

					wyn-=len[it]*len[it];
					len[it] = 0;
					usun(it);

					it = p;
					v = parent[it];
					if(v==-1) break;
					p = getPath(v);
				}
			}else{
				dodaj(i);
			}
			/*
			for(long long j = 0; j < n; j++) cout<<len[j]<<" ";
			cout<<'\n';
			cout<<"WYNIK: "<<wyn<<"\n";
			*/
			cout<<wyn<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
