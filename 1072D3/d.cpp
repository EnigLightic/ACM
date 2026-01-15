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
int C[35][35];
void init(){
    for(int i=0;i<=30;i++){
        for(int j=0;j<=30;j++){
            if(i<j) C[i][j]=0;
            else if(j==0) C[i][j]=1;
            else C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
}

void solve(){
    int n,k;
    cin>>n>>k;
    int bits=0;
    while(n%2==0){
        n>>=1;
        bits++;
    }
    int ans=0;if(bits+1>k) ans++;
    for(int i=0;i<bits;i++)
        for(int j=1;j<=i+1;j++)
            if(i+j>k) ans+=C[i][j-1];
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}