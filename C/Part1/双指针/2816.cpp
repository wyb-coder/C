#include<bits/stdc++.h>
using namespace std;
const int INF = 100010;

// 如果子序列存在，双指针一定能找到
int main(){
    long long int N, M, A[INF], B[INF], K = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    for(int i = 0; i < M; i++) if(A[K] == B[i]) K++;
    if(K >= N) cout << "Yes";
    else cout << "No";
}