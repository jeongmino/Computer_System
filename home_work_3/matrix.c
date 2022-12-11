#include <stdio.h>

#define ROW 4
#define COL 4

void swap(int *x, int *y)
{
    int tmp = *x;
    *x= *y;
    *y= tmp;
    return ;
}

void print_matrix(int mat[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }

}

int main(void)
{
	int ori_mat[4][4];
    int trans_mat[4][4];
    int sum_mat[4][4];

    for (int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            printf("Input your number : ");
            scanf("%d", &ori_mat[i][j]);
            trans_mat[i][j] = ori_mat[i][j];
        }
    }
    printf("-----------Original matrix-------------\n");
    print_matrix(ori_mat);
    for (int i = 0; i < ROW; i++)
    {
        for(int j = i; j < COL; j++)
        {
            swap(&trans_mat[i][j], &trans_mat[j][i]);
        }
    }
    printf("-----------Transposed matrix-------------\n");
    print_matrix(trans_mat);
    for (int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            sum_mat[i][j] = ori_mat[i][j] + trans_mat[i][j];
        }
    }
    printf("------------Sum matrix-------------\n");
    print_matrix(sum_mat);
    return (0);
}
    

