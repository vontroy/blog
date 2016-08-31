#include <iostream>
#include <cstdio>

const int maxn = 30000 + 5;

using namespace std;

int father[maxn],rank[maxn];

void init( int n )
{
    for ( int i = 0; i < n; i++)
    {
        father[i] = i;
        rank[i] = 1;
    }
}

int findSet( int n )
{
    if(father[n] != n)
        father[n] = findSet(father[n]);
    return father[n];
}

void Union( int a, int b )
{
    int x = findSet( a );
    int y = findSet( b );

    if( x == y ) return ;
    if( rank[x] >= rank[y] )
    {
        father[y] = x;
        rank[x] += rank[y];
    }
    else
    {
        father[x] = y;
        rank[y] += rank[x];
    }
}

int main()
{
    int m, n, count, temp, first;
    while( ~scanf("%d%d", &n, &m ) && n )
    {
        init(n);
        while( m-- )
        {
            scanf("%d%d", &count, &first );
            for( int i = 1; i < count ;i ++)
            {
                scanf("%d", &temp);
                Union( first, temp );
            }
        }
        printf("%d\n",rank[findSet(0)]);
    }
    return 0;
}
