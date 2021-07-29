#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int last=arr[n-1];
    for(int i=0;i<n-1;i++){
        arr[n-i-1]=arr[n-i-2];
    }
    arr[0]=last;
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";

}
