#include <bits/stdc++.h>
using namespace std;
typedef string str;
set<str> r;
void perm(int k,string a){
    if(k<2){
        r.insert(a);return;
    }
    for(int i=0;i<k;i++){
        perm(k-1,a);
        if(i<k-1){
            if(k%2) swap(a[0],a[k-1]);
            else swap(a[i],a[k-1]);
        }
    }
}
int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    cout.tie(NULL)->sync_with_stdio(false);
    int n,f;
    char bn;
    cin>>n>>f;
    str tmp="12345678",sk=tmp.substr(0,n);
    map<char,bool> fb;
    for(int i=0;i<f;i++) cin>>bn,fb[bn]=true;
    perm(n,sk);
    for(str it:r){
        if(fb.count(it[0])) continue;
        for(char c:it) cout<<c<<" ";
        cout<<"\n";
    }
    
}