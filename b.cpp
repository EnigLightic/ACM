#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=2e5;
int n,m;//n个节点，m条无向边
int f[MAXN];
struct edge{
	int u,v,weight;
};
vector<edge>E;

bool cmp(edge x,edge y){//快速排序中使用到的比较函数
	return x.weight<y.weight;//按照边权从小到大排序
}

int getfather(int v){
	if(f[v]==v) return v;
	f[v]=getfather(f[v]);
	return f[v];
}

void merge(int u,int v){
	int fu=getfather(u),fv=getfather(v);
	if(fu>fv) f[fu]=fv;
	else f[fv]=fu;
}

void kruskal(){
	int tot=0;//记录已经选了的边的条数
	int ans=0;//记录总的边权
	for(int i=0;i<m;i++){
		int fu=getfather(E[i].u),fv=getfather(E[i].v);
		if(fu!=fv){//两者不在同一个集合
			merge(fu,fv);
			tot++;
			ans+=E[i].weight;
			if(tot==n-1){
				cout<<ans<<endl;
				return ;
			}
		}
	}
//	cout<<"No answer!\n";
	cout<<"orz\n";
}

int main(){
	cin>>n>>m;//输入n个节点
	E.reserve(m);
	for(int i=0;i<m;i++){//输入m条无向边
		int u,v,w;
		cin>>u>>v>>w;
		E.push_back({u,v,w});
	}
	sort(E.begin(),E.end(),cmp);
	kruskal();
	
	return 0;
}
