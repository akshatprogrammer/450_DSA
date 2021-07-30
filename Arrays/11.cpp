#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n+1];
    for(int i=1;i<n+1;i++)
        cin >> arr[i];
    int duplicate=0;
    sort(arr+1,arr+n+1);

    for(int i=1;i<n;i++){
        if(arr[i]==arr[i+1]){
            cout << arr[i];
            break;
        }
        else{
            continue;
        }
    }
    //for(int i=1;i<n+1;i++)
       // cout << arr[i] << " ";
}
