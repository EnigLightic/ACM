#include<bits/stdc++.h>
#define int long long 
using namespace std;

bool cmp(string x,string y){
    return x[0]<y[0];
}

signed main(){
    map<pair<int,int>,int>mp;
    int MX;
    cin>>MX;
    int n,m;
    cin>>n>>m;
    vector<char>msg(n);
    for(int i=0;i<n;i++){
        cin>>msg[i];
    }
    vector<vector<int> >g(n);
    vector<bool>vis(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(u==v) continue;
        pair<int,int>k1={u,v},k2={v,u};
        if(mp.count(k1)||mp.count(k2)) continue;
        mp[k1]++,mp[k2]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<string> ans;
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        queue<int>q;
        string out="";
        vis[i]=1;
        q.push(i);
        while(!q.empty()){
            int u=q.front();q.pop();
            out+=msg[u];
            for(auto it=g[u].rbegin();it!=g[u].rend();it++){
                int v=*it;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        ans.push_back(out);
        // cout<<out<<endl;
    }
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
