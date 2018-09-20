#include <string.h>
#include <stdio.h>
#include <math.h>

#define MAXX (100000)


int main(int argc, char *argv[])
{


    while(1){


        // start testing the prime factors
        unsigned int target ;
        unsigned int target2 ;             //��Jint
        unsigned int found_list_number[MAXX];     //��]��
        unsigned int found_list_val[MAXX];        //��]�Ʀ���
        unsigned int found_top_index = 0;         //��]�ƶ��Ǥ��s��
        int  i;
        memset(found_list_number, 0, MAXX);        //�]��]�ư}�C�Ҭ�0
        printf("Enter an unsigned integer >= 2 :  ");
        scanf("%u", &target);
        printf("Prime factorization of %u =",target);
        i = 2;
        target2=target;
        while(target2 != 1)
        {
            if(target2 % i == 0) //�㰣
            {
                target2 /= i;
                //��]�� 'i' ���F���U�ӳB�z
                found_list_number[found_top_index++] = i;
            }
            else
            {
                i++; // test next int  3.4.5.6........
            }
        }

        memset(found_list_val, 0, MAXX);         //�]��]�Ʀ���}�C�Ҭ�0
        int cur = found_list_number[0], val;
        for(i=0; i < found_top_index; )
        {
            val = 0;
            cur = found_list_number[i];
            do
            {
                val++;
            }while(cur == found_list_number[i++]);
            i--;
            val--;

            found_list_val[i-1] = val;
        }
        //�C�X��]�Ƭۭ�
        for(i=0; i<found_top_index; i++){
            if(found_list_val[i] != 0)
            {
                printf("%u^%u", found_list_number[i], found_list_val[i]);
                if(i != found_top_index - 1)
                    printf("x");
            }
        }
        printf("\n");




        //�p��number of divisors
        unsigned int num=1;
        for(i=0;i<found_top_index; i++){
            num=num*(1+found_list_val[i]);
        }
        printf("Number of divisors = %d\n",num);




        // �p�� Sum of divisors
        unsigned int pre_calc;
        unsigned int k, l, sum = 1, pow_oper;

        printf("Sum of divisors=");
        for(i=0; i < found_top_index; i++)
        {
            pre_calc = 0;
            for(k=0; k<=found_list_val[i]; k++)
            {
                //pre_calc += pow(found_list_number[i], k);
                pow_oper = 1;
                for(l=0; l<k; l++)
                    pow_oper *= found_list_number[i];
                pre_calc += pow_oper;
            }
            sum *= pre_calc;

        }
        printf("%u\n", sum);





        //�p��Product of divisors
        unsigned int j;
        int overflowed_flag = 0;
        unsigned long long int num_test=1,sum1,sum2,num2=1;

        if(num%2==0)           //����
        {
            sum1=num/2;           //�p���num�����Ʈɪ�����

            for(j=0;j<sum1;j++){          //�p��ҿ�J��target�� Product of divisors

                num2=num2*target;
                num_test=num2*target;            //����overflow
                if((num_test/target)!=num2 || num2 > ((unsigned int)-1)){       //����overflow
                    printf("Product of divisors overflow!\n");
                    overflowed_flag = 1;
                    break;
                }
            }
            if(!overflowed_flag)
                printf("Product of divisors = %llu \n",num2);
        }
        else
        {                          //�_��
            sum2=(num-1)/2;
            for(j=0;j<sum2;j++){                   //�p��ҿ�J��target�� Product of divisors

                num2=(num2*target)*sqrt(num2);
                num_test=num2*target;              //����overflow
                if((num_test/target)!=num2 || num2 > ((unsigned int)-1)){       //����overflow
                    printf("Product of divisors overflow!\n");
                    overflowed_flag = 1;
                    break;
                }
            }
            if(!overflowed_flag)
                printf("Product of divisors = %llu \n",num2);

        }

    }




    return 0;
}
