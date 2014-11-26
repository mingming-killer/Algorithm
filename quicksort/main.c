#include <stdio.h>

void quickSort(int data[], int low, int high) {
    if (low >= high) {
        return;
    }

    int i = low;
    int j = high;
    int pivotKey = data[low];

    while (i < j) {
        while (i < j && data[j] >= pivotKey) j--;
        if (i < j) {
            data[i] = data[j];
            i++;
        }

        while (i < j && data[i] <= pivotKey) i++;
        if (i < j) {
            data[j] = data[i];
            j--;
        }
    }

    data[i] = pivotKey;
    quickSort(data, low, i - 1);
    quickSort(data, i + 1, high);
}

void printList(int data[], int len) {
    printf("list is: ");
    int i = 0;
    for (i = 0; i < len; i++) {
        printf("%d, ", data[i]);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    int data[] = {12, 2, 16, 30, 8, 28, 4, 10, 20, 6, 18};
    printList(data, 11);
    
    quickSort(data, 0, 10);
    printList(data, 11);

    return 0;
}
