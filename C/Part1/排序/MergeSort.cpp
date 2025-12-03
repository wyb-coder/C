# include <bits/stdc++.h>
using namespace std;

#define INF 100000
int tempArr[INF];
long long int res = 0;

void mergeSort(int arr[], int left, int right){
    if(left >= right) return;
    int mid = (left + right) >> 1;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    int index = 0, i = left, j = mid + 1;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]) tempArr[index++] = arr[i++];
        else {
            tempArr[index++] = arr[j++];
            res += mid - i + 1;
        } // i、j都递增，则此i后全部为逆序对;以每个j判断所有i
    }
    while(i <= mid) tempArr[index++] = arr[i++];
    while(j <= right) tempArr[index++] = arr[j++];
    for(int i = left, j = 0;i <= right;i++, j++) arr[i] = tempArr[j];
}

int main(){
    int N;
    cin >> N;
    int arr[N + 1];
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    mergeSort(arr, 0, N-1);
    for(int i = 0;i < N;i++) cout << arr[i] << " ";
    cout << endl;
    cout << res;
}