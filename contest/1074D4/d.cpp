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
const int INF=1e18,N=2e5,MOD=1e9+7;

void solve(){
    int n,m,h,v=1;
    cin>>n>>m>>h;
    vi a(n+1),prs(n+1),lst(n+1);
    for(int i=1;i<=n;i++) {cin>>a[i];}
    for(int i=0;i<m;i++){
        int p,val;
        cin>>p>>val;
        if(lst[p]!=v){
            prs[p]=0;
            lst[p]=v;
        }
        prs[p]+=val;
        if(a[p]+prs[p]>h) v++;
    }
    for(int i=1;i<=n;i++){
        if(lst[i]==v) cout<<a[i]+prs[i]<<' ';
        else cout<<a[i]<<' ';
    }cout<<endl;
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