#include<bits/stdc++.h>
using namespace std;
const int INF = 100010;

// 单调栈，左侧第一个比其小的
// 一般化，if(Ax >= Ay && x < y)x在y左侧,则x永远不会被选中
// 则每次有新的元素进入，都判定是否可以出栈栈顶元素(当前更优)
// 单调的意思是，删去无用的，剩下的必然单调
int main(){
    int N;
    stack<int> res;
    cin >> N;
    while(N--){
        int num;
        cin >> num;
        while(res.size() > 0 && res.top() >= num) res.pop();
        if(res.size() > 0) cout << res.top() << " ";
        else cout << "-1 ";
        res.push(num);
    }
}