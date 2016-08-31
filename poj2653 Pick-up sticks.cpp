#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100000 + 5;
const double eps=1e-10;

struct point
{ 
    double x, y; 
};

point p[maxn], b[maxn];
bool ans[maxn];

double min(double a, double b) { return a < b ? a : b; }

double max(double a, double b) { return a > b ? a : b; }

bool inter(point a, point b, point c, point d)
{
    if( min(a.x, b.x) > max(c.x, d.x) || min(a.y, b.y) > max(c.y, d.y) || min(c.x, d.x) > max(a.x, b.x) || min(c.y, d.y) > max(a.y, b.y) ) {
        return 0;
    }

    double h, i, j, k;

    h = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    i = (b.x - a.x) * (d.y - a.y) - (b.y - a.y) * (d.x - a.x);
    j = (d.x - c.x) * (a.y - c.y) - (d.y - c.y) * (a.x - c.x);
    k = (d.x - c.x) * (b.y - c.y) - (d.y - c.y) * (b.x - c.x);

    return h * i <= eps && j * k <= eps;
}

int main()
{
    int n;
    int res[maxn];
    while( cin >> n, n )
    {
        memset( ans, 0, sizeof( ans ) );
        for( int i = 0; i < n; i++ )
        {
            cin >> p[i].x >> p[i].y >> b[i].x >> b[i].y;
        }

        for( int i = 0; i < n; i++ )
        {
            for( int j = i + 1; j < n; j++ )
            {
                if( inter(p[i], b[i], p[j], b[j] ) )
                {
                    ans[i] = 1;
                    break;              //TLE without break
                }
            }
        }
        int ct = 0;
        cout << "Top sticks: ";
        for( int i = 0; i < n; i++ ) {
            if( !ans[i] )  
                res[ct++] = i + 1;
        }
        
        for( int i = 0; i < ct - 1; i++ ) {
            cout << res[i] << ", ";
        }
        cout << res[ct-1] << "." << endl;
    }
    return 0;
}
