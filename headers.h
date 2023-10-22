#ifndef HEADER.H
#define HEADER.H
#define MAX 9
#define ZERO_FLAG 0
int sudokuBoard[MAX][MAX] =
{
    { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
    { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
    { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
    { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
    { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
    { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
    { 0, 0, 5, 2, 0, 6, 3, 0, 0 }
};
const int sudokuBoard_level_1[MAX][MAX] =
{
    { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
    { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
    { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
    { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
    { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
    { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
    { 0, 0, 5, 2, 0, 6, 3, 0, 0 }
};
int sudokuBoard_const[MAX][MAX] =
{
    { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
    { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
    { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
    { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
    { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
    { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
    { 0, 0, 5, 2, 0, 6, 3, 0, 0 }
};
int sudokuBoard_solved[MAX][MAX] =
{
    { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
    { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
    { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
    { 2, 6, 3, 4, 1, 5, 9, 8, 7 },
    { 9, 7, 4, 8, 6, 3, 1, 2, 5 },
    { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
    { 1, 3, 8, 9, 4, 7, 2, 5, 6 },
    { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
    { 7, 4, 5, 2, 8, 6, 3, 1, 9 }
};
int columnCheckFlag =ZERO_FLAG,rowCheckFlag=ZERO_FLAG, boxCheckFlag=ZERO_FLAG;
int levelCount=1;

void app();

void print_sudoku(int arr[][MAX]);

void set_sudoku(int arr[][MAX], int x, int y, int value );

int checkColumn (int y, int value);
int checkRow(int x, int value);
int checkBox(int initial_row, int initial_col, int value);
int canEnter(int x, int y, int value);
int checkValue(int value);

int printWin();

int checkSolved();
void solve();
void desolve();
void createLevel(int level);
void LevelBack(int level);

void rules_sudoko();
int chooseOP();

#endif // HEADER
