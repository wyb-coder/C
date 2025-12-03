#include<bits/stdc++.h>
using namespace std;
const int INF = 100010, M = 10000000;

// 异或，指二进制进行异或 1 3 -> 01 11 -> 10 -> 2
// 用Trie树存取0、1
int son[M][2] = {0}, idx = 0;
void insert(int num){
    int pos = 0;
    for(int i = 30; i >=0; i--){
        int temp = (num >> i) & 1;
        if(!son[pos][temp]) son[pos][temp] = ++idx;
        pos = son[pos][temp];
    }
}

int query(int num){
    int pos = 0, res = 0;
    for(int i = 30; i >=0; i--){
        int temp = (num >> i) & 1;
        if(son[pos][!temp]){
            res += 1 << i;
            pos = son[pos][!temp];
        } else {
            pos = son[pos][temp];
        }
    }
    return res;
}

int main(){
    int N, A[INF];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        insert(A[i]);
    }
    int res = -1;
    for(int i = 0; i < N; i++){
        res = max(res, query(A[i]));
    }
    cout << res;
}