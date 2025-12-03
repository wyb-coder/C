#include<bits/stdc++.h>
using namespace std;
const int INF = 100010;

// 使用静态链表模拟，则第K个插入的节点必在K - 1下标
// 使用两个数组模拟，快
// A节点数值、next指针、head头节点、idx当前索引可分配
// 这里的head是头指针，不具备实体，所以最开始是-1
// 理解为，-1为尾指针所在索引，所以开始head -> -1
int node[INF], nextNode[INF], head, idx;

void initLinkList(){
    head = -1; idx = 0;
}
// 插头结点
void addToHead(int num){
    node[idx] = num;
    nextNode[idx] = head;
    head = idx;
    idx++;
}
// 插普通，下标是inode的节点后面
void add(int inode, int num){
    node[idx] = num;
    nextNode[idx] = nextNode[inode];
    nextNode[inode] = idx;
    idx++;
}
// 删除下标inode后面的
void remove(int inode){
    // 特判删除头节点
    if(inode == -1) head = nextNode[head];
    nextNode[inode] = nextNode[nextNode[inode]];
}

int main(){
    int M;
    cin >> M;
    initLinkList();
    while(M--){
        char op;
        int tidx, num;
        cin >> op;
        if(op == 'H'){
            cin >> num;
            addToHead(num);
        } else if (op == 'D'){
            cin >> tidx;
            remove(tidx - 1);
        } else {
            cin >> tidx >> num;
            add(tidx - 1, num);
        }
    }
    // 第一步就插入头节点 + head初始等于-1，保证了在-1时结束
    for(int i = head; i != -1;i = nextNode[i]) cout << node[i] << " ";
}