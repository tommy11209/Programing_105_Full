#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct n{
    char c;
    struct n *next;                                  //�U�@��node

}node;

void append(node * list, node * final_)            //�@�ӭ�node�s���_��
{
    node * node_temp = list;
    while(node_temp->next)                         //��next���Ȯ� �ϥL�����U�@��node
        node_temp = node_temp->next;
    node_temp->next = final_;                           //�̫�@��node��final_  �L���U�@�Ӭ�null
    final_->next = NULL;
}
char* reverse(node *list, int m, char * string_array)
{
    int i;

    for(i=m-1;i>=0;i--)
    {
       string_array[i]=list->c;                                //�Nnode������ �ϦV�s�Jarray
       list=list->next;                                       //list next���U�@��node
    }
    string_array[m-1] = '\0';                                  //�r�굲��
    return string_array;
}


int main()
{
    while(1)
    {
   int long_;
   int i;
   node n;                                     //�O�̫�@��node��n
   node *list;
   *list = &n;
   n.next = NULL;
   char string_array[200];
   printf("Enter a string = ");
   fgets(string_array,200,stdin);
   long_=strlen(string_array);                     //Ū�Jarray������

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
