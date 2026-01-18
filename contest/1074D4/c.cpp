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
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int mx=-1,cur=INF,now=0;
    for(int i=0;i<n;i++){
        if(a[i]==cur) continue;
        if(a[i]==cur+1){
            now++;
            
        }else{
            mx=max(now,mx);
            now=1;
        }cur=a[i];
    }mx=max(now,mx);
    cout<<mx<<endl;
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