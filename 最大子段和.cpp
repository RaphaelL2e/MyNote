/*最大子段和问题*/
#include <iostream>

using namespace std;
int a[100];
int max_sum(int a[],int n,int best_i ,int best_j)
{
    int i=1,j,this_sum[n+1],sum[n+1];
    this_sum[0]=0;
    sum[0]=0;
    best_i=0;
    best_j=0;

    for(j=1;j<=n;j++)
    {
        this_sum[j]=this_sum[j-1]+a[j];
        if(this_sum[j]>sum[j-1])
        {
            sum[j]=this_sum[j];
            best_i=i;
            best_j=j;
        }else {
            sum[j]=sum[j-1];
        }
        if(this_sum[j]<0)//重新定位开始位置
        {
            i=j+1;
            this_sum[j]=0;
        }
    }//for end

    cout<< " 最大子段起始位置为："<<best_i<<endl;
    cout<< " 最大子段终点位置为："<<best_j<<endl;

    return sum[n];
}//max_sum end
int main()
{
    int n,i,best_i,best_j;
    char flag='y';
    while(true){
        cout<< " 请输入数列的长度"<<endl;
        cin>>n;
        for(i=1;i<=n;i++) cin>>a[i];
        cout<< " 该序列的最大子段和为："<<max_sum(a,n,best_i,best_j)<<endl;//调用计算模块
        cout<< " Do you want to continue?(y or n):";cin>>flag;//是否继续
        if(flag=='n')break;
    }
    return 0;
}
