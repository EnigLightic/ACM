#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<unordered_map>
#include<unordered_set>
#include<set>

using namespace std;
//#define int long long
#define ll long long
#define vi vector<int> 
#define pb push_back 
#define pii pair<int,int>
#define fi first
#define se second
#define endl '\n'

//[[maybe_unused]] const int INF = 1e18;
[[maybe_unused]] const int N   = 5e5 + 5;
[[maybe_unused]] const int MOD = 1e9 + 7;

int ans;
int n;
void msort(int l,int r,vector<int>& a,vector<int>& t){
    if(r-l<1) return ;
    int mid=l+(r-l)/2;
    int p=l,q=mid,i=l;
    msort(l,mid,t,a);
    msort(mid,r,t,a);
    while(p<mid||q<r){
        if(q>=r||(q<r&&a[p]<=a[q])) t[i++]=a[p++];
        else {t[i++]=a[q++];ans+=mid-p;}
    }
    for(i=l;i<r;i++) a[i]=t[i];
}

void solve(){
    ans=0;
    
    cin>>n;
    vi a(n+1),t(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    msort(0,n,t,a);//This is vital-->[)
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    //cin>>T;
    while(T--)
        solve();
    return 0;
}
