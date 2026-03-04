#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define df double
#define inall(a) for(auto& i:a)cin>>i;
#define outall(a) for(auto i:a)cout<<i<<' ';cout<<endl;

ll pow(ll a,ll b){
    ll ans=1;
    while(b--)ans*=a;
    return ans;
}

const ll MOD = 1e9+7;

void solve(){
    ll n,k,c;
    cin>>n>>k>>c;
    ll a[n];
    inall(a);
    ll least,most;
    cin>>least>>most;
    int l[n],r[n];
    bool valid[n];
    for(int i=0;i<n;i++){
        l[i]=n;
        r[i]=-1;
        valid[i]=0;
    }
    for(int i=0;i<n;i++){
        ll cursum=0;
        for(int j=i;j<n;j++){
            cursum+=pow(j-i,c)*a[j];
            if(least<=cursum&&cursum<=most){
                l[i]=min(l[i],j);
                r[i]=j;
                valid[i]=1;
            }else if(cursum>most)break;
        }
        l[i]++;
        r[i]++;
        //if(r[i]==n)r[i]--;

    }
    /*for(int i=0;i<n;i++){
        cout<<a[i]<<'/'<<i<<' '<<l[i]<<' '<<r[i]<<endl;
    }*/
    ll suffix[n][2];
    int prev=0,cur=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            suffix[i][j]=0;
            //cout<<suffix[i][j]<<' ';
        }
        //cout<<endl;
    }
    for(int j=1;j<=k;j++){
        //cout<<"j="<<j<<endl;
        for(int i=n-1;i>=0;i--){
            if(valid[i]&&r[i]==n&&j==1){
                suffix[i][cur]=1;
                r[i]--;
            }else suffix[i][cur]=0;
            if(i!=n-1)suffix[i][cur]+=suffix[i+1][cur];
            //cout<<suffix[i][cur]<<' ';
            suffix[i][cur]+=MOD;
            suffix[i][cur]%=MOD;
            if(valid[i] && j!=1 && l[i]<=r[i]){
                suffix[i][cur]+=suffix[l[i]][prev];
                //cout<<"prev:"<<suffix[l[i]][prev]<<endl;
                if(r[i]!=n-1)suffix[i][cur]-=suffix[r[i]+1][prev];
            }
            suffix[i][cur]+=MOD;
            suffix[i][cur]%=MOD;
        }
        //cout<<endl;
        swap(prev,cur);
    }
    ll ans=suffix[0][prev];
    if(n!=1)ans-=suffix[1][prev];
    ans+=MOD;
    ans%=MOD;
    cout<<ans<<endl;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
}


/*
n-1 choose k-1
(n-1)!/((k-1)!(n-k)!)
*/