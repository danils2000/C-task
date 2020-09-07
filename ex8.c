#include <stdio.h>

void convert(char *something);
void convert(char *something) {

	for(int i = 0; something[i]!='\0'; i++) {
		if (i == 0) {
			if((something[i] >= 'a' && something[i] <= 'z'))
                	something[i] = toupper(something[i]);
		}
		if (something[i] == ' ') {
			i++;
			if(something[i] >= 'a' && something[i] <= 'z') {
			something[i] = toupper(something[i]);
			}
		}
	}
    printf("%s\n", something);
}

int main () {
    char someting[200];
    do {
        printf("Type something: ");
        gets(someting);
        if (strcmp(someting, "stop") == 0 ) {
            break;
        }
        convert(someting);
       

       } while ((strcmp(someting, "STOP") != 0 ));

    printf("Program terminates\n");
    return 0;
}
