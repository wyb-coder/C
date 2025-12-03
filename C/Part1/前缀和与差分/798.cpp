#include<bits/stdc++.h>
using namespace std;
#define INF 1010

// 可以不用想构造，0矩阵的差分矩阵也是0矩阵
// 矩阵A与其差分矩阵B是一一对应的
// 每次对A矩阵的每一个点 + C, 使用差分矩阵的算法对B进行插入，则生成差分矩阵
// 差分矩阵是对右下角包括本身全部 + C
void Insert(int B[][INF], int x1, int y1, int x2, int y2, int num){
    B[x1][y1] += num; B[x2 + 1][y2 + 1] += num;
    B[x1][y2 + 1] -= num; B[x2 + 1][y1] -= num; 
}

int main(){
    int A[INF][INF] = {0}, B[INF][INF] = {0}, N, M, Q;
    cin >> N >> M >> Q;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> A[i][j];
            Insert(B, i, j, i, j, A[i][j]);
        }
    }
    while(Q--){
        int x1, y1, x2, y2, num;
        cin >> x1 >> y1 >> x2 >> y2 >> num;
        Insert(B, x1, y1, x2, y2, num);
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            B[i][j] += B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1];
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
}