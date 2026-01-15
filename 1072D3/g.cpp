//二分+线段树
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
const int INF=1e18,N=2e5+5,MOD=998244353;
int a[N+5],st[N<<2];
int ans,curmin;
void build(int v,int l,int r){
    if(l+1==r){
        st[v]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(v<<1|1,l,mid);
    build((v<<1)+2,mid,r);
    st[v]=min(st[v<<1|1],st[v*2+2]);
}

void upd(int v,int l,int r,int pos,int x){
    if(pos<l||pos>=r) return ;
    if(l+1==r){
        a[pos]=x;
        st[v]=x;
        return ;
    }
    int mid=(l+r)>>1;
    upd(v*2+1,l,mid,pos,x);
    upd(v*2+2,mid,r,pos,x);
    st[v]=min(st[v<<1|1],st[v*2+2]);
}

int getMin(int v,int l,int r,int lq,int rq){
    if(rq<=l||lq>=r) return INF;
    if(lq<=l&&r<=rq) return st[v];
    int mid=(l+r)>>1;
    return min(getMin(v*2+1,l,mid,lq,rq),getMin(v*2+2,mid,r,lq,rq));
}

void findInter(int v,int l,int r,int lq,int rq){
    if(rq<=l||lq>=r||ans!=INF) return ;
    if(lq<=l&&r<=rq&&min(curmin,st[v])>r-lq-1){
        curmin=min(curmin,st[v]);
        return ;
    }
    if(l+1==r){
        ans=l;
        return ;
    }
    int mid=(r+l)>>1;
    findInter(v*2+1,l,mid,lq,rq);
    findInter(v*2+2,mid,r,lq,rq);
}

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>a[i];
    build(0,0,n);
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int p,x;
            cin>>p>>x;
            upd(0,0,n,p-1,x);
        }else{
            int l,r;
            cin>>l>>r;
            l--;
            if(getMin(0,0,n,l,r)>r-l){
                cout<<"0\n";
                continue;
            }
            ans=curmin=INF;
            findInter(0,0,n,l,r);
            cout<<(ans!=INF&&getMin(0,0,n,l,ans+1)==ans-l)<<endl;
        }
    }    
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