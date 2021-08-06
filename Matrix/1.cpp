#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> arr[i][j];
    }
    int l=0,k=0;
    while(k<n && l<m){
        for(int i=l;i<m;i++){
            cout << arr[k][i] << " ";
        }k++;
        for(int i=k;i<n;i++){
            cout << arr[i][m-1] <<" ";
        }m--;

        if(k<n){
            for(int i=m-1;i>=l;i--)
                cout << arr[n-1][i] << " ";
        }n--;
        if(l<m){
            for(int i=n-1;i>=k;i--)
                cout << arr[i][l] << " ";
        }l++;
    }

}
