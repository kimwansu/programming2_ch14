#include <stdio.h>
#include <math.h>
#include <Windows.h>

#define WIDTH 20
#define HEIGHT 20

enum position {
    TOP_LEFT = 1, TOP, TOP_RIGHT,
    LEFT, CENTER, RIGHT,
    BOTTOM_LEFT, BOTTOM, BOTTOM_RIGHT
};

int get_horizontal_pos(int* pos, int* base, int width);
int get_vertical_pos(int* pos, int* base, int width, int height);
void print_board(int *board, int width, int height);
void gotoxy(int x, int y);

void Blinker(int board[HEIGHT][WIDTH])
{
    board[1][0] = 1;
    board[1][1] = 1;
    board[1][2] = 1;
}

void Toad(int board[HEIGHT][WIDTH])
{
    board[3][7] = 1;
    board[3][8] = 1;
    board[3][9] = 1;
    board[4][6] = 1;
    board[4][7] = 1;
    board[4][8] = 1;
}

void Beacon(int board[WIDTH][HEIGHT])
{
    board[2][13] = 1;
    board[2][14] = 1;
    board[3][13] = 1;
    board[3][14] = 1;
    board[4][15] = 1;
    board[4][16] = 1;
    board[5][15] = 1;
    board[5][16] = 1;
}

void Pulsar(int board[WIDTH][HEIGHT])
{
    board[6][4] = 1;
    board[6][5] = 1;
    board[6][6] = 1;
    
    board[11][4] = 1;
    board[11][5] = 1;
    board[11][6] = 1;
    
    board[13][4] = 1;
    board[13][5] = 1;
    board[13][6] = 1;
    
    board[18][4] = 1;
    board[18][5] = 1;
    board[18][6] = 1;
    
    
    board[8][2] = 1;
    board[9][2] = 1;
    board[10][2] = 1;
    
    board[8][7] = 1;
    board[9][7] = 1;
    board[10][7] = 1;
    
    board[8][9] = 1;
    board[9][9] = 1;
    board[10][9] = 1;
    
    board[8][14] = 1;
    board[9][14] = 1;
    board[10][14] = 1;
    
    
    board[6][10] = 1;
    board[6][11] = 1;
    board[6][12] = 1;
    
    board[11][10] = 1;
    board[11][11] = 1;
    board[11][12] = 1;
    
    board[13][10] = 1;
    board[13][11] = 1;
    board[13][12] = 1;
    
    board[18][10] = 1;
    board[18][11] = 1;
    board[18][12] = 1;
    
    
    board[14][2] = 1;
    board[15][2] = 1;
    board[16][2] = 1;
    
    board[14][7] = 1;
    board[15][7] = 1;
    board[16][7] = 1;
    
    board[14][9] = 1;
    board[15][9] = 1;
    board[16][9] = 1;
    
    board[14][14] = 1;
    board[15][14] = 1;
    board[16][14] = 1;
}

int main()
{
    int g;
    int i;
    int gene = 1000;
    int* p;
    int* next_p;
    int neighbor;

    int board1[WIDTH][HEIGHT] = { 0 };
    int board2[WIDTH][HEIGHT] = { 0 };

    int* board_base = &(board1[0][0]);
    int* next_base = &(board2[0][0]);
    int* tmp;

    int pos;
    
    // 초기값 넣기
    Blinker(board1);
    Toad(board1);
    Beacon(board1);
    Pulsar(board1);

    print_board(board_base, WIDTH, HEIGHT);

    for (g = 0; g < gene; g++)
    {
        p = board_base;
        for (i = 0; i < WIDTH * HEIGHT; i++, p++)
        {
            pos = get_position(p, board_base, WIDTH, HEIGHT);
            neighbor = 0;
            
            neighbor += (pos != TOP_LEFT) & *(p - WIDTH - 1);
            neighbor += (pos != TOP) & *(p - WIDTH);
            neighbor += (pos != TOP_RIGHT) & *(p - WIDTH + 1);

            neighbor += (pos != LEFT) & *(p - 1);
            neighbor += (pos != RIGHT) & *(p + 1);

            neighbor += (pos != BOTTOM_LEFT) & *(p + WIDTH - 1);
            neighbor += (pos != BOTTOM) & *(p + WIDTH);
            neighbor += (pos != BOTTOM_RIGHT) & *(p + WIDTH + 1);

            next_p = next_base + (p - board_base);
            if (neighbor == 3)
                *next_p = 1;
            else if (neighbor >= 4 || neighbor < 2)
                *next_p = 0;
            else
                *next_p = *p;
        }
        print_board(board_base, WIDTH, HEIGHT);

        tmp = board_base;
        board_base = next_base;
        next_base = tmp;
    }

    return 0;
}

int get_position(int* pos, int* base, int width, int height)
{
    int row = (pos - base) / width; 
    int col = (pos - base) % width;

    int p = CENTER;
    if (row == 0)
        p -= 3;
    else if (row == height - 1)
        p += 3;

    if (col == 0)
        p -= 1;
    else if (col == width - 1)
        p += 1;

    return p;
}

void print_board(int *board, int width, int height)
{
    int i;
    int j;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            putchar(*(board + (i * width + j)) ? 'O' : ' ');
            putchar(' ');
        }
        putchar('\n');
    }

    Sleep(200);
    gotoxy(0, 0);
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}