#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    double len;
    double tmp;
    int ans;

    while( cin >> len, len )
    {
        tmp = 0;
        ans = 1;
        while( ans++ )
        {
            tmp += 1 / ( ans * 1.0 );
            if( tmp >= len )
            {
                cout << ans - 1 << " card(s)" << endl;
                break;
            }
        }
    }
    return 0;
}
