#include<bits/stdc++.h>
using namespace std;
const int INF = 100010;

// i, j双指针，一般为就j落后于i，向后扫描而不是向前
// 最长不重复序列中，j能切仅能向右移动
// 双指针是动态的，每次检查移动的i是否符合条件即可
// 记得初始化
int main(){
    int N, A[INF], Tub[INF] = {0}, res = 0;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0, j = 0; i < N; i++){
        Tub[A[i]]++;
        while(j < i && Tub[A[i]] > 1) Tub[A[j]]--, j++;
        res = max(res, i - j + 1);
    }
    cout << res;
}