#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    char text[] = "ABABDABACDABABCABABCDHABAB";
    char pattern[] = "ABAB";
    
    int n = strlen(text);
    int m = strlen(pattern);
    int i, j;
    int found = 0;

    clock_t start, end;
    start = clock();

    for(i = 0; i <= n - m; i++) {
        for(j = 0; j < m; j++) {
            if(text[i + j] != pattern[j])
                break;
        }
        if(j == m) {
            printf("Pattern found at index %d\n", i);
            found = 1;
        }
    }

    end = clock();

    if(!found)
        printf("Pattern not found.\n");

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution Time: %f seconds\n", time_taken);

    printf("Shreya Singh\n");
    printf("2401020496\n");

    return 0;
}
