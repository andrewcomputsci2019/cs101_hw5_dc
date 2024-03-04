#include <SmartPointer.h>
#include <assert.h>
#include <sol.h>
#include <stdlib.h>


int* helper(int l, int r, size_t n, size_t m, int* steps,int** array){
    if(l == r){ // base case
        //iterate over colounm of 2d array find min and max O(n) time
        int min = array[0][l];
        int max = array[0][l];
        for(int i = 1; i < n; i++){
            min = MIN(array[i][l], min);
            max = MAX(array[i][l],max);
            (*steps)++;
        }
        int* val_array = allocate_ptr(sizeof(int)*3,NULL, PTR_SHARED);
        assert(val_array);
        val_array[0] = 0; //diff 
        val_array[1] = max; //max 
        val_array[2] = min; //min
        (*steps)++;
        return val_array;
    }
    int mid = (r-l)/2 + l;
    int* left = helper(l, mid, n, m,steps,array);
    int* right = helper(mid+1,r,n,m,steps,array);
    int* val_array = allocate_ptr(sizeof(int)*3, NULL, PTR_SHARED);
    assert(val_array);
    int max_diff_sub = MAX(left[0], right[0]);
    int max_val = MAX(left[1],right[1]);
    int lower_val = MIN(left[2], right[2]);
    int max_diff_cur = MAX(left[1]-right[2], max_diff_sub);
    val_array[0] = max_diff_cur;
    val_array[1] = max_val;
    val_array[2] = lower_val;
    release_ptr(&left);
    release_ptr(&right);
    (*steps)++;
    return val_array;
}


int max_diff(size_t n, size_t m, int* number_steps,int** array){
    if(!(array && *array)){
        return 0;
    }
    int* sol = helper(0, m-1,n,m,number_steps,array);
    int sol_val = sol[0];
    release_ptr(&sol);
    return sol_val;
}
