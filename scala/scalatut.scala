// Byte -128 to 127
// Boolean : true or false
// Char : unsigned max value 65535
// Short : -32768 to 32767
// Int : -2147483648 to 2147483647
// Long : 9223372036854775808 to 9223372036854775807
// Float : -3.402823E38 to 3.4028235F38
// Double : -1.7976931348623157E308 to 1.7976931348623157E308

import scala.io.StdIn.{readLine, readInt}
import scala.math._
import scala.collection.mutable.ArrayBuffer
import java.io.PrintWriter
import scala.io.Source

object ScalaTutorial {

	// Exception handling
	def main(args: Array[String]) {
		def divideNums(num1: Int, num2: Int) = try
		{
			(num1 / num2)
		} catch {
			case ex : java.lang.ArithmeticException => "Can't divide by zero"
		} finally {
			// cleanup after exception
		}

		print("3 / 0 = " + divideNums(3,0))
	}


	// File I/O
	def main13(args: Array[String]) {

		val writer = new PrintWriter("test.txt")
		writer.write("Just some random text\nSome more random text")
		writer.close()

		val textFromFile = Source.fromFile("test.txt", "UTF-8")

		val lineIterator = textFromFile.getLines

		for(line <- lineIterator) print(line)

		textFromFile.close()

	}


	// Higher order functions
	def main12(args: Array[String]) {
		val log10Func = log10 _
		println(log10Func(1000))

		List(1000.0, 10000.0).map(log10Func).foreach(println)

		List(1,2,3,4,5).map((x : Int) => x * 50).foreach(println)

		List(1,2,3,4,5).filter(_ % 2 == 0).foreach(println)

		def times3(num : Int) = num * 3
		def times4(num : Int) = num * 4

		def multIt(func : (Int) => Double, num : Int) = {
			func(num)
		}

		printf("3 * 100 = %.1f\n", multIt(times3, 100))

		val divisorVal = 5
		val divisor5 = (num : Double) => num / divisorVal

		println("5 / 5 = " + divisor5(5.0))
	}


	// Traits - like interfaces, more than one can be implemented
	def main11(args: Array[String]) {

		val superman = new Superhero("Superman")
		println(superman.fly)
		println(superman.hitByBullet)
		println(superman.ricochet(2500))

	}

	trait Flyable {
		def fly : String
	}

	trait BulletProof {
		def hitByBullet : String
		def ricochet(startSpeed : Double) : String = {
			"The bullet ricochets at a speed of %.1f ft/sec".format(startSpeed * .75)
		}
	}

	class Superhero(val name: String) extends Flyable with BulletProof {
		def fly = "%s flys through the air".format(this.name)

		def hitByBullet = "The bullet bounces off of %s".format(this.name)
	}


	// Abstract classes
	def main10(args: Array[String]) {
		val fang = new Wolf("Fang")
		fang.moveSpeed = 36.0
		println(fang.move)
	}

	abstract class Mammal(val name : String) {
		var moveSpeed : Double

		def move : String
	}

	class Wolf(name: String) extends Mammal(name){
		var moveSpeed = 35.0

		def move = "The wolf %s runs %.2f mph".format(this.name, this.moveSpeed)
	}


	def main9(args: Array[String]) {
		// Classes
		// No static vars or methods
		val rover = new Animal
		rover.setName("Rover")
		rover.setSound("Woof")
		printf("%s says %s\n", rover.getName, rover.getSound)

		val whiskers = new Animal("Whiskers", "Meow")
		println(s"${whiskers.getName} with id ${whiskers.id} says ${whiskers.sound}" )

		println(whiskers.toString)

		val spike = new Dog("Spike", "woof", "Grrrr")
		spike.setName("Spike1")
		println(spike.toString)
	} // END OF MAIN


	class Animal(var name: String, var sound: String) {

		this.setName(name)
		val id = Animal.newIdNum

		def getName() : String = name
		def getSound() : String = sound
		def setName(name : String) {
			if (!(name.matches(".*\\d+.*")))
				this.name = name
			else
				this.name = "No Name"
		}
		def setSound(sound: String) {
			this.sound = sound
		}

		// Custom constructors
		def this(name : String) {
			this("No Name", "No Sound")
			this.setName(name)
		}
		def this() {
			this("No Name", "No Sound")
		}

		// Overriding
		override def toString() : String = {
			return "%s with the id %d says %s".format(this.name, this.id, this.sound)
		}
	}

	// Companion object - for static vars and functions
	object Animal {
		private var idNumber = 0
		private def newIdNum = { idNumber += 1; idNumber }
	}


	// Inheritance
	class Dog(name: String, sound: String, growl: String) extends Animal(name, sound) {
		def this(name: String, sound: String) {
			this("No Name", sound, "No Growl")
			this.setName(name)
		}

		def this(name: String) {
			this("No Name", "No Sound", "No Growl")
			this.setName(name)
		}

		def this(){
			this("No Name", "No Sound", "No Growl")
		}

		override def toString(): String = {
			return "%s with the id %d says %s".format(this.name, this.id, this.growl)
		}
	}


	def main8(args: Array[String]) {
		// Tuples
		var tupleMarge = (
			103, "Marge", 10.25
		)

		printf("%s owes us $%.2f\n", tupleMarge._2, tupleMarge._3)

		// Product iterator
		tupleMarge.productIterator.foreach{ i => println(i) }
		println(tupleMarge.toString())
	}


	def main7(args: Array[String]) {
		// Maps
		val employees = Map(
			"Manager" -> "Bob Smith",
			"Secretary" -> "Sue Brown"
		)

		if (employees.contains("Manager"))
			printf("Manager : %s\n", employees("Manager"))

		val customers = collection.mutable.Map(
			100 -> "Paul Smith",
			101 -> "Sally Smith"
		)

		printf("Cust 1: %s\n", customers(100))

		customers(100) = "Tom Marks"

		customers(102) = "Megan Swift"

		for ((k, v) <- customers)
			printf("%d : %s\n", k, v)

	}


	def main6(args: Array[String]) {
		// Functions
		// def funcName (param1:dataype, param2:dataType) : returnType = {
		// 	function body
		// 	return valueToReturn
		// }
		def getSum(num1 : Int = 1, num2 : Int = 1) : Int = {
			return num1 + num2
		}

		println("5 + 4 = " + getSum(num2 = 5, num1 = 4))

		// Procedures don't return values
		def sayHi() : Unit = {
			println("Hi how are you?")
		}

		sayHi

		def getSum2(args : Int*) : Int = {
			var sum : Int = 0
			for (num <- args) {
				sum += num
			}
			sum
		}
		println("Get Sum2: " + getSum2(1,2,3,4,5))

		def factorial(num : BigInt) : BigInt = {
			if (num <= 1)
				1
			else
				num * factorial(num - 1)
		}

		println("Factorial of 4 = " + factorial(4))

		// Array
		val favNums = new Array[Int](20)
		val friends = Array("Bob", "Tom")
		friends(0) = "Sue"
		println("Best friends " + friends(0))
		// Arraybuffers for variable sized arrays
		val friends2 = ArrayBuffer[String]()
		friends2.insert(0, "Phil")
		friends2 += "Mark"
		friends2 ++= Array("Susy", "Paul")
		friends2.insert(1, "Mike", "Sally", "Sam", "Mary", "Sue")
		friends2.remove(1,2)

		var friend : String = " "

		for (friend <- friends2) println(friend)
		for (j <- 0 to (favNums.length - 1)){
			favNums(j) = j
			println(favNums(j))
		}

		// similar to list comprehensions
		val favNumsTimes2 = for(num <- favNums) yield 2 * num
		// functional print list
		favNumsTimes2.foreach(println)

		var favNumsDiv4 = for(num <- favNums if num % 4 == 0) yield num
		favNumsDiv4.foreach(println)

		// multidim arrays
		var multTable = Array.ofDim[Int](10,10)
		for (i <- 0 to 9) {
			for (j <- 0 to 9) {
				multTable(i)(j) = i * j
				printf("%d : %d = %d\n", i, j, multTable(i)(j))
			}
		}

		println("Sum: " + favNums.sum)
		println("Sum: " + favNums.min)
		println("Sum: " + favNums.max)

		// Desc sort
		val sortedNums = favNums.sortWith(_>_)
		// Asc sort
		val sortedNums2 = favNums.sortWith(_<_)

		println(sortedNums.deep.mkString(", "))

	}


	def main5(args: Array[String]) {
		// Iteration
		var randSent = "I saw a dragon fly by"
		println("String length: " + randSent.length)
		println(randSent.concat(" and explode"))
		println("Are strings equal " + "I saw a dragon".equals(randSent))
		println("dragon starts at index " + randSent.indexOf("dragon"))
		val randSentArray = randSent.toArray
		for (v<- randSentArray) println(v)
	}

	def main4(args: Array[String]) {
		// Strings
		val name = "Derek"
		val age = 39
		val weight = 175.5

		println(s"Hello $name")
		println(f"I am ${age + 1} and weight $weight%.2f")

		println("'%-5s'\n", 3.14)

	}


	def main3(args: Array[String]) {
		// IO

		var numberGuess = 0

		do {
			print("Guess a number ")
			numberGuess = readLine.toInt
		} while (numberGuess != 15)
		printf("You guessed the secret number %d\n", 15)

	}


	def main2(args: Array[String]) {
		// Working with vars
		var i = 0
		while (i <= 10) {
			println(i)
			i += 1
		}

		do {
			println(i)
			i += 1
		} while (i <= 20)


		val randLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		for (i <- 0 until randLetters.length)
			print(randLetters(i))

		val aList = List(1,2,3,4,5)
		for (i <- aList) { println("List items " + i) }


		var evenList = for { i <- 1 to 20 
			if (i % 2) == 0
		} yield i

		for (i <- evenList) println(i)

		for (i <- 1 to 5; j <- 6 to 10) {
			println(i, j)
		}

		def printPrimes() {
			val primeList = List(1,2,3,5,7,11)
			for (i <- primeList) {
				if (i == 11) {
					return
				}
				if(i != 1) { println(i)}
			}
		}
		printPrimes
	}

}
