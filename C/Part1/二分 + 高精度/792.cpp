#include<bits/stdc++.h>
using namespace std;

#define N 100010

// 直接使用字符串比较会有奇怪的bug
// 一定是计算大的减小的，避免最高位借位麻烦
bool Cmp(vector<int> &A, vector<int> &B){
    if(A.size() != B.size()) return A.size() > B.size();
    for(int i = A.size() - 1;i >= 0; i--){
        if(A[i] != B[i]) return A[i] > B[i];
    }
    return true;
}

vector<int> Sub(vector<int> &A, vector<int> &B){
    vector<int> res;
    int temp = 0, fp = 0;
    for(int i = 0;i < A.size();i++){
        temp = A[i] + fp;
        // 无需再填满，默认让进入的长的减小的
        if(i < B.size()) temp -= B[i];
        if(temp < 0){
            res.push_back(temp + 10);
            fp = -1;
        } else {
            res.push_back(temp);
            fp = 0;
        }
    }
    while(res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

int main(){
    string num1, num2;
    vector<int> res;
    cin >> num1 >> num2;
    vector<int> A, B;
    for(int i = num1.size() - 1;i >= 0;i--) A.push_back(num1[i] - '0');
    for(int i = num2.size() - 1;i >= 0;i--) B.push_back(num2[i] - '0');
    if(Cmp(A, B)){
        res = Sub(A, B);
    } else {    
        cout << "-";
        res = Sub(B, A);
    }
    for(int i = res.size() - 1;i >= 0;i--) cout << res[i];
}