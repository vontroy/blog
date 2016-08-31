/**
* As is required to ouput the result in lexicographic order，
* visit smaller coordinates first and the first legitimate result is the right answer
**/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
 
using namespace std;
 
int const maxn = 30;
 
bool vis[maxn][maxn];
int p, q;
bool flag = false;
 
int const steps[8][2] = { { -1, -2 }, { 1, -2 }, { -2, -1 }, { 2, -1 }, { -2, 1 }, { 2, 1 }, { -1, 2 }, { 1, 2 } };
 
typedef struct node
{
    int x;
    int y;
}coordinate;
 
bool judge()
{
    for( int i = 0; i < p; i++ )
        for( int j = 0; j < q; j++ )
            if( !vis[i][j] )
                return false;
    return true;
}
 
vector<coordinate> path;
 
void dfs( int x, int y )
{
    if( flag )
        return;
    if( judge() && !flag ) {
        printf( "A1" );
        for( int i = 0; i < path.size(); i++ ){
            printf( "%c", path[i].y + 65 );
            printf( "%d", path[i].x + 1 );
        }
        puts("");
        flag = true;
        return;
    }
    for( int i = 0; i < 8; i++ ) {
        int next_x = x + steps[i][0];
        int next_y = y + steps[i][1];
        if( next_x >= 0 && next_x < p && next_y >= 0 && next_y < q && !vis[next_x][next_y] ) {
            coordinate tmp;
            tmp.x = next_x;
            tmp.y = next_y;
 
            path.push_back( tmp );
            vis[next_x][next_y] = 1;
 
            dfs( next_x, next_y );
 
            vis[next_x][next_y] = 0;
            path.pop_back();
        }
    }
 }
 
int main()
{
    int n; scanf( "%d", &n );
 
    for( int i = 0; i < n; i++ ) {
        scanf( "%d%d", &p, &q );
 
        flag = false;
 
        printf( "Scenario #%d:\n", i + 1 );
 
        memset( vis, 0, sizeof( vis ) );
 
        path.clear();
        vis[0][0] = 1;
        dfs( 0, 0 );
        if( !flag )
            printf( "impossible\n" );
        puts("");
 
    }
    return 0;
}
