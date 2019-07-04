#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool vis[10001][10001];//是否联通 
vector<int>g[10001];//矢量 
int p[10001],d[10001],r[200001];
int s=0;
int findset(int x) //并查集 看一对点在不在一个组里，不在的话并进去 
{
	if(x==p[x])
	return x;
	else
	return p[x]=findset(p[x]);
}
void dfs(int k) //欧拉路 欧拉路是指从图中任意一个点开始到图中任意一个点结束的路径，并且图中每条边通过的且只通过一次
{	
	for(int i=0;i<g[k].size();++i)
	{
		int y=g[k][i];
		if(!vis[k][y])
		{
			vis[k][y]=vis[y][k]=true;
			dfs(y);
		}
	}
	r[s++]=k;//模拟栈 
}
int main()
{
	int n,m,a,b,cnt,du=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	p[i]=i;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		d[a]++; d[b]++;
		g[a].push_back(b);
		g[b].push_back(a);
		int x=findset(a); //并查集 
		int y=findset(b);
		if(x!=y)
		p[x]=y;	
	}
	for(int i=1;i<=n;i++)
	{
	  sort(g[i].begin(),g[i].end());	//边排序，保证字典序最小 
	   if(p[i]==i)    //联通分量，大于1表示图不连通，连通图的连通分量只有一个 
	    cnt++;
	   if(d[i]%2==1)  //点的度数为奇数，欧拉图只能没有奇数点或者两个 
	    du++;
	}
	dfs(1);
  	if(cnt!=1||(du!=0&&du!=2)||(du==2&&d[1]%2==0))
  	  cout<<-1<<endl;
  	else
  	{
  		for(int i=s-1;i>=0;i--)
    	cout<<r[i]<<" ";
	}
   return 0;	
} 
