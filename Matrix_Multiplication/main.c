/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Furkan_ATAK_HW1.c
 * Author: Pc
 *
 * Created on 15 November 2020, 20:54
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


float** createSqrMatrix(int n){ // matris oluşturma (malloc ile)
    float **A;
    A = (float**)calloc(sizeof(float*),n);
     int i;
    for (i = 0; i < n; i++) {
        A[i] = (float*)calloc(sizeof(float),n);
    }
 return A;    
}
float** fillSqrMatrix(float** A,int n){ // matrisi random değerler ile doldurma
    int i,j;
    srand(time(0));
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = (float)(rand() % 10);
        }
    }
    return A;
}
float** matrixMatrixMultiply1(float **A,float **B,int n){  // i,j,k için matris çarpımı
    float** result;                                        // diğer döngülerin herbiri için de 
    result = createSqrMatrix(n);                           // herbirine ayrı metot
    A = fillSqrMatrix(createSqrMatrix(n),n);
    B = fillSqrMatrix(createSqrMatrix(n),n);
    int i,j,k;
    clock_t start1 = clock();
    for(i = 0; i < n; i++){
        for(j = 0;j < n; j++){
                for(k = 0; k < n; k++){
                    result[i][j] += A[i][k]*B[k][j];
                }
        }
    }
    clock_t end1 = clock();
    double exe = ((double)(end1 - start1) / CLOCKS_PER_SEC);
    printf("Exe time of i, j, k = %.2lf sec\n", exe);  
    return result;
}
float** matrixMatrixMultiply2(float **A,float **B,int n){
    float **result;
    result = createSqrMatrix(n);
    A = createSqrMatrix(n);
    B = createSqrMatrix(n);
    int i,j,k;
    clock_t start1 = clock();
    for(i = 0; i < n; i++){
        for(k = 0;k < n; k++){
                for(j = 0; j < n; j++){
                    result[i][j] += A[i][k]*B[k][j];
                }
        }
    }
    clock_t end1 = clock();
    double exe = ((double)(end1 - start1) / CLOCKS_PER_SEC);
    printf("Exe time of i, k, j = %.2lf sec\n", exe);  
    return result;
}
float** matrixMatrixMultiply3(float **A,float **B,int n){
    float **result;
    result = createSqrMatrix(n);
    A = createSqrMatrix(n);
    B = createSqrMatrix(n);
    int i,j,k;
    clock_t start1 = clock();
    for(j = 0; j < n; j++){
        for(i = 0;i < n; i++){
                for(k = 0; k < n; k++){
                    result[i][j] += A[i][k]*B[k][j];
                }
        }
    }
    clock_t end1 = clock();
    double exe = ((double)(end1 - start1) / CLOCKS_PER_SEC);
    printf("Exe time of j, i, k = %.2lf sec\n", exe);  
    return result;
}
float** matrixMatrixMultiply4(float **A,float **B,int n){
    float **result;
    result = createSqrMatrix(n);
    A = createSqrMatrix(n);
    B = createSqrMatrix(n);
    int i,j,k;
    clock_t start1 = clock();
    for(j = 0; j < n; j++){
        for(k = 0;k < n; k++){
                for(i = 0; i < n; i++){
                    result[i][j] += A[i][k]*B[k][j];
                }
        }
    }
    clock_t end1 = clock();
    double exe = ((double)(end1 - start1) / CLOCKS_PER_SEC);
    printf("Exe time of j, k, i = %.2lf sec\n", exe);  
    return result;
}
float** matrixMatrixMultiply5(float **A,float **B,int n){
    float **result;
    result = createSqrMatrix(n);
    A = createSqrMatrix(n);
    B = createSqrMatrix(n);
    int i,j,k;
    clock_t start1 = clock();
    for(k = 0; k < n; k++){
        for(i = 0;i < n; i++){
                for(j = 0; j < n; j++){
                    result[i][j] += A[i][k]*B[k][j];
                }
        }
    }
    clock_t end1 = clock();
    double exe = ((double)(end1 - start1) / CLOCKS_PER_SEC);
    printf("Exe time of k, i, j = %.2lf sec\n", exe);  
    return result;
}
float** matrixMatrixMultiply6(float **A,float **B,int n){
    float **result;
    result = createSqrMatrix(n);
    A = createSqrMatrix(n);
    B = createSqrMatrix(n);
    int i,j,k;
    clock_t start1 = clock();
    for(k = 0; k < n; k++){
        for(j = 0;j < n; j++){
                for(i = 0; i < n; i++){
                    result[i][j] += A[i][k]*B[k][j];
                }
        }
    }
    clock_t end1 = clock();
    double exe = ((double)(end1 - start1) / CLOCKS_PER_SEC);
    printf("Exe time of k, j, i = %.2lf sec\n", exe);  
    return result;
}

int main(int argc, char** argv) {
   // printf("Başlamak için Enter'a basınız. (Program kapatılana kadar matris çarpımı yapabilirsiniz.)\n");
    float **A;
    float **B;    
    int n;
    while(1){    // program kapatılana kadar girilen boyutun exe sürelerini yazdırma.
    printf("Please Enter The Size Of Matrix: ");
    scanf("%d",&n);
    matrixMatrixMultiply1(A,B,n);
    matrixMatrixMultiply2(A,B,n);
    matrixMatrixMultiply3(A,B,n);
    matrixMatrixMultiply4(A,B,n);
    matrixMatrixMultiply5(A,B,n);
    matrixMatrixMultiply6(A,B,n);
    }
    return (EXIT_SUCCESS);
}

