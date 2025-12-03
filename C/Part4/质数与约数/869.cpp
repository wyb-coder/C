#include<bits/stdc++.h>
using namespace std;
const int INF = 1000010, MX = 0x3f3f3f3f;

// 1~N的所有约数
vector<int> res;
void getDivisors(int N){
    for(int i = 1; i <= N / i; i++){
        if(N % i == 0){
            res.push_back(i);
            if(N / i != i) res.push_back(N / i);
        }
    }
    sort(res.begin(), res.end());
}

int main(){
    int N;
    cin >> N;
    while(N--){
        int temp;
        cin >> temp;
        getDivisors(temp);
        for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
        res.clear();
    }
}