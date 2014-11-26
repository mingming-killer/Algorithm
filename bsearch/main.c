#include <stdio.h>

int bsearch(int datas[], int len, int target) {
    int low = 0;
    int mid = 0;
    int high = len - 1;
    printf("search %d l=%d h=%d \n", target, low, high);
    while (low <= high) {
        mid = low + ((high - low) / 2);
        printf("l=%d, h=%d, m=%d \n", low, high, mid);
        if (datas[mid] == target) {
            return mid;
        } else if (datas[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

void print_list(int datas[], int len) {
    printf("list is: ");
    int i = 0;
    for (i = 0; i < len; i++) {
        printf("%d, ", datas[i]);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    // binary search must sorted data !!
    int datas[] = {2, 4, 6, 8, 10, 12, 16, 18, 20, 28, 30};
    print_list(datas, 11);


    int i;
    int index = -1;
    int targets[] = {10, 2, 30, 16, 28};
    for (i = 0; i < 5; i++) {
        index = bsearch(datas, 11, targets[i]);
        printf("search %d index is  %d \n", targets[i], index);
        index = -1;
    }


    return 0;
}
