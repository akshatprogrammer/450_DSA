#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int maxEle,minEle;
    sort(arr,arr+n);
    int res = arr[n-1]-arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>=k && arr[n-1]>=k){
            maxEle=max(arr[i-1]+k,arr[n-1]-k);
            minEle=min(arr[0]+k,arr[i]-k);
            res=min(res,maxEle-minEle);
        }
    }
   // for(int i=0;i<n;i++)
        cout << res << endl;
//sort(arr,arr+n);
   // cout << arr[n-1] - arr[0] << endl;
}
