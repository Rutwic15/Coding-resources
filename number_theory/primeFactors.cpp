#include<bits/stdc++.h>
using namespace std;

int arr[1000001];
int main(){
    int sz = 1000001;
    memset(arr,-1,sz);
    for(int i=2;i<=sz;i++){
        if(arr[i] != -1){
            for(int j=i;j<=sz;j+=i){
                if(arr[j] == -1)
                arr[j] = i;
            }
        }
    }
}