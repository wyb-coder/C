#include<bits/stdc++.h>
using namespace std;
const int INF = 110;

// 状态A -> B 做为图的一个分支，最终正确分支只有一个
// BFS求最短分支
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
string endState = "12345678x";
int bfs(string start){
    // dis存储每个状态的路径长度，找到一个新的路径就 + 1(新状态);
    unordered_map<string, int> dis;
    queue<string> q;
    q.push(start);
    dis[start] = 0;
    while(!q.empty()){
        string state = q.front();
        q.pop();
        // state会一直被修改，保存;
        int distance = dis[state];
        if(state == endState) return distance;
        int idx = state.find('x');
        int x = idx / 3, y = idx % 3;
        for(int i = 0; i < 4; i++){
            int tx = x + dx[i], ty = y + dy[i];
            if(tx >= 0 && tx < 3 && ty >= 0 && ty < 3){
                // 修改状态的值，一会还要恢复
                swap(state[idx], state[tx * 3 + ty]);
                // BFS一定是第一次扫到的最近，是逐步向目标的，反复扫到必然回头了，不取
                if(!dis.count(state)){
                    dis[state] = distance + 1;
                    q.push(state);
                }
                // 具体后面选哪个状态由队列决定，因此要恢复，继续以原状态试探
                swap(state[idx], state[tx * 3 + ty]);
            }
        }
    }
    return -1;
}

int main(){
    char c;
    string str;
    for(int i = 0; i < 9; i++){
        cin >> c;
        str += c;
    }
    cout << bfs(str);
}