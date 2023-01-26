#include <cstdio>
#include <cstdlib>

int main() {

    int N;
    int* arr;
    printf("Enter number of elements in the array: ");
    scanf("%d", &N);
    

    arr = (int *) malloc(N * sizeof(int));


    for (int i = 0; i < N; i++) {
        printf("Enter the elements of the array: ");
        scanf("%d", &arr[i]);
    }

    printf("Given array is: ");
    for (int i=0; i < N; i++){
        printf("%d ", arr[i]);
        
    }

    int M;

    printf("\nEnter the number of elements in another array: ");
    scanf("%d", &M);

    int* anotherArr;
    anotherArr = (int *) malloc(M * sizeof(int));

    for (int i = 0; i < M; i++) {
        printf("Enter the elements of the another array[%d]: ", i+1);
        scanf("%d", &anotherArr[i]);
    }

    printf("Given array is: \n");
    for (int i=0; i < M; i++){
        printf("%d ", anotherArr[i]);    
    }

    for (int i = 0; i < M; i++) {
        bool found = false;
        int low = 0;
        int high = M - 1;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (arr[mid] == anotherArr[i]) {
                found = true;
                break;
            } else if (arr[mid] < anotherArr[i]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (found) {
            printf("\n%d is found", anotherArr[i]);
            
        } else {
            printf("\n%d is not", anotherArr[i]);

        }
    }

    return 0;
}