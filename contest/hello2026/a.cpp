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

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<array<array<int,2>,4>>dp(n+1);
    dp[0][0][0]=1;
    for(auto c:s){
        auto ndp=dp;
        for(int b=0;b<=n;b++){
            int nb=b+(c=='('?1:-1);
            if(nb<0||nb>n) continue;
            for(int i=3;i>=0;i--){
                if(i<3&&c==")(("[i]){
                    ndp[nb][i+1][1]=(ndp[nb][i+1][1]+dp[b][i][1])%MOD;
                    ndp[nb][i+1][1]=(ndp[nb][i+1][1]+dp[b][i][0])%MOD;
                    ndp[nb][i+1][0]=(ndp[nb][i+1][0]+dp[b][i][0])%MOD;
                }else{
                    ndp[nb][i][1]=(ndp[nb][i][1]+dp[b][i][1])%MOD;
                    ndp[nb][i][1]=(ndp[nb][i][1]+dp[b][i][0])%MOD;
                    ndp[nb][i][0]=(ndp[nb][i][0]+dp[b][i][0])%MOD;
                }
            }
        }
        dp=ndp;
    }
    cout<<(dp[0][3][1]-(dp[0][3][0]*2)%MOD+MOD)%MOD<<'\n';
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