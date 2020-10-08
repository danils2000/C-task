#include <stdio.h>

#define DEBUG
#ifdef DEBUG

#define DEBUGMSG(...)printf(__VA_ARGS__)

#else
#define DEBUGMSG(...)
#endif

int main(void) {
	int i = 0, s = 0;
	char test[8] = "Success";
    char tes[5];

    do {
        printf("Enter 5 numbers\n");
            for (int j = 0; j < 5; j++) {
                scanf("%c",&tes[j]);   
                getchar(); 
                s++;
        }
    }while (s != 5);
	
        for(i = 0; i < 5; i++) {
            DEBUGMSG("Check the macro. Loop var: %d\nString: %c %s\n\n",i, tes[i], test);
        }

	return 0;
}