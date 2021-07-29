#include<iostream>
using namespace std;
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

    int intersection[10];
    int i_count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i]==arr2[j]){
                intersection[i_count]=arr[i];
            //    cout << intersection[i_count] << endl;
                arr2[j]=0;
                i_count++;
                break;
            }
        }
    }
    for(int i=0;i<i_count;i++)
        cout << intersection[i] << " ";
}
