
#include <stdio.h>

#include <stdlib.h>

#include "generator.h"

struct s{

    int top;

    char data[100];

} stack;

void stack_push(char c)

{

    stack.data[stack.top++] = c;

}

char stack_pop()

{

    return stack.data[stack.top--];

}

void stack_clear()

{

    stack.top = 0;

}

void stack_print()

{

    stack.data[stack.top] = '\0';

    printf("%s \n", stack.data);

}





int gen_x3(int n)

{

    if(n == 0)

    {

        stack_print();

        return 1;

    }

    stack_push('0');                     //�]0 �ǳƶi�U�@�h

    int sum = gen_x3_1(n-1);

    stack_pop();//���k��

    stack_push('1');                    // �A�^�_�쥻��index �]��1

    sum += gen_x3(n-1);

    stack_pop();

    return sum ;                   //���U��

}

int gen_x3_1(int n)

{

    if(n == 0)

    {

       return 0;

    }

    stack_push('0');                     //�]0 �ǳƶi�U�@�h

    int sum = gen_x3_2(n-1);

    stack_pop();//���k��

    stack_push('1');                    // �A�^�_�쥻��index �]��1

    sum += gen_x3_1(n-1);

    stack_pop();

    return sum ;



}

int gen_x3_2(int n)

{

    if(n == 0)

    {

       return 0;

    }

    stack_push('0');                     //�]0 �ǳƶi�U�@�h

    int sum = gen_x3(n-1);

    stack_pop();//���k��

    stack_push('1');                    // �A�^�_�쥻��index �]��1

    sum += gen_x3_2(n-1);

    stack_pop();

    return sum ;

}


