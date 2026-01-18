//That's me.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define vi vector<int> 
#define pb push_back 
#define pii pair<int,int>
#define fi first
#define se second
#define endl '\n'
const int INF=1e18,N=2e5,MOD=998244353;

void solve(){
    int n,k;
    cin>>n>>k;
    int l,r;
    l=r=n;int tm=0;
    
    while(r!=1){
        if(l<=k&&k<=r) break;
        tm++;
        l>>=1;
        r=(r>>1)+(r%2);
    } 
    if(l<=k&&k<=r) cout<<tm<<endl;
    else cout<<-1<<endl;
    return ;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
