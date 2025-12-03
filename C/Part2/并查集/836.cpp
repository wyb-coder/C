#include<bits/stdc++.h>
using namespace std;
const int INF = 100010;

int father[INF] = {0};

// 返回集合所在根节点的编号
// 路径压缩 + 查询
int findRoot(int idx){
    if(father[idx] != idx) father[idx] = findRoot(father[idx]);
    return father[idx];
}

int unionSet(int x, int y){
    father[findRoot(x)] = findRoot(y); 
}

int main(){
    int N, M;
    cin >> N >> M;
    // 每个元素开始都自己为一个集合
    for(int i = 1; i <= N ; i++) father[i] = i;
    while(M--){
        char op;
        int a, b;
        cin >> op >> a >> b;
        if(op == 'M'){
            unionSet(a, b);
        } else {
            if(findRoot(a) == findRoot(b)) cout << "Yes";
            else cout << "No";
        }
    }
}