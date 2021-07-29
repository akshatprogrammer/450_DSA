// Dutch National Flag Algorithm
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int low=0,high=n-1;
    int mid=0;
    while(mid<=high){
        switch(arr[mid]){
            case 0:
                swap(arr[low],arr[mid]);
                low++,mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid],arr[high]);
                high--;
        }
    }
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";

}
