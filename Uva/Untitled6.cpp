#include<stdio.h>

int  tsearch(int *a,int i,int j,int k);

int main()
{
    int a[10]= {1,2,3,4,5,6,7,8,9,10};
    int search;
    int k;
    printf("enter no to be searched :");
    scanf("%d",&k);
    search=tsearch(a,0,9,k);
    printf("\n%d",search);
    return 0;
}

int tsearch(int *data, int left, int right, int value)
{
    int i;
    int first,second;
    if(left>right)
        return -1;

    i= (right - left)/3;
    if(i==0) i++;

    first = i  + left -1;
    second = i*2 + left - 1;

    if(data[first]==value)
        return first;
    else if(data[first]>value)
        return tsearch(data, left, first-1, value);
    else
    {
        if(data[second]==value)
            return second;
        else if(data[second]>value)
            return tsearch(data, first+1,second-1, value);
        else
            return tsearch(data, second+1,right, value);
    }
}
