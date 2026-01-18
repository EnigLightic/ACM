#include<bits/stdc++.h>
using namespace std;
#define int long long
// #define ll long long
#define vi vector<int> 
#define pb push_back 
#define pii pair<int,int>
#define fi first
#define se second
#define endl '\n'
const int INF=1e18,N=2e5,MOD=1e9+7;

struct rb{
    int alv=1;
    int pos;
};

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vi dd(k+1);
    string s;
    vi a(n),spk(m);
    
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) {cin>>spk[i];}
    cin>>s;
    sort(spk.begin(),spk.end());
    vi mxp(k+2,-1),mnp(k+2,-1);
    int cur=0,ll=0,rr=0;
    for(int i=0;i<k;i++){
        if(s[i]=='L') cur--;
        else cur++;
        if(cur>0&&mxp[cur]==-1) mxp[cur]=i+1;
        if(cur<0&&mnp[abs(cur)]==-1) mnp[abs(cur)]=i+1;
    }
    for(int i=0;i<n;i++){
        int tm=-1;
        auto t=lower_bound(spk.begin(),spk.end(),a[i]);
        if(t!=spk.end()){
            int r=*t-a[i];
            if(r<=k&&mxp[r]!=-1) tm=mxp[r];
        }
        if(t!=spk.begin()){
            int l=a[i]-*prev(t);
            if(l<=k&&mnp[l]!=-1){
                if(mnp[l]<tm||tm==-1) tm=mnp[l];
            }
        }
        if(tm!=-1) dd[tm]++;
    }
    int now=n;
    for(int i=1;i<=k;i++){
        now-=dd[i];
        cout<<now<<' ';
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