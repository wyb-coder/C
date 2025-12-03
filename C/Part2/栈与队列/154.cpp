#include<bits/stdc++.h>
using namespace std;
const int INF = 1000010;

// 单调队列 + 双端队列，用数组模拟，以便判断是否在窗口内
// 尾进头出
int main(){
    int N, K, A[INF] = {0}, res[INF] = {0};
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> A[i];
    int head = 0, tail = -1;
    for(int i = 0; i < N; i++){
        if(head <= tail && res[head] < i - K + 1) head++;
        while(head <= tail && A[i] <= A[res[tail]]) tail--;
        // 元素已经存在A[]中了，因此队列中一定是位序
        res[++tail] = i;
        // 让前面的元素先填满窗口
        if(i >= K - 1) cout << A[res[head]] << " ";
    }
    cout << endl;
    head = 0, tail = -1;
    for(int i = 0; i < N; i++){
        if(head <= tail && res[head] < i - K + 1) head++;
        while(head <= tail && A[i] >= A[res[tail]]) tail--;
        res[++tail] = i;
        if(i >= K - 1) cout << A[res[head]] << " ";
    }
}