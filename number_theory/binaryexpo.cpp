#include<bits/stdc++.h>
using namespace std;

long long bin_pow(long long base,long long n){
    long long res = 1;
    while(n != 0){
        if(n % 2 == 0){
            base = base * base;
            n /= 2;
        }
        else{
            res = res * base;
            n--;
        }
    }
    return res;
}

int main(){
    long long base,n;
    cin>>base>>n;
    long long ans = bin_pow(base,n);
    cout<<ans<<endl;
    return 0;
}