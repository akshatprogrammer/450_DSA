#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int arr[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> arr[i][j];
    int target;
    cin >> target;
    int index;
    for(int i=0;i<n;i++){
        if(target<arr[i][0]){
            index=i-1;
        }
    }
    for(int i = index;i<m;i++){
        if(target==arr[index][i])
        {
            cout << "True";
            exit(-1);
        }
    }
    cout << "False" << endl;
}
