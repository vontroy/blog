/******************************************
设需要n年
设半圆面积为 S，半径为 r
S = 50 * n;
S = (PI * r * r) / 2;
解得 n = (PI * r * r ) / 100;
所给点到原点距离 len = sqrt( x * x + y * y );
令len = r即可解出 n
*******************************************/

#include <iostream>
#include <cstdio>
#include <cmath>

const double PI = 3.1415927;

using namespace std;

int main()
{
    double x, y;
    int cnt;

    cin >> cnt;
    int pro = 1;
    while( cnt-- )
    {
        cin >> x >> y;
        double len = sqrt( x * x + y * y );
        int n = (PI * len * len ) / (100 * 1.0);
        printf("Property %d: This property will begin eroding in year %d.\n", pro++, n + 1);
    }
    cout << "END OF OUTPUT.\n";
    return 0;
}
