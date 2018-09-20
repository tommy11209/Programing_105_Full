#include<stdio.h>
#include<stdlib.h>


typedef struct n
{
    int data;
    struct n *next;                       //next���U�@��node
}node;

void insert_node(node **list_temp, int data);
void bubble_Sort(node *list);
void swap(node *a, node *b);
void print_(node *list);

int main()
{
    int int_array;

    node *list = NULL;
    printf("Enter a sequence of integer== \n");

    scanf("%d",&int_array);
    do{

        insert_node(&list,int_array);                                   //�NŪ�J���� ��Jnode
    }while(scanf("%d",&int_array));


    bubble_Sort(list);
    printf("output== ");
    print_(list);

    return 0;
}



void insert_node(node **list_temp, int data)                          //�NŪ�J���� ��Jcurrent node
{
    node *current = (node*)malloc(sizeof(node));
    current->data = data;
    current->next = *list_temp;
    *list_temp = current;                                           //�~��U�@��node
}

void bubble_Sort(node *list)                                 //�Nlinklist ����node �Ѥj�ƨ�p ����NULL����
{
    int swapped;
    node *current;
    node *last_node = NULL;

    if (current == NULL)                                     //�Ycurrent node���Ū�  ����
        return;

    do
    {
        swapped = 0;
        current = list;

        while (current->next != last_node)                             //��current node ���U�@��node����null
        {
            if (current->data < current->next->data)                         //�Ƥj�p
            {
                swap(current, current->next);
                swapped = 1;
            }
            current = current->next;                                   //�~��U�@��node
        }
        last_node = current;                                        //��current node ���U�@�Ӭ�null current��last node
    }while (swapped!=0);

}
void swap(node *a, node *b)                                      //����NODE
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
void print_(node *list)
{
    node *list_temp = list;
    while (list_temp!=NULL)
    {
        printf("%d ", list_temp->data);                              //�̧ǦL�X
        list_temp = list_temp->next;                              //�~��U�@��node
    }
}
