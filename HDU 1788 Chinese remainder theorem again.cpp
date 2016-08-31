/**********************************
N % MI = MI - a
因为 a < MI
原式等价于 (N + a) % MI = 0
所以此题为求 M0 到 MI 的最小公倍数

(注意精度问题,用__int64)

***********************************/

#include <iostream>
#include <cstdio>

using namespace std;

__int64 gcd( __int64 a, __int64 b )
{
    if( b == 0 ) return a;
    return gcd( b, a % b );
}

__int64 lcm( __int64 a, __int64 b )
{
    return a * b / gcd( a, b );
}

int main()
{
    int n, k;
    int tmp;
    __int64 ans;
    while( cin >> n >> k, n || k )
    {
        ans = 1;
        for( int i = 0; i < n; i++ )
        {
            cin >> tmp;
            ans = lcm( ans, tmp );
        }
        cout << ans - k << endl;
    }
    return 0;
}
