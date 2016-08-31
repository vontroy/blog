#include <iostream>  
#include <cstdio>  
#include <string> 
 
using namespace std;
  
const int maxn = 301;  

string str1, str2;  

int main()  
{  
    while( cin >> str1 >> str2 )  
    {  
        int dp[maxn][maxn] = {0};  
        int len1 = str1.length();  
        int len2 = str2.length();  
        for( int i = 1; i <= len1; i++ )  
            for( int j = 1; j <= len2; j++ )  
            {  
                if( str1[i - 1] == str2[j - 1] )  
                    dp[i][j] = dp[i - 1][j - 1] + 1;  
                else  
                    dp[i][j] = max( dp[i][j - 1], dp[i - 1][j] );  
            }  
        printf("%d\n", dp[len1][len2]);  
    }  
    return 0;  
}  
