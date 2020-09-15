#include <stdio.h>

int main() {
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;

	FILE *file;
	file = fopen("text.txt", "r");
    char line[250];

    
	if (file == NULL) {
		printf("Error with file");
		return 0;
	}

	fgets(line, 250, file);
	sscanf(line, "%d %d %d", &num1, &num2, &num3);
	fclose(file); 

	//sort 3 numbers
	int a =num1, b = num2, c = num3;
    num1 = (a < b) ? (a < c ? a : c) : (b < c ? b : c);
    num2 = (b < c) ? (a < b ? b : (a < c ? a : c)) : (a < c ? c : (a < b ? a : b));
    num3 = (a < c) ? (b < c ? c : b) : (a < b ? b : a);

    file = fopen("text.txt","w"); 
    fprintf(file, "%d %d %d",num1 ,num2 ,num3);
    fclose(file);
	return 0;
}