#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int comptext(const char *fname1, const char *fname2, const int max) {
    char *line1;
    char *line2;
    FILE *f1;
    FILE *f2;
    int c;

    if ((f1 = fopen(fname1, "r")) == NULL)
        return 0;

    if ((f2 = fopen(fname2, "r")) == NULL) {
        fclose(f1);
        return 0;
    }

    if ((line1 = calloc(max, sizeof(char))) == NULL) {
        fclose(f1);
        fclose(f2);
        return 0;
    }

    if ((line2 = calloc(max, sizeof(char))) == NULL) {
        fclose(f1);
        fclose(f2);
        free(line1);  // No need to free line2 since it wasn't allocated
        return 0;
    }

    for (c = 0; fgets(line1, max, f1) != NULL; c++) {
        if (fgets(line2, max, f2) == NULL || strcmp(line1, line2) != 0) {
            fclose(f1);
            fclose(f2);
            free(line1);
            free(line2);
            return 0;
        }
    }

    free(line1);
    free(line2);
    
    if (fclose(f1) == EOF || fclose(f2) == EOF)
        return 0;

    return 1;
}

int main() {
    printf("%d\n", comptext("a.txt", "b.txt", 80));
    return 0;
}

