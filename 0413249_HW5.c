#include <stdio.h>
#include <stdlib.h>

typedef struct m{
    int a,b,c,d;                           //�w�qmatrix�̧t��4���ܼ�
}matrix;

matrix mul(matrix m1,matrix m2)                       //��2��2*2�x�}����
{
   matrix matrix_temp;
   matrix_temp.a= m1.a*m2.a+m1.b*m2.c;
   matrix_temp.b= m1.a*m2.b+m1.b*m2.d;
   matrix_temp.c= m1.a*m2.c+m1.d*m2.c;
   matrix_temp.d= m1.c*m2.b+m1.d*m2.d;
   return matrix_temp;

}

matrix pow_(matrix m,int n)                            //��x�}��n����
{
    if(n==0)                                           //���x�}
    {
        matrix matrix1;
        matrix1.a =1;
        matrix1.b =0;
        matrix1.c =0;
        matrix1.d =1;
        return matrix1;
    }


    if(n%2!=0)                                         //�_��
    {
        return mul(m, pow_(m,n-1));                    //m*m^n-1  ���j
    }
    else
    {
        return pow_(mul(m,m),n/2);                      //m^2^n/2  ���j
    }

}


int F(int n)
{
    matrix matrix2;
    matrix matrix3;
    matrix2.a=0;
    matrix2.b=1;
    matrix2.c=1;
    matrix2.d=1;

    matrix3=pow_(matrix2,n);                             //�N����
    return matrix3.b;


}

int main(void)
{
    while(1)
    {
    int n;
    printf("Enter an integer>=0 : ");
    scanf("%d",&n);
    printf("F(%d)=%d  \n",n,F(n));
    }
    return 0;
}
