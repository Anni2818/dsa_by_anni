#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int>arr = {1,2,3,4,5};
    int i=0;
    int count=0;
    while(arr[i]){
        count++;
        i++;
    }
    cout<<count<<endl;
    return 0;
}
