#include <cstdio>
#include <cstdlib>

using namespace std;
void mergesort(int *arr, size_t left, size_t right);
void merge(int *arr, size_t left, size_t mid, size_t right);
void binarySearch(int *arr, size_t left, size_t right, int key);

int main()
{
    int N, i;
    int *arr;
    // printf("Enter the number :");
    printf("enternumber");
    scanf("%d", &N);
    arr = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    { 
        scanf("%d",&arr[i]);
    }

    mergesort(arr, 0, N-1);

    for (i = 0; i < N; i++)
    {
        printf("%d ",arr[i]);
    }
    free(arr);

    exit(EXIT_SUCCESS);
}

void mergesort(int *arr, size_t left, size_t right)
{               
    if (left < right)
    {printf("yoo");
        size_t mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid+1 , right);
        merge(arr, left, mid, right);
    }
}

/**
 * Merge two adjacent sorted numbers
 * First sub-array is arr[left..mid]
 * Second sub-array is arr[mid+1..right]
 *

 * @param arr a reference to- or a memory address of an array
 * @param left a left index of sorting area
 * @param mid a midpoint index of separating two sub-array
 * @param right a right index of sorting area
 * 
 */
void merge(int *arr, size_t left, size_t mid, size_t right)
{   int key[right]; 
    
    int i;
    // int *key=right;
// if (left!=(right-1))
// {
     printf("\n%d    %d  %d ",arr [left],arr[mid],arr[right]);
      printf("\nleft = %d mid = %d right = %d \n ",left,mid,right);

   if (left = mid)
   {
    binarySearch(arr,mid,right,key);
   }
   else
    {
    
    binarySearch(arr,left,right,key);
   }

   for ( i = left ; i <=right; i++)
   {
    arr[i]= key[i];
   }
   
   
   
        // binarySearch(arr,left,mid,key);
        // binarySearch(arr,mid,right,key);
    


   
    
   
   
  
    
  
    
    

    // TODO: For out-of-place merging,

    // you'll need to allocate a temporary area.
    // The number of elements can be calculated from the given indices.

    // TODO: iteratively pick the numbers from both sub-arrays
    // see merging animation on slide 8
}

/**
 * Find an occurence of key in array
 *
 * @param arr a reference to- or a memory address of an sorted array
 * @param left a left index of the array
 * @param right a right index of the array
 * @param key a key to be searched in for its occurence in the array
 * @return an index to the occurence, return (right + 1) if not found
 */
void binarySearch(int *arr, size_t left, size_t right, size_t *key)
{int i,j,c=0 ;
    for ( i = left; i <= right; i)
    {
        for ( j =left; j <= right; j)
        {
            if (arr[i]<arr[j])
            {
                key[c] = arr[i];
                c++;
                i++;
            }
            else if (arr[i]>arr[j])
            {
                key[c] = arr[j];
                c++;
                j++;
            }
        }
        
        
    }
    
    // TODO: find the midpoint

    // TODO: check if the midpoint is the key
    // TODO: if it is, return the index
    // TODO: if it's not, do the same thing on the left or right part
}
