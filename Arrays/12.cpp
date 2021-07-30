#include<iostream>
#include<algorithm>

using namespace std;
void merge(int arr1[], int arr2[], int n, int m) {
	    int index=0;
	    for(int i=n;i<m+n;i++){
	        arr1[i]=arr2[index];
	        index++;
	    }
	    sort(arr1,arr1+n+m);
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    int m;
    cin >> m;
    int arr2[m];
    for(int i=0;i<m;i++)
        cin >> arr2[i];
    merge(arr,arr2,n,m);
    for(int i=0;i<n+m;i++)
        cout << arr[i] <<" ";
}

