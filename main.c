#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *matrix_info_file;
    matrix_info_file=fopen("readinput.txt","r");//there is a code way to read input from ".txt" file
                                                //"r"=>read file mode

    int N;//Dimension of matrices
    fscanf(matrix_info_file,"%d",&N);//this code will open the .txt file and assign the value of N

    int number_of_non_zeros_items=(N*(N+1)/2);//This line will find the number of items

    int *MatrixA=(int*)malloc(sizeof(int)*N*(N+1)/2);//define of MatrixA
                                                     //in this code,there is a malloc function for memory
    int *MatrixB=(int*)malloc(sizeof(int)*N*(N+1)/2);//define of MatrixB

    int *CopyMatrixA=(int*)malloc(sizeof(int)*(N*N));//There is a copy matrix to include zeros items

    int *CopyMatrixB=(int*)malloc(sizeof(int)*(N*N));//There is a copy matrix to include zeros items

    //this loop read the items of matrixA
    for(int i=0;i<number_of_non_zeros_items;i++){
            MatrixA[i]=0;//assign to 0 because maybe there is a another value in the copy matrix array
            fscanf(matrix_info_file,"%d",&MatrixA[i]);//assign the items of matrixA from .txt file
    }

    //this loop read the items of matrixB
    for(int i=0;i<number_of_non_zeros_items;i++){
        MatrixB[i]=0;//assign to 0 because maybe there is a another value in the copy matrix array
        fscanf(matrix_info_file,"%d",&MatrixB[i]);//assign the items of matrixB from .txt file
    }

    fclose(matrix_info_file);//this code will close the .txt file

    //this function assign the zeros items and non zeros items in the copy matrix
    void Copy_Matrix(int *Matrix, int *CopyMatrix, int N) {
    for (int i = 0; i < N * N; i++) {
        CopyMatrix[i] = 0;
    }
    int index = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            CopyMatrix[i * N + j] = Matrix[index];
            index++;
        }
    }
    }

     Copy_Matrix(MatrixA,CopyMatrixA,N);
     Copy_Matrix(MatrixB,CopyMatrixB,N);

    //this loop prints copy matrixA like a 2D array
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", CopyMatrixA[i * N + j]);
        }
        printf("\n");
    }

    printf("\n");

    //this loop prints copy matrixB like a 2D array
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", CopyMatrixB[i * N + j]);
        }
        printf("\n");
    }

    printf("\n");

    //This function will multiply two matrices
    int *MatrixC=(int*)malloc(sizeof(int)*N*N);//define the result matrix with malloc

    //this function multiplies the matrixes parameters
    void Multiply_Matrices(int MatrixA[],int MatrixB[],int MatrixC[]){
        // !!!!! I can explain these code so, these are definitly not copy!!!!! //
        for(int multiply_index=0;multiply_index<N;multiply_index++){
            for(int row_index=0;row_index<N;row_index++){
                MatrixC[multiply_index*N+row_index]=0;//assign to 0 because there is another value in the result matrix
                for(int column_index=0;column_index<N;column_index++){
                    MatrixC[multiply_index*N+row_index]+=CopyMatrixA[multiply_index*N+column_index]*CopyMatrixB[column_index*N+row_index];//sums of the multiply results put in result matrix
                }
            }
        }
    }
    Multiply_Matrices(CopyMatrixA,CopyMatrixB,MatrixC);//this code runs the multiply function

    //this loop prints the result matrix like a 2D array
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", MatrixC[i * N + j]);
        }
        printf("\n");
    }


    // these codes lines unload memory because we do not need memory allocation now
    free(MatrixA);
    free(MatrixB);
    free(CopyMatrixA);
    free(CopyMatrixB);

    return 0;
}

