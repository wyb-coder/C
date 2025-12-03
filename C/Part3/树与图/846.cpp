#include<bits/stdc++.h>
using namespace std;
const int INF = 1000010;

// 使用vector存储图
vector<int> gp[INF];
bool use[INF];
int ans = INF, N;
// 本质还是暴力,返回以idx节点为根的子树的节点数
int dfs(int idx){
    // sum是子树的节点数，size是用于判断点数的最大值
    int sum = 1, size = 0;
    use[idx] = true;
    for(int i : gp[idx]){
        if(!use[i]){
            // 儿子是节点i的,以i为根的子树的节点数要求一个最大
            int tsum = dfs(i);
            size = max(size, tsum);
            // sum用于最终减去，求上面那一部分的总数
            sum += tsum;
        }
    }
    size = max(size, N - sum);
    ans = min(ans, size);
    return sum;
}

int main(){
    cin >> N;
    for(int i = 1; i < N; i++){
        int n1, n2;
        cin >> n1 >> n2;
        gp[n1].push_back(n2);
        gp[n2].push_back(n1);
    }
    dfs(1);
    cout << ans;
}