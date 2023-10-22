#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "headers.h"

int main()
{
    app();
    return ZERO_FLAG;
}
void app()
{
    int value=ZERO_FLAG, x=ZERO_FLAG, y=ZERO_FLAG, choose=ZERO_FLAG;
    char  wantToSolve=ZERO_FLAG;
    while(1)
    {
        rules_sudoko();
        choose= chooseOP();
        system("cls");
        if(choose==1)
        {
            system("cls");
            solve();
            print_sudoku(sudokuBoard);
            if(printWin()==ZERO_FLAG)
            {
                LevelBack(levelCount);
                createLevel(++levelCount);
            }
            else system("cls");
        }
        else if(choose==2)
        {

            while(1)
            {
                rules_sudoko();
                print_sudoku(sudokuBoard);
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                printf("\t Do You want to solve it ? \n");
                printf("\t press [YES/NO][Y/N] \n \t\tY to solve automatic it N to manual solving ? : ");
                fflush(stdin);
                scanf("%c",&wantToSolve);
                fflush(stdin);
                if(wantToSolve == 'Y' || wantToSolve == 'y')
                {
                    system("cls");
                    solve();
                    print_sudoku(sudokuBoard);
                    if(printWin()==ZERO_FLAG)
                    {
                        LevelBack(levelCount);
                        createLevel(++levelCount);
                    }
                    else system("cls");
                }
                else if(wantToSolve == 'N' || wantToSolve == 'n')
                {
                    printf("\t\t\tEnter the Row  : ");
                    scanf("%d",&x);
                    if(checkValue(x))
                    {
                        printf("\t\t\tEnter the Column : ");
                        scanf("%d",&y);
                        if(checkValue(y))
                        {
                            printf("\t\t\tEnter the value : ");
                            scanf("%d",&value);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
                            if(checkValue(value))
                            {
                                system("cls");
                                set_sudoku(sudokuBoard, x-1,y-1,value);
                            }
                            else
                            {
                                system("cls");
                                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY );
                                printf("%d not allowed Value", value);
                                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            }
                        }
                        else
                        {
                            system("cls");
                            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY );
                            printf("%d not allowed column", y);
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        }
                    }
                    else
                    {
                        system("cls");
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY );
                        printf("%d not allowed row", x);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    }
                    if(printWin()==ZERO_FLAG)
                    {
                        LevelBack(levelCount);
                        createLevel(++levelCount);
                    }
                }
                else
                {
                    system("cls");
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY );
                    printf("Please enter valid letter Y/N \n");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
            }
        }
        else
        {
            exit(0);
        }
    }
}
void createLevel(int level)
{
    int i=0;
    if(level<=1)
    {
        levelCount=1;
    }
    if(level>=8)
    {
        levelCount=8;
    }
    if(level==2)
    {
        for(i=0; i<MAX; i++)
        {
            sudokuBoard[2][i]=0;
            sudokuBoard[4][i]=0;
            sudokuBoard_const[2][i]=0;
            sudokuBoard_const[4][i]=0;
        }
    }
    else if(level==3)
    {
        for(i=0; i<MAX; i++)
        {
            sudokuBoard[3][i]=0;
            sudokuBoard[6][i]=0;
            sudokuBoard_const[3][i]=0;
            sudokuBoard_const[6][i]=0;
        }
    }
    else if(level==4)
    {
        for(i=0; i<MAX; i++)
        {
            sudokuBoard[i][2]=0;
            sudokuBoard[i][4]=0;
            sudokuBoard_const[i][2]=0;
            sudokuBoard_const[i][4]=0;
        }
    }
    else if(level==5)
    {
        for(i=0; i<MAX; i++)
        {
            sudokuBoard[i][3]=0;
            sudokuBoard[i][6]=0;
            sudokuBoard_const[i][3]=0;
            sudokuBoard_const[i][6]=0;
        }
    }
    else if(level==7)
    {
        for(i=0; i<MAX; i++)
        {
            sudokuBoard[i][2]=0;
            sudokuBoard[i][4]=0;
            sudokuBoard[2][i]=0;
            sudokuBoard[4][i]=0;
            sudokuBoard_const[2][i]=0;
            sudokuBoard_const[4][i]=0;
            sudokuBoard_const[i][2]=0;
            sudokuBoard_const[i][4]=0;
        }
    }
    else if(level==8)
    {
        for(i=0; i<MAX; i++)
        {
            sudokuBoard[i][3]=0;
            sudokuBoard[i][6]=0;
            sudokuBoard[3][i]=0;
            sudokuBoard[6][i]=0;
            sudokuBoard_const[3][i]=0;
            sudokuBoard_const[6][i]=0;
            sudokuBoard_const[i][3]=0;
            sudokuBoard_const[i][6]=0;
        }
    }
}
void LevelBack(int level)
{
    int i=0;
    if(level<=1)
    {
        levelCount=1;
    }
    if(level>=8)
    {
        levelCount=8;
    }
    if(level==2)
    {
        for(i=0; i<MAX; i++)
        {
            sudokuBoard[2][i]=sudokuBoard_level_1[2][i];
            sudokuBoard[4][i]=sudokuBoard_level_1[4][i];
            sudokuBoard_const[2][i]=sudokuBoard_level_1[2][i];
            sudokuBoard_const[4][i]=sudokuBoard_level_1[4][i];
        }
    }
    else if(level==3)
    {
        for(i=0; i<MAX; i++)
        {
            sudokuBoard[3][i]=sudokuBoard_level_1[3][i];
            sudokuBoard[6][i]=sudokuBoard_level_1[6][i];
            sudokuBoard_const[3][i]=sudokuBoard_level_1[3][i];
            sudokuBoard_const[6][i]=sudokuBoard_level_1[6][i];
        }
    }
    else if(level==4)
    {
        for(i=0; i<MAX; i++)
        {
            sudokuBoard[i][2]=sudokuBoard_level_1[i][2];
            sudokuBoard[i][4]=sudokuBoard_level_1[i][4];
            sudokuBoard_const[i][2]=sudokuBoard_level_1[i][2];
            sudokuBoard_const[i][4]=sudokuBoard_level_1[i][4];
        }
    }
    else if(level==5)
    {
        for(i=0; i<MAX; i++)
        {
            sudokuBoard[i][3]=sudokuBoard_level_1[i][3];
            sudokuBoard[i][6]=sudokuBoard_level_1[i][3];
            sudokuBoard_const[i][3]=sudokuBoard_level_1[i][3];
            sudokuBoard_const[i][6]=sudokuBoard_level_1[i][6];
        }
    }
    else if(level==7)
    {
        for(i=0; i<MAX; i++)
        {
            sudokuBoard[i][2]=sudokuBoard_level_1[i][2];
            sudokuBoard[i][4]=sudokuBoard_level_1[i][4];
            sudokuBoard[2][i]=sudokuBoard_level_1[2][i];
            sudokuBoard[4][i]=sudokuBoard_level_1[4][i];
            sudokuBoard_const[2][i]=sudokuBoard_level_1[2][i];
            sudokuBoard_const[4][i]=sudokuBoard_level_1[4][i];
            sudokuBoard_const[i][2]=sudokuBoard_level_1[i][2];
            sudokuBoard_const[i][4]=sudokuBoard_level_1[i][4];
        }
    }
    else if(level==8)
    {
        for(i=0; i<MAX; i++)
        {
            sudokuBoard[i][3]=sudokuBoard_level_1[i][3];
            sudokuBoard[i][6]=sudokuBoard_level_1[i][6];
            sudokuBoard[3][i]=sudokuBoard_level_1[3][i];
            sudokuBoard[6][i]=sudokuBoard_level_1[6][i];
            sudokuBoard_const[3][i]=sudokuBoard_level_1[3][i];
            sudokuBoard_const[6][i]=sudokuBoard_level_1[6][i];
            sudokuBoard_const[i][3]=sudokuBoard_level_1[i][3];
            sudokuBoard_const[i][6]=sudokuBoard_level_1[i][6];
        }
    }
}
void set_sudoku(int arr[][MAX], int x, int y, int value )
{
    if(sudokuBoard_const[x][y] !=ZERO_FLAG)
    {
        system("cls");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY );
        printf("You can't add %d in const place\n", value);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    else
    {
        if(canEnter(x,y,value))
        {
            sudokuBoard[x][y]=value;
            system("cls");
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY );
            printf("You add %d\n", value);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        else
        {
            system("cls");
            if (!columnCheckFlag)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY );
                printf("Can't add %d in this column\n", value );
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            if (!rowCheckFlag)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY );
                printf("Can't add %d in this row\n", value );
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            if (!boxCheckFlag)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY );
                printf("Can't add %d in this Box\n", value );
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
        }
    }
}

int printWin()
{
    int solvedFlag=checkSolved();
    char continueFlag=ZERO_FLAG ;
    if(solvedFlag)
    {
        system("cls");
        print_sudoku(sudokuBoard);
        Beep(824,1000);
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("\n\n\n");
        printf("      YY      YY               U        U       W               W   IIIIIIII   NN        NN\n");
        printf("       YY    YY      OOOOOO    U        U       W               W      II      NNN       NN\n");
        printf("        YY  YY      O      O   U        U       W               W      II      NNNN      NN\n");
        printf("         YYY       O        O  U        U       W       W       W      II      NN NN     NN\n");
        printf("         YYY       O        O  U        U       W      W W      W      II      NN  NN    NN\n");
        printf("         YYY       O        O  U        U       W     W   W     W      II      NN   NN   NN\n");
        printf("         YYY       O        O  U        U       W    W     W    W      II      NN    NN  NN\n");
        printf("         YYY       O        O  U        U       W   W       W   W      II      NN     NN NN\n");
        printf("         YYY       O        O  U        U       W  W         W  W      II      NN      NNNN\n");
        printf("         YYY        O      O    U      U        W W           W W      II      NN       NNN\n");
        printf("         YYY         OOOOOO      UUUUUU         WW             WW   IIIIIIII   NN        NN\n\n\n");
        printf("                    Enter any key to continue or enter to  exit                \n");
        fflush(stdin);
        scanf("%c",&continueFlag);
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        LevelBack(levelCount);
        desolve();
        if(continueFlag=='\n')
        {
            system("cls");
            exit(0);
        }
        else
        {
            system("cls");
            return 0;
        }
    }
    return 1;
}
void solve()
{
    int i =0, j=0;
    for(i=0; i<MAX; i++)
    {
        for(j=0; j <MAX; j++)
        {
            sudokuBoard[i][j]=sudokuBoard_solved[i][j];
        }
    }
}
void desolve()
{
    int i =0, j=0;
    for(i=0; i<MAX; i++)
    {
        for(j=0; j<MAX; j++)
        {
            sudokuBoard[i][j]=sudokuBoard_const[i][j];
        }
    }
}
int checkSolved()
{
    int i =0, j=0;
    for(i=0; i<MAX; i++)
    {
        for(j=0; j <MAX; j++)
        {
            if(sudokuBoard_solved[i][j] != sudokuBoard[i][j])
            {
                return ZERO_FLAG;
            }
        }
    }
    return 1;
}

int checkValue(int value)
{
    if(value>MAX||value<ZERO_FLAG)
    {
        return ZERO_FLAG;
    }
    return 1;
}
int canEnter(int x, int y, int value)
{
    columnCheckFlag=checkColumn(y, value);
    rowCheckFlag =checkRow(x, value);
    boxCheckFlag = checkBox(x-x%3,y-y%3,value);
    return columnCheckFlag && rowCheckFlag && boxCheckFlag;
}
int checkBox(int initial_row, int initial_col, int value)
{
    int i=0, j=0;
    for(i=0; i<(MAX/3); i++)
    {
        for(j=0; j<(MAX/3); j++)
        {
            if(sudokuBoard[i+initial_row][j+initial_col] == value)
            {
                return ZERO_FLAG;
            }
        }
    }
    return 1;
}
int checkRow (int x, int value)
{
    int i=0;
    for(i=0; i<MAX; i++)
    {
        if(sudokuBoard[x][i] == value)
        {
            return 0;
        }
    }
    return 1;
}
int checkColumn (int y, int value)
{
    int i=0;
    for(i=0; i<MAX; i++)
    {
        if(sudokuBoard[i][y] == value)
        {
            return 0;
        }
    }
    return 1;
}

void print_sudoku(int arr[][MAX])
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    printf("\t\t\t\t-----------------------------------\n");
    printf("\t\t\t\t   | 1  2  3  | 4  5  6  | 7  8  9 \n");
    printf("\t\t\t\t-----------------------------------\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
    int i, j;
    for(i=0; i<MAX; i++)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
        printf("\t\t\t\t %d | ",i+1);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        for(j=0; j<MAX; j++)
        {
            if(j == 3 || j == 6)
            {
                printf("| ");
            }
            if(arr[i][j]==ZERO_FLAG)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                printf("%d  ",arr[i][j]);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            else if(sudokuBoard_const[i][j] !=ZERO_FLAG)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY );
                printf("%d  ",arr[i][j]);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            else
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
                printf("%d  ",arr[i][j]);
                SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
        printf("\n");
        if((i+1)%3==ZERO_FLAG)
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            printf("\t\t\t\t-----------------------------------\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        }
    }
}
void rules_sudoko()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY );
    printf("\n*********************************** Rules Of Sudoku **********************************\n");
    printf("\t\t---------------- Your level is   %d ----------------\n", levelCount);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    HANDLE yConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(yConsole, FOREGROUND_INTENSITY  | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("\t\tRed Number is Const You Can't Replace it By Any Number .\n");
    printf("\t\tYou Can't Edit Number Like Any Number In Same ( Row || Column || Box) .\n");
    printf("\t\tYou Can Edit Number By Enter Row , Column And Value .\n");
    SetConsoleTextAttribute(yConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
int chooseOP()
{
    int choose;
    HANDLE yConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(yConsole, FOREGROUND_INTENSITY  | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("\t----------------------------------------------------------------------\n");
    printf("1. Choose 1 to solve the game . \n");
    printf("2. Choose 2 to play or continue the game . \n");
    printf("3. Choose any key to exit the game . \n");
    scanf("%d",&choose);
    SetConsoleTextAttribute(yConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return choose;
}
