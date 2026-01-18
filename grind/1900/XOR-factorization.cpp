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
    if(k&1) {for(int i=0;i<k;i++) cout<<n<<' ';cout<<endl;return ;}
    int o=0;
    vi ans(k);
    for(int i=30;i>=0;i--){
        if(n>>i&1){
            for(int j=0;j<k;j++){
                if(j!=min(o,k-1)) ans[j]+=(1<<i);
            }
            if(o<k) o++;
        }else{
            for(int j=0;j<(o/2)*2;j++){
                ans[j]+=(1<<i);
            }
        }
    }
    for(int i=0;i<k;i++) cout<<ans[i]<<' ';
    cout<<endl;
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
