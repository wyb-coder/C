#include<bits/stdc++.h>
using namespace std;
const int INF = 110;

// graph存储地图，dis存储到源点距离,初始值是-1
int N, M, graph[INF][INF], dis[INF][INF];
// 利用数组枚举上下左右四个点
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
void bfs(){
    queue<pair<int, int>> q;
    q.push({0, 0});
    //到源点距离,初始值是-1
    memset(dis, -1, sizeof(dis));
    dis[0][0] = 0;
    while(!q.empty()){
        pair<int, int> temp = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int x = temp.first + dx[i];
            int y = temp.second + dy[i];
            // 判断dis，不能被走过，否侧不是最短
            if((x >= 0 && x < N) && (y >= 0 && y < M) && !graph[x][y] && dis[x][y] == -1){
                q.push({x, y});
                dis[x][y] = dis[temp.first][temp.second] + 1;
            }
        }
    }
}


int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) cin >> graph[i][j]; 
    bfs();
    cout << dis[N - 1][M - 1];
}