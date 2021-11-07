#include "sum.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int sum(int a[], int n)
{
    //Precondition
    assert(n>=0); 

    //Postcondition
    if(n==0)
        return 0;
    else
        return a[n-1] + sum(a,n-1);
}