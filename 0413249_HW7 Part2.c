#include<stdio.h>
#include<stdlib.h>


typedef struct n
{
    int data;
    struct n *next;                       //next為下一個node
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

        insert_node(&list,int_array);                                   //將讀入之值 放入node
    }while(scanf("%d",&int_array));


    bubble_Sort(list);
    printf("output== ");
    print_(list);

    return 0;
}



void insert_node(node **list_temp, int data)                          //將讀入之值 放入current node
{
    node *current = (node*)malloc(sizeof(node));
    current->data = data;
    current->next = *list_temp;
    *list_temp = current;                                           //繼續下一個node
}

void bubble_Sort(node *list)                                 //將linklist 內的node 由大排到小 直到NULL為止
{
    int swapped;
    node *current;
    node *last_node = NULL;

    if (current == NULL)                                     //若current node為空的  結束
        return;

    do
    {
        swapped = 0;
        current = list;

        while (current->next != last_node)                             //當current node 的下一個node不為null
        {
            if (current->data < current->next->data)                         //排大小
            {
                swap(current, current->next);
                swapped = 1;
            }
            current = current->next;                                   //繼續下一個node
        }
        last_node = current;                                        //當current node 的下一個為null current為last node
    }while (swapped!=0);

}
void swap(node *a, node *b)                                      //互換NODE
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
        printf("%d ", list_temp->data);                              //依序印出
        list_temp = list_temp->next;                              //繼續下一個node
    }
}
