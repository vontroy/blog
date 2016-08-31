#include <iostream>
#include <cstdio>
#include <algorithm>

const int maxn = 1000 + 5;

using namespace std;

bool cmp( int a, int b )
{
    return a > b;
}

int main()
{
    int a[maxn], b[maxn];
    int n, t, ans = 0;
    while( cin >> n >> t )
    {
        ans = 0;
        for( int i = 0; i < n; i++ )
            cin >> a[i];
        for( int i = 0; i < n; i++ )
            cin >> b[i];

        sort( a, a + n );
        sort( b, b + n, cmp );

        for( int i = 0; i < n; i++ )
            if( a[i] + b[i] > t )
                ans += a[i] + b[i] - t;
        cout << ans << endl;
    }
    return 0;
}
