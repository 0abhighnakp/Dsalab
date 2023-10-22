#include<stdio.h>

//to read matrix
void sparce(int sr[100][3])
{
    int i,j,k=1;
    printf("Enter total number of rows of sparse matrix :");
    scanf("%d",&sr[0][0]);
    printf("Enter total number of colunm of sparse matrix :");
    scanf("%d",&sr[0][1]);
    printf("Enter total number of non zero elements of sparse matrix :");
    scanf("%d",&sr[0][2]);
            for(i=1;i<sr[0][2]+1;i++){
                printf("Enter row coloum value :");
                for(j=0;j<3;j++){
                       scanf("%d",&sr[i][j]);
                }
            }
        for(k=0;k<sr[0][2]+1;k++){
            for(j=0;j<3;j++){
                printf("%d",sr[k][j]);
            }
            printf("\n");
        }
}
//for transpose
void transpose(int mat_tup[100][3])
{
    // Transpose
    int temp[100],i,j;
    int tr=mat_tup[0][2];
    for(i=0;i<tr;i++)
    {
        temp[i]=mat_tup[i][0];
    }
    for(i=0;i<tr;i++) // exchanging row and column indexes
    {
        mat_tup[i][0]= mat_tup[i][1];
         mat_tup[i][1]=temp[i];
    }
    
    printf("\nThe Transpose is\n");
    for(i=0;i<tr+1;i++)
    {
        printf("\n");
        for(j=0;j<3;j++)
        {
            printf("%d  ",mat_tup[i][j]);
        }
    }
    
}

void main()
{
    int mat[100][3];
    sparce(mat);
    transpose(mat);
}
