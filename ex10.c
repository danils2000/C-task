#include <stdio.h>

int main() {

	FILE *file;
	file = fopen("text.txt", "r");
	char line[350];
	double amout_lines = 0; 
	float num;
	float value = 0, sum = 0;

	fgets(line, 250, file);
	sscanf(line, "%f", &num);

	while (!feof(file)) {
		if (fgets(line ,250, file) != NULL) {
			sscanf(line, "%f", &value);
			sum = sum + value;
	    	amout_lines++;
	    }
	}

	if (file == NULL) {
		printf("Input file does not exist");
		return 0;
	}

	fclose(file); 


	if (amout_lines == num) {
		printf("Average of %.0f numbers is: %.2f\n",num ,(float)sum / num);
	}
	else {
		printf("Error! Tried to read %.0f numbers, %0.f numbers were read\n",num, amout_lines);
		printf("Average of %.0f numbers is: %.2f\n",amout_lines ,(float)sum / amout_lines);
	}

	return 0;
}

