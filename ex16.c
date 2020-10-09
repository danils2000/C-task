#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

bool fileDataGenerate(char filename[]);
bool read(char filename[], char *str, int *size);
void write(char filename[], char *str, int size, int position, int num);

bool fileDataGenerate(char filename[]) {
    FILE *file;
    int i = 0, ran = 0;
    char ch = '\0';

    file = fopen(filename,"wb"); 

    if (file == NULL) {
        return false;
    }

    srand(time(NULL));
    i = rand()%50 + 50; 
    for (i ; i > 0 ; i--) {
        ran = (rand()%940)%94 + 33;
        ch = ran;
        fwrite(&ch, sizeof(char), 1, file);
    }

    fclose(file);
}


bool read(char filename[], char *str, int *size) {
    FILE *file;
    int count = 0;
    char ch = '\0';

    file = fopen(filename,"rb");
    
     if (file == NULL) {
        return false;
    }

    while (!feof(file)) {
        fread(&ch, sizeof(char), 1, file);
        str[count] = ch;
        count++;
    }

    fclose(file);

    *size = count - 1;
}

void write(char filename[], char *str, int size, int position, int number) {
    FILE *file;
    int i = 0;
    file = fopen(filename,"wb");

    printf("\nOriginal\n");
    
    for (i = 0; i < size; i++) {
        printf("%c",str[i]);
        printf("\n");
    }

    for (i = 0; i < position-1; i++) {
        printf("%c",str[i]);
    }

    for (i = position + number - 1; i < size; i++ ) {
        printf("%c",str[i]);
    }

    for (i = 0; i < position-1; i++) {
        fwrite(&str[i], sizeof(char), 1, file);
    }

    for (i = position + number - 1; i < size; i++ ) {
        fwrite(&str[i], sizeof(char), 1, file);
    }

    fclose(file);
}


int main() {
    char filename[10]; 
    char *str = {'\0'};
    str = (char *)malloc(150*sizeof(char));
    int size = 0, position = 0, number = 0; 

    printf("Filename: ");
    scanf("%s",filename);

    if (!fileDataGenerate(filename)) return 0;
    if (!read(filename,str,&size)) return 0; 

    printf("The file size is %d.\nFrom which position you want to remote byte(s): ",size);
    scanf("%d",&position);

    if (position > size) {
        printf("Error");
        return 0;
    }

    printf("Enter number of bytes you want to remove: ");
    scanf("%d",&number);

    if (position + number - 1 <= size) {
        write(filename, str, size, position, number);
    } 

    else {
        printf("Error");
    } 

    free(str);
    return 0;
}
