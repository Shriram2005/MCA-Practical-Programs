/*
Question 2:
Write a program to represent sparse matrix using array and perform simple and fast transpose
*/

#include <stdio.h>

void main()
{
    int r, c, i, j, count = 0, k = 1;

    printf("Enter rows and columns respectively : ");
    scanf("%d%d", &r, &c);

    int arr[r][c];

    printf("\nEnter elements of the matrix (total %d elements): ", r * c);
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] != 0)
                count++;
        }
    }

 
    int sp[count + 1][3];
    sp[0][0] = r;
    sp[0][1] = c;
    sp[0][2] = count;

    k = 1;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (arr[i][j] != 0)
            {
                sp[k][0] = i;
                sp[k][1] = j;
                sp[k][2] = arr[i][j];
                k++;
            }
        }
    }

  
    printf("\nOriginal Matrix:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }

  
    printf("\nSparse Matrix Representation:\n");
    for (i = 0; i <= count; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %d ", sp[i][j]);
        }
        printf("\n");
    }

  
    int simple[count + 1][3];
    simple[0][0] = sp[0][1];
    simple[0][1] = sp[0][0];
    simple[0][2] = sp[0][2];

    k = 1;
    for (i = 0; i < sp[0][1]; i++)
    {
        for (j = 1; j <= count; j++)
        {
            if (sp[j][1] == i)
            {
                simple[k][0] = sp[j][1];
                simple[k][1] = sp[j][0];
                simple[k][2] = sp[j][2];
                k++;
            }
        }
    }

    printf("\nSimple Transpose:\n");
    for (i = 0; i <= count; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %d ", simple[i][j]);
        }
        printf("\n");
    }

    int fast[count + 1][3];
    int row_terms[c], starting_pos[c];
    for (i = 0; i < c; i++)
        row_terms[i] = 0;

    for (i = 1; i <= count; i++)
        row_terms[sp[i][1]]++;

    starting_pos[0] = 1;
    for (i = 1; i < c; i++)
        starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];

    fast[0][0] = sp[0][1];
    fast[0][1] = sp[0][0];
    fast[0][2] = sp[0][2];

    for (i = 1; i <= count; i++)
    {
        int col = sp[i][1];
        int pos = starting_pos[col];
        fast[pos][0] = sp[i][1];
        fast[pos][1] = sp[i][0];
        fast[pos][2] = sp[i][2];
        starting_pos[col]++;
    }

    printf("\nFast Transpose:\n");
    for (i = 0; i <= count; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %d ", fast[i][j]);
        }
        printf("\n");
    }
}


