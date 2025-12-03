#include<bits/stdc++.h>
using namespace std;
const int INF = 1000010, MX = 0x3f3f3f3f;
typedef pair<int, int> PII;

// 观察点的编号的范围，较大则默认稀疏图，仅能使用邻接表存储
// 默认所有结点先存权值，再存编号,不用考虑重复边，全存了，算法自动
int dis[INF], N, M;
bool use[INF];
vector<PII> gp[INF];
priority_queue<PII, vector<PII>, greater<PII>> heap;
int dijkstra(){
    dis[1] = 0;
    heap.push({0, 1});
    while(!heap.empty()){
        // 取出的直接就是距离最短的
        PII temp = heap.top();
        heap.pop();
        int distance = temp.first, idx = temp.second;
        if(use[idx]) continue;
        use[idx] = true;
        // 更新遍历也直接在单一邻接表中遍历即可，因为下一个选的也必定是以当前为头的
        for(int i = 0; i < gp[idx].size(); i++){
            int j = gp[idx][i].second, val = gp[idx][i].first;
            if(dis[j] > dis[idx] + val){
                dis[j] = dis[idx] + val;
                heap.push({dis[j], j});
            }
        }
    }
    if(dis[N] == MX) return -1;
    else return dis[N];
}

int main(){
    cin >> N >> M;
    memset(dis, MX, sizeof(dis));
    while(M--){
        int x, y, z;
        cin >> x >> y >> z;
        gp[x].push_back({z, y});
    }
    cout << dijkstra();
}