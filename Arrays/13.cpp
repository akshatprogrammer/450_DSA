#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    int max_sum=-1,max_end=0;
    for(int i=0;i<n;i++){
        max_end+=arr[i];
        if(max_sum<max_end){
            max_sum=max_end;
        }
        if(max_end<0)
            max_end=0;
    }
    cout << max_sum << endl;

}
