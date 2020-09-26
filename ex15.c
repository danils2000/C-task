#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>


typedef struct chunk {
    uint8_t *data;
    uint16_t size;
    uint16_t capacity;
    uint16_t crc;
} 

chunk;


void randomgen(char filename[]);
void reading(char filename[], chunk *chunks, int size, int *chunknumber);
uint16_t crc16(const uint8_t* data_p, unsigned int length);

void randomgen(char filename[]) {
    FILE *f;
    char s = '\0';
    int i = 0;
    int random = 0;
  

    f = fopen(filename,"wb");
    srand(time(NULL));
    i = rand() % 1000 + 1000;

    while(i > 0 ) { 
        i--;
        random = rand() % 256;
        s = random;
        fwrite(&s, sizeof(char), 1, f);
    }

    if (f == '\0') {
      printf("Error in random");
    }

    fclose(f);
}

void reading(char filename[],chunk *c, int size, int *num) {
    FILE *f;
    char s = '\0';
    int number = 0;
    int count = 0; 
  
  
    f = fopen(filename,"rb"); 
    c[number].data = (uint8_t *)malloc(sizeof(uint8_t) * size);

    while (!feof(f)) {
        fread(&s, sizeof(char), 1, f);
        c[number].data[count] = s; 

        if (count == size - 1) {
            c[number].size = size;
            c[number].crc = 0;
            c[number].capacity = size;
            count = 0;
            number++;
            c[number].data = (uint8_t *)malloc(sizeof(uint8_t) * size);
        }

        else {
          count++; 
      } 
    }

    if (count != 0) {
        c[number].size = count - 1;
        c[number].crc = 0;
        c[number].capacity = size;
    }

    if (f == '\0') {
      printf("Error in writning");
    } 
  *num = number ;
  fclose(f); 
}

uint16_t crc16(const uint8_t* data_p, unsigned int length) {
  uint8_t x;
  uint16_t crc = 0xFFFF;

  while (length--) {
    x = crc >> 8 ^ *data_p++;
    x ^= x>>4;
    crc = (crc << 8) ^ ((uint16_t)(x << 12)) ^ ((uint16_t)(x <<5)) ^ ((uint16_t)x);
  }

 return crc;
}

int main() {
    char filename[10];
    int number = 0;
    int i = 0;
    int size = 0;
    char more[5];
    chunk *c = NULL;
    c = malloc(number * sizeof *c);

    printf("File name(in .bin mode): ");
    scanf("%s",filename);
    printf("Type size: ");
    scanf("%d", &size);
    number = 2000 / size + 2;
    c = malloc(number * sizeof *c);

    randomgen(filename);
    reading(filename, c, size, &number);

   while(i <= number ){
            printf("%s: %d      %s: %d         %s: %d        %s: %.X\n", "Chunk number" ,i+1, "Chunk capacity", c[i].capacity, "Chunk size", c[i].size, "CRC", crc16(c[i].data, c[i].size));
            i++;
   }
        printf("\nAnother one? (yes or no): ");
        scanf("%s", more);

        if(!strcmp(more, "yes")) {
          return main();
        }
        else if (!strcmp(more, "no")) {
          return 0;  
        }
        else{
          return 0;
        }

    return 0;
}
