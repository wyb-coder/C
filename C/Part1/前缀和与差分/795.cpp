#include<bits/stdc++.h>
using namespace std;

#define INF 100010

// 前缀和，使用逆向思维,求哪一区间就用不同前缀和减
int main(){
    int N, M, sum = 0, PSum[INF];
    cin >> N >> M;
    PSum[0] = 0;
    vector<int> res;
    for(int i = 1; i <= N; i++){
        cin >> PSum[i];
        PSum[i] += PSum[i - 1];
    }
    for(int i = 0; i < M; i++){
        int t1, t2;
        cin >> t1 >> t2;
        res.push_back(PSum[t2] - PSum[t1 - 1]);
    }
    for(int i = 0; i < res.size(); i++) cout << res[i] << endl;
}