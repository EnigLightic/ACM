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
const int INF=1e18,N=262144+5,MOD=1e9+7;
int n,q,nn;
int t[N<<1],a[N];

void upd(int p,int val){
    p+=nn-1;
    t[p]=val;
    for(p>>=1;p>=1;p>>=1){
        t[p]=t[p<<1]^t[p<<1|1];
    }
}

void solve(){
    cin>>n>>q;
    nn=1<<n;
    for(int i=1;i<=nn;i++) {cin>>a[i];t[nn-1+i]=a[i];}
    for(int i=nn-1;i>=1;i--) t[i]=t[i<<1]^t[i<<1|1];
    while(q--){
        int p,val;
        cin>>p>>val;
        int bef=a[p];
        upd(p,val);
        int ans=0,cur=nn+p-1;
        for(int h=0;h<n;h++){
            int ot=cur^1;
            int x=t[cur],y=t[ot],ll=(cur%2==0),w=0;
            if(x>y) w=1;
            else if(x==y&&ll) w=1;
            if(!w) ans+=1<<h;
            cur>>=1;
        }
        cout<<ans<<endl;
        upd(p,bef);
    }
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