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
    vi a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        int l=0,r=0;
        for(int k=0;k<=i;k++){
            if(a[k]==l) l++;
        }
        for(int j=i+1;j<n;j++){
            if(a[j]==r) r++;
        }
        if(l==r){cout<<"NO\n";return ;}
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
