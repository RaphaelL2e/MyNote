#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool vis[10001][10001];//�Ƿ���ͨ 
vector<int>g[10001];//ʸ�� 
int p[10001],d[10001],r[200001];
int s=0;
int findset(int x) //���鼯 ��һ�Ե��ڲ���һ��������ڵĻ�����ȥ 
{
	if(x==p[x])
	return x;
	else
	return p[x]=findset(p[x]);
}
void dfs(int k) //ŷ��· ŷ��·��ָ��ͼ������һ���㿪ʼ��ͼ������һ���������·��������ͼ��ÿ����ͨ������ֻͨ��һ��
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
	r[s++]=k;//ģ��ջ 
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
		int x=findset(a); //���鼯 
		int y=findset(b);
		if(x!=y)
		p[x]=y;	
	}
	for(int i=1;i<=n;i++)
	{
	  sort(g[i].begin(),g[i].end());	//�����򣬱�֤�ֵ�����С 
	   if(p[i]==i)    //��ͨ����������1��ʾͼ����ͨ����ͨͼ����ͨ����ֻ��һ�� 
	    cnt++;
	   if(d[i]%2==1)  //��Ķ���Ϊ������ŷ��ͼֻ��û��������������� 
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
