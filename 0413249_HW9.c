#include <stdio.h>

#include <stdlib.h>

#include "recongizer.h"

#include "generator.h"



int main()

{



    while(1)

    {



    char number[5];

    printf("Enter your choice : (1)recognizer (2)generator : ");

    fflush(stdin);

    fgets(number, 5, stdin);

    if(number[0] == '1')

    {

       extern char string_[100];

       printf("enter a binary string ");

       fflush(stdin);

       fgets(string_, 100, stdin);

       extern int state ;

       state = 1;

       extern int index__;

       index__ = 0;

       rec_x3();



       if(state == 1)

        printf("Accepted \n");

       else

        printf("Rejected  \n");

    }

    else

    {

       printf("enter the length of binary string :");

       char n[12];

       fflush(stdin);

       fgets(n, 12, stdin);

       int length = atoi(n);

        stack_clear();

       printf("%d binary strings in total \n",gen_x3(length));





    }

    }

    return 0;

}

