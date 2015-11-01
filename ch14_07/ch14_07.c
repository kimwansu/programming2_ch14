#include <stdio.h>

#define ROWS 5
#define COLS 10

void binarize(unsigned char* p, int size, unsigned char threshold);
void invert(unsigned char* p, int size);
void print_image(unsigned char* img, int rows, int cols);

int main()
{
    unsigned char image[ROWS][COLS] = {
        { 0, 0, 0, 0, 9, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 9, 9, 0, 0, 0, 0, 0 },
        { 0, 0, 9, 0, 9, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 8, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 9, 0, 0, 0, 0, 0 },
    };

    print_image(image, ROWS, COLS);

    binarize(image, ROWS * COLS, 8);
    print_image(image, ROWS, COLS);

    invert(image, ROWS * COLS);
    print_image(image, ROWS, COLS);

    return 0;
}

void binarize(unsigned char* p, int size, unsigned char threshold)
{
    int i;
    for (i = 0; i < size; i++, p++)
    {
        if (*p < threshold)
            *p = 0;
        else
            *p = 255;
    }
}

void invert(unsigned char* p, int size)
{
    int i;
    for (i = 0; i < size; i++, p++)
    {
        *p = 255 - *p;
    }
}

void print_image(unsigned char* img, int rows, int cols)
{
    int i;
    int j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%3d ", (int)(*(img + (i * cols) + j)));
        }
        printf("\n");
    }
    printf("\n");

}