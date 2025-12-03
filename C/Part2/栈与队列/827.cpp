#include<bits/stdc++.h>
using namespace std;
const int INF = 100010;

int node[INF], nodeLeft[INF], nodeRight[INF], idx;

// 使用头节点和尾节点,定为0与1
void initDLinkList(){
    nodeLeft[1] = 0;
    nodeRight[0] = 1;
    idx = 2;
}

// 在目标索引inode的右侧插入,注意顺序
void insertInRight(int inode, int num){
    node[idx] = num;
    nodeLeft[idx] = inode;
    nodeRight[idx] = nodeRight[inode];
    nodeLeft[nodeRight[inode]] = idx;
    nodeRight[inode] = idx;
    idx++;
}
// 删除inode,从2开始，则调用时remove(k + 1)
void remove(int inode){
    nodeRight[nodeLeft[inode]] = nodeRight[inode];
    nodeLeft[nodeRight[inode]] = nodeLeft[inode];

}

int main(){
    int M;
    cin >> M;
    initDLinkList();
    while(M--){
        string op;
        cin >> op;
        int tidx, num;
        if(op == "L"){
            cin >> num;
            insertInRight(0, num);
        } else if (op == "R"){
            cin >> num;
            insertInRight(nodeLeft[1], num);
        } else if (op == "D"){
            cin >> tidx;
            remove(tidx + 1);
        } else if (op == "IL"){
            cin >> tidx >> num;
            insertInRight(nodeLeft[tidx + 1], num);
        } else {
            cin >> tidx >> num;
            insertInRight(tidx + 1, num);
        }
    }
    for(int i = nodeRight[0]; i != 1; i = nodeRight[i])
        cout << node[i] << " ";
}