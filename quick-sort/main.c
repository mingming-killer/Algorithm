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
void quickSort(int[], int, int);


/*
 *
 * 1．先从数列中取出一个数作为基准数。
 *
 * 2．分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。
 *
 * 3．再对左右区间重复第二步，直到各区间只有一个数。
 *
 *
 * -----------------------------------
 * 虽然快速排序称为分治法，但分治法这三个字显然无法很好的概括快速排序的全部步骤。因此我的对快速排序作了进一步的说明：
 * 挖坑填数+分治法
 *
 * 对挖坑填数进行总结
 *
 * 1．i = L; j = R; 将基准数挖出形成第一个坑a[i]。
 *
 * 2．j--由后向前找比它小的数，找到后挖出此数填前一个坑a[i]中。
 *
 * 3．i++由前向后找比它大的数，找到后也挖出此数填到前一个坑a[j]中。
 *
 * 4．再重复执行2，3二步，直到i==j，将基准数填入a[i]中。
 *
 *
 * 填坑例子：
 * 基数 72, i = 1, j = 9
 * xx, 6 , 57, 88, 60, 42, 83, 73, 48, 85
 *
 *
 *                                    <--
 * 48, 6 , 57, 88, 60, 42, 83, 73, xx, 85
 *
 *     -->
 * 48, 6 , 57, xx, 60, 42, 83, 73, 88, 85
 *
 *                            <--
 * 48, 6 , 57, 42, 60, xx, 83, 73, 88, 85
 *
 *                 -->           
 * 48, 6 , 57, 42, 60, xx, 83, 73, 88, 85
 *
 *
 * 48, 6 , 57, 42, 60, 72, 83, 73, 88, 85
 *
 */

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
    printList(sData, sLen);

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

    quickSort(sData, 0, sLen - 1);

    printf("\n");
    printList(sData, sLen);
    return 0;
}

