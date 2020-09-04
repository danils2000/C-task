#include <stdio.h>

int main(){

    int number;
    int cout = 0;
    float sum = 0;
    float avg;

        printf("RULES:\n 1.Press any positive number\n 2.Exit = 0\n 3. Cannot to use negative numbers\n");  
        printf("_____________________________________________________________________________________\n\n"); 

    do {
        printf("Enter number - ");
        scanf("%d", &number);
        printf("\n");
        sum = sum + number;
        cout++;

        if (number < 0){
            cout--;
            sum = sum - number;
            printf("Ignore the negative numbers, use only positive\n");
        }
    } while (number != 0);

    cout--;
    printf("Avarage - ");
    printf("%.4f\n", sum / cout);
}