/***************************************
比较经典的中国剩余定理~~

使33×28被23除余1，用33×28×6=5544

使23×33被28除余1，用23×33×19=14421

使23×28被33除余1，用23×28×2=1288

（5544×p+14421×e+1288×i）%（23×28×33）=n+d

n=（5544×p+14421×e+1288×i-d）%（23×28×33）
****************************************/

#include <iostream>
#include <cstdio>

using std :: cin;
using std :: cout;
using std :: endl;

int get__( int a, int b, int c )
{
    int ans;
    int cnt = 1;
    while( ( a * b * cnt ) % c != 1 )
    {
        cnt++;
    }
    return a * b * cnt;
}

int main()
{
    int _p = get__( 28, 33, 23 );
    int _e = get__( 23, 33, 28 );
    int _i = get__( 23, 28, 33 );

    int p, e, i, d;
    int cas = 1;
    while( cin >> p >> e >> i >> d )
    {
        if( p == e && e == i && i == d && d == -1 ) break;
        int ans = ( _p * p + _e * e + _i * i - d ) % ( 23 * 28 * 33 );
        if( ans <= 0 )
            printf("Case %d: the next triple peak occurs in %d days.\n", cas++, 21252 - ans - 2 * d);
        else
            printf("Case %d: the next triple peak occurs in %d days.\n", cas++, ans);
    }
    return 0;
}
