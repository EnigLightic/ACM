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
vi G[N+5];
vector<bool>dp[N+5];

void merge(vector<bool>& bef,vector<bool>& fur,vector<bool>& res){
    for(int i=0;i<3;i++){
        if(!bef[i]) continue;
        for(int j=0;j<3;j++){
            if(!fur[j]) continue;
            res[(i+j)%3]=1;
        }
    }
}

void dfs(int u,int fa){
    vi sons;
    for(auto v:G[u]){
        if(v!=fa){
            dfs(v,u);
            sons.pb(v);
        }
    }
    dp[u].resize(3);
    
    if(sons.size()){dp[u][0]=1;
        for(auto v:sons){
            vector<bool>tmp(3,0);
            merge(dp[u],dp[v],tmp);
            dp[u]=tmp;
        }
    }
    dp[u][1]=1;
}

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++) G[i].clear(),dp[i].clear();
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1,-1);
    cout<<(dp[1][0]?"Yes\n":"No\n");
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