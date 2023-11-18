//  lab1_es5_array
//  Created by ing.conti on 18/10/20.

#include <stdio.h>

#define MAX 10
int main(int argc, const char * argv[]) {

    int A[MAX];
    int B[MAX/2];
    int i,j;

    for (i=0; i<MAX; i++) {
        printf("dammi A[%d]: ", i);
        scanf("%d" ,&A[i]);
    }

    for (i=0; i<MAX/2; i++) {
        printf("dammi B[%d]: ", i);
        scanf("%d" ,&B[i]);
    }

    j=0;
    for (i=0; i<MAX && j<MAX/2; i++) {
        if (A[i] == B[j]){
            j++;
        }else{
            j=0;
        }
    }
    
    if (j == MAX/2)
        printf("CONTIENE\n");
    else
        printf("non CONTIENE\n");
    return 0;
}
