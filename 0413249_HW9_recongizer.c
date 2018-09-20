#include <stdio.h>

#include <stdlib.h>

#include "recongizer.h"



char string_[100];

int index__;

int state;

void rec_x3()

{

   if(string_[index__]=='\0' || string_[index__]=='\n')

     {

        state = 1;

        return;

     }

   else if(string_[index__++]=='1')

      return rec_x3();

   else

      return rec_x3_1();



}

void rec_x3_1()

{

    if(string_[index__]=='\0' || string_[index__]=='\n')

     {

        state = 2;

        return;

     }

   else if(string_[index__++]=='1')

      return rec_x3_1();

   else

      return rec_x3_2();

}

void rec_x3_2()

{

    if(string_[index__]=='\0' || string_[index__]=='\n')

     {

        state = 3;

        return;

     }

   else if(string_[index__++]=='1')

      return rec_x3_2();

   else

      return rec_x3();

}



