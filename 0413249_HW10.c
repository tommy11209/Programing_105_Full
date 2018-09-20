#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b);
int cmp_(const void *p, const void *q);
struct n{
    char site_name[100];
    char date[100];
    char concentration[100];
    char unit[100];
}data[1001];

int cmp_s(const void *a, const void *b, int num)
{
    if((( struct n *)a)->site_name[num] > (( struct n *)b)->site_name[num])
    {
        return 1;
    }
    else if((( struct n *)a)->site_name[num] == (( struct n *)b)->site_name[num])
    {
        return cmp_s(a, b, num + 1);
    }
    else
        return -1;

}

int cmp(const void *a, const void *b)                            ///字母由小到大
{
    return cmp_s(a, b, 0);
}
int cmp_(const void *p, const void *q)                          ///數字由大到小
{
    if( atoi(((struct n *)p)->concentration) < atoi(((struct n *)q)->concentration))
    {
        return 1;
    }
    else if( atoi(((struct n *)p)->concentration) == atoi(((struct n *)q)->concentration))
    {
        return 0;
    }
    else
        return -1;
}


int main()
{

     char buf[100], c;
     int dot_number=0;
     int i,k;
     FILE *fp;
     FILE *output;
     FILE *output_single;

     fp=fopen("PM2.5.csv","r");
     output=fopen("outcomePair.csv","w");
     output_single=fopen("outcomeSingle.csv","w");
     if(fp == NULL)
         printf("not open\n");
     int buf_index = 0;
     int row=0;
     for(k=0;k<100;k++)
         buf[k]='\0';
     while(fscanf(fp,"%c",&c))
     {
         if(c == ',')
         {
             for(i=0;i<buf_index;i++)
             {
                 if(dot_number == 0)
                     data[row].site_name[i] = buf[i];
                 else if (dot_number == 1)
                     data[row].date[i]=buf[i];
                 else
                     data[row].concentration[i]=buf[i];

             }
             dot_number++;
             buf_index = 0;
         }
         else if(c == '\n')
         {
             for(i=0;i<buf_index;i++)
                 data[row].unit[i]=buf[i];
             dot_number = 0;
             buf_index = 0;
             break;
         }
         else
         {
             buf[buf_index++] = c;
         }
     }

     fprintf(output_single,"%s,%s,%s,%s\n",data[0].site_name , data[0].date , data[0].concentration , data[0].unit);
     row = 0;
     dot_number = 0;
     buf_index = 0;
     for(k=0;k<100;k++)
     {
        data[0].concentration[k]='\0';
        data[0].date[k]='\0';
        data[0].site_name[k]='\0';
        data[0].unit[k]='\0';
     }

     while(fscanf(fp,"%c",&c) != EOF)
     {
         if(c == ',')
         {
             for(i=0;i<buf_index;i++)
             {
                 if(dot_number == 0)
                     data[row].site_name[i] = buf[i];
                 else if (dot_number == 1)
                     data[row].date[i]=buf[i];
                 else
                     data[row].concentration[i]=buf[i];

             }
             dot_number++;
             buf_index = 0;
         }
         else if(c == '\n')
         {
             for(i=0;i<buf_index;i++)
                 data[row].unit[i]=buf[i];
             dot_number = 0;
             buf_index = 0;
             row++;
         }
         else
         {
             buf[buf_index++] = c;
         }
     }

     qsort(data,1001,sizeof(data[0]),cmp_);
     for(i=0;i<=row;i++)
         fprintf(output,"%s,%s,%s,%s\n",data[i].site_name , data[i].date , data[i].concentration , data[i].unit);                ///數字+字母大小
     qsort(data,1001,sizeof(data[0]),cmp);
     for(i=1;i<=row;i++)

        fprintf(output_single,"%s,%s,%s,%s\n",data[i].site_name , data[i].date , data[i].concentration , data[i].unit);        ///字母大小



     fclose(fp);

     return 0;
}

