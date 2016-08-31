#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long a, b;
    int ans[5];
    while(cin >> a >> b)
    {
        if( b == 0 )
        {
            cout << "1" << endl;
            continue;
        }
        else if( a == 0 )
        {
            cout << "0" << endl;
            continue;
        }
        ans[1] = a % 10;
        ans[2] = (ans[1] * a ) % 10;
        ans[3] = (ans[2] * a ) % 10;
        ans[4] = (ans[3] * a ) % 10;

        int tmp = b % 4;
        if( tmp == 0 ) tmp = 4;
        cout << ans[tmp] << endl;
    }
    return 0;
}
