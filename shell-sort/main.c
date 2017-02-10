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
void swap(int*, int*);
void genIntDatas(int[], int);
void shellSort(int[], int);
void insertionSortSub(int[], int, int, int);


/**
 *
 * 该方法的基本思想是：先将整个待排元素序列分割成若干个子序列（由相隔某个“增量”的元素组成的）分别进行直接插入排序，然后依次缩减增量再进行排序，
 * 待整个序列中的元素基本有序（增量足够小）时，再对全体元素进行一次直接插入排序。
 * 因为直接插入排序在元素基本有序的情况下（接近最好情况），效率是很高的，因此希尔排序在时间效率上比前两种方法有较大提高。
 *  
 *
 * 以n=10的一个数组49, 38, 65, 97, 26, 13, 27, 49, 55, 4为例
 *
 * 第一次 gap = 10 / 2 = 5
 * 49   38   65   97   26   13   27   49   55   4
 *
 * 1A                       1B
 *      2A                       2B
 *           3A                       3B
 *               4A                        4B
 *                     5A                       5B
 *
 * 1A,1B，2A,2B等为分组标记，数字相同的表示在同一组，大写字母表示是该组的第几个元素， 每次对同一组的数据进行直接插入排序。
 * 即分成了五组(49, 13) (38, 27) (65, 49)  (97, 55)  (26, 4)这样每组排序后就变成了(13, 49)  (27, 38)  (49, 65)  (55, 97)  (4, 26)，下同。
 *
 *
 * 排序后
 * 第二次 gap = 5 / 2 = 2
 * 13   27   49   55   4    49   38   65   97   26
 *
 * 1A        1B        1C        1D        1E
 *      2A        2B        2C        2D        2E
 *
 *
 * 第三次 gap = 2 / 2 = 1
 * 4   26   13   27   38    49   49   55   97   65
 *
 * 1A  1B   1C   1D   1E    1F   1G   1H   1I   1J
 *
 * 第四次 gap = 1 / 2 = 0 排序完成得到数组：
 *
 * 4   13   26   27   38    49   49   55   65   97
 *
 */


void shellSort(int data[], int len) {  
    int i, j, k, l;  
    int gap;
    // 步长可以有很多种优化的，这里简单的除2 ...
    for (gap = len / 2; gap > 0; gap /= 2) {
        printf("gap: %d\n", gap);
        for (i = 0; i < gap; i++) {
            insertionSortSub(data, len, i, gap);
            //printList(sData, sLen);
        }
        printf("\n");
    }
}  

void insertionSortSub(int data[], int len, int index, int gap) {
    int i, j, k;
    int tmp;
    for (i = index + gap; i < len; i += gap) {
        //printf("now: %d \n", data[i]);
        for (j = index; j < i; j += gap ) {
            if (data[i] < data[j]) {
                //为a[i]在前面的a[0...i-1]有序区间中找一个合适的位置  
                tmp = data[i];    
                for (k = i; k > j; k -= gap) {
                    data[k] = data[k - gap];
                }
                data[j] = tmp;
                printList(sData, sLen);
                break;
            }
        }
    }
    printf("\n");
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

    shellSort(sData, sLen);

    printf("\n");
    printList(sData, sLen);
    return 0;
}
