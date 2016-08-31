#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

const int maxn = 20000;
const int MAXN = 100000+10;

using std :: string;
using std :: cout;
using std :: endl;

int main()
{
    string ans[MAXN];
    char tel[maxn];
    char store[maxn];
    int n;
    bool ok;
   while(~ scanf("%d",&n))
    {
        ok = false;
        int count = 0;
        while(n--)
        {
            scanf("%s",tel);
            int j;
            for(int i = 0,j = 0; tel[i] != '\0'; i++)
            {
                if(tel[i]-'0'>=0&&tel[i]-'0'<=9)
                      store[j++] = tel[i];
                else if(tel[i] != '-' && j != 3 )
                {
                    //ans[count]+='2';
                    if(tel[i]=='A'||tel[i]=='B'||tel[i]=='C')
                            store[j++] = '2';
                    else if(tel[i]=='D'||tel[i]=='E'||tel[i]=='F')
                            store[j++] = '3';
                    else if(tel[i]=='G'||tel[i]=='H'||tel[i]=='I')
                            store[j++] = '4';
                    else if(tel[i]=='J'||tel[i]=='K'||tel[i]=='L')
                            store[j++] = '5';
                    else if(tel[i]=='M'||tel[i]=='N'||tel[i]=='O')
                            store[j++] = '6';
                    else if(tel[i]=='P'||tel[i]=='R'||tel[i]=='S')
                            store[j++] = '7';
                    else if(tel[i]=='T'||tel[i]=='U'||tel[i]=='V')
                            store[j++] = '8';
                    else if(tel[i]=='W'||tel[i]=='X'||tel[i]=='Y')
                            store[j++] = '9';
                }
                if( j==3 )  store[j++]='-';
            }
            ans[count++] = store;
        }
        std :: sort(ans,ans+count);
        int ans_count;
        for(int i = 0; i < count; i++)
        {
             ans_count = 1;
             for(int j = i + 1; j < count; j++)
             {
                 if(ans[j]==ans[i]) ans_count++;
                 else break;
             }
             if(ans_count > 1)
             {
                 ok = true;
                 cout << ans[i] << " " << ans_count << endl;
                 i+=(ans_count-1);
             }
        }
        if(!ok)  cout << "No duplicates." << endl;

        //for(int i = 0; i <count; i++)
        //std :: cout << ans[i] << std :: endl;
    }
    return 0;
}
