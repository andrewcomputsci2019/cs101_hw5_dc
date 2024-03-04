#include <sol.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){
    int n = 1000;
    int m = 1000;
    srand((unsigned) time(NULL));
    int** matrix = (int**) malloc(sizeof(int*)*n);
    assert(matrix);
    int example[3][6] = {{6,1,19,3,10,18},{16,7,2,11,3,8},{12,14,13,9,20,5}};
    int* convert[3] = {example[0],example[1],example[2]};
    for(int i = 0; i < n; i++){
        matrix[i] = (int*) malloc(sizeof(int)*m);
        for(int j = 0; j < m; j++){
            int val = rand()%16500;
            matrix[i][j] = val;
        }
    }
    int steps = 0;
    int val = max_diff(n,m,&steps,matrix);
    printf("the solution was %d, and the number of steps was %d", val, steps);
    for(int i = 0; i < n; i++){
        free(matrix[i]);
    }
    free(matrix);
}
