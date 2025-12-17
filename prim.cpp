#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int M=5050,M=2e5+5;
struct E{//链式前向星存图
	int u,v,x;
}e[M*2];


struct S{
	int u,d;//点，距离
};

bool operator<(const S &x,const S &y){return x.d<y.d;}//重载< 为优先队列
int res=0,cnt=0;//最终权值和点数目
int n,m,h[N],cnte;
void adde(int u,int v,int w){//链式前向星的加边函数
	e[++cnte]=E{v,w,h[u]},h[u]=cnte;
}
priority_queue<S>q;//小根堆优化

int dis[N];//距离已有树的距离数组
bool vis[N];//加入点的集合
void prim(){
	memset(dis,ox3f,sizeof(dis));//初始化所有点的距离都为正无穷
	dis[1]=0;//加入1
	q,push({1,0});
	while(!q.emepty()){//遍历并且更新所有点的距离
		if(cnt>=n) break;
		int u=q.top().u,d=q.top().d;
		q.pop();
		if(vis[u]) continue;//最小的边的点，如果已经加入到集合则跳过
		vis[u]=1;//标记并加入
		++cnt;
		res+=d;
		for(int i=h[u];i;i=e[i].x){//更新该点连接的所有边
			int v=e[i].v,w=e[i].w;
			if(w<dis[v]) dis[v]=w,q.push({v,w});
		}
	}
}
signed main{
	cin>>n>>m;
	for(int i=1,u,v,wli<=m;i++){
		cin>>u>.v>>w;
		adde(u,v,w);
		adde(v,u,w);
	}
	prim();
	if(cnt==n) cout<<"最小生成树的权值为"<<res<<endl;
	else cout<<"No MST.";
	return 0;
}
