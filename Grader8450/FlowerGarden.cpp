#include <bits/stdc++.h>
using namespace std;

struct DSU {
    unordered_map<int,int> p;

    int find(int x){
        if(!p.count(x)) p[x]=x;
        if(p[x]==x) return x;
        return p[x]=find(p[x]);
    }

    void unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b) p[a]=b;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    const int OFFSET = 1000001;

    DSU dsu;

    set<int> nodes;

    for(int i=0;i<n;i++){
        int r,c;
        cin>>r>>c;

        int row=r;
        int col=c+OFFSET;

        dsu.unite(row,col);

        nodes.insert(row);
        nodes.insert(col);
    }

    set<int> comp;

    for(int x:nodes)
        comp.insert(dsu.find(x));

    int k=comp.size();

    cout<<max(1,k-1);
}