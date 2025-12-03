#include<bits/stdc++.h>
using namespace std;
const int INF = 100010;

// Trie树:高效存储查找字符串集合(字典树)
// son[]存储Trie树的逻辑关系，为当前节点的儿子节点的序号
// 理解为，二叉树每一层都有A-Z种可能，各层分开考虑，但凡终点相同就向下走
// idx保证了每个节点都有作为终点的机会
int son[INF][26] = {0}, cnt[INF] = {0}, idx = 0;
void insertTrie(string str){
    int pos = 0;
    for(int i = 0; i < str.size(); i++){
        int ti = str[i] - 'a';
        if(!son[pos][ti]) son[pos][ti] = ++idx;
        pos = son[pos][ti];
    }
    cnt[pos]++;
}
int queryTrie(string str){
    int pos = 0;
    for(int i = 0; i < str.size(); i++){
        int ti = str[i] - 'a';
        if(!son[pos][ti]) return 0;
        pos = son[pos][ti];
    }
    return cnt[pos];
}

int main(){
    int N;
    cin >> N;
    while(N--){
        char op;
        string str;
        cin >> op >> str;
        if(op == 'I') insertTrie(str);
        else {
            int res = queryTrie(str);
            cout << res << endl;
        }
    }
}