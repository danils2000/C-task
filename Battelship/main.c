//Battelship project for C programing course in Metropolia Univercity
//Author: Danil Sisov
//Year: 2020
//Platform: Linux(Ubuntu)
//Code editor: Visual Studio Code
//Compiler: gcc 9.3.0


//Libaries
#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


//Ships
const char *shipName[] = {"Carrier", "Battleship", "Cruiser", "Submarine", "Destroyer"};
const int shipShots[] = {5, 4, 3, 3, 2};


//Map Squares
typedef struct {
	int squares[5][3];
} ship;


//Game basic sturct
typedef struct {
	ship ships[5];
	// Game symbols
	// ~ = water
	// S = Ship
	// X = hit
	// O = miss
	char map[10][10];
	char shots[10][10];
	int destroyed;
} player;


//Functions to be used in the game
void name();
void first();
void playerInit(player *p);
void printMap(player *p);
int isClear(char map[10][10], int x, int y);
int isValid(int x, int y);
void initialize(char arr[10][10]);
int playerTurn(player *u, player *a);
int computerTurn(player *a, player *b);
void placeShips(char map[10][10], ship ships[5]);
int shot(int x, int y, player *from, player *to);
int player_hit_c(char c);
char computer_hit_c(int i);



//Game start, write name in .txt file
void name() {
   FILE *file;
   char* filename = "program.txt";
   char name[25];

   file = fopen(filename, "w");

   if(file == NULL) {
      printf("Error!");   
      exit(1);             
   }

    printf("Enter name: ");
    scanf("%s", name);

    fclose(file);	
}



//Game start page with exit, start game with rules.(Also, program read player name from .txt file)
void first() {
	int userInput = 0;
	int choice;
	
	FILE *file;
    char str[25];
    char* filename = "program.txt";
 
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s",filename);
    }

    while (fgets(str, 25, file) != NULL) {
        printf("%s", str);
    	fclose(file);

	}
    fclose(file);	


			printf("\t\t------------------------------------------------------------------------------------\n");
			printf("\t\t  ☆               ___     _  ___ ___      __   __       ___   __      _____         \n");
			printf("\t\t                 |___\\   /_\\  |   |  |   |__  /__  |__|  |   |__|     \\   /      \n");
			printf("\t\t                 |___/  /   \\ |   |  |__ |__  ___\\ |  | _|_  |         | |      ☆ \n");
            printf("\t\t                                                                      /   \\        \n");
            printf("\t\t      ☆                     ___                 ____                 |  ✇  |        \n");
            printf("\t\t                           |       _   |\\  /|  |                      \\___/       \n");
            printf("\t\t                ☆          | __   /_\\  | \\/ |  |----           ☆       \\ /       \n");
			printf("\t\t                           |___| /   \\ |    |  |____                    |          \n");
			printf("\t\t     ☆                                                                              \n");              
            printf("\t\t                                ©Danil Sisov                                 ☆      \n");
			printf("\t\t                 .      ☆                            ☆                              \n");
			printf("\t\t  ☆            __|_____                                        <      ☆            ☆\n");
			printf("\t\t      ________|  o   o |______          ☆                   ___|____                \n");
			printf("\t\t      \\   o   o   o   o   o  /              _______________/  o   o \\____         \n");
			printf("\t\t~~~~~~~\\~~~~~~~~~~~~~~~~~~~~/~~~~~~~~~~~~~~/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\~~~~~~~ \n");
			printf("\t\t                                                                                    \n");
			printf("\t\t                           Welcome: %s                                              \n", str);
			printf("\t\t                                1. Play game                                        \n");
			printf("\t\t                                2. Exit                                             \n");
			printf("\t\t------------------------------------------------------------------------------------\n");
			
			printf("%s ,select option (1-2): ", str);
			scanf("%d", &userInput);

		switch (userInput) {
		
		case 1: 
            printf("                         Welcome to Battelship Game");
			printf("\n1. You will play against the computer\n");
			printf("2. Enemy card on the left, your card with ships on the right\n");
			printf("3. Every game ships put randomly\n");
			printf("4. To strike, you need to choose a letter from a to j and numbers from 0 to 9\n");
			printf("5. Game symbols\n~ = water \nS = Ship \nX = hit \nO = miss\n\n");

			printf("Type 1 if you want return to main menu\n");
			printf("Type any number since 2 to start play\n");
			printf("Option: ");
			scanf("%d", &choice);

			  if(choice == 1) {
				  return first();
			  } 
			  else {

			  }

			break;

		case 2:
			exit(0);	
		}
	
}



//Game start setup and specifies the initial value stored in an object.
void playerInit(player *p) {

	initialize(p->map);
	
	initialize(p->shots);
	
	placeShips(p->map, p->ships);
	
	p->destroyed = 0;
	
}



//Map print 10X10, from 0 to 10, from a to j
void printMap(player *p) {
	int x, y;
	
	printf("\n  0 1 2 3 4 5 6 7 8 9       0 1 2 3 4 5 6 7 8 9\n");

	for (x = 0; x < 10; x++) {
		printf("%c ", 'A'+x);

		for (y = 0; y < 10; y++) {
			printf("%c ", p->shots[x][y]);
		}

		printf("    ");
		printf("%c ", 'A'+x);

		for (y = 0; y < 10; y++) {
			printf("%c ", p->map[x][y]);
		}
		
		printf("\n");
	}
	printf("\n");
}



//Check if squares is clear function will return 1
int isClear(char map[10][10], int x, int y) {
	if (isValid(x, y) && map[x][y] == '~') {
		return 1;
	} 

	return 0;
}



//If squar is valid for x and y, function will return 1
int isValid(int x, int y) {
	if (x < 0 || y < 0){
		return 0;
	} 
	if (x > 9 || y > 9) {
		return 0;
	}  

	return 1;
}



// Initialize all squares "~"(Sea)
void initialize(char arr[10][10]) {
	int x, y;

	for (x = 0; x < 10; x++) {
		for (y = 0; y < 10; y++) {
			arr[x][y] = '~';
		}
	}	
}



//Player turn, сhoosing the coordinates for the strike (insert coordinates)
int playerTurn(player *u, player *a) {
	char x;
	int y , s;
		
	printf("Insert coordinates: ");
	s = scanf(" %c%d", &x, &y);
	if (s == 2 && x >= 'a' && x <= 'j' && y >= 0 && y <= 9 ) { 	
		if( shot(player_hit_c(x), y, u, a)) {
			return 1;
		}
	} 

//Error if coordinates more than j and more than 9. (!!!Programm will use only small letter!!!TYPE WITHOUT CAPS LOCK)
	else {
		printf("Error, choose a letter from a to j and numbers from 0 to 9\n");
		playerTurn(u, a);
	}
	return 0;
}



//Computer turn, computer randomly сhoosing the coordinates for the strike (insert coordinates)
int computerTurn(player *a, player *u) {
	int i, j, x, y, k;
	
//Map coordinates for I and J
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
		
			if (a->shots[i][j] == 'x') { 
				for (k = 0; k < 3; k++) {
					x = i + rand() % 3 - 1;
					y = j + rand() % 3 - 1;

					if (isValid(x, y) && a->shots[x][y] == '~') {
							printf("Computer shot %c%d. ", computer_hit_c(x), y);

							if (shot(x, y, a, u)){
								return 1;
							} 

						return 0;
					}
				}
			}
		}
	}
	
// Random shoot
	do {
		x = rand() % 10;
		y = rand() % 10;
	} while(a->shots[x][y]!='~');
	
	printf("Computer shot %c%d. ", computer_hit_c(x), y);

	if (shot(x, y, a, u)) {
		return 1;
	}

	return 0;
}



// Random arrangement of 5 ships on the map 10 by 10
void placeShips(char map[10][10], ship ships[5]) {
	int s, i, d, c, x, y, j, cx, cy;	

	for (i = 0; i < 5; i++) {
		d = rand() % 2; // 0 is vertical
		c = 0; //check, one if the ship is placed

// Checking the square. Is it possible put a ship in it or not. And place ships
		while (c == 0) { 
			c = 1;
			x = rand() % 10;
			y = rand() % 10;
			cx = x;
			cy = y;
			c = 1;

// Square is not clean
			for (j = 0; j < shipShots[i]; j++) {
				if (isClear(map, cx, cy)) {
					if (d == 0) {
						cy++;
					} 
					
					else {
						cx++;
					}
				} 

				else {
					c = 0;
					break;
				}
			}
			
			if (c == 0) {
			 continue;
			}  
			
			cx = x;
			cy = y;

//Square is clean			
			for (j = 0; j < shipShots[i]; j++) {
				map[cx][cy] = 'S';
				ships[i].squares[j][0] = cx;
				ships[i].squares[j][1] = cy;
				ships[i].squares[j][2] = 0;
				if (d == 0) {
					cy++;
				} 
				else {
					cx++;
				}
			}
		}
	}
}



// Player Shoot if player win function return 1
int shot(int x, int y, player *from, player *to) {
	int i, j, k;
	int isSunk = 1;

//if miss
	if (to-> map[x][y] == '~' || to-> map[x][y] == 'o') { 
		to-> map[x][y] = 'o';
		from-> shots[x][y] = 'o';
		printf("Miss!\n");
	} 

// If hit
	else if (to->map[x][y] == 'S') { 
		to-> map[x][y] = 'X';
		from-> shots[x][y] = 'X';

		for (i = 0; i < 5; i++) {
			for (j = 0; j < shipShots[i]; j++) {
				if (to-> ships[i].squares[j][0] == x && to-> ships[i].squares[j][1] == y) {
					to->ships[i].squares[j][2] = 1;

					for (k = 0; k < shipShots[i]; k++) {
						if (to->ships[i].squares[k][2] == 0) {
							isSunk = 0;
							break;
						}
					}
//If hit and kill
					if (isSunk) {
						printf("%s hit and KILL!!!!!!!!!\n", shipName[i]);
						from-> destroyed++;

//If all ships are sunk
						if (from-> destroyed == 5){
							return 1;
						} 

						return 0;
					}
				}
			}
		}	
		printf("Hit!\n");	

	} 
//If you try to hit twice to one square
	else { 
		printf("It was already hit there.\n");
	}
	
	return 0;
}


//Player hit coordinates pritn
int player_hit_c(char c) {
	return c - 'a';
}


//Computer hit coordinates for print
char computer_hit_c(int i) {
	return i + 'a';
}


//Main function call all needed
int main() {

//generate random number
	srand (time(NULL) );

//call functions
	player user, computer;
	name();
	first();
	playerInit(&user);
	playerInit(&computer);
	

	while(1) {
//for debugging
		printMap(&user);
		printf("\n\n");

//IF cyou are win program will print WIN  on a screen and print to .bin file WIN for statistic
		if (playerTurn(&user, &computer)) {
				printMap(&user);
				printf("\n\nWIN!!!!!!!!!!!!!!!!!\n");

				FILE *file;
   				char* filename = "game_results.txt";
  				char const *result = "Win!\n";
				size_t count;

  				 file = fopen(filename, "a");

   				if(file == NULL) {
     			 printf("Error!");   
      			exit(1);             
   				} 
				   
				else {
					count = fwrite(result, sizeof(char), strlen(result), file);
				   }

    			fclose(file);	
				break;
		}

//IF you are lose program will print you lose on a screen and print to .bin file lose for statistic
		if (computerTurn(&computer, &user)) {
				printMap(&user);
				printf("\n\nYOU LOSE!!!!!!!!!!!\n");

				 FILE *file;
   				char* filename = "game_results.bin";
  				char const *result = "Lose!\n";
				size_t count;

  				 file = fopen(filename, "a");

   				if(file == NULL) {
     			 printf("Error!");   
      			exit(1);             
   				} 
				else {
					count = fwrite(result, sizeof(char), strlen(result), file);

				   }

    			fclose(file);	
				break;
		}
	}

	return 0;
}

//End of project
