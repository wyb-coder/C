#include<bits/stdc++.h>
using namespace std;
const int INF = 100010;

int father[INF] = {0}, dis[INF] = {0};
// 思路，维护到根节点的距离，0 - 1 - 2
// 1吃0、2吃1、0吃2，下层吃上层，再利用模运算
// 没有Union函数，同类和不同类关系合并操作不同
int find(int idx){
    if(father[idx] != idx){
        int temp = find(father[idx]);
        // 不能先更新，先更新父节点的dis未必就到根，要先递归
        // 若不保存，原来的父节点直接变成根，数据丢失了
        dis[idx] += dis[father[idx]];
        father[idx] = temp;
    }
    return father[idx];
}
int main(){
    int N, M, res = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++) father[i] = i, dis[i] = 0;
    while(M--){
        int op, x, y;
        cin >> op >> x >> y;
        if(x > N || y > N) res++;
        else {
            int rx = find(x), ry = find(y);
            if(op == 1){
                if(rx == ry && (dis[x] - dis[y]) % 3 != 0) res++;
                else if (rx != ry){                     
                    father[rx] = ry;
                    // (x + rx - y) % 3 = 0 画抽象集合树
                    dis[rx] = dis[y] - dis[x];
                }
            } else {
                if(rx == ry && (dis[x] - dis[y] - 1) % 3 != 0) res++;
                else if (rx != ry){
                    father[rx] = ry;
                    // (x + rx - 1 - y) % 3 = 0
                    dis[rx] = dis[y] - dis[x] + 1;
                }
            }
        }
    }
    cout << res;
}