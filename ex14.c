#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>


typedef struct chunk {
    uint8_t data[64];
    uint16_t size;
    uint16_t crc;
} 

chunk;


void randomgen(char filename[]);
void reading(char filename[], chunk *chunks);
uint16_t crc16(const uint8_t* data_p, unsigned int length);

void randomgen(char filename[]) {
    FILE *f;
    char s = '\0';
    int i = 0;
    int random = 0;
    srand(time(NULL));

    f = fopen(filename,"wb");
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

void reading(char filename[],chunk *c) {
    FILE *f;
    char s = '\0';
    int count = 0; 
    int number = 0;
  
    f = fopen(filename,"rb"); 

    while (!feof(f)) {
        fread(&s, sizeof(char), 1, f);
        c[number].data[count] = s; 

        if (count == 63) {
            c[number].size = count + 1;
            c[number].crc = 0;
            count = 0;
            number++;
        }

        else {
          count++; 
      } 
    }

    if (count != 0) {
        c[number].size = count - 1;
        c[number].crc = 0;
    }

    if (f == '\0') {
      printf("Error in writning");
    } 

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
    int number = 32;
    int i = 0;
    chunk *c = NULL;
    c = malloc(number * sizeof *c);

    printf("File name(in .bin mode): ");
    scanf("%s",filename);

    randomgen(filename);
    reading(filename, c);

    while ( c[i].size > 0 && i <= number) {
        printf("%s: %-4d    %s: %d    %s: %.X\n", "Chunk" ,i+1, "Bytes",  c[i].size, "CRC", crc16(c[i].data, c[i].size));
        i++;
    }

    return 0;
}