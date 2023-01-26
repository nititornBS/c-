#include <cstdio>
#include <cstdlib>

using namespace std;

void merge(int* array, size_t l, size_t m, size_t r);
void mergeSort(int* array, size_t l, size_t r);
void binarySort(int* array, size_t n);

int main() {

    int N;
    int* arr;
    printf("Enter number of member in the array: ");
    scanf("%d", &N);
    

    arr = (int *) malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        printf("Enter the %d member  of the array: ",i+1);
        scanf("%d", &arr[i]);
    }

    printf("Give me the arrray: \n");
    for (int i=0; i < N; i++){
        printf("%d ", arr[i]);
        
    }

    binarySort(arr, N);

    printf("\nSorted array is:  \n");
    for (int i=0; i < N; i++) {
         printf("%d ", arr[i]);
    }

    return 0;
}




void merge(int* array, size_t l, size_t m, size_t r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int* array, size_t l, size_t r) {
    if (l < r) {
        int m = l+(r-l)/2;
        mergeSort(array, l, m);
        mergeSort(array, m+1, r);
        merge(array, l, m, r);
    }
}

void binarySort(int* array, size_t N) {
    mergeSort(array, 0, N - 1);
}