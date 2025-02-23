/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <conio.h>

int main()
{
    int i,j,k,n;
    float A[20][20],c,x[10],sum=0.0;
    printf("\n Enter the order of the matrix: ");
    scanf("%d",&n);
    printf("\n Enter the entries of the augmented matrix row-wise: \n\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n+1;j++){
            scanf("%f",&A[i][j]);
        }
    }
    for(j=1;j<=n+1;j++){
        for(i=1;i<=n;i++){
            if(i>j){
                c = A[i][j]/A[j][j];
                for(k=1;k<=n+1;k++){
                    A[i][k] = A[i][k] - c*A[j][k];
                }
            }
        }
    }
    x[n] = A[n][n+1]/A[n][n];
    for(i= n-1; i>=1; i--){
        sum = 0;
        for(j=i+1;j<=n; j++){
            sum += A[i][j]*x[j];
            
        }
        x[i] = (A[i][n+1]-sum)/A[i][i];
    }
    printf("\n The required solution is: \n \n");
    for(i=1;i<=n;i++){
        printf("\n x%d = %f\t",i,x[i]);
    }

    return 0;
}
