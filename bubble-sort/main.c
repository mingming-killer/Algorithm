#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN(array) (sizeof(array) / sizeof(array[0]))

typedef int BOOL;
#define TRUE  1;
#define FALSE 0;

//static int sData[] = {12, 2, 16, 30, 8, 28, 4, 10, 20, 6, 18};
//static int sLen = LEN(sData);
static int sLen = 11;
static int sData[11] = {};


void printList(int[], int);
void genIntDatas(int[], int);
void swap(int*, int*);
void bubbleSortV1(int[], int);
void bubbleSortV2(int[], int);
void bubbleSortV3(int[], int);


/**
 *
 * 1．比较相邻的前后二个数据，如果前面数据大于后面的数据，就将二个数据交换。
 *
 * 2．这样对数组的第0个数据到N-1个数据进行一次遍历后，最大的一个数据就“沉”到数组第N-1个位置。
 *
 * 3．N=N-1，如果N不为0就重复前面二步，否则排序完成。
 *
 */

void bubbleSortV1(int data[], int len) {
    int i;
    int j = len;
    BOOL flag = TRUE;  
    for (i = 0; i < len; i++) {
        for (j = 1; j < len - i; j++) {
            if (data[j - 1] > data[j]) {
                swap(data + (j - 1), data + j);  
                flag = TRUE;  
            }
            printList(sData, sLen);
        }
        printf("\n");
    }
}

void bubbleSortV2(int data[], int len) {
    int j;
    int n = len;
    BOOL flag = TRUE;  
    while(flag) {
        flag = FALSE;  
        for (j = 1; j < n; j++) {
            if (data[j - 1] > data[j]) {
                swap(data + (j - 1), data + j);  
                flag = TRUE;  
            }
            printList(sData, sLen);
        }
        printf("\n");
        n--;  
    }
}

void bubbleSortV3(int data[], int len) {
    int j, n;  
    int flag = len;  
    while(flag > 0) {  
        n = flag;  
        flag = 0;  
        for (j = 1; j < n; j++) {
            if (data[j - 1] > data[j]) {  
                swap(data + (j - 1), data + j);  
                flag = j;  
            }  
            printList(sData, sLen);
        }
        printf("\n");
    } 
}

void swap(int* p1, int* p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void printList(int data[], int len) {
    int i = 0;
    printf("list is: ");
    for (i = 0; i < len; i++) {
        printf("%d, ", data[i]);
    }
    printf("\n");
}

void genIntDatas(int data[], int len) {
    int i, r;
    time_t rawTime = time(&rawTime);
    srand((unsigned int)rawTime);

    for (i = 0; i < len; i++) {
        // rand: 1 ~ 99
        data[i] = (rand() % 98) + 1;
    }
}

int main(int argc, char** argv) {
    genIntDatas(sData, sLen);

    printList(sData, sLen);
    printf("\n");

    //bubbleSortV1(sData, sLen);
    //bubbleSortV2(sData, sLen);
    bubbleSortV3(sData, sLen);

    printf("\n");
    printList(sData, sLen);
    return 0;
}
