/* Multiine comment
*/

// Single line comment

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MYNAME "Ian Johnson"







// Left off on #8

int main25(){
  // Characters
  char theChar;
  while((theChar = getchar()) != '\n'){
    printf("Letter or Number %d\n\n", isalnum(theChar));
    printf("Alphabetic Char %d\n\n", isalpha(theChar));
    // Also - isdigit, islower, isupper, ispunct, isspace
  }
}



void noMoreNewline(char* theString){
  char * isANewline;
  isANewline = strrchr(theString, '\n'); // finds last occurrence
  if(isANewline){
    *isANewline = '\0';
  }
}

void makeLowercase(char* theString){
  int i = 0;
  while(theString[i]){
    theString[i] = tolower(theString[i]);
    i++;
  }

}

int main24(){
  char doYouWantToQuit[10];
  printf("Enter quit to quit");
  fgets(doYouWantToQuit, 10, stdin);
  noMoreNewline(doYouWantToQuit);

  makeLowercase(doYouWantToQuit);
  printf(doYouWantToQuit);

  while(strcmp(doYouWantToQuit, "quit")){
    printf("Enter quit to quit");
    fgets(doYouWantToQuit, 10, stdin);
    noMoreNewline(doYouWantToQuit);

    makeLowercase(doYouWantToQuit);
    printf(doYouWantToQuit);
  } 
  
}


int main23(){
  char name[50];
  printf("What is your name?");
  gets(name); // replaces newline with null character
  puts(name); // prints string followed by newline

  fgets(name, 50, stdin); // reads until newline or until array is full
  fputs(name, stdout); // Allows for multiple strings  
  
  // Iterate through string characters
  char * randomString = "Just some random stuff";
  while(*randomString){
    // iterates until 0 is reached
    putchar(*randomString++);
  }

  // the long way
  int i = 0;
  while(randomString[i] != '\0'){
    putchar(randomString[i++]);
  }
}


int main22(){
  // Buffering input, pointer to memory with unspecified size
  char theChar;
  while((theChar = getchar()) != '~'){
    putchar(theChar);
  }
}



int main21(){
  // More on: Strings Characters Booleans Functions Pointers
  _Bool isANumber; // 1, or 0
  int number;
  int sumOfNumbers = 0;

  printf("Enter a number: ");
  isANumber = (scanf("%d", &number) == 1);
  while(isANumber){
    sumOfNumbers = sumOfNumbers + number;
    printf("Enter a number: ");
    isANumber = (scanf("%d", &number) == 1);
  }

  printf("The sum is %d\n\n", sumOfNumbers);
}




typedef struct product {
  const char *name;
  float price;

  struct product *next;
} product;

void printLinkedList(product *pProduct){
  while(pProduct != NULL){
    printf("A %s costs %.2f\n\n", (*pProduct).name, pProduct->price);
    pProduct = pProduct->next;
  }
}

int main20(){
  // Linked lists
  product theProducts[20];
  
  product tomato = {"Tomato", .51, NULL};
  product potato = {"Potato", 1.21, NULL};
  product turkey = {"Turkey", 1.69, NULL};

  tomato.next = &potato;
  potato.next = &turkey;
  
  printLinkedList(&tomato);
}




int main19(){
  // Unions, Enums
  // storing data of different types with unions
  typedef union {
    short individual;
    float pound; 
    float ounce;
  } amount;

  // designated initializer
  amount orangeAmt = {.ounce = 16}; // or ...
  orangeAmt.individual = 4;
  printf("Orange Juice Amount: %.2f : Size: %d\n\n", orangeAmt.ounce, sizeof(orangeAmt.ounce));
  printf("Number of Oranges: %.d : Size: %d\n\n", orangeAmt.individual, sizeof(orangeAmt.individual));
  
  orangeAmt.pound = 1.5;

  printf("Orange Juice Amount: %.2f : Size: %d\n\n", orangeAmt.pound, sizeof(orangeAmt.pound));

  // Union inside a struct
  typedef struct {
    char *brand;
    amount theAmount;
  } orangeProduct;
  
  orangeProduct productOrdered = {"Chiquita", .theAmount.ounce = 16};
  printf("You bought %.2f ounces of %s oranges\n\n", productOrdered.theAmount.ounce, productOrdered.brand);

  // Enumerated types
  // fixees problems with using from % charater for the type
  typedef enum{ INDIV, OUNCE, POUND } quantity;
  quantity quantityType = INDIV;
  orangeAmt.individual = 4;
  if (quantityType == INDIV){
    printf("You bought %d oranges\n\n", orangeAmt.individual);
  } else if (quantityType == OUNCE){ 
    printf("You bought %.2f ounces of oranges\n\n", orangeAmt.ounce);
  } else {
    printf("You bought %.2f pounds of oranges\n\n", orangeAmt.pound);
  }
}



struct dogsFavs {
  char *food;
  char *friend;
};

typedef struct dog {
  const char *name;
  const char *breed;
  int avgHeightCm;
  int avgWeightLbs;

  struct dogsFavs favoriteThings;
} dog;

void getDogInfo(struct dog theDog){
  // theDog[0] doesn't work for structs, only arrays
  printf("Name: %s\n\n", theDog.name);
  printf("breed: %s\n\n", theDog.breed);
  printf("Avg Height: %d\n\n", theDog.avgHeightCm);
}

void getMemoryLocations(struct dog theDog){
  printf("Name location: %d\n\n", theDog.name);
  printf("Breed location: %d\n\n", theDog.breed);
  printf("Name location: %d\n\n", &theDog.avgHeightCm);
}

void getDogsFavs(dog theDog){
  printf("%s loves %s and his friend is %s\n\n", theDog.name, theDog.favoriteThings.food, theDog.favoriteThings.friend);
}

void setDogWeight(dog theDog, int newWeight){
  theDog.avgWeightLbs = newWeight; // Doesn't work!
  printf("the weight was changed to %d\n\n", theDog.avgWeightLbs);
}

void setDogWeightPtr(dog *theDog, int newWeight){
  (*theDog).avgWeightLbs = newWeight;
  printf("The weight was changed to %d\n\n", (*theDog).avgWeightLbs);
}

// Better syntax for struct pointer changes
void setDogWeightPtrNew(dog *theDog, int newWeight){
  theDog->avgWeightLbs = newWeight;
  printf("The weight was changed to %d\n\n", theDog->avgWeightLbs);
}

int main18(){
  dog benji = {"Benji", "Sikly Terrier", 26, 7, {"Meat", "joe camp"}};
  getDogsFavs(benji);

  setDogWeight(benji, 11);
  printf("The weight in main: %d\n\n", benji.avgWeightLbs);
  // C is pass by value, new copies of structs are copied when calling functions
  setDogWeightPtrNew(&benji, 11);
  // Use pointer to actually change the weight
  printf("The weight now is actually changed with a pointer: %d\n\n", benji.avgWeightLbs); 
}


int main17(){
  // Structs
  struct dog cujo = {"Cujo", "Saint Bernard", 90, 264};
  getDogInfo(cujo); 

  struct dog cujo2 = cujo;
  // Pointer point to same locations!
  getMemoryLocations(cujo);
  getMemoryLocations(cujo2);

}



void editMessageSent(char* message, int size){

  char newMessage[] = "New message";
  if (size > sizeof(newMessage)){
    for (int i = 0; i < sizeof(newMessage); i++){
      message[i] = newMessage[i];
    }
  } else {
    printf("New message is too big\n\n");
  }
  
}

int main16(){
  // Pointers with strings
  char randomMessage[] = "Edit my message";
  printf("Old message: %s\n\n", randomMessage);
  editMessageSent(randomMessage, sizeof(randomMessage));
  printf("New message: %s\n\n", randomMessage);

}


// Use * for passing pointers
void pointerRandomNumbers(int* rand1, int* rand2){
  *rand1 = rand() % 50 + 1;
  *rand2 = rand() % 50 + 1;
  printf("With pointer, new rand1 in function = %d\n\n", *rand1);
  printf("With pointer, new rand2 in function = %d\n\n", *rand2);
}

void generateTwoRandomNums(int rand1, int rand2){
  rand1 = rand() % 50 + 1;
  rand2 = rand() % 50 + 1;
  printf("New rand1 in function = %d\n\n", rand1);
  printf("New rand2 in function = %d\n\n", rand2);
}

int main15(){
  // Pointers and functions
  int rand1 = 0, rand2 = 0;
  // wrong way, doesn't change variables
  generateTwoRandomNums(rand1, rand2);
  printf("rand 1 = %d\n\n", rand1);
  printf("rand 2 = %d\n\n", rand2);
  pointerRandomNumbers(&rand1, &rand2);  
  printf("rand 1 = %d\n\n", rand1);
  printf("rand 2 = %d\n\n", rand2);
}


int main14(){
  // Array pointers
  int primeNumbers[] = {2,3,5,7};
  printf("First index : %d\n\n", primeNumbers[0]);
  printf("First index : %d\n\n", *primeNumbers);
  // Pointer arithmetic
  printf("First index : %d\n\n", *(primeNumbers +1));
  
  // Arrays of strings w/ pointers
  char * students[4] = {"Sally", "Mark", "Paul"};
  for (int i = 0; i < 3; i ++){
    printf("%s : %d\n\n", students[i], & students[i]);
  }
  
}


int main13(){
  // Pointers
  int rand1 = 12, rand2 = 15;
  printf("rand1 = %p : rand2 = %p\n\n", &rand1, &rand2);
  printf("rand1 = %d : rand2 = %d\n\n", &rand1, &rand2);
  printf("Size of int %d\n\n", sizeof(rand1));   
  // often addresses are adjacent, but not relilable
  
  int * pRand1 = &rand1;
  printf("Pointer %p\n\n", pRand1);
  printf("pointer %d\n\n", pRand1);

  printf("Value %d\n\n", *pRand1);
}





int globalVal = 100;
int globalVar = 0;

int addTwoInts(int num1, int num2) {
  return num1 + num2;
}

void changeVariables(){
  int age = 40;
  printf("age inside of function = %d\n\n", age);
  globalVar = 100;
  printf("globalVar inside of function = %d\n\n", globalVar);
}

int main12(){
  // Functions & Globals
  printf("\n");
  int total = addTwoInts(4,5);
  printf("the sum is %d\n\n", total);

  int age = 10;
  globalVar = 50;
  printf("age before a call to the function = %d\n\n", age);
  printf("globalVar before a call to the function = %d\n\n", globalVar);
  changeVariables();
  printf("age after call = %d\n\n", age);
  printf("globalVar after call = %d\n\n", globalVar);
}


int main11(){
  // Arrays
  char wholeName[12] = "Ian Johnson";
  int primeNumbers[3] = {2,3,5};
  int morePrimes[] = {13,15,17};
  printf("The first prime is %d\n\n", primeNumbers[0]);

  char city[7] = {'C', 'h', 'i'}; //...
  char thirdCity[] = "Paris";  // better way
  
  // Overwriting past end of strings
  char yourCity[30];
  printf("What city do you live in?");
  // Better than scanf, utilizes size limit
  fgets(yourCity, 30, stdin);
  printf("Hello %s\n\n", yourCity);
  // Remove newline from string
  for (int i=0; i < 30; i++){
    if (yourCity[i] == '\n'){
      yourCity[i] = '\0';
      break;
    } 
  }

  // String compare
  printf("Is your city Paris? %d\n\n", strcmp(yourCity, thirdCity));
  // String concat
  char yourState[] = ", Pennsylvania";
  strcat(yourCity, yourState);
  printf("You live in %s\n\n", yourCity);
  // string length
  printf("Letters in Paris : %d\n\n", strlen(thirdCity));
  // strlcpy - save string copy
  strlcpy(yourCity, "El puebl long name city 12345678", sizeof(yourCity)); 
  printf("New city is %s\n\n");
}


int main10(){
  int whatToDo = 0;
  do {
    printf("1. what time is it?\n");
    printf("2. what is todays date?\n");
    printf("3. what day is it?\n");
    printf("4. quit\n");
    scanf(" %d", &whatToDo);
  } while(whatToDo < 1 || whatToDo > 4);
    
  switch(whatToDo){
    case(1) : printf("print the time");
      break;
    case(2) : printf("print the date");
      break;
    case(3) : printf("print the day");
      break;
    case(4) : printf("bye");
      break;
  }
}


int main9(){

  // Works only in C99
  for(int counter = 0; counter <= 20; counter++){
    printf("%d ", counter);
  }

  // gcc -std=c99 c.c

  for(int counter = 0; counter <= 20; counter++){
    if ((counter % 2) == 0) continue;
    printf("%d ", counter);
  }
}


int main8(){

  int secretNumber = 10, numberGuessed = 0;
  while(1){
    printf("Guess my secret number: ");
    scanf(" %d", &numberGuessed);
    if(numberGuessed == secretNumber) {
      printf("You got it");
      break;
    }
  }

  char sizeOf;
  do {
    printf("What size of shirt (S, M, L)?");
    scanf(" %c", &sizeOf);
  } while (sizeOf != 'S' && sizeOf != 'M' && sizeOf != 'L');

}


int main7(){

  printf("A char takes up %d bytes\n\n", sizeof(char));
  printf("An int takes up %d bytes\n\n", sizeof(int));
  printf("A long takes up %d bytes\n\n", sizeof(long));
  printf("A float takes up %d bytes\n\n", sizeof(float));
  printf("A double takes up %d bytes\n\n", sizeof(double));

  int bigInt = 2147483648; // Too big...
  printf("%d\n\n", bigInt);

  int numberHowBig = 0;
  printf("How many bits? ");
  scanf(" %d", &numberHowBig);
  printf("\n\n");
  // 0 : print what is given
  // 1 : print what is given
  // 2 : 1 + 2 = 3 11
  // 3 : 3 + 4 = 7 111
  int myIncrementor = 1, myMultiplier = 1, finalValue = 1;
  while(myIncrementor < numberHowBig){
    myMultiplier *= 2;
    finalValue = finalValue + myMultiplier;
    myIncrementor++;
  }

  if((numberHowBig == 0) || (numberHowBig == 1)) {
    printf("Top Value: %d\n\n", numberHowBig);
  } else {
    printf("Top value: %d\n\n", finalValue);
  }
}


int main6(){
  // gcc ProgramName.c -o Programname
  // Comparisons
  // < > <= >= !=
  // returns 1, or 0 if false
  int num1 = 1, num2 = 2;
  printf("Is 1 > 2: %d\n\n", num1 > num2);

  if (num1 > num2){
    printf("%d is greater than %d\n\n", num1, num2);
  } else if (num1 < num2) {
    printf("%d is less than %d\n\n", num1, num2);
  } else {
    printf("%d is equal to %d\n\n", num1, num2);
  }

  // Logicals
  // && || !
  int custAge = 38;
  if (custAge > 21 && custAge < 35) printf("They are welcome\n");
  else printf("They are not welcome\n");

  printf("! turns true to false: %d\n\n", !1);

  // Missed less than 10 days work AND has over 30,000 in sales OR > 30 new customers
  int bobMissedDays = 8, bobTotalSales = 24000, bobNewCust = 32;
  if (bobMissedDays < 10 && bobTotalSales > 30,000 || bobNewCust > 30){
    printf("Bob gets a raise\n"); 
  } else {
    printf("Bob doesn't\n");
  }

  char* legalAge = (custAge > 21) ? "true" : "false";
  printf("Is the customer of legal age? %s\n\n", legalAge);

  int numOfProducts = 10;
  printf("I bought %s products\n\n", (numOfProducts > 1) ? "many" : "few");  
}

int main5(){
  // casting
  int numberEx = 12;
  float numberEx2 = 1.234;
  printf("numberEx / numberEx2 : %f\n\n", (float) numberEx / numberEx2);
}

int main4(){
  char middleInitial;
  printf("\n");
  int randomNum = 1;
  printf("1 += 2: %d\n\n", randomNum += 2);
  // Calculates print statement after calculation
  printf("%d += 2 : \n\n", randomNum, randomNum += 2);
  
  // -=, *=, /=, %=, varName-- or ++
  int exNum = 1;
  printf("++%d : %d\n\n", exNum, ++exNum);
  printf("%d++, : %d\n\n", exNum, exNum++);
}

int main3(){
  char middleInitial; 
  printf("\n");
  int num1 = 12, num2 = 15, numAns;
  float decimal1 = 1.2, decimal2 = 1.5, decimalAns;

  printf("Integer calculation %d\n", num2 / num1);
  printf("Float calculation %f\n\n", decimal2 / decimal1);

  printf("Modulus %d\n\n", num2 % num1);
  printf("without parens %d\n\n", 3 + 6 * 10);
}


int main2(){
  char middleInitial;
  printf("what is your middle initial? ");
  scanf(" %c", &middleInitial);
  printf("middle initial %c", &middleInitial);
  
  char firstName[30], lastName[30];
  printf("what is your name? ");
  scanf(" %s %s", firstName, lastName);
  printf("Your Name is %s %c %s\n\n", firstName, middleInitial, lastName);
  int month, day, year;
  printf("What's your birth date? ");
  scanf(" %d/%d/%d", &month, &day, &year);
  printf("\nBirth Date %d/%d/%d\n\n", month, day, year);
}

int main1(){
  char firstLetter = 'D';
  // int +/- 31,768
  int age = 38;
  long int superBigNum = -32767000;
  float piValue = 3.14159;
  double reallyBigPi = 3.1415982342934893904384;
  
  printf("\n");  
  // \n \t - tab, \\ - backslash, \' - quote  
  printf("This will print to screen\n\n");

  printf("I am %d years old \n\n", age);
  printf("Big number %ld\n\n", superBigNum);
  printf("Pi = %.5f\n\n", piValue);
  printf("Big pi = %.15f\n\n", reallyBigPi);
 
  printf("The letter is %c\n\n", firstLetter);  
  printf("My name is %s\n\n", "Ian");

  char myName[15] = "Ian Johnson";
  strcpy(myName, "Bob Smith");
  printf("My name is %s\n\n", myName);

  return 0;
}

