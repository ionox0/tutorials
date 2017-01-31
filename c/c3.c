#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <ctype.h>

// WIP - video #15
char * convertBase(unsigned int numberToConvert, int base, char *pConvertedNumber) {
  char allValues[] = "0123456789abcdef";
  if (base < 2 || base > 16){
    printf("Enter a number between 2 and 16\n");
    exit(1);
  }
  pConvertedNumber[32] = '\0';
  
  do {
    int value = numberToConvert % base;
    pConvertedNumber = pConvertedNumber - 1;
    *pConvertedNumber = allValues[value];
    numberToConvert /= base;
  } while (numberToConvert != 0);
  printf("%s", pConvertedNumber);
  return pConvertedNumber;
}

int main(void){
  // passing memory adressses, bitwise opeerators, signed integers,
  // shift operators, twos compliment, bitmasking
  unsigned int numberSix = 6; // 110
  unsigned int numberSeven = 7; // 111
  
  char *pConvertedNumber;
  pConvertedNumber = malloc(33 * sizeof(char));
  //printf("%s\n", convertBase(numberSix, 2, pConvertedNumber));

  unsigned int andSolution = numberSix & numberSeven;
  printf("%s & ", convertBase(numberSix, 2, pConvertedNumber));
  printf("%s = ", convertBase(numberSeven, 2, pConvertedNumber));
  printf("%s\n\n", convertBase(andSolution, 2, pConvertedNumber));

  unsigned int onesCompSolution = ~numberSix;
  printf("%s & ", convertBase(numberSix, 2, pConvertedNumber));
  printf("%s\n\n", convertBase(onesCompSolution, 2, pConvertedNumber));
  printf("Negative of %d = %d\n\n", numberSix, (onesCompSolution + 1));

  free(pConvertedNumber);
  return 0;
}

int baseToDecimal(char* number, int baseFrom, int sizeOfNumber){
  int result = 0;
  int toThePowerOf = 0; // 8^0, 8^1...
  
  for(int i = (sizeOfNumber - 2); i >= 0; --i){
    if (isalpha(number[i])){
      int charCode = ((int)tolower(number[i])) - 87;
      result += charCode * pow(baseFrom, toThePowerOf);
    } else {
      // ... + (4* 8^1) + (5 * 8^0)
      result += (number[i] - '0') * pow(baseFrom, toThePowerOf);
    }
    toThePowerOf++;
  }

  printf("%s in the base %d equals %d in base 10\n", number, baseFrom, result);
  return result;
}  

int main4(void){
  // Converting from other bases to base 10
  printf("a: %d\n", "a");
  printf("A: %d\n", "A");
  printf("b: %d\n", "b");
  printf("c: %d\n", "c");
  printf("d: %d\n", "d");
  printf("e: %d\n", "e");
  printf("f: %d\n", "f");

  printf("\n");
  char numberToConvert[] = "3C";
  baseToDecimal(numberToConvert, 16, sizeof(numberToConvert));
  return 0;
}


char * convertBase2(unsigned int numberToConvert, int base){
  char buffer[33];
  char *pConvertedNumber;

  char allValues[] = "0123456789abcdef";
  
  if (base < 2 || base > 16){
    printf("Enter a number between 2 and 16\n");
    exit(1);
  }

  pConvertedNumber = &buffer[sizeof(buffer) - 1];
  
  *pConvertedNumber = '\0';
  do{
    int value = numberToConvert % base;
    pConvertedNumber = pConvertedNumber - 1;
    *pConvertedNumber = allValues[value];
    numberToConvert /= base; // numberToConvert = numberToConvert / 2
  } while(numberToConvert != 0);

  printf("%s", pConvertedNumber);
  return pConvertedNumber;

}


int main3(void){
  // converting between bases 10, 2, and 16
  unsigned int numberOne = 60; // 111100
  printf("%d in Base 2 = ", numberOne);
  convertBase2(numberOne, 2);
  printf("\n");

  printf("%d in Base 8 = ", numberOne);
  convertBase2(numberOne, 8);
  printf("\n");

  printf("%d in Base 16 = ", numberOne);
  convertBase2(numberOne, 16);
  printf("\n");

  return 0;
}


int main2(void){
  FILE *pFile;
  pFile = fopen("randomnumbs.bin", "rb+");
  if (pFile == NULL){
      perror("Error Occured");
      printf("Error Code: %d\n", errno);
      printf("File being created\n\n");
      pFile = fopen("randomnumbs.bin", "wb+");
      
      if (pFile == NULL){
        perror("Error Occured");
        printf("Error Code: %d\n", errno);
        exit(1);
      }
  }

  int randomNumbers[20];
  for (int i = 0; i < 20; i++){
    randomNumbers[i] = rand() %100;
    printf("Number %d is %d\n", i, randomNumbers[i]);
  }

  fwrite(randomNumbers, sizeof(int), 20, pFile);
  long randomIndexNumber;
  int numberAtIndex;

  printf("Which Random Number do you Want?");
  scanf("%ld", &randomIndexNumber);
  fseek(pFile, randomIndexNumber * sizeof(int), SEEK_SET);
  fread(&numberAtIndex, sizeof(int), 1, pFile);
  printf("The Random Number at Index %d is %d\n", randomIndexNumber, numberAtIndex);
  
  fclose(pFile);
  return 0;
}


int main1(void){
 
  FILE *pFile;
  char * buffer;

  size_t dataInFile;
  long fileSize;
  pFile = fopen("names.bin", "rb+");
  if(pFile == NULL){
    perror("Error Occured");
    printf("Error Code: %d\n", errno);
    
    printf("File being created\n\n");
    pFile = fopen("namesbin", "wb+");
    
    if (pFile == NULL){
      perror("Error Occured");
      printf("Error Code: %d\n", errno);
      exit(1);
    }

    char name[] = "Derek Banas";
    fwrite(name, sizeof(name[0]), sizeof(name)/sizeof(name[0]), pFile);

    fseek(pFile, 0, SEEK_END);
    fileSize = ftell(pFile);
    
    rewind(pFile);

    buffer = (char*) malloc(sizeof(char)*fileSize);
    
    if(buffer == NULL){
      perror("Error Occured");
      printf("Error Code: %d\n", errno);
      exit(2);
    }

    dataInFile = fread(buffer, 1, fileSize, pFile);
    if(dataInFile != fileSize){
      perror("Error Occured");
      printf("Error Code: %d\n", errno);
      exit(3);    
    }

    printf("%s\n", buffer);
    printf("\n");
  }

  return 0;
}
