#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{   while(1){
    srand(time(0));
    printf("Enter the size of the maze : ");
    int row,column;
    scanf("%d%d",&row,&column);

    int maze[row][column];
    int i,k;
    for(i=0;i<row;i++)
        for(k=0;k<column;k++)
            maze[i][k]='.';                     //MAZE陣列一開始皆為'.'

    int cur_x=0,cur_y=0;                           //目前座標位置    左上角
    int mov_x[4]={0,1,0,-1},                                       //列跟行 可移動之4個方向  上下左右 +1-1
        mov_y[4]={1,0,-1,0}, stack[4], pass, steps, R;         //stack 可行走的方向  steps紀錄有幾個方向可走

    char c = 'A';
    while(1)
    {
        maze[cur_x][cur_y] = c++;      //從目前A開始 執行迴圈 下一次執行值為B,C,D,.....   放入MAZE陣列 取代'.'

        if(c > 'Z')                            //執行迴圈 放入連續字母 直到Z為止 跳出
            break;

        //printf("%d %d \n", cur_x, cur_y);
        steps = 0;
        for(i = 0; i<4; i++)                                          //依序 測試上下左右    是否停止
        {
            if(cur_x + mov_x[i] < 0 || cur_y + mov_y[i]<0)                //若目前位置移動後 列跟行皆小於0 表示在MAZE外
                pass =0;                                                                   //停止移動
            else if(  cur_x + mov_x[i] >= row|| cur_y + mov_y[i] >= column)       //MAZE外
                pass = 0;                                                          //停止移動
            else if(maze[cur_x + mov_x[i]][cur_y + mov_y[i]]!='.')                //遇到非'.'者  停止移動
                pass = 0;
            else
                pass = 1;                                                         //移動
            if(pass)                                                              //TRUE
            {
                stack[steps++] = i;                                               //將可走之方向 存入方向陣列
            }
        }


        if(steps == 0)                                              //STEPS=0 表沒有方向可走 跳出迴圈
        {
            //printf("%d %d dead\n", cur_x, cur_y);
            break;
        }

        R = rand();
        cur_x += mov_x[stack[R % steps]];                                  //計算ROW COLUMN移動  隨機從方向陣列選一方向  移動位置
        cur_y += mov_y[stack[R % steps]];
    }

     for(i=0;i<row;i++)
     {
         for(k=0;k<column;k++)
            printf("%c",maze[i][k]);
         printf("\n");
     }
}

    return 0;
}

