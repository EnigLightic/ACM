# Nexus_Raphael的模板

## 字符串部分

### KMP

string从1开始数

```c++
int L=s.length();
int j=0;
for(int i=2;i<L;i++){
    while(j&&s[j+1]!=s[i]) j=nxt[j];
    if(s[j+1]==s[i]) j++;
    nxt[i]=j;
}
```

### Manacher(马拉车)

```c++
int mnc_mxpali(string s){
	string s1="$";
	for(int i=0;i<s.length();i++){
		s1=s1+'#';
		s1=s1+s[i];
	}
	s1=s1+"#*";
	vector<int>p(s1.length());
	int c=0,r=0;
	for(int i=1;i<s1.length();i++){
		if(i>r) p[i]=0;
		else p[i]=min(r-i,p[2*c-i]);
		while(s1[i-p[i]-1]==s1[i+p[i]+1]) p[i]++;
		if(p[i]+i>r){
			r=p[i]+i;
			c=i;
		}
	}
	int mx=-1;
	for(auto x:p){
		mx=max(x,mx);
	}
	return mx;
}
/*****************************************/
int d1[N],d2[N];

void mnc_odd(string s){
	int len=0;
	int n=s.length();
	for(int i=0,l=0,r=-1;i<n;i++){
		if(i>r) len=1;					//越过边界就置为1
		else len=min(d1[l+r-i],r-i+1);  //否则置为对称处的长，不越界
		while(i-len>=0&&i+len<n&&s[i-len]==s[i+len]) len++;
		d1[i]=len;
		len--;
		if(i+len>r){
			l=i-len;
			r=i+len;
		}
	}
}

void mnc_even(string s){//切记这个i是偏右的那个位置
						//也即i左边0.5格才是所算回文串的中心
	int len=0;
	int n=s.length();
	for(int i=0,l=0,r=-1;i<n;i++){
		if(i>r) len=0;
		else len=min(d2[l+r-i+1],r-i+1);
		while(i-len-1>=0&&i+len<n&&s[i-len-1]==s[i+len]) len++;
		d2[i]=len;
		len--;
		if(i+len>r){
			l=i-len-1;
			r=i+len;
		}
	}
}
```

## 数据结构部分

### 树状数组

树状数组都是从1开始存,下面是求逆序数的代码

```c++
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+5;
struct fac{
	int val,pos;
}a[N];
int b[N];
int tree[N];
int n;

bool cmp(fac x,fac y){
	if(x.val==y.val) return x.pos<y.pos;
	return x.val<y.val;
}

int lowbit(int x){return x&-x;}

void ins(int p,int x){
	while(p<=n){
		tree[p]+=x;
		p+=lowbit(p);
	}
}

int qry(int p){
	int ret=0;
	while(p>=1){
		ret+=tree[p];
		p-=lowbit(p);
	}
	return ret;
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].val;
		a[i].pos=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		b[a[i].pos]=i;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ins(b[i],1);
		ans+=i-qry(b[i]);
	}
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
//	cin>>T;
	while(T--)
		solve();
	return 0;
}
```

### 线段树

下面分别是区间求和+区间加数 和 区间求和和区间加/乘数的代码

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
const int MAX=5e5+5;
ll tree[MAX<<2],g[MAX<<2];//g[]是懒标记
ll a[MAX];
ll n,m;

void build(ll o,ll l,ll r){
	if(l==r){tree[o]=a[l];return ;}
	ll mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	tree[o]=tree[o<<1]+tree[o<<1|1];
}

void pushdown(ll o,ll l,ll r){
	if(g[o]==0) return ;
	ll mid=(l+r)>>1;
	g[o<<1]+=g[o];
	g[o<<1|1]+=g[o];
	tree[o<<1]+=g[o]*(mid-l+1);
	tree[o<<1|1]+=g[o]*(r-mid);
	g[o]=0;
}

void add(ll o,ll l,ll r,ll x,ll y,ll k){
	if(l>y||r<x) return;
	if(l>=x&&r<=y){
		tree[o]+=k*(r-l+1);
		g[o]+=k;
		return ;
	}
	ll mid=(l+r)>>1;
	pushdown(o,l,r);
	if(x<=mid) add(o<<1,l,mid,x,y,k);
	if(y>=mid+1) add(o<<1|1,mid+1,r,x,y,k);
	tree[o]=tree[o<<1]+tree[o<<1|1];
}

ll sum(ll o,ll l,ll r,ll L,ll R){
	ll ans=0;
	if(l>R||r<L) return 0;
	if(l>=L&&r<=R) return tree[o];
	pushdown(o,l,r);
	ll mid=(l+r)>>1;
	if(L<=mid) ans+=sum(o<<1,l,mid,L,R);
	if(R>=mid+1) ans+=sum(o<<1|1,mid+1,r,L,R);
	return ans;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);

	for(int i=0;i<m;i++){
		int opt;
		cin>>opt;
		if(opt==1){
			ll x,y,k;
			cin>>x>>y>>k;
			add(1,1,n,x,y,k);
		}else{
			ll ans=0;
			ll L,R;
			cin>>L>>R;
			ans+=sum(1,1,n,L,R);
			cout<<ans<<endl;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
//	cin>>T;
	while(T--)
		solve();
	return 0;
}

```

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll t[N<<2],a[N],ad[N<<2],mu[N<<2];
int n,q,m;

void build(ll o,ll l,ll r){
	mu[o]=1;
	if(l==r){t[o]=a[l]%m;return ;}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	t[o]=(t[o<<1]+t[o<<1|1])%m;
}

void pushdown(ll o,ll l,ll r){
	int mid=(l+r)>>1;
	t[o<<1]=(t[o<<1]*mu[o]+ad[o]*(mid-l+1))%m;
	t[o<<1|1]=(t[o<<1|1]*mu[o]+ad[o]*(r-mid))%m;
	
	ad[o<<1]=(ad[o<<1]*mu[o]+ad[o])%m;
	ad[o<<1|1]=(ad[o<<1|1]*mu[o]+ad[o])%m;
	
	mu[o<<1]=(mu[o<<1]*mu[o])%m;
	mu[o<<1|1]=(mu[o<<1|1]*mu[o])%m;

	ad[o]=0;
	mu[o]=1;
}

void add(ll o,int l,int r,int x,int y,int k){
	if(x<=l&&y>=r){
		t[o]=(t[o]+k*(r-l+1))%m;
		ad[o]=(ad[o]+k)%m;
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(o,l,r);
	if(x<=mid) add(o<<1,l,mid,x,y,k);
	if(y>mid) add(o<<1|1,mid+1,r,x,y,k);
	t[o]=(t[o<<1]+t[o<<1|1])%m;
}

void mul(ll o,int l,int r,int x,int y,int k){
	if(x<=l&&y>=r){
		t[o]=t[o]*k%m;
		mu[o]=mu[o]*k%m;
		ad[o]=ad[o]*k%m;
		return ;
	}
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(x<=mid) mul(o<<1,l,mid,x,y,k);
	if(y>mid) mul(o<<1|1,mid+1,r,x,y,k);
	t[o]=(t[o<<1]+t[o<<1|1])%m;
}

ll qry(ll o,int l,int r,int L,int R){
	if(L<=l&&r<=R) return t[o];
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	ll ans=0;
	if(L<=mid) ans=(ans+qry(o<<1,l,mid,L,R))%m;
	if(R>mid) ans=(ans+qry(o<<1|1,mid+1,r,L,R))%m;
	return ans;
}

void solve(){
	cin>>n>>q>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	while(q--){
		int opt;
		cin>>opt;
		if(opt==1){
			int x,y,k;
			cin>>x>>y>>k;
			mul(1,1,n,x,y,k);
		}else if(opt==2){
			int x,y,k;
			cin>>x>>y>>k;
			add(1,1,n,x,y,k);
		}else{
			int L,R;
			cin>>L>>R;
			ll ans=0;
			ans=qry(1,1,n,L,R);
			cout<<ans%m<<endl;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
//	cin>>T;
	while(T--)
		solve();
	return 0;
}
```

### 并查集



```c++
//这是信号站的代码,涉及到并查集
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fi first
#define se second
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define endl '\n'
#define MOD 1000000007
const int N=2e5+5;
int n,d;
int f[N],x[N],y[N],ok[N];


int getf(int v){
	if(f[v]==v) return v;
	f[v]=getf(f[v]);
	return f[v];
}

void merge(int u,int v){
	int fu=getf(u),fv=getf(v);
	if(fu>fv) fu=fv;
	else fv=fu;
}



void solve(){
	cin>>n>>d;
	memset(x,0,n+1);
	memset(y,0,n+1);
	memset(ok,0,n+1);
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		f[i]=i;
	}
	char c;
	while(cin>>c){
		if(c=='O'){
			int t;
			cin>>t;
			ok[t]=1;
			for(int i=1;i<=n;i++){
				if(ok[i]&&(x[t]-x[i])*(x[t]-x[i])+(y[t]-y[i])*(y[t]-y[i])<=d*d){
					merge(t,i);
				}
			}
		}else {
			int a,b;
			cin>>a>>b;
			if(ok[a]&&ok[b]&&getf(a)==getf(b)) cout<<"SUCCESS\n";
			else cout<<"FAIL\n";
		}
	}
	
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
//	cin>>T;
	while(T--)
		solve();
	return 0;
}
```

```c++
//这个是食物链的代码,算是并查集的深度使用
#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,r[N],p[N];//r[]表示x和p[x]的关系
				//p[]表示x的父亲

int getf(int i){
	int t;
	if(p[i]==i) return i;
	t=p[i];
	p[i]=getf(p[i]);
	r[i]=(r[t]+r[i])%3;
	return p[i];
}

void merge(int x,int y,int h){
	int a=getf(x),b=getf(y);
	p[a]=b;
	r[a]=(h+3+r[y]-r[x])%3;
}

void solve(){
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++) p[i]=i;
	while(k--){
		int d,x,y;
		cin>>d>>x>>y;
		if(x>n||y>n){
			ans++;
			continue;
		}
		if(d==1){
			if(getf(x)==getf(y)){
				if(r[x]!=r[y]) ans++;
			}
			else merge(x,y,0);
		}else{
			if(getf(x)==getf(y)){
				if(r[x]!=(r[y]+1)%3) ans++;
			}
			else merge(x,y,1);
		}
	}
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
//	cin>>T;
	while(T--)
		solve();
	return 0;
}
```



## 图论

#### tarjan

```c++
//HDU-1269迷宫城堡
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>

using namespace std;
const int MAX=1e5;
struct node{
    int to;
    int next;
}edge[MAX+5];
int n,m;
int head[MAX+5],ans;
void addnode(int u,int v)
{
    edge[ans].to=v;
    edge[ans].next=head[u];
    head[u]=ans++;
}

int dfn[MAX+5];
int low[MAX+5],num;
int sta[MAX+5],top;
int scc[MAX+5],sig;

void dfs(int u)
{
    dfn[u]=low[u]=++num;
    sta[top++]=u;
    for(int i=head[u];~i;i=edge[i].next){
        int t=edge[i].to;
        if(dfn[t]==0){
            dfs(t);
            low[u]=min(low[u],low[t]);
        }
        else if(scc[t]==0){
            low[u]=min(low[u],low[t]);
        }
    }
    if(dfn[u]==low[u]){
        sig++;
        while(1){
            int j=sta[--top];
            scc[j]=sig;
            if(j==u){
                break;
            }
        }
    }
}

void tarjan()
{
    sig=0,top=0,num=0;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(sta,0,sizeof(sta));
    memset(scc,0,sizeof(scc));
    for(int i=1;i<=n;i++){
        if(dfn[i]==0){
            dfs(i);
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0){
            break;
        }
        else{
        	memset(head,-1,sizeof(head));
        	ans=0;
            for(int i=1;i<=m;i++){
                int u,v;
                cin>>u>>v;
                addnode(u,v);
            }
            tarjan();
            if(sig==1){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
    }
    return 0;
}
```

```c++
//CF 427C  --Checkposts 
//链式前向星存图
#include<bits/stdc++.h>
#define MOD 1000000007
#define inf 0x3f3f3f3f
typedef long long ll;
using namespace std;
const int MAXN=300005;


struct node{
	int to,nxt;
}e[MAXN];

bool vis[MAXN];
ll n,m,tot,top,cnt,t;
ll ans1,ans2=1;

int dfn[MAXN],num[MAXN],sum[MAXN],low[MAXN];
int siz[MAXN],zhan[MAXN],head[MAXN],val[MAXN];

void add(int u,int v){
	e[++tot].to=v;
	e[tot].nxt=head[u];
	head[u]=tot;
}

void tarjan(int x){
    low[x]=dfn[x]=++cnt;
    zhan[++top]=x;vis[x]=1;
    for(int i=head[x];i;i=e[i].nxt){
        int to=e[i].to;
        if(!dfn[to]) tarjan(to),low[x]=min(low[x],low[to]);
        else if(vis[to]) low[x]=min(low[x],dfn[to]);
    }
    if(dfn[x]==low[x]){
        ++t;
        int pre=zhan[top--];
        sum[t]=val[pre];
        vis[pre]=0;num[pre]=t;
        while(pre!=x){
            pre=zhan[top--];
            vis[pre]=0;num[pre]=t;
            sum[t]=min(sum[t],val[pre]);
        }
    }
}

void solve(){

	cin>>n;
	for(int i=1;i<=n;i++) cin>>val[i];
	cin>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++) if(val[i]==sum[num[i]]) siz[num[i]]++;
	for(int i=1;i<=t;i++) ans1+=sum[i],ans2=(ans2*siz[i])%MOD;
	cout<<ans1<<' '<<ans2%MOD<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
//	int T;
//	cin>>T;
//	while(T--)
		solve();
	return 0;
}
```



## 杂项

### 莫队

```c++
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fi first
#define se second
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define endl '\n'
#define MOD 1000000007
const int N=2e5+5,INF=1e18;
int ans,n,T,t,cnt[N],a[N];
struct seg{int l,r,id;}q[N],ret[N];

bool cmp(seg x,seg y){
	if(x.l/t==y.l/t) return x.r<y.r;
	return x.l/t<y.l/t;
}

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

void add(int x){
	ans+=cnt[a[x]];
	cnt[a[x]]++;
}
void del(int x){
	cnt[a[x]]--;
	ans-=cnt[a[x]];
}

void solve(){
	cin>>n>>T;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=T;i++){
		cin>>q[i].l>>q[i].r;
		q[i].id=i;
	}
	t=sqrt(n);
	sort(q+1,q+T+1,cmp);
	int l=1,r=0;
	for(int i=1;i<=T;i++){ //先扩再缩
		while(r<q[i].r) add(++r);
		while(l>q[i].l) add(--l);
		while(r>q[i].r) del(r--);
		while(l<q[i].l) del(l++);
		int up=ans,down=(r-l+1)*(r-l)>>1;
		if(r==l){
			ret[q[i].id].l=0;
			ret[q[i].id].r=1;
			continue;
		}
		int G=gcd(up,down);
		up/=G;down/=G;
		ret[q[i].id].l=up;
		ret[q[i].id].r=down;
	}
	for(int i=1;i<=T;i++) cout<<ret[i].l<<'/'<<ret[i].r<<'\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
//	cin>>T;
	while(T--)
		solve();
	return 0;
}
```

### 排序

<号表示从小到大

\>号表示从大到小

#### qsort

qsort(数组名（首地址），元素个数，元素内存大小，int的比较函数)

对二维数组进行比大小

```C
#include<stdlib.h>
//a[num][3]的第三维
int cmp(const void *a,const void *b){
    return ((const int*)a)[2]-((const int*)b)[2];
}

qsort(a,num,sizeof(int[3]),cmp);
//----------------========------对等号上面的更改cmp也要更改
```



#### sort

sort(首地址，尾地址+1，[cmp函数])

-   传2或3个参数
-   第一个为区间首地址
-   第二个为区间尾地址的下一地址
-   第三个参数不写则缺省为递增排序

**sort的cmp为真则说明cmp的第一个参数会在第二个参数的前面，为假则让第一个参数在第二个参数的后面**（不严谨）

```c++
#include<algorithm>

bool cmp(int a,int b){
    return a>b;
}
sort(num,num+100,cmp);
```

以上从大到小的排序,string类类似

字符数组需要strcmp()函数

```cpp
struct node
{ int a; double b;}arr[100];
bool cmp(node x,node y)
{
	if(x.a!=y.a) return x.a<y.a;
	return x.b>y.b;
}
sort(arr,arr+100,cmp);
```

以上实现结构体排序,没错浮点数是这样

```
struct student
{	char name[11];	int age;	double score;
}stu[100];

bool cmp1(student x,student y)
{
	if(fabs(x.score-y.score)>0.000001)
		return x.score>y.score;
	if(x.age!=y.age) return x.age<y.age;
	return strcmp(x.name,y.name)<0;
}
```

上述代码是先比较分，再比较年纪，再比较名字字典序

让分高的在前面，年纪小的在前面，名字字典序小的在前面



### 输入

#### getline

delim被省略则默认在碰到'\n'后终止输入

##### \<isstream>

```c++
istream& getline (char* s, streamsize n );
istream& getline (char* s, streamsize n, char delim );
//例如
cin.getline(name, 256);
cin.getline( line, 100, 't' );
```

##### \<string>

重载了四种

```c++
istream& getline (istream&  is, string& str, char delim);
istream& getline (istream&& is, string& str, char delim);
istream& getline (istream&  is, string& str);
istream& getline (istream&& is, string& str);

//例如
getline(cin, name);
getline(cin, name, '#');
```



#### sscanf

仅在<stdio.h>里面的字符串,处理string要转换为**C风格的字符串**

```c++
//原型
#include <stdio.h>
int sscanf(const char *str, const char *format, ...);
/*************例子***************/
int year, month, day;
int converted = sscanf("20191103", "%04d%02d%02d", &year, &month, &day);
//converted=3, year=2019, month=11, day=03

int converted = sscanf("113.123456789 31.123456789", "%lf %lf", &longitude, &latitude);
//converted=2, longitude=113.123456789, latitude=31.123457
/*************end****************/

//长度限制
char str[32] = "";
sscanf("123456abcdedf", "%31[0-9]", str);
//str="123456"
sscanf("123456abcdedf", "%31[0-9a-z]", str);
//str=123456abcdedf
sscanf("123456abcdedf586", "%31[^a-z]", str);
//str=123456	碰到a~z截止,不再往后读
int ret = sscanf("123456abcdedf", "%*[0-9]%31[a-z]", str);
//ret=1, str=abcdedf
//*表示忽略前面的0~9
```



### 位运算

```c++
x+y=x^y+2*(x&y)
    
01跳变就^1即可

偶数|1就是加上1
```

### GCD

```c++
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
```



