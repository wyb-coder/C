#include<bits/stdc++.h>
using namespace std;
#define INF 1010

int main(){
    int N, M, Q, Mix[INF][INF] = {0}, PSum[INF][INF] = {0}, temp = 0;
    vector<int> res;
    cin >> N >> M >> Q;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> PSum[i][j];
            PSum[i][j] += PSum[i][j - 1] + PSum[i - 1][j] - PSum[i - 1][j - 1];
        }
    } 
    while(Q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        res.push_back(PSum[x2][y2] - PSum[x2][y1 - 1] - PSum[x1 - 1][y2] + PSum[x1 - 1][y1 - 1]);
    }
    for(int i = 0; i < res.size(); i++) cout << res[i] << endl;
}