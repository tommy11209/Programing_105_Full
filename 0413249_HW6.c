#include<stdio.h>
#include <string.h>

void reverse_(char arr[][100], int h)
{
    int k, i;
    for(i = 0; i < h; i++)
        for(k = 0; k < strlen(arr[0]) / 2; k++)
        {
            char t = arr[i][k];
            arr[i][k] = arr[i][strlen(arr[0]) - k - 1];
            arr[i][strlen(arr[0]) - k - 1] = t;
        }
}

void print_M(char arr[][100], int h)
{
    int k, i;
    for(i = 0; i < h; i++)
    {
        for(k = 0; k < strlen(arr[0]) ; k++)
        {
            printf("%c",arr[i][k]);
        }

    }


}
int main()
{
    FILE *fp;
    char buf[100], arr[100][100];
    int i = 0;
    fp = fopen("C:\\Users\\user\\Desktop\\µ{³]\\0413249_HW6\\bin\\Debug\\deer.txt","r");

    while(fgets(buf, 100, fp) != NULL)
    {
        int j;
        for(j = 0; j < strlen(buf); j++)
            arr[i][j] = buf[j];
        i++;
    }
    reverse_(arr, i);
    print_M(arr, i);
    fclose(fp);
    return 0;
}

