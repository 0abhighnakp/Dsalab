 #include<stdio.h>

//to read matrix
void readSparsemat(int mat_normal[100][100],int r,int c)
{
    int i=0,j=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&mat_normal[i][j]);
        }
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

//conevrt to sparse matrix 
int sparse(int mat_normal[100][100],int r,int c,int mat_tup[100][3])
{
    //sparse  to Tuple Form Conversion
   
    int i,j,cnz=0,tr=0,tc=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(mat_normal[i][j]!=0)
            {
                cnz++;
                mat_tup[cnz][0]=i;
                mat_tup[cnz][1]=j;
                mat_tup[cnz][2]=mat_normal[i][j];
            }
            
        }
    }
    mat_tup[0][0]=r;
    mat_tup[0][1]=c;
    mat_tup[0][2]=cnz;
    tr=cnz+1;
    //tc=3;
    return tr;
    
}

void main()
{
    int mat[100][100],r,c;
    int mattup[100][3];
    
    printf("\nEnter the no. of rows:");
    scanf("%d",&r);
    printf("\nEnter the no. of columns:");
    scanf("%d",&c);
    printf("Enter the elements\n");
    readSparsemat(mat,r,c);
    int tr1=sparse(mat,r,c,mattup);
    transpose(mattup);
 }
