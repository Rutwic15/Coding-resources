//Matrix exponentiation -> nth fibonacci number -> O(logn)

#include<bits/stdc++.h>
using namespace std;
#define N 101

//declare arrays globally
int ar[N][N], I[N][N];

void mul(int A[][N],int B[][N],int dim){
    int res [dim+1] [dim+1];
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            res[i][j] = 0;
            for(int k=0;k<dim;k++){
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            A[i][j] = res[i][j];
        }
    }
}

void power(int A[][N],int dim,int n){
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            if(i == j) I[i][j] = 1;
            else I[i][j] = 0;
        }
    }
    // for(int i=0;i<n;i++){
    //     //I = I * A
    //     //we cannot do like above step because it is matrix multiplication
    //     mul(I,A,dim);
    // }

    //By using binary multiplication
    while(n){
        if(n % 2){
            mul(I, A, dim);
            n--;
        }
        else{
            mul(A, A, dim);
            n/= 2;
        }
    }
    //final output should be in A;
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            A[i][j] = I[i][j];
        }
    }
}

void print(int A[][N],int dim){
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int t,dim,n;
    cin>>t;
    while(t--){
        cin>>dim>>n;
        for(int i=0;i<dim;i++){
            for(int j=0;j<dim;j++){
                cin>>ar[i][j];
            }
        }
        power(ar,dim,n);
        print(ar,dim);
    }
}