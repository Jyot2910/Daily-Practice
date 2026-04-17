#include <stdio.h>
#include <time.h>

int set[20], subset[20];
int n, target;
int moves = 0;

void subsetSum(int i, int sum, int k)
{
    moves++;

    if(sum == target)
    {
        printf("{ ");
        for(int j = 0; j < k; j++)
            printf("%d ", subset[j]);
        printf("}\n");
        return;
    }

    if(i == n || sum > target)
        return;

    subset[k] = set[i];
    subsetSum(i + 1, sum + set[i], k + 1);

    subsetSum(i + 1, sum, k);
}

int main()
{
    clock_t start, end;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    start = clock();

    printf("\nSubsets with sum %d:\n", target);
    subsetSum(0, 0, 0);

    end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nTotal moves tried: %d\n", moves);
    printf("Time consumed: %.6f seconds\n\n", time_taken);

    printf("Nitesh Kumar\n");
    printf("Regd No: 2401020478\n");

    return 0;
}