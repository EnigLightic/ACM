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
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
void solve(){
    int n,m1,m2;
    cin>>n>>m1>>m2;
    DSU dsuF(n+1),dsuG(n+1);
    vector<pii>f(m1),g(m2);
    for(int i=0;i<m1;i++){
        int x,y;
        cin>>x>>y;
        f[i]={x,y};
    }
    for(int i=0;i<m2;i++){
        int x,y;
        cin>>x>>y;
        g[i]={x,y};
        dsuG.merge(x,y);
    }
    int ans=0;
    for(int i=0;i<m1;i++){
        int x=f[i].fi,y=f[i].se;
        if(dsuG.find(x)!=dsuG.find(y)){
            ans++;
        }else{
            dsuF.merge(x,y);
        }
    }
    for(int i=0;i<m2;i++){
        int x=g[i].fi,y=g[i].se;
        if(dsuF.find(x)!=dsuF.find(y)){
            ans++;
            dsuF.merge(x,y);
        }
    }
    cout<<ans<<endl;
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
