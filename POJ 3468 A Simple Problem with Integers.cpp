#include <iostream>
#include <cstdio>

using namespace std;

struct CNode
{
    int L, R;
    CNode * pLeft, * pRight;
    long long nSum, Inc;
};

CNode Tree[1000000];

int nCount = 0;

void BuildTree( CNode * pRoot, int L, int R )
{
    pRoot->L = L;
    pRoot->R = R;
    pRoot->nSum = 0;
    pRoot->Inc = 0;

    if( L == R )    return;
    nCount++;
    pRoot->pLeft = Tree + nCount;
    nCount++;
    pRoot->pRight = Tree + nCount;
    BuildTree( pRoot->pLeft, L, ( L + R ) / 2 );
    BuildTree( pRoot->pRight, ( L + R ) / 2 + 1, R );
}

void Insert( CNode * pRoot, int i, int v )
{
    if( pRoot->L == i && pRoot->R == i )
    {
        pRoot->nSum = v;
        return;
    }
    pRoot->nSum += v;
    if( i <= ( pRoot->L + pRoot->R ) / 2 )
        Insert( pRoot->pLeft, i, v );
    else
        Insert( pRoot->pRight, i, v);
}

void Add( CNode * pRoot, int a, int b, long long c )
{
    if( a == pRoot->L && b == pRoot->R )
    {
        pRoot->Inc += c;
        return;
    }
    pRoot->nSum += ( b - a + 1 ) * c;
    if( b <= ( pRoot->L + pRoot->R ) / 2)
        Add( pRoot->pLeft, a, b, c );
    else if ( a >= (pRoot->L + pRoot->R ) / 2 + 1 )
        Add ( pRoot->pRight, a, b, c );
    else
    {
        Add( pRoot->pLeft, a, ( pRoot->L + pRoot->R ) / 2, c );
        Add( pRoot->pRight, (pRoot->L + pRoot->R ) / 2 + 1, b, c );
    }
}

long long QuerynSum( CNode * pRoot, int a, int b )
{
    if ( a == pRoot->L && b == pRoot->R )
        return (pRoot->nSum + (pRoot->R - pRoot->L + 1 ) * pRoot->Inc);
    pRoot->nSum += (pRoot->R - pRoot->L + 1 ) * pRoot->Inc;
    Add( pRoot->pLeft, pRoot->L, (pRoot->L + pRoot->R ) / 2, pRoot->Inc );
    Add( pRoot->pRight, (pRoot->L + pRoot->R ) / 2 + 1, pRoot->R, pRoot->Inc );
    pRoot->Inc = 0;

    if( b <= (pRoot->L + pRoot->R ) /2 )
        return QuerynSum( pRoot->pLeft, a, b );
    else if ( a >= (pRoot->L + pRoot->R ) / 2 + 1 )
        return QuerynSum ( pRoot->pRight, a, b);
    else
        return QuerynSum( pRoot->pLeft, a, (pRoot->L  +pRoot->R ) / 2 ) + QuerynSum( pRoot->pRight, (pRoot->L + pRoot->R ) / 2 + 1, b ) ;
}

int main()
{
    int n,q;
    scanf("%d%d", &n, &q );
    nCount = 0;
    BuildTree( Tree, 1, n);
    int temp;
    for( int i = 1; i <= n; i++ )
    {
        scanf("%d", &temp);
        Insert( Tree, i, temp );
    }
    char c_temp[10];
    int a, b, c;
    for( int i = 0; i < q; i++ )
    {
        scanf("%s", c_temp);
        if( c_temp[0] == 'C' )
        {
            scanf("%d%d%d", &a, &b, &c );
            Add( Tree, a, b, c);
        }
        else
        {
            scanf("%d%d", &a, &b );
            printf("%I64d\n",QuerynSum( Tree, a, b ));
        }
    }
    return 0;
}
