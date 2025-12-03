#include <bits/stdc++.h>
using namespace std;

// 逆向存储、逆向思维，便于最高位进位、低位对齐
vector<int> Add(vector<int> &A, vector<int> &B){
    int temp = 0, fp = 0;
    vector<int> res;
    for(int i = 0; i < A.size(); i++){
        temp = A[i] + fp;
        if(i < B.size()) temp += B[i];
        if(temp >= 10){
            res.push_back(temp % 10);
            fp = 1;
        } else {
            res.push_back(temp);
            fp = 0;
        }
    }
    // 最高位进位
    if(fp != 0) res.push_back(fp);
    while(res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

int main(){
    string num1, num2;
    cin >> num1 >> num2;
    vector<int> A, B, res;
    for(int i = num1.size() - 1; i >= 0; i--) A.push_back(num1[i] - '0');
    for(int i = num2.size() - 1; i >= 0; i--) B.push_back(num2[i] - '0');
    if(A.size() > B.size()) res = Add(A, B);
    else res = Add(B, A);
    for(int i = res.size() - 1; i >= 0; i--) cout << res[i];
}

