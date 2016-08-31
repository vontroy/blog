//log10(n!)=(0.5*log(2*PI*n)+n*log(n)-n)/log(10)

#include <iostream>
#include <cstdio>
#include <cmath>

const double PI = 3.1415926;

int main()
{
    int n;
    int tmp;
    while( ~scanf("%d", &n ) )
    {
        for( int i = 0; i < n; i++ )
        {
            scanf("%d", &tmp);
            double cnt = 1;
            cnt += (0.5 * log( 2 * PI * tmp ) + tmp * log( tmp ) - tmp ) / log(10);
            printf("%d\n", (int)(cnt));
        }
    }
    return 0;
}
