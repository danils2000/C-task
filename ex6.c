#include <stdio.h>

void cipher(char *str, int num);
void chiper(char *word, int amout) {

    char ch;
    for(int i = 0; word[i] != '\0'; i++) {
        ch = word[i];
        
           if(ch >= 'A' && ch <= 'Z') {
			ch = ch + amout;
			if (ch < 'A') {
			   ch = ch + 'Z' - 'A' + 1;
			}
			else if (ch > 'Z') {
			    ch = ch - 'Z' + 'A' - 1;
			}
         }
         word[i] = ch;
    }
    printf("%s\n", word);
}

int main(){

char word[200];
int amout = 0;
int i;


    printf("Type someting to perform Caesar cipher: ");
	scanf("%s", word);
	printf("Please, type amount of shift: ");
	scanf("%d", &amout);
    printf("\nOriginal text: %s\n",word);//Original text
    
    while (word[i]) {
		word[i] = toupper(word[i]);
		i++;
	}

    printf("Encrypted message: ");//Encrypted message
    chiper(word, amout);
    printf("Decrypted message: ");//Decrypted message
    chiper(word, -amout);
    

	return 0;
}