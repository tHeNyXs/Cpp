#pragma GCC optimize("O5,unroll-loops,inline,fast-math")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define exoworldgd cin.tie(0)->sync_with_stdio(0),cout.tie(0)
using namespace std;
const int mod = 1<<21;
int id[mod]={},hsh[mod]={},found[100003]={};
bool occ[mod]={};
inline int H(int x) { return x*2654435761u>>(32-21); }
signed main(void) {
	exoworldgd;
	string s;
	int m,k,curr,q,x,p;
	cin >> k >> m;
	for (int i = 1; i <= k; i++) {
		cin >> s, curr=0;
		for (int j = 0; j < m; j++) curr=(curr<<1)|(s[j]-'0');
		p = H(curr);
		while (occ[p]) p=(p+1)&(mod-1);
		occ[p] = 1;
		hsh[p] = curr;
		id[p] = i;
	}
	cin >> q;
	while (q--) {
		cin >> x >> s;
		int f=0; curr=0;
		for (int i = 0; i < m-1; i++) curr=(curr<<1)|(s[i]-'0');
		for (int i = m-1; i < x; i++) {
			curr = (curr<<1)|(s[i]-'0');
			curr &= ~(1<<m);
			p = H(curr);
			while (occ[p]) {
				if (hsh[p]==curr) { found[id[p]]=1; f=1; break; }
				p=(p+1)&(mod-1);
			}
		}
		if (!f) cout << "OK\n";
		else {
			for (int i = 1; i <= k; i++) if (found[i]) cout << i << " ", found[i]=0;
			cout << "\n";
		}
	}
}