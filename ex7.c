#include <stdio.h>
#include <string.h>

void whitespace(char *word);
void whitespace(char *word) {
    int i = 0;
//change all whitespaces to "_"
     while (word[i]) {
        if (word[i] == ' ') 
            word[i] = '_'; 
            i++; 
  }
}

int main(){
char word[200];

do {
    printf("Enter a string: ");
    gets(word);
    whitespace(word);
    printf("%s\n", word);

} while (strcmp(word, "stop") != 0 && strcmp(word, "STOP") != 0 );

    printf("Program terminates\n");
    return 0;
}