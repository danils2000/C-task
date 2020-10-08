#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct car_struct {
    char make[10];
    char model[9];
    int price;
    float emission;
} car;

void start_car_list(char *filename, car *cars) {
    cars[0] = (car){.make = "Audi", .model = "a6", .price = 75000, .emission = 109.3};
    cars[1] = (car){.make = "BMW", .model = "5", .price = 75000, .emission = 112.6};
    cars[2] = (car){.make = "Mercedes", .model = "S", .price = 155000, .emission = 37.1};
    cars[3] = (car){.make = "Mercedes",.model = "GLE",.price = 112000,.emission = 48.8};
    cars[4] = (car){.make = "Opel", .model = "Omega", .price = 15000, .emission = 199.8};
    cars[5] = (car){.make = "Ford", .model = "Mustang", .price = 55000, .emission = 237};
    cars[6] = (car){.make = "Audi", .model = "A8", .price = 155000, .emission = 55.2};
    cars[7] = (car){.make = "BMW", .model = "3", .price = 60000, .emission = 100};
    cars[8] = (car){.make = "Ford", .model = "Focus", .price = 22000, .emission = 165};

    FILE *file;
    file = fopen(filename,"wb");
    
    if (file == NULL) { 
        printf("Error");
        return 0;
    }
    
    char ch;
    for (int i = 0; i < 10; i++) {
        ch = '-';
        fwrite(cars[i].make, 1,sizeof(cars[i].make),file);
        fwrite(&ch, sizeof(char), 1, file);
        
        fwrite(cars[i].model, 1,sizeof(cars[i].model),file);
        fwrite(&ch, sizeof(char), 1, file);
        
        fwrite(&cars[i].price,sizeof(int),1,file);
        fwrite(&ch, sizeof(char), 1, file);
        
        fwrite(&cars[i].emission,sizeof(float),1,file);
        ch = '\n';
        fwrite(&ch, sizeof(char), 1, file);
    }
    
    fclose(file);
}

void All(char *filename) {
    
    FILE *file;
    char ch = '\0'; 
    int count = 0;
    int i = 0;
    
    file = fopen(filename,"rb");
    if (file == NULL) {
        printf("Error");
        return 0;
    } 

    printf("\nCar list: \n");
    printf("%-10s%10s%19s%19s\n","BRAND","MODEL","PRICE","CO2 EMISSION");

    while (!feof(file)) {
        if (count < 2) fread(&ch, sizeof(char), 1, file);
        if (ch == '-') {
            printf("%7s"," ");
            count++;
        } 
        else printf("%c",ch);

        if (count == 2 && ch == '-') {
            fread(&i, sizeof(int), 1, file);
            printf("%d",i);
            fread(&ch, sizeof(char), 1, file);
        } 
        else if (count == 3 && ch == '-') {
            float i = 0;
            fread(&i, sizeof(float), 1, file);
            printf("%.2f",i);
            fread(&ch, sizeof(char), 1, file);
        } 
        else if (ch == '\n') {
            count = 0;
            
        }
    }
    fclose(file);
    return true;
}

bool new_car(char *filename, car carNew) {
    FILE *file;
    char ch;
    file = fopen(filename,"ab"); 
    if (file == NULL) {
        return false;
    }
    
    ch = '-';
    fwrite(carNew.make, 1,sizeof(carNew.make),file);
    fwrite(&ch, sizeof(char), 1, file);
    
    fwrite(carNew.model, 1,sizeof(carNew.model),file);
    fwrite(&ch, sizeof(char), 1, file);
    
    fwrite(&carNew.price,sizeof(int),1,file);
    fwrite(&ch, sizeof(char), 1, file);
    
    fwrite(&carNew.emission,sizeof(float),1,file);
    ch = '\n';
    fwrite(&ch, sizeof(char), 1, file);
    
    
    fclose(file); 
    return true;
}

int main() {
    char *filename = "car.bin";
    int numCars = 9;
    int choise = 0;
    car *cars = malloc(numCars * sizeof *cars), carNew = {'\0'};
    start_car_list(filename,cars); 

    do {
        printf("Three functions:\n1. Print all cars from the file\n2. Add new car to the end of the file\n3. Quit program\n");
        do {
            printf("Choose a function: ");
            scanf("%d", &choise);
            if (choise > 3 || choise < 1) {
                printf("Only 1, 2 ,3 selection.\n");
            }
        } while (choise > 3 || choise < 1);
        switch (choise) {

            case 1:
                All(filename);
                break;

            case 2:
                printf("Type the brand: ");
                scanf("%s", carNew.make);
                printf("Type the model: ");
                scanf("%s", carNew.model);
                printf("Type the price: ");
                scanf("%d",&carNew.price);
                printf("Type the CO2 emission: ");
                scanf("%f",&carNew.emission);

                if (new_car(filename,carNew)) printf("New car is added to the end of file.\n\n");
                else printf("Error. Try again!\n\n");
                break;

            case 3:
                printf("Exit program");
                break;
        }
    } while (choise != 3);

    free(cars);
    return(0);
}