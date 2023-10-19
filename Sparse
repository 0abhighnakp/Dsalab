#include<stdio.h>

int main()
{	
	int r,c,matrix[100][100],size = 0;
	int sparseMatrix[100][3],k=0;
	
	printf("enter number of rows ");
	scanf("%d",&r);
	printf("enter number of column");
	scanf("%d",&c);

  //read matrix
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("enter element of row %d and column %d : ",i+1,j+1);
			scanf("%d", &matrix[i][j]);
		}
	}

	//to find number of non zero elements
	for (int i = 0; i < r; i++){
		 for (int j = 0; j < c; j++){
			 if (matrix[i][j] != 0)
                size++;
		 }
	
	}
	
	//sparse matrix
	for(int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			 if (matrix[i][j] != 0)
            {
                sparseMatrix[k][0] = i;
                sparseMatrix[k][1] = j;
                sparseMatrix[k][2] = matrix[i][j];
                k++;
            }
		}
           
	}

  //print sparse matrix
	for (int i=0; i<size; i++){
        for (int j=0; j<3; j++){
			printf("%d ", sparseMatrix[i][j]);
 
		}
            
        printf("\n");
    }
    return 0;
        
        
}
