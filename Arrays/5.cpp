#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int pointer=0;
    for(int i=0;i<n;i++){
      if(arr[i]<0){
        swap(arr[i],arr[pointer]);
        pointer++;
      }
      else if(arr[i]>=0 && arr[i+1]>=0){
        continue;
      }
    }
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
}
