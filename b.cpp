#include<iostream>
#include<vector>
#include<algorithm>//快速排序用到的头文件
using namespace std;
const int MAXN=2e5;
int n,m;//n个节点，m条无向边
int f[MAXN];
struct edge{
	int u,v,weight;
};
vector<edge>E;//用元素类型为结构体的可变长数组vector存储每条边

bool cmp(edge x,edge y){//快速排序中使用到的比较函数
	return x.weight<y.weight;//按照边权从小到大排序
}
//并查集的查询根节点的函数，使用了路径压缩
int getfather(int v){
	if(f[v]==v) return v;
	f[v]=getfather(f[v]);
	return f[v];
}
//并查集的合并函数
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
			tot++;//加入这条边，并将ans加上该边权值
			ans+=E[i].weight;
			if(tot==n-1){//如果已经加入的边数达到n-1(可以构成一棵树)，就结束
				cout<<"最小生成树的总权值是:"<<ans<<endl;
				return ;
			}
		}
	}
	cout<<"No answer!\n";//这里说明没有达到n-1条边，说明图没有最小生成树
}

int main(){
	cin>>n>>m;//输入n个节点
	E.reserve(m);
	for(int i=0;i<=n;i++) f[i]=i;//并查集的初始化
	for(int i=0;i<m;i++){//输入m条无向边
		int u,v,w;
		cin>>u>>v>>w;
		E.push_back({u,v,w});//将边作为结构体进行存储
	}
	sort(E.begin(),E.end(),cmp);//进行边权的排序，以边权作为排序关键字
	kruskal();//调用kruskal算法
	
	return 0;
}
