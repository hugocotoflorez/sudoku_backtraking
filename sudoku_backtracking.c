#include <stdio.h>

void print(int s[9][9])
{
    putchar('\n');
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(s[i][j])
                printf("%d", s[i][j]);
            else
                putchar('_');
            putchar(' ');
        }
        putchar('\n');
    }
    putchar('\n');
}

int is_valid(int s[9][9], int i, int j)
{
    for(int k = 0; k < 9; k++)
    {
        if((s[i][k] == s[i][j] && k != j) || (s[k][j] == s[i][j] && k != i))
            return 0;
    }
    for(int ii = (i / 3) * 3; ii < (i / 3) * 3 + 3; ii++)
        for(int jj = (j / 3) * 3; jj < (j / 3) * 3 + 3; jj++)
            if(s[ii][jj] == s[i][j] && i != ii && j != jj)
                return 0;
    return 1;
}


int solve(int s[9][9])
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(s[i][j] == 0) // unassigned possition
            {
                for(int k = 1; k <= 9; k++)
                {
                    s[i][j] = k;
                    if(is_valid(s, i, j))
                        if(solve(s))
                            return 1;
                }
                s[i][j] = 0;
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    // clang-format off
    int sudoku [9][9] = {
        8, 0, 0,    0, 0, 0,    0, 0, 0,
        0, 0, 3,    6, 0, 0,    0, 0, 0,
        0, 7, 0,    0, 9, 0,    2, 0, 0,

        0, 5, 0,    0, 0, 7,    0, 0, 0,
        0, 0, 0,    0, 4, 5,    7, 0, 0,
        0, 0, 0,    1, 0, 0,    0, 3, 0,

        0, 0, 1,    0, 0, 0,    0, 6, 8,
        0, 0, 8,    5, 0, 0,    0, 1, 0,
        0, 9, 0,    0, 0, 0,    4, 0, 0,
    };
    // clang-format on
    print(sudoku);
    solve(sudoku);
    print(sudoku);
}
