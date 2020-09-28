#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

 int main() {
	

	int userInput = 0;

			printf("\t\t                  ___     _  ___ ___      __   __       ___   __                    \n");
			printf("\t\t                 |___\\   /_\\  |   |  |   |__  /__  |__|  |   |__|                 \n");
			printf("\t\t                 |___/  /   \\ |   |  |__ |__  ___\\ |  | _|_  |                    \n");
            printf("\t\t                                                                                    \n");
            printf("\t\t                            ___                 ____                                \n");
            printf("\t\t                           |       _   |\\  /|  |                                   \n");
            printf("\t\t                           | __   /_\\  | \\/ |  |----                              \n");
			printf("\t\t                           |___| /   \\ |    |  |____                               \n");
			printf("\t\t                                                                                    \n");              
            printf("\t\t                                 By: Danil Sisov                                    \n");
			printf("\t\t                 .                                                                  \n");
			printf("\t\t               __|_____                                        <                    \n");
			printf("\t\t      ________|  o   o |______                              ___|____                \n");
			printf("\t\t      \\   o   o   o   o   o  /              _______________/  o   o \\____         \n");
			printf("\t\t~~~~~~~\\~~~~~~~~~~~~~~~~~~~~/~~~~~~~~~~~~~~/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\~~~~~~~ \n");
			printf("\t\t                                                                                    \n");
			printf("\t\t                                1. Game Rules                                       \n");
			printf("\t\t                                2. Play Game                                        \n");
			printf("\t\t                                3. Exit                                             \n");
			scanf("%d", &userInput);

		switch (userInput)
		{
		case 1:
			printf("RULES");
		case 2: 
            printf("game");
			break;
		}
	printf("Goodbye!\n");

	return 0;
}
