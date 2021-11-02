#include<iostream>
#include<algorithm>
using namespace std;
int findPosF(int *arr,int n,int key){
	// int count[10];
	int left=0,right=n-1;
	int res=-1;
	while(left<=right){
		int mid = (right+left)/2;
		if(arr[mid]<key){
			right=mid-1;
		}
		else if(arr[mid]>key){
			left=mid+1;
		}
		else{
			res=mid;
			right=mid-1;
		}
	}
	return res;
	// sort(count,count+i);
	// cout << count[0] << " " << count[i-1] << endl;
}
int findPosL(int *arr,int n,int key){
	// int count[10];
	int left=0,right=n-1;
	int res=-1;
	while(left<=right){
		int mid = (right+left)/2;
		if(arr[mid]<key){
			right=mid-1;
		}
		else if(arr[mid]>key){
			left=mid+1;
		}
		else{
			res=mid;
			left=mid+1;
		}
	}
	return res;
	// sort(count,count+i);
	// cout << count[0] << " " << count[i-1] << endl;
}
int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int k;
	cin >> k;

	cout << findPosF(arr,n,k) << "  ";
	cout << findPosL(arr,n,k) << endl;

}