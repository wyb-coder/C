#include<bits/stdc++.h>
using namespace std;
const int INF = 100;

// chess代表棋盘,dfs每次在每一行中选可行的一列
// 这个选择的过程也就包含了剪枝
int N;
char chess[INF][INF];
bool col[INF], dg[INF], udg[INF];

void dfs(int idx){
    if(idx == N){
        // 方便的输出二维方阵
        for(int i = 0; i < N; i++) puts(chess[i]);
        cout << endl;
    }
    for(int i = 0; i < N; i++){
        // 用dg、udg标明每一个对角线、反对角线、col标记本列
        if(!col[i] && !dg[N - idx + i] && !udg[idx + i]){
            chess[idx][i] = 'Q';
            col[i] = dg[N - idx + i] = udg[idx + i] = true;
            dfs(idx + 1);
            col[i] = dg[N - idx + i] = udg[idx + i] = false;
            chess[idx][i] = '.';
        }
    }
}

int main(){
    cin >> N;
    // 初始化
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) chess[i][j] = '.';
    dfs(0);
}