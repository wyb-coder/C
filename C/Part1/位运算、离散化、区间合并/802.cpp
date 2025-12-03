#include<bits/stdc++.h>
using namespace std;
const int INF = 300010;

// 离散:将离散的数字(数轴上，但个数较少)映射到连续的数组中
// (1)去重    (2)用二分找映射关系

// 离散化 + 前缀和; 正负被二分映射为了正整数
// 传入参数过多会显著降低速度，能开全局就全局
vector<int> All;
int findIndexByBS(int num){
    int left = 0, right = All.size() - 1, mid;
    while(left < right){
        mid = (left + right) >> 1;
        if(All[mid] >= num) right = mid;
        else left = mid + 1;
    }
    return right + 1;
    // 为了前缀和,离散到1...N
}  

int main(){
    vector<pair<int, int>> Add, Query;
    int N, M, A[INF] = {0}, res[INF] = {0};
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int X, C;
        cin >> X >> C;
        All.push_back(X);
        Add.push_back({X, C});
    }
    for(int i = 0; i < M; i++){
        int left, right;
        cin >> left >> right;
        All.push_back(left);
        All.push_back(right);
        Query.push_back({left, right});
    }
    // 去重
    sort(All.begin(), All.end());
    All.erase(unique(All.begin(), All.end()), All.end());
    // 处理插入
    for(int i = 0; i < Add.size(); i++){
        int temp = findIndexByBS(Add[i].first);
        A[temp] += Add[i].second;
    }
    // 计算前缀和,数组上限不会超过All中元素个数
    for(int i = 1; i <= All.size(); i++) res[i] = res[i - 1] + A[i];
    // 处理询问
    for(int i = 0; i < Query.size(); i++){
        int left = Query[i].first, right = Query[i].second;
        left = findIndexByBS(left);
        right = findIndexByBS(right);
        cout << res[right] - res[left - 1] << endl;
    }
    return 0;
}