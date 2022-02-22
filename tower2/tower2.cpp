/*Ханойская башня*/

#include <iostream>
using namespace std;
#define Endl cout << endl;

void showBoard(int board[5][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] == 0)
            {
                cout << " \t";
            }

            else
            {
                cout << board[i][j] << "\t";
            }            
        }
        Endl;
    }
    cout << "------------------";
    cout <<"\n\n";
}

int getRow(int board[5][3], int rows, int nCol)
{
    int nRow = -1;
    for (int i = 0; i < rows; i++)
    {
        if (board[i][nCol] != 0)
        {
            nRow = i;
            break;
        }
    }
    return nRow;
}

void move1(char kernel1, char kernel2, int board[5][3], int rows, int cols)
{
    //cout << "Из стержня " << kernel1 << " на стержень " << kernel2 << endl;

    int col1 = (int)kernel1 - (int)'A';
    int col2 = (int)kernel2 - (int)'A';

    int row1 = getRow(board, rows, col1);
    int row2 = getRow(board, rows, col2);

    if (row2 == -1)
    {
        row2 = rows - 1;
    }
    else
    {
        row2--;
    }
    int value = board[row1][col1];
    board[row1][col1] = 0;
    board[row2][col2] = value;

    showBoard(board, rows, cols);
}

bool isEmpty(int board[5][3], int rows, int cols)
{
    int lastRowIndex = rows - 1;
    for (int j = 0; j < cols; j++)
    {
        if (board[lastRowIndex][j] != 0)
            return false;
        
    }
    return true;
}
void initBoard(int discCount, int board[5][3], int rows, int nCol)
{
    int lastRowIndex = rows - 1;
    for (int i = lastRowIndex; discCount > 0; i--)
    {
        board[i][nCol] = discCount;
        discCount--;
    }

}

void moveTower(int disc, char kernel1, char kernel2, char kernelTemp, int board[5][3], int rows, int cols)
{
    if (disc == 0)
    {
        return;
    }
    if (isEmpty(board, rows, cols))
    {
        initBoard(disc, board, rows, 0);

        cout << "Исходная позиция" << endl;
        showBoard(board, rows, cols);
    }
    moveTower(disc - 1, kernel1, kernelTemp, kernel2, board, rows, cols);
    move1(kernel1, kernel2, board, rows, cols);
    moveTower(disc - 1, kernelTemp, kernel2, kernel1, board, rows, cols);
}

int main()
{
    setlocale(LC_ALL, "ru");

    const int rows = 5;
    const int cols = 3;
    int board[rows][cols] = { 0 };
    //showBoard(board, rows, cols);
    moveTower(5, 'A', 'B', 'C', board, rows, cols);
    return 0;
}