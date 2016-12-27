// This is a comment
/* 
multi line comment
*/

#include <iostream>
#include <vector>
#include <string> 
#include <fstream>

using namespace std;



// if the getClass method of animal is declared virtual,
// this will produce the correct result for the Dog subclass
void whatClassAreYou(Animalvirt animal){

	animal -> getClass();

}


// Virtual methods
class Animalvirt {
	public: 
		void getFamily() { cout << "We are animals " << endl; }
		virtual void getClass() { cout << "I'm an Animal" << endl; }
};

class Dogvirt : public Animalvirt {
	public:
		void getClass() { cout << "I'm a Dog" << endl; }
};



int main(){

	Animalvirt *animal = new Animalvirt;
	Dogvirt *dog = new Dogvirt;

	animal->getClass();
	dog->getClass();

	whatClassAreYou(animal);
	whatClassAreYou(dog);

	return 0;

} 











class Animal {

	private: 
		int height;
		int weight;
		string name;

		static int numOfAnimals;
	
	public:
		int getHeight() { return height; }
		int getWeight() { return weight; }
		string getName() { return name; }
		void setHeight(int cm) { height = cm; }
		void setWeight(int kg) { weight = kg; }
		void setName(string animalName) { name = animalName; }
		
		void setAll(int, int, string);
		
		Animal(int, int, string);

		~Animal();

		Animal();
		
		static int getNumOfAnimals() { return numOfAnimals; }
			
		void toString();	

};


// Define static vars
int Animal::numOfAnimals = 0;

// Define static methods
void Animal::setAll(int height, int weight, string name) {

	this -> height = height;
	this -> weight = weight;
	this -> name = name;
	Animal::numOfAnimals++;

}


Animal::Animal(int height, int weight, string name){

	this -> height = height;
        this -> weight = weight;
        this -> name = name;
        Animal::numOfAnimals++;

}



Animal::~Animal(){

	cout << "Animal " << this -> name << "destroyed " << endl;

}

Animal::Animal(){
	
	Animal::numOfAnimals++;

}

void Animal::toString() {

	cout << this -> name << " is " << this -> height << " cms tall and " << this -> weight << " kgs" << endl;

}



// Inheritance
class Dog : public Animal {
	
	private: 
		string sound = "Woof";
	public:
		void getSound() { cout << sound << endl; }
	
	Dog(int, int, string, string);
	
	// Call dafault superclass constructor as default constructor
	Dog(): Animal() {};

	void toString();

};

// Use Animal constructor for part of the construction
Dog::Dog(int height, int weight, string name, string bark) :
Animal(height, weight, name) {

	this -> sound = bark;

}

void Dog::toString(){

	cout << this -> getName() << " is " << this -> getHeight() << " cm tall " << endl;

}

int main8() {
	// classes

	Animal fred; 

	fred.setHeight(33);
	fred.setWeight(10);
	fred.setName("Fred");

	cout << fred.getName() << " is " << fred.getHeight() << " cm  tall " << endl;

	Animal tom(36, 15, "Tom");

	cout << tom.getName() << " is " << tom.getHeight() << " cm tall" << endl;

	Dog spot(38, 16, "Spot", "woof");

	cout << "Number of Animals " << Animal::getNumOfAnimals() << endl;

	spot.getSound();
	tom.toString();
	spot.toString();

	spot.Animal::toString();

	return 0;

}



void makeMeYoung(int* age){
	cout << "I used to be " << *age << endl;
	*age = 21;
}

void actYourAge(int& age) {
	age = 39;
}


int main7(){
	// Passing by reference

	int myAge = 35;
	
	// with pointer
	makeMeYoung(&myAge);

	cout << "I'm " << myAge << " years old now" << endl;

	// with reference
	int& ageRef = myAge;

	cout << "myAge : " << myAge << endl;

	ageRef++;
	
	cout << "myAge : " << myAge << endl;	

	actYourAge(ageRef);

	cout << "myAge : " << myAge << endl;
	
}



int main6() {
	// pointers

	int myAge = 39; 

	char myGrade = 'A';

	cout << "size of int " << sizeof(myAge) << endl;

	cout << "size of char " << sizeof(myGrade) << endl;

	cout << "myAge is located at " << &myAge << endl;

	

	int myAge2 = 39;

	int* agePtr = &myAge2;

	cout << "Address of pointer " << agePtr << endl;

	cout << "Data at memory address " << *agePtr << endl;

	int badNums[5] = {4,13,14,24,34};

	int* numArrayPtr = badNums;

	cout << "Address " << numArrayPtr << " Value " << *numArrayPtr << endl;

	numArrayPtr++; 	
	
	// Arrays are just pointers
	cout << "Address " << badNums << " Value " << *badNums << endl;

}





int main5() {
	// exception handling

	int number = 0;

	try {

		if (number != 0) {

			cout << 2 / number << endl;

		} else throw(number);

	} catch (int number) {

		cout << number << " is not valid" << endl;

	}

}



int main4(){
	// fileio

	string steveQuote = "A day without sunshine is like, you know, night";

	ofstream writer("stevequote.txt");

	if (! writer){
		cout << "Error opening file" << endl;
		return -1;
	} else {
		writer << steveQuote << endl;
		writer.close();
	}


	ofstream writer2("stevequote.txt", ios::app);

	if (! writer2){
                cout << "Error opening file" << endl;
                return -1;
        } else {
                writer2 << "\n -Steve Martin" << endl;
                writer2.close();
        }

	char letter; 
	
	ifstream reader("stevequote.txt");
	
	if(! reader){
		cout << "Error reading file" << endl;
		return -1;
	} else {
		for(int i = 0; ! reader.eof(); i++) {
			reader.get(letter);
			cout << letter;
		}
	}
	return 0;
}


int addNumbers(int firstNum = 0, int secondNum = 0) {
	int combinedValue = firstNum + secondNum;
	return combinedValue;
}


int addNumbers(int firstNum, int secondNum, int thirdNum) {
        int combinedValue = firstNum + secondNum + thirdNum;
        return combinedValue;
}


int main3() {
	// working with functions
	cout << addNumbers(1,2) << endl;
	cout << addNumbers(1,5,6) << endl;
} 


int main2() {
	// working with vetors 
	vector <int> lotteryNumVect(10);

	int lotteryNumArray[5] = {4, 13, 14, 24, 34};

	lotteryNumVect.insert(lotteryNumVect.begin(), lotteryNumArray, lotteryNumArray + 3);

	lotteryNumVect.insert(lotteryNumVect.begin() + 5, 44);

	cout << lotteryNumVect.at(5) << endl;

	lotteryNumVect.push_back(64);

	cout << "Final Value " << lotteryNumVect.size();

	lotteryNumVect.pop_back();

	cout << "Size " << lotteryNumVect.size() << endl;
}


int main1() {

	cout << "Hello World" << endl;
	
	cout << sizeof(29) << endl;
	
	char happyArray[4] = {'H', 'a', 'p', '\0'};

	string birthdayString = " Birthday";

	double eulersConstant = .57721;

	cout << happyArray + birthdayString << endl;
	
	string eulerDouble;
	//eulerDouble = stod(eulerGuess);
	getline(cin, eulerDouble);

	cout << eulerDouble << endl;
	cout << eulerDouble.size() << endl;
	cout << sizeof(eulerDouble) << endl;


	string yourName; 
	cout << "What is your name? ";
	getline(cin, yourName);

	cout << "hello " << yourName << endl;

	string wholeName = yourName.assign(yourName);

	cout << wholeName << endl;

	string firstName = wholeName.assign(wholeName, 0, 5);

	cout << firstName << endl;

	int lastNameIndex = yourName.find("Ian", 0);
	cout << "Index for last (first) name " << lastNameIndex << endl;
	
	yourName.insert(5, " Banas");
	cout << yourName << endl;

	return 0;
	
}
