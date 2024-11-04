#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function prototypes
void reverseString(char *str);
void concatenateStrings(char *dest, const char *src);
void countVowels(const char *str);
void convertToUpper(char *str);

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    char *ptr1, *ptr2;
    int choice;

    do {
        printf("\nString and Pointer Practice Program");
        printf("\n1. Reverse a string");
        printf("\n2. Concatenate two strings");
        printf("\n3. Count vowels");
        printf("\n4. Convert to uppercase");
        printf("\n5. Exit");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer

        switch(choice) {
            case 1:
                printf("Enter a string to reverse: ");
                fgets(str1, MAX_LENGTH, stdin);
                str1[strcspn(str1, "\n")] = 0; // Remove newline
                ptr1 = str1;
                reverseString(ptr1);
                printf("Reversed string: %s\n", str1);
                break;

            case 2:
                printf("Enter first string: ");
                fgets(str1, MAX_LENGTH, stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Enter second string: ");
                fgets(str2, MAX_LENGTH, stdin);
                str2[strcspn(str2, "\n")] = 0;
                ptr1 = str1;
                ptr2 = str2;
                concatenateStrings(ptr1, ptr2);
                printf("Concatenated string: %s\n", str1);
                break;

            case 3:
                printf("Enter a string: ");
                fgets(str1, MAX_LENGTH, stdin);
                str1[strcspn(str1, "\n")] = 0;
                ptr1 = str1;
                countVowels(ptr1);
                break;

            case 4:
                printf("Enter a string: ");
                fgets(str1, MAX_LENGTH, stdin);
                str1[strcspn(str1, "\n")] = 0;
                ptr1 = str1;
                convertToUpper(ptr1);
                printf("Uppercase string: %s\n", str1);
                break;

            case 5:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}

// Function to reverse a string using pointers
void reverseString(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;
    char temp;

    while(start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Function to concatenate strings using pointers
void concatenateStrings(char *dest, const char *src) {
    // Move to the end of dest string
    while(*dest) dest++;
    
    // Copy src to dest
    while((*dest++ = *src++));
}

// Function to count vowels using pointers
void countVowels(const char *str) {
    int count = 0;
    while(*str) {
        char c = *str;
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
        str++;
    }
    printf("Number of vowels: %d\n", count);
}

// Function to convert string to uppercase using pointers
void convertToUpper(char *str) {
    while(*str) {
        if(*str >= 'a' && *str <= 'z') {
            *str = *str - 32;
        }
        str++;
    }
}
