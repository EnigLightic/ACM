#include <bits/stdc++.h>
#define INF 1e10
using namespace std;
typedef long long ll;
map<string,int> ma;
map<string,int>::iterator qq;
set<string> s;
set<string>::iterator it;
vector<pair<string,int> > pa;
 
bool cmp(pair<string,int> a, pair<string,int> b)
{
    if(a.second == b.second)
        return a.first<b.first;
    return a.second > b.second;
}
int main()
{
    int n;
    cin>>n;
    getchar();
    while(n--)
    {
        s.clear();
        int l,l1 = -1,l2 = -1;
        string buf;
        getline(cin,buf);
        l = buf.size();
        char p[150];
        for(int i = 0;i < l;i++)
        {
            if(buf[i] == '#' && l1 == -1)
            {
                l1 = i;
            }
            else if(buf[i] == '#' && l1 != -1)
                l2 = i;
            if(l2 != -1)
            {
                memset(p,0,sizeof(p));
                //printf("%dgg\t%dgg\n",l1,l2);
                int num = 0;
                for(int j = l1 + 1;j < l2;j++)
                {
                    //cout<<buf[j];
                    if(isalpha(buf[j]) || isdigit(buf[j]))
                    {
                        //cout<<buf[j];
                        if(isupper(buf[j]))
                        {
                            buf[j] = (char)('a' - 'A' + (int)buf[j]);
                            //cout<<buf[j];
                        }
                        if(buf[j-1] == ' ') p[num++] = ' ';
                        p[num++] = buf[j];
                    }
                    else buf[j] = ' ';
                }
                //cout<<p<<endl;
                l1 = l2 = -1;
                s.insert(p);
            }
        }
        for(it = s.begin();it != s.end();it++)
        {
            string q = *it;
            //cout<<q<<endl;
            ma[q]++;
        }
    }
    for(qq = ma.begin();qq != ma.end();qq++)
    {
        pair<string,int> r;
        r.first = qq->first;
        r.second = qq->second;
        pa.push_back(r);
    }
    sort(pa.begin(),pa.end(),cmp);
    int num = pa[0].second;
    string x = pa[0].first;
    x[0] = (char)(x[0] + 'A' - 'a');
    int oth = 0;
    for(int i = 1;i < pa.size();i++)
    {
        if(pa[i].second == num)
          oth++;
    }
    cout<<x<<endl;
    printf("%d\n",num);
    if(oth)
    {
        printf("And %d more ...\n",oth);
    }
    return 0;
}
