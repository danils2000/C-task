#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void generator(char *pass, int length, const char *words[]);

void generator(char *pass, int length, const char *words[]) {
    int i = 0;
    int random = 0, positon = 0;

    pass = (char*)malloc(length* sizeof(char));

    for (i = 0; i < length; i++) {
        random = (rand()%940)%94 + 33; //random from 33 to 126
        pass[i] = random; 
    }

    random = (rand()%100)%10; //position
    i = length - strlen(words[random]);
    positon = (rand()%i*10) %i; //value

    for (i = 0; i < strlen(words[random]); i++) {
        pass[positon] = words[random][i];
        positon++;
    }
    int count = 1;
    printf("password: ");
    for (i = 0; i < length; i++) 
    printf("%c", pass[i]);
    printf("\n");

    free(pass);
}

int main() {
    srand(time(NULL));
    char *password; 
    const char *words[11] = {"road", "truck", "metropolia", "car", "sky", "light", "dog", "heater", "foot", "ball","\0"};                       

    printf("3 random password generate from 10 words in array\n\n"); 
    generator(password, 15, words);
    generator(password, 25, words);
    generator(password, 35, words);

    printf("\nEnd of programm\n\n");

    return 0;
}
