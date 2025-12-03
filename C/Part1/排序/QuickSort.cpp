#include <iostream>
using namespace std;

int Quick_Sort(int arr[], int left, int right){
    if(left >= right) return 0;
    int pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j){
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (j > left) Quick_Sort(arr, left, j);
    if (i < right) Quick_Sort(arr, i, right);
}

int main(){
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];
    Quick_Sort(arr, 0, N - 1);
    for(int i = 0;i < N;i++) cout << arr[i] << " ";
}