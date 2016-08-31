#include <iostream>
#include <cstdio>
#include <cmath>

const int maxn = 10;

using namespace std;

bool escape;

char map[maxn][maxn];

int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int n, m, t;
int si, sj, di, dj;

void dfs( int x, int y, int cnt )
{
    if( escape ) return;

    if( x == di && y == dj && cnt == t )
    {
        escape = 1;
        return;
    }

    int temp = t - cnt - ( fabs(di - x) + fabs(dj - y ) );

    if( temp < 0 || temp % 2 != 0 )     return;//奇偶剪枝

    if( x <= 0 || y <= 0 || x > n || y > m )    return;

    for( int i = 0; i < 4; i++ )
    {
        if( map[x+dir[i][0]][y+dir[i][1]] != 'X')
        {
            map[x+dir[i][0]][y+dir[i][1]] = 'X';
            dfs(x+dir[i][0], y+dir[i][1], cnt+1);
            map[x+dir[i][0]][y+dir[i][1]] = '.';
        }
    }

}

int main()
{
    while( cin >> n >> m >> t, m || n || t )
    {
        int wall = 0;
        escape = 0;
        for ( int i = 1; i <= n; i++ )
            for ( int j = 1; j <= m; j++ )
            {
                cin >> map[i][j];

                if( map[i][j] == 'D')
                {
                    di = i;
                    dj = j;
                }

                else if ( map[i][j] == 'S' )
                {
                    si = i;
                    sj = j;
                }

                else if ( map[i][j] == 'X' )
                    wall ++ ;
            }

        if( m * n - wall <= t )
        {
            printf("NO\n");
            continue;
        }
        else
        {
            map[si][sj] = 'X';
            dfs( si, sj, 0 );
            printf("%s\n", escape ? "YES" : "NO" );
        }
    }
    return 0;
}
