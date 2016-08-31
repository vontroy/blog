/**
Stable Sort
**/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct DNA
{
    int pos;
    int cnt;
    string str;
};

bool cmp(const DNA &a, const DNA &b)
{
    if (a.cnt != b.cnt)
    {
        return a.cnt < b.cnt;
    }
    else
    {
        return a.pos < b.pos;
    }
}

int main()
{
    int n, m, count;
    DNA ans[110];
    string str;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> str;
        count = 0;
        
        for (int j = 0; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
                if (str[j] > str[k]) count++;
                
        ans[i].str = str;
        ans[i].cnt = count;
        ans[i].pos = i;
    }

    sort(ans, ans + m, cmp);

    for (int i = 0; i < m; i++)
        cout << ans[i].str << endl;

    return 0;
}
