import Data.List
import System.IO

-----------------
-- Data Types  --
-----------------
-- Int -2^63, 2^63
-- Integer
-- Float
-- Double -- 11pts precision

bigFloat = 3.99999999999 + 0.000000000005 -- works
bigFloatBad = 3.99999999999 + 0.00000000000005 -- doesn't?

-- Bool True False
-- Char
-- Tuple

-- permanent values
always5 :: Int
always5 = 5


--------------------
-- Math functions --
--------------------
mathEx = 5 + 4 / 3 * 2
modEx = mod 5 4 -- prefix operator (comes before actual numbers)
modEx2 = 5 `mod` 4 -- infix operator

negNumEx = 5 + (-4) -- needed for negative numbers

-- Note: to get info about functions use `:t`

num9 = 9 :: Int
sqrtOf9 = sqrt (fromIntegral num9)

piVal = pi
ePow9 = exp 9
logOf9 = log 9
squared9 = 9 ** 2
truncateVal = truncate 9.999
roundVal = round 9.999
ceilingVal = ceiling 9.999
floorVal = floor 9.999

-- Also sin, cos, tan, asin, atan, acos, sinh,
-- tanh, cose, asinh, atanh, acosh

-----------------------
-- Logical operators --
-----------------------

trueAndFalse = True && False
trueOrFalse = True || False
notTrue = not(True)

-----------------------
-- Lists --
---------------------
primeNumbers = [3,5,7,11]
morePrimes = primeNumbers ++ [13,17.19]
favNums = 2: 7 : 21 : 66 : []
multList = [[3,5,7],[11,13,17]]
morePrimes2 = 2 : morePrimes
lenPrime = length morePrimes2

revPrime = reverse morePrimes2
isListEmpty = null morePrimes2
secondPrime = morePrimes2 !! 1
firstPrime = head morePrimes2
lastPrime = last morePrimes2
primeInit = init morePrimes2
first3Primes = take 3 morePrimes2
removedPrimes = drop 3 morePrimes2
is7InList = 7 `elem` morePrimes2
maxPrime = maximum morePrimes2
minPrime = minimum morePrimes2
sumPrimes = sum primeNumbers

newList = [2,3,5]
prodList = product newList

evenList = [2,4..20]
letterList = ['A', 'C'..'Z']

infinPow10 = [10, 20..] -- infinite list (lazily created)

many2s = take 10 (repeat 2)
many3s = replicate 10 3

cycleList = take 10 (cycle [1,2,3,4,5])
listTimes2 = [x * 2 | x <- [1..10]] -- like list comprehensions
listTimes3 = [x * 3 | x <- [1..10], x * 3 <= 50] -- with filtering
divisBy9N13 = [x | x <- [1..500], x `mod` 13 == 0, x `mod` 9 == 0] -- 1 thru 500, when divisible by 13 and 9

sortedList = sort [9, 1, 78, 3]
sumOfLists = zipWith (+) [1,2,3,4,5] [6,7,8,9,10]
listBiggerThen5 = filter (>5) morePrimes
evensUpTo20 = takeWhile (<= 20) [2,4..]
multOfList = foldl (*) 1 [2,3,4,5] -- perform an operation on items from l to r

-------------------------
-- List comprehensions --
-------------------------
pow3List = [3^n | n <- [1..10]]
multTable = [[x * y | y <- [1..10]] | x <- [1..10]]

-------------------------
-- Tuples ---------------
-------------------------
randTuple = (1, "Random Tuple")
bobSmith = ("Bob Smith", 52)

bobsName = fst bobSmith
bobsAge = snd bobSmith
names = ["Bob", "Mary", "Tom"]
addresses = ["123 Main", "234 North", "567 South"]
namesNAddress = zip names addresses

-------------------------
-- Functions ------------
-------------------------
main1 = do
	putStrLn "Whats your name?"
	name <- getLine
	putStrLn ("Hello " ++ name)

-- Type declarations
addMe :: Int -> Int -> Int
-- funcName param1 param2 = operations (returned value)
addMe x y = x + y

-- No type declaration, floats can be used
sumMe x y = x + y

addTuples :: (Int, Int) -> (Int, Int) -> (Int, Int)
addTuples (x, y) (x2, y2) = (x + x2, y + y2)

whatAge :: Int -> String
whatAge 16 = "You can drive"
whatAge 18 = "You can vote"
whatAge 21 = "You're an adult"
whatAge _ = "Nothing important"

-- Recursion
factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n - 1)

-- Another way to do it
prodFact n = product [1..n]

-- Guards
isOdd :: Int -> Bool
isOdd n
	| n `mod` 2 == 0 = False
	| otherwise = True

isEven n = n `mod` 2 == 0

whatGrade :: Int -> String
whatGrade age
	| (age >= 5) && (age <= 6) = "Kindergarden"
	| (age > 6) && (age <= 10) = "Elementary School"
	| (age > 10) && (age <= 14) = "Middle School"
	| otherwise = "Go to high school"

-- Whatwhere
batAvgRating :: Double -> Double -> String
batAvgRating hits atBats
	| avg <= 0.200 = "Terrible Batting avg"
	| avg <= 0.250 = "Average player"
	| otherwise = "Superstar"
	where avg = hits / atBats

-- List Items Accession
getListItems :: [Int] -> String
getListItems [] = "Your list is empty"
getListItems (x:[]) = "Your list starts with " ++ show x
getListItems (x:y:[]) = "Your list contains " ++ show x ++ " and " ++ show y
getListItems (x:xs) = "The 1st item is " ++ show x ++ " and the rest are " ++ show xs

getFirstItem :: String -> String
getFristItem [] = "Empty String"
getFirstItem all@(x:xs) = "The first letter in " ++ all ++ " is " ++ [x]

-- Higher order functions
times4 :: Int -> Int
times4 x = x * 4

listTimes4 = map times4 [1,2,3,4,5]

multBy4 :: [Int] -> [Int]
multBy4 [] = []
multBy4 (x:xs) = times4 x : multBy4 xs

areStringsEq :: [Char] -> [Char] -> Bool
areStringsEq [] [] = True
areStringsEq (x:xs) (y:ys) = x == y && areStringsEq xs ys
areStringsEq _ _ = False

-- Pass function into a function
doMult :: (Int -> Int) -> Int
doMult func = func 3
num3Times4 = doMult times4

getAddFunc :: Int -> (Int -> Int)
getAddFunc x y = x + y
adds3 = getAddFunc 3
fourPlus3 = adds3 4
threePlusList = map adds3 [1,2,3,4,5]

-- Lambdas
dbl1To10 = map (\x -> x * 2) [1..10]

------------------
-- Conditionals --
------------------
doubleEvenNumber y =
	if (y `mod` 2 /= 0)
		then y
		else y * 2

-- doubleEvenNumber 100 -- 200
-- doubleEvenNumber 101 -- 101

getClass :: Int -> String
getClass n = case n of
	5 -> "Go to Kindergarten"
	6 -> "Go to elementary School"
	_ -> "Go away"

-------------
-- Modules --
-------------
-- Define exports in another file
--module SampFunctions (getClass, doubleEvenNumbers) where
-- import in this file
--import SampFunctions

-----------------------
-- Enumeration Types --
-----------------------
data BaseballPlayer = Pitcher
	| Catcher
	| Infielder
	| Outfield
	deriving Show

barryBonds :: BaseballPlayer -> Bool
barryBonds Outfield = True
barryInOF = print(barryBonds Outfield)

------------------
-- Custom Types --
------------------
data Customer = Customer String String Double
	deriving Show -- to use as a string

tomSmith :: Customer
tomSmith = Customer "Tom Smith" "123 Main" 20.50
getBalance :: Customer -> Double
getBalance (Customer _ _ b) = b


data RPS = Rock | Paper | Scissors
shoot :: RPS -> RPS -> String
shoot Paper Rock = "Paper beats Rock"
shoot Rock Scissors = "Rock beats Scissors"
shoot Scissors Paper = "Scissors beats Paper"
shoot Scissors Rock = "Scissors Losts to Rock"
shoot Paper Scissors = "Paper Loses to Scissors"
shoot Rock Paper = "Rock loses to Paper"
shoot _ _ = "Error"

-- shoot Paper Rock --> "Paper Beats Rock"

-- Two versions of a type
data Shape = Circle Float Float Float | Rectangle Float Float Float Float
	deriving Show

area :: Shape -> Float
area (Circle _ _ r) = pi * r ^ 2
area (Rectangle x y x2 y2) = (abs $ x2 - x) * (abs $ y2 - y)

------------------
-- Dot Operator --
------------------
sumValue = putStrLn (show (1 + 2))
sumValue2 = putStrLn . show $ 1 + 2
areaOfCircle = area (Circle 50 60 20)
areaOfRect = area $ Rectangle 10 10 100 100

------------------
-- Type classes --
------------------
data Employee = Employee {
	name :: String,
	position :: String,
	idNum :: Int
	} deriving (Eq, Show)

samSmith = Employee {name = "Sam Smith", position = "Manager", idNum = 1000}
pamMarx = Employee {name = "Pam Marx", position = "Sales", idNum = 200}

isSamPam = samSmith == pamMarx
samSmithData = show samSmith

data ShirtSize = S | M | L
instance Eq ShirtSize where
	S == S = True
	M == M = True
	L == L = True
	_ == _ = False

instance Show ShirtSize where
	show S = "Small"
	show M = "Medium"
	show L = "Large"

smallAvail = S `elem` [S, M, L]
theSize = show S

class MyEq a where
	areEqual :: a -> a -> Bool

instance MyEq ShirtSize where
	areEqual S S = True
	areEqual M M = True
	areEqual L L = True
	areEqual _ _ = False

newSize = areEqual S S

--------------
-- I/O -------
--------------
sayHello = do
	putStrLn "What's your name"
	name <- getLine
	putStrLn $ "Hello " ++ name

writeToFile = do
	theFile <- openFile "test.txt" WriteMode
	hPutStrLn theFile ("Random line of text")
	hClose theFile

readFromFile = do
	theFile2 <- openFile "test.txt" ReadMode
	contents <- hGetContents theFile2
	putStr contents
	hClose theFile2

------------
-- Fib    --
------------
fib = 1 : 1 : [a + b | (a, b) <- zip fib (tail fib)]
fib300 = fib !! 300
