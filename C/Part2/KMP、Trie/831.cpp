#include<bits/stdc++.h>
using namespace std;
const int INF = 1000010;

// KMP next[4],默认1-4,则为前三个元素的最长重复前序序列
// next[i] = j -> p[1 ~ j] = p[(j - i+ 1) ~ i]
// 例如 abab -> 2,同向扫描,则可不用移至最前到序号3即可重新匹配
// 因此先对模式串进行处理
int main(){
    char S[INF], P[INF];
    int N, M, nextidx[INF] = {0};
    // 从1开始读入
    cin >> N >> P + 1 >> M >> S + 1;
    // nextidx[1] = 0;
    for(int i = 2, j = 0; i <= N; i++){
        while(j > 0 && P[i] != P[j + 1]) j = nextidx[j];
        if(P[i] == P[j + 1]) j++;
        nextidx[i] = j;
    }
    // 每次都是S[i]与P[i + 1]作比较
    for(int i = 1, j = 0; i <= M; i++){
        while(j > 0 && S[i] != P[j + 1]) j = nextidx[j];
        if(S[i] == P[j + 1]) j++;
        if(j == N){
            cout << i - N << " ";
            j = nextidx[j];
        }
    }
}