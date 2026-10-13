#include <bits/stdc++.h>
using namespace std;
struct A{
    int h,pos;
    bool operator<(const A&o) {
        if(h!=o.h) return h<o.h;
        return pos < o.pos;
    }
} o[1000005];
int a[200005];
int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);
    int m,n,k;cin>>m>>n>>k;
    for(int i=1 ; i<=n ; ++i)cin>>a[i];
    for(int i=1 ; i<=k ; ++i) {
        cin>>o[i].pos>>o[i].h;
    }
    sort(o+1,o+k+1);
    for(int i = k ;i>=1 ; --i) swap(a[o[i].pos],a[o[i].pos+1]);
    int s;cin>>s;
    int ans1 = a[s],ans2 = 0;
    for(int i =1 ; i<=k ; ++i) {
        ans2 = max(ans2,a[s-1]);
        ans2 = max(ans2,a[s+1]);
        swap(a[o[i].pos],a[o[i].pos+1]);
        if(s == o[i].pos) s = o[i].pos+1;
        else if(s == o[i].pos+1) s = o[i].pos;
    }
    if(ans1 > ans2) cout << ans1 << "\nNO";
    else cout << ans2 << "\nUSE";

}