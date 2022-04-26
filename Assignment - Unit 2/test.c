#include<stdio.h>
#include<stdlib.h>
int main(){
    int count[6]; int A[6] ={75,50,25,19,80,90}, S[6];
    for( int i=0; i<6; i++) count[i]=0;
    for( int i=0; i<5; i++){
        for( int j=i+1; j<4; j++){
            if(A[i]<A[j]) count[j] +=1;
            else count[i]+=1;

        }
    }
    for( int i=0; i<5; i++){
        printf("%d %d\n",count[i],A[i]);
        S[count[i]] = A[i];
    }

}