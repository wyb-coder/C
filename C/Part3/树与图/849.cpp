#include<bits/stdc++.h>
using namespace std;
const int MX = 510, INF = 0x3f3f3f3f;

// 贪心，带权有向图用邻接矩阵存，dis表示距离
// use表示是否已经加入了贪心集合
// 显然使用use会多循环几次，但再优化也是N^2，不会卡
// dijkstra仅试用于权值全正
int val[MX][MX], dis[MX], N, M;
bool use[MX];
int dijkstra(){
    dis[1] = 0;
    for(int i = 0;i < N - 1; i++){
        int temp = -1;
        // 找到当前距离集合最近的点
        for(int j = 1; j <= N; j++){
            // temp = -1一定过是因为，最终一定要加一个点进入集合
            if(!use[j] && (temp == -1 || dis[temp] > dis[j])){
                    temp = j;
            }
        }
        // 更新距距离，无论是否在集合，都要更新经过temp
        // 实际上集合内的无需再更新，但此算法时间复杂度没那么重要
        for(int j = 1; j <= N; j++){
            dis[j] = min(dis[j], dis[temp] + val[temp][j]);
        }
        use[temp] = true;
    }
    if(dis[N] == INF) return -1;
    else return dis[N];
}

int main(){
    cin >> N >> M;
    memset(val, INF, sizeof(val));
    memset(dis, INF, sizeof(dis));
    while(M--){
        int x, y, z;
        cin >> x >> y >> z;
        val[x][y] = min(val[x][y], z);
    }
    cout << dijkstra();
}