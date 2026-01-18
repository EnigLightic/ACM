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
    string s;
    cin>>s;
    vi ans;
    int p1=-1,p0=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='1'&&p1==-1) p1=i;
        if(s[i]=='0') p0=i;
    }
    if(p1>p0||p1==-1||p0==-1){cout<<"Bob\n";return ;}
    cout<<"Alice\n";
    while(p1<p0){
        ans.pb(p1);ans.pb(p0);
        while(p1<n&&s[++p1]!='1');
        while(p0>=0&&s[--p0]!='0');
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x+1<<' ';
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
