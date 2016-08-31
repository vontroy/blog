/**********************************************
1. C(m,n)=C(m,m-n)
2. C(m,n)=C(m-1,n)+C(m-1,n-1)

derangement D(n) = n!(1 - 1/1! + 1/2! - 1/3! +  + (-1)^n/n!)
                 = (n-1)(D(n-2) - D(n-1))
  Q(n) = D(n) + D(n-1)
求和公式,k = 1..n
1. sum( k ) = n(n+1)/2
2. sum( 2k-1 ) = n^2
3. sum( k^2 ) = n(n+1)(2n+1)/6
4. sum( (2k-1)^2 ) = n(4n^2-1)/3
5. sum( k^3 ) = (n(n+1)/2)^2
6. sum( (2k-1)^3 ) = n^2(2n^2-1)
7. sum( k^4 ) = n(n+1)(2n+1)(3n^2+3n-1)/30
8. sum( k^5 ) = n^2(n+1)^2(2n^2+2n-1)/12
9. sum( k(k+1) ) = n(n+1)(n+2)/3
10. sum( k(k+1)(k+2) ) = n(n+1)(n+2)(n+3)/4
12. sum( k(k+1)(k+2)(k+3) ) = n(n+1)(n+2)(n+3)(n+4)/5
*********************************************/
//ploya 定理
//例题：手镯有n个位置(位置等距)用来嵌入宝石，有m种宝石可以用来嵌入。可以产生多少种不同的手镯？
//n=4 ,m=3,结果21
//n=20 ,m=7,结果1 994 807 299 453 766 (上限)
#include<iostream>   
#include<cstdio>   
#include<cmath>   
using namespace std;   
const int M=20;   
int g[M];   
int vis[M];   
int main()   
{   
    int m,n;   
    double res=0,tmp;   
    while(cin>>m>>n)   
    {   
        res=0;   
        int   i,j,k,c;   
        for(i=0;i<m;i++)
        {   
            for(j=0;j<m;j++)   
            {   
                g[j]=(j+i)%m;   
                vis[j]=0;   
            }   
            for(j=0,c=0;j<m;j++)   
            {   
                if(vis[j]==0)
                {   
                    c++;   
                    for(k=j;vis[k]==0;vis[k]=1,k=g[k]);   
                }   
            }    
            res+=pow(n,c);   
            for(j=1;j*2<m;j++)   
            {   
                k=g[j];g[j]=g[m-j];g[m-j]=k;   
                vis[j]=0;   
            }   
            for(j=0;j<m;j++)vis[j]=0;   
            for(j=0,c=0;j<m;j++)   
            {   
                if(vis[j]==0)
                {   
                    c++;   
                    for(k=j;vis[k]==0;vis[k]=1,k=g[k]);   
                }   
            }   
            res+=pow(n,c);     
        }   
        printf("%0.0lf\n",res/(2*m));   
    }  
    return 0;   
}

//生成排列：n<=8, wei 150ms n==9 wei 1200ms 0(n);
#include <iostream>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;
ifstream fin("g.txt");
ofstream fout("g.out");
int c=0;
void Swap(int &x,int &y)
{   
    int t;
    t=y;
    y=x;
    x=t;
}
void perm(int list[], int k, int m)
{
    if(k==m-1)
    {
        for(int i=0; i<m; i++) printf("%d",list[i]);
            printf("\n");
            c++;
    }
    else {
        for(int i=k; i<m; i++)
        {
            Swap(list[k],list[i]);
            perm(list,k+1,m);
            Swap(list[k],list[i]);
        }
    }
}

int main()
{   
    freopen("g.txt","r",stdin);
    freopen("g.out","w",stdout);
    int list[100];
    memset(list,0,sizeof(list));
    int n; scanf("%d",&n);
    for(int i=0; i<n;i++)
        scanf("%d",&list[i]);
    time_t a=clock();
    perm(list,0,n);
    time_t a1=clock();
    printf("%d\n%d\n",a1-a,c);
    return 0;
}

//高效生成组合算法：
int list[100];
bool b[100];
int n,tot=1;
int C(int n, int m)//计算组合数：
{
    int result = 1;
    if(m > n - m) m = n - m;
    for(int i = 1; i <= m; ++i)
    {
        result = result * (n - m + i)  / i;//一定可以整除,^_^
    }
    return result;
}

void comb()
{   
    int i,j,k;
    while(1)
    {
        bool c=0;
        for(i=1; i<n; i++)
        {
            if(b[i]==1&&b[i+1]==0)
            {   
                c=1;
                break;
            }
        }
        if(c==0) break;
        tot++;
        b[i+1]=1;
        b[i]=0;
        for(k=1; k<i; k++)
        {
            for(j=1; j<i-k; j++) {
                if(b[j]==0&&b[j+1]==1)
                {
                    bool s;
                    s=b[j+1];
                    b[j+1]=b[j];
                    b[j]=s;
                }
            }
         }
        for(i=1 ;i<=n; i++) {
            if(b[i]==1)
                cout<<list[i];
        }
        cout<<endl;
    }
}
int main()
{     
    int m,i;
    memset(list,0,sizeof(list));
    memset(b,0,sizeof(b));
    cin>>n>>m;
    for(i=1; i<=n; i++)
        cin>>list[i];
    for(i=1; i<=m; i++)
    {
        b[i]=1;
        cout<<list[i];
    }
    cout<<endl;
    time_t a=clock();
    comb();
    time_t a1=clock();
    cout<<C(n,m)<<endl;
    cout<<tot<<" "<<a1-a<<endl;
    return 0;
}
//整数划分数的个数：
int q(int n, int m)
{
    if((n<1)||(m<1)) return 0;
    if(n==1||m==1)return 1;
    if(n<m) return q(n,n);
    if(n==m) return q(n,m-1)+1;
    return q(n,m-1)+q(n-m,m);
}
//错排的递推公式：
//M(n)=(n-1)[M(n-2)+M(n-1)]
//特殊地，M(1)=0,M(2)=1
