#include <stdio.h>

int main()
{
     float array[12];
     float income, six, month;
     double num;
     
     printf("Please, enter your yearly gross income: ");
     scanf("%f", &income);
     num = income;
     six = income / 12.5 * 1.5;
     income = income - six;
     month = income / 11;
     
     array[6] = six;

     for(int i = 0; i < 5; i++){
          array[i] = month;
                printf("  element[ %d] =  ", i);
                printf("%.4f\n", array[i]);
     }
               printf("  element[ 6] =  ");
               printf("%.4f\n", array[6]);
        
     for(int a = 7; a < 9; a++){
          array[a] = month;
               printf("  element[ %d] =  ", a);
               printf("%.4f\n", array[a]);
    }
    for(int j = 10; j < 12; j++){
          array[j] = month;
               printf("  element[%d] =  ", j);
               printf("%.4f\n", array[j]);
    }
               printf("  total       =  %.4f\n", num);
}