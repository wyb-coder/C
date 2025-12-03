#include<bits/stdc++.h>
using namespace std;
const int INF = 100010;

// 排列数字,假设空位,递归的用DFS搜索,回溯现场
// path保存当前路径,use检查某个数字是否被用过
int path[INF], N;
bool use[INF];
void dfs(int idx){
    if(idx == N){
        for(int i = 0; i < N; i++) cout << path[i] << " ";
        cout << endl;
    } else {
        for(int i = 1; i <= N; i++){
            if(!use[i]){
                path[idx] = i;
                use[i] = true;
                dfs(idx + 1);
                use[i] = false;
            }
        }
    }
}

int main(){
    cin >> N;
    dfs(0);
    
}