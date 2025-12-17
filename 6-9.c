
bool IsBFS(MGraph graph,Vertex ver[]){
    int n=graph->n_verts;
    bool ex[kMaxV]={0};
    for(int i=0;i<n;i++){
        if(ver[i]<0||ver[i]>=n) return false;
        if(ex[ver[i]]) return false;
        ex[ver[i]]=1;
    }
    bool vis[kMaxV]={0};
    int q[kMaxV],front=0,rear=0;
    int idx=0;
    while(idx<n){
        if(front>=rear){
            Vertex st=ver[idx];
            if(vis[st]) return false;
            vis[st]=1;
            q[rear++]=st;
            idx++;
            continue;
        }
        Vertex u=q[front];
        int neib[kMaxV],k=0;
        for(Vertex v=0;v<n;v++){
            if(ExistEdge(graph,u,v)&&!vis[v]) neib[k++]=v;
        }
        if(!k){
            front++;continue;
        }
        if(idx+k>n) return false;
        bool inneib[kMaxV]={0};
        for(int i=0;i<k;i++) inneib[neib[i]]=1;
        for(int j=idx;j<idx+k;j++){
            Vertex v=ver[j];
            if(!inneib[v]||vis[v]) return false;
            vis[v]=1;
            q[rear++]=v;
        }
        idx+=k;
        front++;
    }
    return true;
}
