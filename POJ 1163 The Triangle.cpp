#include <iostream>
#include <cstdio>

using namespace std;

int const maxn = 105;

int dp[maxn][maxn];

int main()
{
    int n; scanf( "%d", &n );

    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j <= i; j++ ) {
            scanf( "%d", &dp[i][j] );
        }
    }

    for( int i = n - 2; i >= 0; i-- ) {
        for( int j = 0; j <= i; j++ ) {
            dp[i][j] = dp[i+1][j] > dp[i+1][j+1] ? dp[i+1][j] + dp[i][j] : dp[i+1][j+1] + dp[i][j];
        }
    }

    printf( "%d\n", dp[0][0] );
}
