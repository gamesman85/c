#include <stdio.h>

#define N 10

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

int main() {
    int arr[N];

    zero_array(arr, N);
    print_out_array(arr, N);

    read_into_array(arr, N);
    int sum = sum_array(arr, N);
    printf("%d\n", sum);

    return 0;
}
