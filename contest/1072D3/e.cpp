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

vi sz,f;

int find(int x){
    if(f[x]==x) return x;
    f[x]=find(f[x]);
    return f[x];
}

void merge(int a,int b){
    int fa=find(a),fb=find(b);
    if(fa>fb) swap(fa,fb);
    sz[fa]+=sz[fb];
    f[fb]=fa;
}

int cal(int x){
    x=find(x);
    return sz[x]*(sz[x]-1)/2;
}

void solve(){
    int n;
    cin>>n;
    map<int,vi>mp;
    int pre=0;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(i) mp[abs(t-pre)].pb(i);
        pre=t;
    }
    sz.resize(n);
    f.resize(n);
    for(int i=0;i<n;i++){f[i]=i;sz[i]=1;}
    vi ans;
    int cur=0;
    for(int i=n-1;i>0;i--){
        for(auto y:mp[i]){
            cur-=cal(y);
            cur-=cal(y-1);
            merge(y,y-1);
            cur+=cal(y);
        }
        ans.pb(cur);
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<n-1;i++) cout<<ans[i]<<' ';
    cout<<endl;
    sz.clear();f.clear();
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