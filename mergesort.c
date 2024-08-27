#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int animal_id;
} animal_t;

animal_t *mergesort(int num, animal_t *data) {
    // sorted elements
    animal_t *result, *result1, *result2;

    // sizes of two subsets of data
    int size1, size2;

    // counter for putting elements into result array
    int t;

    // for getting elements from result1/2 arrays
    int t1, t2;

    result = (animal_t *)malloc(num * sizeof(animal_t));

    // solve trivial case
    if (num == 1) {
        result[0] = data[0];
    }
    // main work
    else {
        size1 = num / 2;
        size2 = num - size1;
        
        // sort first half
        result1 = mergesort(size1, data);
        
        // sort second half
        result2 = mergesort(size2, data + size1);

        t = 0;
        t1 = 0;
        t2 = 0;

        // merge result1, result2 into result
        while (t < num) {
            if ((t2 == size2) || (t1 < size1 && result1[t1].weight < result2[t2].weight))
                result[t++] = result1[t1++];
            else
                result[t++] = result2[t2++];
        }

        // Free allocated memory for result1 and result2
        free(result1);
        free(result2);
    }
    return result;
}

int main() {
    animal_t data[] = {{5, 1}, {3, 2}, {8, 3}, {1, 4}, {7, 5}};
    int num = sizeof(data) / sizeof(data[0]);

    animal_t *sorted_data = mergesort(num, data);

    for (int i = 0; i < num; i++) {
        printf("Animal ID: %d, Weight: %d\n", sorted_data[i].animal_id, sorted_data[i].weight);
    }

    free(sorted_data);  // Free the final sorted array
    return 0;
}