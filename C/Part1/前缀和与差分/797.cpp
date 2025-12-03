#include<bits/stdc++.h>
using namespace std;
#define INF 100010
// 差分、前缀和的逆，A -> B的前缀和，B为A的差分 B[n] = A[n] - A[n - 1]
// B的前缀和是A， B[r] + C = A[r, N] + C
int main(){
    int N, M, A[INF], DSum[INF] = {0}, res[INF] = {0};
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> A[i];
    for(int i = 1; i <= N; i++) DSum[i] = A[i] - A[i - 1];
    while(M--){
        int left, right, num;
        cin >> left >> right >> num;
        DSum[left] += num;
        DSum[right + 1] -= num;
    }
    for(int i = 1; i <= N; i++) res[i] = res[i - 1] + DSum [i];
    for(int i = 1; i <= N; i++) cout << res[i] << " ";
}