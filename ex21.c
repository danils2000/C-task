#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generator(char filename[]);
void count(char filename[]);

void generator(char filename[]) {  
    int ran = 0;
    char ch = '\0';
  
    FILE *file;
    file = fopen(filename,"wb"); 
    if (file == NULL) {
        printf("Error");
    }

    srand(time(NULL));
    for (int i = 1000; i >= 0; i--) {
        ran = (rand()%2550)%255; 
        ch = ran;
        fwrite(&ch, sizeof(char), 1, file);
    }

    fclose(file);
}

void count(char filename[]) {
    int j = 0;
    char ch = '\0';
    int count[256] = {0}; 

    FILE *file;
    file = fopen(filename,"rb"); 
    if (file == NULL) {
        printf("Error");
    } 

    while (!feof(file)) {
        fread(&ch, sizeof(char), 1, file);
        j = ch;
        if (j < 0) {
           j += 256;
        } 
        count[j]++; 
    }
    fclose(file); 


int maximum = 0, current = 0;
    for (int i = 0; i < 10; i++) {
        for (j = 0; j < 256; j++) {
            if (maximum < count[j]) {
                maximum = count[j];
                ch = j;
                current = j;
            }
        }
        count[current] = -1;
        printf("%.2d. | %c | - char num %d - show %d\n", i+1, ch, current, maximum);
    }
}

int main() {
    char filename[10]; 

    printf("Filename: ");
    scanf("%s",filename);

    generator(filename);
    count(filename);

    return 0;
}
