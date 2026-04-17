#include <stdio.h>
#include <string.h>
#include <time.h>

#define d 256
#define q 101   // A prime number

int main() {
    char text[] = "ABABDABACDABABCABABDCABAB";
    char pattern[] = "ABAB";

    int n = strlen(text);
    int m = strlen(pattern);
    int i, j;

    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;

    int hits = 0;
    int spurious_hits = 0;

    clock_t start, end;
    start = clock();

    // Calculate h = pow(d, m-1) % q
    for(i = 0; i < m-1; i++)
        h = (h * d) % q;

    // Calculate initial hash values
    for(i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide pattern over text
    for(i = 0; i <= n - m; i++) {

        // If hash values match
        if(p == t) {
            hits++;
            for(j = 0; j < m; j++) {
                if(text[i + j] != pattern[j])
                    break;
            }

            if(j == m)
                printf("Pattern found at index %d\n", i);
            else
                spurious_hits++;
        }

        
        if(i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if(t < 0)
                t = t + q;
        }
    }

    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution Time: %f seconds\n", time_taken);
    printf("Total Hash Hits: %d\n", hits);
    printf("Spurious Hits: %d\n", spurious_hits);

    
    printf("Shreya Singh\n");
    printf("2401020496\n");

    return 0;
}
