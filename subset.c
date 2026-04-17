#include <stdio.h>

int set[20], subset[20];
int n, target;

void solve(int sum, int index, int size) {
    if (sum == target) {
        printf("Subset: ");
        for (int i = 0; i < size; i++)
            printf("%d ", subset[i]);
        printf("\n");
        return;
    }

    if (sum > target || index == n)
        return;

    subset[size] = set[index];
    solve(sum + set[index], index + 1, size + 1);

    solve(sum, index + 1, size);
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    solve(0, 0, 0);

    return 0;
}