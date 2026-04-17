#include <stdio.h>

int main() {
    int i;
    int n = 12;
    int capacity = 30;
    int totalWeight = 0;
    int totalValue = 0;

    int weight[12] = {10, 15, 4, 5, 6, 5, 6, 8, 8, 10, 15, 6};
    int value[12]  = {10, 50, 20, 70, 30, 20, 20, 40, 50, 50, 40, 50};

    printf("Name : NITESH KUMAR\n");
    printf("Regd No: 2401020478\n");
    printf("Group : 04\n\n");

    /* Select items while capacity allows */
    for (i = 0; i < n; i++) {
        if (totalWeight + weight[i] <= capacity) {
            totalWeight += weight[i];
            totalValue += value[i];
        }
    }

    printf("Total Weight        = %d kg\n", totalWeight);
    printf("Total Value         = %d\n", totalValue);
    printf("Remaining Capacity  = %d kg\n", capacity - totalWeight);

    return 0;
}
