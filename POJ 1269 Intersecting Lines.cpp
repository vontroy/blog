/*************************************
计算几何基础题，判断直线相交及求交点
注意斜率不存在的情况
**************************************/
#include <iostream>
#include <cstdio>

int main()
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    int n;
    double k1, k2;
    double b1, b2;
    double i_x, i_y;
    scanf("%d", &n);
    std::cout << "INTERSECTING LINES OUTPUT" << std::endl;
    while( n-- )
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

        if( x1 != x2 && x3 != x4 )
        {
            k1 = ( y2 - y1 ) / ( x2 - x1 );
            k2 = ( y4 - y3 ) / ( x4 - x3 );
            b1 = y1 - k1 * x1;
            b2 = y3 - k2 * x3;
            if( k1 == k2 )
            {
                if( b1 == b2 )
                    printf("LINE\n");
                else
                    printf("NONE\n");
            }
            else
            {
                i_x = (b2 - b1) / (k1 - k2);
                i_y = k1 * i_x + b1;
                printf("POINT %.2lf %.2lf\n", i_x, i_y);
            }
        }
        else if( x1 == x2 && x3 == x4 )
        {
            if( x1 == x3 )
            std::cout << "LINE\n";
            else
            std::cout << "NONE\n";
        }
        else if( x1 == x2 && x3 != x4 )
        {
            k2 = ( y4 - y3 ) / ( x4 - x3 );
            b2 = y3 - k2 * x3;
            i_x = x1;
            i_y = k2 * x1 + b2;
            printf("POINT %.2lf %.2lf\n", i_x, i_y);
        }
        else
        {
            k1 = ( y2 - y1 ) / ( x2 - x1 );
            b1 = y1 - k1 * x1;
            i_x = x3;
            i_y = k1 * x3 + b1;
            printf("POINT %.2lf %.2lf\n", i_x, i_y);
        }
    }
    std::cout << "END OF OUTPUT\n";
    return 0;
}
