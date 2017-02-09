#include <stdio.h>

#define LEN(array) (sizeof(array) / sizeof(array[0]))

typedef int BOOL;
#define TRUE  1;
#define FALSE 0;

static int s_data[] = {12, 2, 16, 30, 8, 28, 4, 10, 20, 6, 18};
static int s_len = LEN(s_data);


void printList(int[], int);
void swap(int*, int*);
void bubbleSortV1(int[], int);
void bubbleSortV2(int[], int);
void bubbleSortV3(int[], int);


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
            printList(s_data, s_len);
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
            printList(s_data, s_len);
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
            printList(s_data, s_len);
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

int main(int argc, char** argv) {
    printList(s_data, s_len);
    printf("\n");

    //bubbleSortV1(s_data, s_len);
    //bubbleSortV2(s_data, s_len);
    bubbleSortV3(s_data, s_len);

    printf("\n");
    printList(s_data, s_len);
    return 0;
}
