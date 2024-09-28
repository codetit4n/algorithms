#ifndef MY_HEADER_H
#define MY_HEADER_H

#include <stdio.h>

static inline void display_arr_1D(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

static inline void display_arr_1D_with_msg(char *message, int arr[], int size) {
    printf("%s", message);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


static inline void display_arr_2D(int rows, int cols, int arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

static inline void display_arr_2D_with_msg(char *message, int rows, int cols, int arr[rows][cols]) {
    printf("%s\n", message);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}


#endif // MY_HEADER_H
