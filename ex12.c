#include <stdio.h>
#include <string.h>

int readInput();

struct item_record {
    char name[200];
    float price;
} 

items[21];

int readInput() {
    char line[200];
    int elements = 0;
    char filename[20];
    char st_name[256] = {'\0'};
    float st_price = 0;
    

    printf("Please, type filename: ");
    scanf("%s", filename);
    printf("\n");

    FILE *f;
    f = fopen(filename, "r");

    if (f == NULL) {
        printf("Sorry, can not be open %s file", filename);
        return 0;
    }

	while (!feof(f)) {
		if (fgets(line, 200, f) != NULL) {
		    elements++;
            
		    if (elements <= 20) {
                if (sscanf(line, "%f;%[^\n]s", &st_price, st_name) == 2) {
                    items[elements - 1].price = st_price;
                    strcpy(items[elements - 1].name, st_name);
                }

                else {
                    printf("Too many items! ONLY 20 ELEMENTS\n");
                    return 0;
                }
            }
        }
	}

    printf("%-40s%-s\n"," NAME","PRICE\n");
    
       for (int i = 0; i < elements; i++) {
          printf("%-40s%-40.2f\n",items[i].name,items[i].price);
                             }
    fclose(f); 
}

int main() {
    readInput();
    return 0;
}

