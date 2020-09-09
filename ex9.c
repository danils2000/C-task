#include<stdio.h>

struct car {
    char brand[50];
    char model[40];
    char type[10];
    char num_plate[50];
    int millage; 
};

void carinfo();
void print(struct car *car);
void menu();
void all();
void free();
void change();

int Pav = 1, Sav = 1, Sav2 = 1; Cav = 1, Mav = 1, Iav = 1;



void carinfo() {
    struct car car1;      
    struct car car2;  
    struct car car3;  
    struct car car4;  
    struct car car5;
    struct car car6; 
    

        strcpy( car1.brand, "Audi");
        strcpy( car1.model, "A4"); 
        strcpy( car1.type, "Standart");
        strcpy( car1.num_plate, "IOI-577");
        car1.millage = 5407;

        strcpy( car2.brand, "BMW");
        strcpy( car2.model, "530"); 
        strcpy( car2.type, "Premium");
        strcpy( car2.num_plate, "IEI-573");
        car2.millage = 9407;

        strcpy( car3.brand, "Audi");
        strcpy( car3.model, "A1"); 
        strcpy( car3.type, "Compact");
        strcpy( car3.num_plate, "TRI-437");
        car3.millage = 15407;

        strcpy( car4.brand, "VOLVO");
        strcpy( car4.model, "V30"); 
        strcpy( car4.type, "Compact");
        strcpy( car4.num_plate, "FGD-432");
        car4.millage = 25407;

        strcpy( car5.brand, "SKODA");
        strcpy( car5.model, "OCTAVIA"); 
        strcpy( car5.type, "Intermidiate");
        strcpy( car5.num_plate, "IOI-101");
        car5.millage = 53407;

        strcpy( car6.brand, "Mersedes");
        strcpy( car6.model, "C-class"); 
        strcpy( car6.type, "Standart");
        strcpy( car6.num_plate, "IZI-777");
        car6.millage = 35407;


        printf("Car 1:\n");
        print( &car1 );
        printf("\nCar 2:\n");
        print( &car2 );
        printf("\nCar 3:\n");
        print( &car3 );
        printf("\nCar 4:\n");
        print( &car4 );
        printf("\nCar 5:\n");
        print( &car5 );
        printf("\nCar 6:\n");
        print( &car6 );

}


void menu(){
    int choise;
    int exit = 0;
    printf("\n\n          CAR RENTAL PROGRAMM \n");
    printf("-----------------------------------------------------\n");
    printf("\n Press 1 for print all cars \n");
    printf("\n Press 2 for print free cars of given category\n");
    printf("\n Press 3 for change state of a car\n");
    printf("\n Press 4 for exit\n");
    printf("\n Press any Option: ");
    scanf("%d", &choise);
    printf("\n----------------------------------------------------\n");
    
    switch(choise) {
        case 1:
            all();
            printf("\n\nPress 0 for exit: ");
            scanf("%d", &exit);
            printf("\n----------------------------------------------------\n");
            if(exit == 0){
                menu();
            } 

        case 2:

            free();
            printf("\n\nPress 0 for exit: ");
            scanf("%d", &exit);
            printf("\n----------------------------------------------------\n");
            if(exit == 0){
                menu();
            } 

        case 3:
            change();
            printf("\n\nPress 0 for exit: ");
            scanf("%d", &exit);
            printf("\n----------------------------------------------------\n");
            if(exit == 0){
                menu();
            } 

        case 4:
        printf("Exit, thank you!\n");
        return 0;
    }
}

void print(struct car *car) {
        printf( "Brand: %s\n", car->brand);
        printf( "Model: %s\n", car->model);
        printf( "Type: %s\n",  car->type);
        printf( "Number plate : %s\n", car->num_plate);
        printf( "Millgage : %d\n", car->millage);
}

void all() {
    carinfo();
}

void free() {
    printf("Press 1 for (Standtart class)\nPress 2 for (Premium class)\nPress 3 for (Mini Elite class)\nPress 4 for Intermideate class\nPress 5 for Compact class\n\n");
    int g;
    printf("Option: ");
    scanf("%d", &g);
    switch(g) {
        case 1:
        if(Sav == 1 && Sav2 == 1){
            printf("Car: Audi a4, IOI-577\nAND \nCar: Mersedes C-class, IZI-777\n");
            printf("These cars are avaible ");
            break;
            
        } else if (Sav == 1 && Sav2 == 0){
            printf("Car: Audi a4, IOI-577\n");
            printf("This car is avaible ");
            break;
        }
        else if (Sav2 == 1 && Sav == 0){
            printf("Car: Mersedes C-class, IZI-777\n");
            printf("This car is avaible ");
            break;
        } else {
            printf("Car: Audi a4, IOI-577\nAND \nCar: Mersedes C-class, IZI-777\n");
            printf("These cars are not avaible ");
            menu();
        }
        break;  

        case 2:
        printf("Car: BMW 530, IEI-573\n");
        if(Pav == 1){
          printf("This car is avaible ");  
          break;
        } else {
          printf("This car is not avaible, choise other car");  
          menu();
        }

        case 3:
        printf("Car: Audi a1, TRI-437\n");   
        if(Mav == 1){
          printf("This car is avaible ");  
          break;
        } else {
          printf("This car is not avaible, choise other car");  
          menu();
        }

        case 4:
        printf("Car: Scoda Octavia, IOI-101\n");
        if(Iav == 1){
          printf("This car is avaible ");  
          break;
        } else {
          printf("This car is not avaible, choise other car");  
          menu();
        }

        case 5:
        printf("Car: Volvo V30, IOI-101\n");
        if(Cav == 1){
          printf("This car is avaible ");  
          break;
        } else {
          printf("This car is not avaible, choise other car");  
          menu();
        }
    }
}


void change(){
    int choose_car;
    printf("\n What car you want to take:\n");
    printf("Press 1 for (Standtart class)\nPress 2 for (Premium class)\nPress 3 for (Mini Elite class)\nPress 4 for Intermideate class\nPress 5 for Compact class\n\n ");
    int r;
    scanf("%d", &r);
    switch(r) {
        case 1:
        printf("What car you want Audi or Mersedes ?(1- Audi ; 2- Mersedes )");
        printf("\nOption: ");
        scanf("%d", &choose_car);
        if(choose_car == 1){
            printf("Car: Audi a4, IOI-577\n");

            if(Sav == 1){
                Sav--; 
                printf("Good\n");
            } else {
                printf("This car is not available");  
            }
            break;

            } else if( choose_car == 2){
                printf("Car: Mersedes C-class, IZI-777\n");

                if(Sav2 == 1){
                    Sav2--; 
                    printf("Good\n");
                } else {
                    printf("This car is not available");
                }
        }
       

        case 2:
        printf("Car: BMW 530, IEI-573\n");

        if (Pav == 1){
            Pav--;
            printf("Good, you made a reservation for this car.");
        } else {
            printf("This car is not available");  
        }
        break;
    

        case 3:
        printf("Car: Audi a1, TRI-437\n");   

        if(Mav == 1){
            Mav--;
            printf("Good");  
        } else {
            printf("This car is not available");  
        }
        break;

        case 4:
        printf("Car: Scoda Octavia, IOI-101\n");

        if(Iav == 1){
            Iav--;
            printf("Good");  
        } else {
            printf("This car is not available");  
        }
        
        break;

        case 5:
        printf("Car: Volvo V30, IOI-101\n");

        if (Cav == 1){
            Cav--;
            printf("Good");  
        } else {
            printf("This car is not available");  
        }
        break;
        
    } 
}

void main() {

    menu();  

}