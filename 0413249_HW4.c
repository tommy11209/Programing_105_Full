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
            maze[i][k]='.';                     //MAZE�}�C�@�}�l�Ҭ�'.'

    int cur_x=0,cur_y=0;                           //�ثe�y�Ц�m    ���W��
    int mov_x[4]={0,1,0,-1},                                       //�C��� �i���ʤ�4�Ӥ�V  �W�U���k +1-1
        mov_y[4]={1,0,-1,0}, stack[4], pass, steps, R;         //stack �i�樫����V  steps�������X�Ӥ�V�i��

    char c = 'A';
    while(1)
    {
        maze[cur_x][cur_y] = c++;      //�q�ثeA�}�l ����j�� �U�@������Ȭ�B,C,D,.....   ��JMAZE�}�C ���N'.'

        if(c > 'Z')                            //����j�� ��J�s��r�� ����Z���� ���X
            break;

        //printf("%d %d \n", cur_x, cur_y);
        steps = 0;
        for(i = 0; i<4; i++)                                          //�̧� ���դW�U���k    �O�_����
        {
            if(cur_x + mov_x[i] < 0 || cur_y + mov_y[i]<0)                //�Y�ثe��m���ʫ� �C���Ҥp��0 ��ܦbMAZE�~
                pass =0;                                                                   //�����
            else if(  cur_x + mov_x[i] >= row|| cur_y + mov_y[i] >= column)       //MAZE�~
                pass = 0;                                                          //�����
            else if(maze[cur_x + mov_x[i]][cur_y + mov_y[i]]!='.')                //�J��D'.'��  �����
                pass = 0;
            else
                pass = 1;                                                         //����
            if(pass)                                                              //TRUE
            {
                stack[steps++] = i;                                               //�N�i������V �s�J��V�}�C
            }
        }


        if(steps == 0)                                              //STEPS=0 ��S����V�i�� ���X�j��
        {
            //printf("%d %d dead\n", cur_x, cur_y);
            break;
        }

        R = rand();
        cur_x += mov_x[stack[R % steps]];                                  //�p��ROW COLUMN����  �H���q��V�}�C��@��V  ���ʦ�m
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

