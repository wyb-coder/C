#include<bits/stdc++.h>
using namespace std;
const int INF = 1000010;

vector<int> gp[INF];
int N, M, dis[INF];
bool use[INF];
void bfs(int start){
    memset(dis, -1, sizeof(dis));
    queue<int> q;
    q.push(start);
    use[start] = true;
    dis[start] = 0;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i : gp[temp]){
            if(!use[i]){
                dis[i] = dis[temp] + 1;
                q.push(i);
                use[i] = true;
            }
        }
    }
}

int main(){
    cin >> N >> M;
    while(M--){
        int n1, n2;
        cin >> n1 >> n2;
        gp[n1].push_back(n2);
    }
    bfs(1);
    cout << dis[N];
}