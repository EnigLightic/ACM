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
    int n;
    cin>>n;
    vi co(n+5),a(n+5);
    for(int i=0;i<n;i++){
        cin>>a[i];
        co[a[i]]=i%2;
    }
    sort(a.begin(),a.begin()+n);
    for(int i=0;i<n-1;i++){
        if(co[a[i]]==co[a[i+1]]) {cout<<"NO\n";return ;}
    }
    cout<<"YES\n";
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
