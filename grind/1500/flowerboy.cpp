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
    int n,m;
    cin>>n>>m;
    vi a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    vi tail(m);
    int j=n-1;
    for(int i=m-1;i>=0;i--){
        while(j>=0&&a[j]<b[i]) j--;
        tail[i]=j--;
    }
    vi fron(m);
    j=0;
    for(int i=0;i<m;i++){
        while(j<n&&a[j]<b[i]) j++;
        fron[i]=j++;
    }
    if(fron.back()<n) {cout<<"0\n";return ;}
    int ans=INF;
    for(int i=0;i<m;i++){
        int pre,suf;
        if(i==0) pre=-1;
        else pre=fron[i-1];
        if(i==m-1) suf=n;
        else suf=tail[i+1];
        if(pre<suf) ans=min(ans,b[i]);
    }
    cout<<(ans==INF?-1:ans)<<endl;
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