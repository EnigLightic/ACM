#include<bits/stdc++.h>
#define int long long 
using namespace std;
int ans=0;
const int N=5e5+5;
int a[N],t[N];
void msort(int l,int r){
	if(r-l<=1) return ;
	int mid=(l+r)/2;
	int p=l,q=mid,i=l;
	msort(l,mid);
	msort(mid,r);
	while(p<mid||q<r){
		if(q>=r||(p<mid&&a[p]<=a[q])) t[i++]=a[p++];
		else {t[i++]=a[q++];ans+=mid-p;}
	}
	for(int i=l;i<r;i++) a[i]=t[i];
}

signed main(){
	ans=0;
	
	int n;
	cin>>n;
//	vector<int> a(n+2),t(n+2);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	msort(0,n);
	cout<<ans<<endl;
	return 0;
}
