#include <stdio.h>
#define ROW 2
#define COLS 3

int main()
{
    // 1d array

    int arr1D[ROW] = {1, 2, 3, 4, 5};
    for (int i = 0; i < ROW; i++)
    {
        printf("%d\t", arr1D[i]);
    }
    printf("\n");

    int arr2D[ROW][COLS] = { {1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}
    }

    // for{}

    return 0;
}
