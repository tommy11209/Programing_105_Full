#include <stdio.h>
#include <stdlib.h>

#define kinds 4

void facevalue(int k);
void ui(void);
int cc(int dollars , int k);

int d[kinds]={1,50,10,5};

struct stack1
{
    int top;
    int stk[100];
}stack;

void facevalue(int k)
{
    if(k == 0)
    {
        printf("$%d", d[0]);
        return;
    }

    int i;
    int max_id=0;
    for(i=0;i<=k;i++)
    {
        if(d[i] < d[max_id])
        {
            max_id = i;
        }
    }
    printf("$%d ", d[max_id]);
    int tmp = d[k];
    d[k] = d[max_id];
    d[max_id] = tmp;
    facevalue(k-1);
    return ;
}
void ui(void)
{
   int dollars;

   if(kinds==0)
    return ;
   else
   {
    printf("enter amount of money = ");
    scanf("%d",&dollars);
    facevalue(3);
    printf("\n");
    printf("there are %d ways to change. \n",cc(dollars,4));
    ui();
   }

}
int cc(int dollars , int k)
{
   int i;
   if(dollars < 0 || k == 0)
      return 0;
   else if(dollars == 0)
   {
       int Am[kinds] = {0};
       for(i=0; i<stack.top; i++)
       {
           switch(stack.stk[i])
           {
               case 1:
                   Am[0]++;
                   break;

               case 5:
                   Am[1]++;
                   break;
               case 10:
                   Am[2]++;
                   break;
               case 50:
                   Am[3]++;
                   break;
           }
       }
       printf("%d  %d  %d  %d\n",Am[0],Am[1],Am[2],Am[3]);
       return 1;
   }


    else
    {
        stack.stk[stack.top++]=d[k-1];
        int M = cc(dollars-d[k-1],k);
        stack.top--;
        return M + cc(dollars,k-1);
    }
}

int main()
{

    ui();

    return 0;
}

