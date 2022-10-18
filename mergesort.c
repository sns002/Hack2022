#include<stdio.h>
#include <stdlib.h>
#include <time.h>
void MERGE(long long int arr[],long int p,long int q,long int r)
{
    long long int n1=q-p+1;
    // no of elements in array from index p to q
    long long int n2=r-q;
    // no of elements in array from index q+1 to r
    long long int i,j,k;
    long long int L[n1],R[n2]; //create temp arrays

    for(i=0;i<n1;i++)
    {
      L[i]=arr[p+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]= arr[q+1+j];
    }
    // merge the temp arrays
    i=0;
    j=0;
    k=p;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
    else
       { 
        arr[k]=R[j];
        j++;
       }
       k++;
    }
    // copy the reamaining elements of L[]
       while(i<n1)
       {
          arr[k]=L[i];
          i++;
          k++;
       }
       // copy the reamaining elements of R[]
       while(j<n2)
       {
          arr[k]=R[j];
          j++;
          k++;
       }
    }
double mergeSort(long long int arr[],long long int l,long long int r)
{
    clock_t start = clock();
    if(l<r)
    {
        long long int m= l+((r-l)/2);
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        MERGE(arr,l,m,r);
    }
    clock_t end = clock();
    return (((double)(end-start))/CLOCKS_PER_SEC);
}
void reverseArray(long long int arr[],long long int start,long long int end)
{
   while (start < end)
   {
     int temp = arr[start];
     arr[start] = arr[end];
     arr[end] = temp;
     start++;
     end--;
   }
}
void input_array(int arr[],int n)
{
    printf("Enter the elements of the array : ");
    for(long long int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

    }
}
void output_array(int arr[],int n)
{
    printf("The resulltng array is : ");
    for(long long int i=0;i<n;i++)
    {
        printf("%d \t ",arr[i]);
    }
}

int main()
{
    long long int choice, flag, l, a[50000], i, j, s;
    double cpurtra, cpurtaa, cpurtda;
      printf("0) Enter (0) to calculate the central processing unit (C.P.U) run time of rearanging the numbers in ascending order which were already aranged in the random,ascending,reversely sorted order.\n\n");
    flag = 1;
    while(flag==1)
    {
        printf("Choose from the above given menu:\n");
        scanf("%lld", &choice);
        switch(choice)
        {
            case 0:
            s = 0;
            printf("Analysis Table for Mergee Sort Algorithm:\n\n");
            printf("Serial Number: |Length of List: |C.P.U Clock Time: (R-->Ascen): |C.P.U Clock Time: (Ascending -> Ascending): |C.P.U Clock Time: (Descending -> Ascending):\n");
            for(i=5000;i<=50000;i+=5000)
            {
                for(j=0;j<i;j++)
                {
                    a[j] = rand()%1000;
                }
                cpurtra =   mergeSort(a,0,i-1);
                cpurtaa =   mergeSort(a,0,i-1);
                reverseArray(a,0, i-1);
                cpurtda =   mergeSort(a,0,i);
                printf("(%lld)            |(%lld)          |(%lf)                     |(%lf)                                  |(%lf)\n", s++, i, cpurtra, cpurtaa, cpurtda);
            }
            break;
            default:
            printf("Plese choose from within the above given menu.");
        }
    }
    return (0);
}
