#include <stdio.h>
int main()
{
    // Assume 4x5 sparse matrix
    int sparseMatrix[4][5] =
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };


    int size = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMatrix[i][j] != 0)
                size++;

    int compactMatrix[size+1][3];

    // Making of new matrix
    int k = 1;
    printf("Sparse matrix representation:\n");
    compactMatrix[0][0]=4;
    compactMatrix[0][1]=5;
    compactMatrix[0][2]=size;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMatrix[i][j] != 0)
            {
                compactMatrix[k][0] = i;
                compactMatrix[k][1] = j;
                compactMatrix[k][2] = sparseMatrix[i][j];
                k++;
            }

    for (int i=0; i<size+1; i++)
    {
        for (int j=0; j<3; j++)
            printf(" %d",compactMatrix[i][j]);

        printf("\n");
    }
    /*
    printf("transpose \n");
    //transpose
    
    k=1;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMatrix[i][j] != 0)
            {
                compactMatrix[k][0] = j;
                compactMatrix[k][1] = i;
                compactMatrix[k][2] = sparseMatrix[i][j];
                k++;
            }
    for (int i=0; i<size+1; i++)
    {
        for (int j=0; j<3; j++)
            printf(" %d",compactMatrix[i][j]);

        printf("\n");
    }
    */
    
    
    printf("addition \n");
    //addition
    //just add both sparse matrix and make their compact matrix 
    int size2=0;
    int sparseMatrix2[4][5] =
    {
        {0 , 1 , 0 , 0 , 0 },
        {9 , 0 , 0 , 0 , 10 },
        {0 , 0 , 4 , 0 , 0 },
        {8 , 0 , 0 , 0 , 0 }
    };
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            if((sparseMatrix2[i][j]+sparseMatrix[i][j])!=0)
            {
                sparseMatrix2[i][j]+=sparseMatrix[i][j];
                size2++;
            }
        }
    }
    printf("%d \n",size2);
    int compactmatrix2[size2+1][3];
    compactmatrix2[0][0]=4;
    compactmatrix2[0][1]=5;
    compactmatrix2[0][2]=size2;
    int m=1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(sparseMatrix2[i][j]!=0)
            {
                compactmatrix2[m][0]=i;
                compactmatrix2[m][1]=j;
                compactmatrix2[m][2]=sparseMatrix2[i][j];
                m++;
            }
        }
    }
    for (int i = 0; i < size2+1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d",compactmatrix2[i][j]);
        }
        printf("\n");
    }
  

    //for multiplication just multiply 2 matrix and similarly
    //create their compact matrix
    
 
}