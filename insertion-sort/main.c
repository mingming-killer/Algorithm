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
void insertionSort(int[], int);


/**
 *
 * 1. 初始时，a[0]自成1个有序区，无序区为a[1..n-1]。令i=1
 *
 * 2. 将a[i]并入当前的有序区a[0…i-1]中形成a[0…i]的有序区间。
 *
 * 3. i++并重复第二步直到i==n-1。排序完成。
 *
 */

void insertionSort(int data[], int len) {
    int i, j, k;
    int tmp;
    for (i = 1; i < len; i++) {
        printf("now: %d \n", data[i]);
        for (j = 0; j < i; j++) {
            if (data[i] < data[j]) {
                //为a[i]在前面的a[0...i-1]有序区间中找一个合适的位置  
                tmp = data[i];    
                for (k = i; k > j; k--) {
                    data[k] = data[k - 1];
                }
                data[j] = tmp;
                printList(sData, sLen);
                break;
            }
        }
        printf("\n");
    }
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

    insertionSort(sData, sLen);

    printf("\n");
    printList(sData, sLen);
    return 0;
}
