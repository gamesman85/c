#include <stdio.h>

#define N 10

void zero_array(int[], int);
void read_into_array(int[], int);
int sum_array(int[], int);
void print_out_array(int[], int);
void max_min(int[], int, int*, int*);

void zero_array(int arr[], int size) {
    for(int i=0; i<size; i++) {
        arr[i] = 0;
    }
}

void read_into_array(int arr[], int size) {
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
}

int sum_array(int arr[], int size) {
    int sum = 0;

    for(int i=0; i<size; i++) {
        sum += arr[i];
    }

    return sum;
}

void print_out_array(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// pointer fun
void max_min(int a[], int n, int *max, int *min) {
    int i;

    *max = *min = a[0];
    for(i=1; i<n; i++) {
        if(a[i] > *max)
            *max = a[i];
        else if(a[i] < *min)
            *min = a[i];
    }
}

int main() {
    int arr[N];
    read_into_array(arr, N);

    int big, small;
    max_min(arr, N, &big, &small);
    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);

    return 0;
}