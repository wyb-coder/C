#include<bits/stdc++.h>
using namespace std;
const int INF = 100010;

// 双指针就找单调性、固定一个，找另一个的单调性
// 固定i,对j而言，A[i] + B[j] >= Num,此时i向后移动，则j向左
// 则，只用寻找左侧
int main(){
    int N, M, X, A[INF], B[INF];
    cin >> N >> M >> X;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    for(int i = 0, j = M - 1; i < N; i++){
        while(j >= 0 && A[i] + B[j] > X) j--;
        if(A[i] + B[j] == X){
            cout << i << " " << j;
            break;
        }
    }
}