#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct n{
    char c;
    struct n *next;                                  //下一個node

}node;

void append(node * list, node * final_)            //一個個node連接起來
{
    node * node_temp = list;
    while(node_temp->next)                         //當next有值時 使他成為下一個node
        node_temp = node_temp->next;
    node_temp->next = final_;                           //最後一個node為final_  他的下一個為null
    final_->next = NULL;
}
char* reverse(node *list, int m, char * string_array)
{
    int i;

    for(i=m-1;i>=0;i--)
    {
       string_array[i]=list->c;                                //將node中的值 反向存入array
       list=list->next;                                       //list next為下一個node
    }
    string_array[m-1] = '\0';                                  //字串結束
    return string_array;
}


int main()
{
    while(1)
    {
   int long_;
   int i;
   node n;                                     //令最後一個node為n
   node *list;
   *list = &n;
   n.next = NULL;
   char string_array[200];
   printf("Enter a string = ");
   fgets(string_array,200,stdin);
   long_=strlen(string_array);                     //讀入array之長度

   for(i=0;i<long_;i++)
   {
      node * n = (node *)malloc(sizeof(node));
      n->c = string_array[i];
      append(list, n);
   }

    reverse(list,long_,string_array);

    printf("string reversal = %s\n",string_array);
    }
    return 0;
}
