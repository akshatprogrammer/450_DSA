#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int minJump=0;
    int check,index;
    for(int i=0;i<n;i++){
        check=arr[i];
        index=check+i-1;
        if(index==n-2){
            minJump++;
            break;
        }
        else if(index>n){
            minJump++;
            break;
        }

        i=index;
        minJump++;
    }
    cout << minJump << endl;
}
