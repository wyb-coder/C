#include <bits/stdc++.h>
using namespace std;

// 二分最左侧的待定值
int bianrySearchlLeft(int arr[], int left, int right, int num){
    while(left < right){
        int mid = (left + right) >> 1;
        if(arr[mid] >= num) right = mid;
        else left = mid + 1;
    }
    return left;
}
// 二分最右侧的待定值
int bianrySearchRight(int arr[], int left, int right, int num){
    while(left < right){
        int mid = (left + right + 1) >> 1;
        if(arr[mid] <= num) left = mid;
        else right = mid - 1;
    }
    return left;
}

int main(){
    int N, num;
    cin >> N >> num;
    int arr[N];
    for(int i = 0;i < N;i++) cin >> arr[i];
    while(num--){
        int temp;
        cin >> temp;
        int i1 = bianrySearchlLeft(arr, 0, N - 1, temp);
        if(arr[i1] != temp){
            cout << "-1 -1" << endl;
            continue;
        } else {
            int i2 = bianrySearchRight(arr, 0, N - 1, temp);
            cout << i1 << " " << i2 << endl;
        }
    }
}