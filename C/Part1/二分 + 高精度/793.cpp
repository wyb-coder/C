#include <bits/stdc++.h>
using namespace std;

// B较小、每次取A的一位×B，再算进位，默认全正
vector<int> Mul(vector<int> A, int B){
    vector<int> res;
    int temp = 0;
    for(int i = 0; i < A.size() || temp > 0; i++){
        if(i < A.size()) temp += A[i] * B;
        res.push_back(temp % 10);
        temp /= 10;
    }
    while(res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

int main(){
    string num1;
    int B;
    vector<int> A, res;
    bool flag = true;
    cin >> num1 >> B;
    for(int i = num1.size() - 1; i > 0; i--) A.push_back(num1[i] - '0');
    if(num1[0] != '-') A.push_back(num1[0] - '0');
    else flag = !flag;
    if(B < 0) flag = !flag, B = -B;
    if(B == 0){
        cout << "0";
        return 0;
    }
    if(!flag) cout << "-";
    res = Mul(A, B);
    for(int i = res.size() - 1; i >= 0; i--) cout << res[i];
}