#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int const maxn = 1005;

int main() 
{
	int n;
	int num[maxn];
	int origin[maxn];
	while( scanf( "%d", &n ), n ) {
		memset( origin, 0, sizeof( origin ) );

		while( scanf( "%d", &num[1] ), num[1] ) {
			for( int i = 2; i <= n; i++ )
				scanf( "%d", &num[i] );
			int top = 1;
			int seq = 2;
			origin[1] = 1;
			bool flag = true;
			for( int i = 1; i <= n; i++ ) {
				while( true ) {
					if( origin[top] == num[i]) {
						origin[top] = 0;
						top--;
						break;
					}
					else {
						top++;
						origin[top] = seq++;
						if( top > n ) {
							flag = false;
							break;
						}
					}
				}
            }
			printf( "%s\n", flag ? "Yes" : "No" );
		}
		puts( "" );
	}
	return 0;
}
