// Kadane's Algorithm
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    int max_sum=-1,max_temp=0;
    for(int i=0;i<n;i++){
        max_temp += arr[i];
        if(max_sum<max_temp)
            max_sum=max_temp;
        if(max_temp<0)
            max_temp=0;
    }
    cout << max_sum << endl;
}
