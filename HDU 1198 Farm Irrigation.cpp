#include<iostream>
using namespace std;

int bin[2500];

int find(int x)
{return x==bin[x]?x:find(bin[x]);}

void merge(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x!=y) bin[x]=y;
}

int main()
{
    int a[11] = {9, 3, 12, 6, 5, 10, 11, 13, 14, 7, 15}, m, n, i, j, map[50][50], total;
    char c;
    while(scanf("%d %d", &m, &n), m != -1 || n != -1){
        getchar();
        for(i = 0; i < m; ++i){
            for(j = 0; j < n; ++j){
                scanf("%c", &c);
                map[i][j] = c - 65;
            }
            getchar();
        }
        for(i = 0; i < m * n; ++i) bin[i] = i;
        for(i = 0; i < m; ++i)
            for(j = 0; j < n; ++j){
                if(i + 1 < m && a[map[i][j]] & 0x04 && a[map[i + 1][j]] & 0x01)
                    merge(i * n + j, i * n + n + j);
                if(j + 1 < n && a[map[i][j]] & 0x02 && a[map[i][j + 1]] & 0x08)
                    merge(i * n + j, i * n + j + 1);
            }
        for(total = 0, i = 0; i < m * n; ++i)
            if(i == bin[i]) ++total;
        printf("%d\n", total);
    }
    return 0;
}
