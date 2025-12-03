#include<bits/stdc++.h>
using namespace std;
const int INF = 100010;

int main(){
    int N, M, temp;
    cin >> N >> M;
    priority_queue<int, vector<int>, greater<int>> heap;
    vector<int> res;
    for(int i = 0; i < N; i++){
        cin >> temp;
        heap.push(temp);
    }
    for(int i = 0; i < M; i++){
        cout << heap.top() << " ";
        heap.pop();
    }
}