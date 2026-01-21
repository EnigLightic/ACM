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
    int n,k;
    cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    vi l,sl;
    while(k&&l!=a){
        k--;
        sl=l;
        l=a;
        vi f(n+1,0);
        for(int i=0;i<n;i++) f[a[i]]++;
        int mex=0;
        while(f[mex]) mex++;
        int mm=0;
        vi b;
        for(int num:a){
            if(f[num]>1) b.pb(mex);
            else b.pb(mm);
            if(num==mm) mm++;
        }
        sort(b.begin(),b.end());
        a=b;
        if(a==sl) k&=1;
    }
    int sum=0;
    for(int num:a) sum+=num;
    cout<<sum<<endl;
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