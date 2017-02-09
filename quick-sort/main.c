#include <stdio.h>

#define LEN(array) (sizeof(array) / sizeof(array[0]))

static int s_data[] = {12, 2, 16, 30, 8, 28, 4, 10, 20, 6, 18};
static int s_len = LEN(s_data);


void printList(int[], int);
void quickSort(int[], int, int);


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
    printList(s_data, s_len);

    quickSort(data, low, i - 1);
    quickSort(data, i + 1, high);
}

void printList(int data[], int len) {
    int i = 0;
    printf("list is: ");
    for (i = 0; i < len; i++) {
        printf("%d, ", data[i]);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    printList(s_data, s_len);
    printf("\n");

    quickSort(s_data, 0, s_len - 1);

    printf("\n");
    printList(s_data, s_len);
    return 0;
}
