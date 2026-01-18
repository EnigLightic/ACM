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
    vi suf(n+1),pre(n+1);
    for(int i=n-1;i>=0;i--){
        suf[i]=suf[i+1]+(s[i]=='(');
    }
    pre[0]=1;
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+s[i]=='(';
    }
    int b=0,ans=-1;
    for(int i=0;i<n;i++){
        // if(s[i]=='(') b++;
        if(s[i]==')'){
            // b--;
            // if(b<0) continue;
            // int tmp=i+1,nd=b+2;
            // while(tmp<n&&s[tmp]==')') tmp++;
            // if(tmp==n) break;
            // if(suf[tmp]>=nd) ans=i+1+nd;
            for(int j=i+1;j<n;j++){
                if(s[j]=='('){
                    if(suf[j+1]>=j-i) ans=max(ans,n-2*(j-i));
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
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

