#include<bits/stdc++.h>
using namespace std;
const int INF = 100010;

vector<pair<int, int>> res;
// 区间合并
void InterMerge(vector<pair<int, int>> &A){
    sort(A.begin(), A.end());
    int left = -1e9 - 1, right = -1e9 - 1;
    for(int i = 0; i < A.size(); i++){
        if(right < A[i].first){
            if(left != (-1e9 - 1)) res.push_back({left, right});
            left = A[i].first;
            right = A[i].second;
        }
        else right = max(right, A[i].second);
    }
    if(left != (-1e9 - 1)) res.push_back({left, right});
}

int main(){
    int N;
    vector<pair<int, int>> A;
    cin >> N;
    while(N--){
        int left, right;
        cin >> left >> right;
        A.push_back({left, right});
    }
    InterMerge(A);
    cout << res.size();
}