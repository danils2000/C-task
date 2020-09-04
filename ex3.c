#include <stdio.h>

int main() {
     int n;
     float sum = 0;
     int id = 45000;
     float average;

     printf("Enter number of students: ");
     scanf("%d", &n);

     int marks[n]; 

     for(int i = 0; i < n; ++i) {
          id++;
          printf("Studentd id %d:  Print Grade (0-5):", id);
          scanf("%d", &marks[i]);

     if(marks[i] < 0 || marks[i] > 5) {
          printf("!Error type grades from 0 to 5!\n");
          i--;
          id--;
     } 
     else {
          sum += marks[i]; 
          } 
     }

     average = sum/n;
     printf("Average grades is = %.4f\n", average);

     return 0;
}