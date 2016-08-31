//数论模板

#include<iostream>
#include<cmath>
using namespace std;
//辗转相除法求最大公约数
long gcd(long a, long b)
{
     if(b==0)
                 return a;
         else
                 return gcd(b,a%b);
}
//求最大公倍数
long lcm(long a, long b)
{
        if(a*b==0) return 0;
        else
                return a*b/gcd(a,b);
}
//求a^b mod n
long modexp(long a, long b, long n)
{
    int t, y;
        t=1; y=a;
        while(b!=0)
        {
           if(b&1==1)
                   t=t*y%n;
           y=y*y%n;
           b/=2;
        }
        return t;
}
//扩展的Euclid算法
//返回a.b的最大公约数， 并使ax+by=d;
long exEuclid(long a, long b, long & x, long & y)
{ 
        long tmp,d;
        if(b==0)
        {
                x=1;
                y=0;
                return a;
        }
        d=exEuclid(b, a%b, x,y);
        tmp=x;
        x=y;
        y=tmp-a/b*y;
    return d;
}
//解线性同余方程ax=b(mod n)
//返回最小的x
long  modu(long a, long b, long n)
{
     long d,x=1,y=0;
         d=exEuclid(a,n,x,y);
         x=x*(b/d);
         x=(x%(n/d)+n/d)%(n/d);
         return x;
}
//用中国剩余定理解同余方程组a=bi（modni)
long solmodu(long z, long b[], long n[])
{   
        int i;
    long a,m,x,y,t;
        m=1 ;a=0;
        for(i=0; i<z; i++)  m*=n[i];
        for(i=0; i<z; i++)
    {
                t=m/n[i];
                exEuclid(n[i],t,x,y);
                a=(a+t*y*b[i])%m;
        }
        return (a+m)%m;
}
//筛法求素数
const maxn=100000;
bool  prime[maxn+1];
void  searchprime(long b[],long & k)
{
   int i ,j;
   memset(prime,0,sizeof(prime));
   prime[1]=1;
   for(i=2; i<sqrt(maxn); i++)
           if(!prime[i])
           {
          j=i*2;
                  while(j<=maxn)
                  {
                          prime[j]=1;
                          j+=i;
                  }
           }
  j=0;
  for(i=1; i<maxn; i++)
          if(prime[i]==0)
                     b[j++]=i;
   k=j;
}
//判定素数 素数表
bool isPrime(long x,long b[])
{
        int i;
        i=1;
        while(b[i]*b[i]<=x)
        {
       if(x%b[i]==0)
                   return 0;
           i++;
        }
        return true;
}
//判定素数，概率方法
bool passTest(long n)
{
        long l ,m,b,i,k;
        m=n-1;
        l=0;
        while(m%2==0)
        {
                l++;
            m/=2;
        } 
    b=rand()%n+1;
        if(modexp(b,m,n)==1) return 1;
    k=m;
        for(i=0; i<l; i++)
        {
                if(modexp(b,k,n)==n-1) return 1;
                k*=2;
        }
        return 0;
}
//取子游戏
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
        double alpha = (1.0 + sqrt(5.0)) / 2.0;
        double beta  = (3.0 + sqrt(5.0)) / 2.0;
        int big, small, n, temp1, temp2;
        while(cin>>big>>small)        
        {        
                if(big < small)        
                swap(big, small);        
                n = ceil(big / beta);        
                temp1 = alpha * n;                
                temp2 = beta  * n;        
                if(small == temp1 && big == temp2)
                            cout<<0<<endl;        
                else cout<<1<<endl;        
        }
        return 0;
}
//二维树状数组1195
#include<cstdio>
#include<iostream>
using namespace std;
int  c[1025][1025];
int  n, cmd;
static inline int  lastexp(int i)
{
        return i&(-i);
}
void modify(int x, int y, int a)
{
        int i, j;
        for(i=x; i<=n; i+=lastexp(i))
                 for(j=y; j<=n; j+=lastexp(j))
                            c[i][j]+=a;
}
long getsum(int x, int y)
{
        long total=0;
    int i, j;
        for(i=x; i>0; i-=lastexp(i))
                 for(j=y; j>0; j-=lastexp(j))
                             total+=c[i][j];
        return total;
}
void modify1()
{   
    int x, y, a;
        scanf("%d%d%d",&x,&y,&a);
        x++;
        y++;
        modify(x,y,a);
}
long getsum1()
{
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        a++; b++; c++; d++;
        return getsum(c,d)-getsum(c,b-1)-getsum(a-1,d)+getsum(a-1,b-1);
}
int main()
{   
        long s;
        while(1)
        {
                cin>>cmd;
                switch(cmd)
                {
                case 0:   memset(c,0,sizeof(c)); cin>>n;  break;
                case 1:   modify1(); break;
                case 2:   s=getsum1(); printf("%ld\n",s); break;
                case 3:   goto L; 
                }
        }
L:        return 0;
}
