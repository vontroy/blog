/**
如图，每条路径上保存一个字母，从根节点开始进行dfs，每遍历到一个标记节点（图中的红点），从根节点到当前节点路径上所有字母连起来即为一个单词
上图中存储了 abc, abcd, b, bcd, efg, hij.
对于Trie树主要有三种操作：
新建一个结点
插入一个单词
在trie树中查找单词
trie树中每次插入一个结点的时间复杂度是 O( strlen( str ) )
建立trie树的时间复杂度为 O( ∑strlen( str[i] ) )
对于每个单词，查询的时间复杂度为 O( strlen( str ) )
**/

struct node  
{  
    int flag;     //The end of a word  
    node* next[26];  
};  

node* newnode()  
{  
    node* p = new node;  
  
    p->flag = 0;  
  
    for( int i = 0; i < 26; i++ )  
        p->next[i] = NULL;  
  
    return p;  
}

void trie_insert( node* root, char* s )  
{  
    node* p = root;  
    int len = strlen( s );  
  
    int tmp;  
    for( int i = 0; i < len; i++ )  
    {  
        tmp = s[i] - 'a';  
        if( p->next[tmp] == NULL )  
            p->next[tmp] = newnode();  
        p = p->next[tmp];  
    }  
    p->flag = 1;  
}

int trie_search( node* root, char* s )  
{  
    node* p = root;  
    int len = strlen( s );  
  
    int tmp;  
    for( int i = 0; i < len; i++ )  
    {  
        tmp = s[i] - 'a';  
        if( p->next[tmp] == NULL )         //not matched  
            return 0;  
        p = p->next[tmp];  
    }  
  
    if( p->flag )     //match && it is a word which has been stored  
    return 1;  
    return 0;  
}  
