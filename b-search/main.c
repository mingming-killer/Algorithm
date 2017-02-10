#include <stdio.h>

#define LEN(array) (sizeof(array) / sizeof(array[0]))

// binary search must sorted data !!
static int sData[] = {2, 4, 6, 8, 10, 12, 16, 18, 20, 28, 30};
static int sLen = LEN(sData);


void printList(int[], int);
int bsearch(int[], int, int);


int bsearch(int data[], int len, int target) {
    int low = 0;
    int mid = 0;
    int high = len - 1;
    printf("search %d l=%d h=%d \n", target, low, high);
    while (low <= high) {
        mid = low + ((high - low) / 2);
        printf("l=%d, h=%d, m=%d \n", low, high, mid);
        if (data[mid] == target) {
            return mid;
        } else if (data[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
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
    printList(sData, sLen);
    printf("\n");

    int i;
    int index = -1;
    int targets[] = {10, 2, 30, 16, 28};
    for (i = 0; i < 5; i++) {
        index = bsearch(sData, sLen, targets[i]);
        printf("search %d index is  %d \n", targets[i], index);
        printf("\n");
        index = -1;
    }

    return 0;
}
