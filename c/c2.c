#include <stdio.h>
#include <stdlib.h>



// At section 12

int main(){
  // File I/O
  char buffer[1000];

  int randomNumber;
  FILE *pFile;
  pFile = fopen("randomnumbers.txt", "r");
  if (!pFile){
    printf("Error: couldn't read to file");
    return 1;
  }

  //for(int i = 0; i < 10; i++){
    //randomNumber = rand() % 100;
    //fprintf(pFile, "%d\n", randomNumber);
  //}

  while(fgets(buffer, 1000, pFile) != NULL){
    printf("%s", buffer);
  }

  while(fscanf(pFile, "%s", buffer) == 1){
    puts(buffer);
  }

  printf("Success reading to file\n");
  if (fclose(pFile) != 0){
    printf("Error: File not closed\n");
  }

  return 0;
}




struct product2 {
  float price;
  char productName[30];
  
  struct product *next;
};

struct product2 *pFirstNode = NULL;
struct product2 *pLastNode = NULL;

void createNewList(){
  struct product2 *pNewStruct = (struct product2 *) malloc(sizeof(struct product2));
  pNewStruct -> next = NULL;

  printf("Enter product name");
  scanf("%s", &(pNewStruct)->productName);
  printf("Enter product price");
  scanf("%f", &(pNewStruct)->price);

  pFirstNode = pLastNode = pNewStruct;
}

void inputData(){
  if (pFirstNode == NULL) {
    createNewList();
  } else {

    struct product2 * pNewStruct = (struct product2 *) malloc(sizeof(struct product2));
    printf("Enter product name");
    scanf("%s", &(pNewStruct)->productName);
    printf("Enter product price");
    scanf("%f", &(pNewStruct)->price);

    if (pFirstNode == pLastNode){
      pFirstNode -> next = pNewStruct;
      pLastNode = pNewStruct;
      pNewStruct -> next = NULL;
    } else {
      pLastNode -> next = pNewStruct;
      pNewStruct -> next = NULL;
      pLastNode = pNewStruct;
    }

  }
}

void outputData(){
  struct product2 *pProducts = pFirstNode;
  printf("Products Entered \n\n");
  while(pProducts != NULL){
    printf("%s costs %.2f\n\n", pProducts->productName, pProducts->price);
    pProducts = pProducts->next;
  }
}

struct product2 *pProductBeforeProductToDelete = NULL;

struct product* searchForProduct(char * productName){
  struct product2 *pProductIterator = pFirstNode;
  while (pProductIterator != NULL){
    int areTheyEqual = strncmp(pProductIterator->productName, productName, 30);
    
    if (!areTheyEqual) {
      printf("%s was found and it costs %.2f\n\n", pProductIterator->productName, pProductIterator->price);
      return pProductIterator;
    }
    pProductBeforeProductToDelete = pProductIterator;
    pProductIterator = pProductIterator -> next;
  }
  printf("%s Wasnt found\n\n", productName);
  return NULL;
}

void removeProduct(char * productName){
  struct product2 *pProductToDelete = NULL;
  pProductToDelete = searchForProduct(productName);
  if (pProductToDelete != NULL){
    printf("%s was deleted\n\n", productName);
    if(pProductToDelete == pFirstNode){
      pFirstNode = pProductToDelete -> next;
    } else {
      pProductBeforeProductToDelete -> next = pProductToDelete -> next;
    }
    free(pProductToDelete);
  } else {
    printf("%s was not found", productName);
  }
}

int main4() {
  // Linked list
  inputData();
  inputData();
  inputData();
  outputData();

  searchForProduct("Tomato");
  removeProduct("Tomato");
  return 0;
}





struct product {
  float price;
  char productName[30];
};

int main3(){

  struct product *pProducts;
  int i, j;
  int numberOfProducts;
  printf("Enter the Number of products to store: ");
  scanf("%d", &numberOfProducts);
  
  pProducts = (struct product *) malloc(numberOfProducts * sizeof(struct product));

  for (i = 0; i < numberOfProducts; i++){
    printf("Enter a Product Name: ");
    scanf("%s", &(pProducts + i) -> productName);
    printf("Enter a product price: ");
    scanf("%f", &(pProducts + i) -> price);
  }

  for (j = 0; j < numberOfProducts; ++j){
    printf("%s\t%.2f\n", (pProducts + j) -> productName, (pProducts + j) -> price);
  }

  free(pProducts);

  return 0;  

}

int main2(){

  int amtOfNumbersToStore;
  printf("How many number do you want to store?");
  scanf("%d", &amtOfNumbersToStore);
  int * pRandomNumbers;
  pRandomNumbers = (int *) malloc(amtOfNumbersToStore * sizeof(int));
  
  if (pRandomNumbers != NULL) {
    int i = 0;
    printf("Enter a number or quit: ");
    while (i < amtOfNumbersToStore && scanf("%d", &pRandomNumbers[i]) == 1) {
      printf("Enter a number or Quit: ");
      i++;
    }
    printf("You entered the following numbers\n");
    for (int j = 0; j < i; j++){
      printf("%d\n", pRandomNumbers[j]);
    }
  }
    
  free(pRandomNumbers);  

  return 0;

}
