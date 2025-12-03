#include<bits/stdc++.h>
using namespace std;

// A/B 余R
vector<int> Div(vector<int> &A, int B, int &R){
    vector<int> res;
    R = 0;
    for(int i = A.size() - 1; i >= 0; i--){
        R = R * 10 + A[i];
        res.push_back(R / B);
        R %= B;
    }
    reverse(res.begin(), res.end());
    while(res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

int main(){
    string num1;
    int B = 0, R = 0;
    vector<int> A, res;
    cin >> num1 >> B;
    for(int i = num1.size() - 1; i >= 0; i--) A.push_back(num1[i] - '0');
    res = Div(A, B, R);
    for(int i = res.size() - 1; i >= 0; i--) cout << res[i]; 
    cout << endl << R;

}