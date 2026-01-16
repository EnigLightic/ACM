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
const int INF=1e18,N=1e6+6,MOD=1e9+7;
int f[N][2];
void solve(){
    
    string x,y;
    cin>>x>>y;
    int len=x.size();
    f[0][0]=0;f[0][1]=INF;
    for(int i=0;i<len;i++){
        for(int b=0;b<=1;b++){
            f[i+1][b]=INF;
            for(int a=0;a<=1;a++){
                int pos=(b-a+2)%2;
                if(f[i][pos]>=INF) continue;
                int c=f[i][pos];
                if((x[i]-'0')!=a) c++;
                if((y[i]-'0')!=b) c++;
                f[i+1][b]=min(f[i+1][b],c);
            }
        }
    }
    cout<<min(f[len][0],f[len][1])<<endl;
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
