#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

   int maxi=arr[0],mini=arr[0];
   for(int i=1;i<n-1;i++){
    if(arr[i]>maxi){
        maxi = arr[i];
    }
    if(arr[i]<mini){
        mini = arr[i];
    }
   }
   cout << maxi << "  " << mini;
}
