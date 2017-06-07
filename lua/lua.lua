print("Hello World!")

io.write("Hello world, from ",_VERSION,"!\n")

--[[ my first program in Lua --]]

--Reserved words:
--and break do else
--elseif end false for
--function if in local
--nil not or repeat
--return then true until
--while

local i, j
local i
local a,c

local d , f = 5 , 10 -- local
d , f = 5 , 10; --globals
d, f = 10 --f is nil

-- Variable definition
local a, b

-- Initialization
a = 10
b = 30

print("value of a:", a)
print("value of b:", b)

-- Swapping of variables
b, a = a, b
print("value of a:", a)
print("value of b:", b)

f = 70.0/3.0
print("value of f:", f)

g = 20

-- Lua is Dynamically typed
-- but the values have types:
-- nil, boolean, number, string
-- function, userdata, thread, table

print(type("What is my type"))
t = 10
print(type(5.8*t))
print(type(true))
print(type(print))
print(type(type))
print(type(nil))
print(type(type("ABC")))

-- Operators
A = 10
B = 20
print(A + B)
print(A - B)
print(A * B)
print(A / B)
print(A % B)
print(A ^ 2)
print(-A)

print(A == B)
print(A ~= B)
print(A > B)
print(A < B)
print(A >= B)
print(A <= B)

A, B = true, false
print(A and B)
print(A or B)

A = "Hello "
B = "World"
print(A..B)
print(#A)

-- Loops
a = 10
while ( a < 20)
do 
    print("value of a:", a)
    a = a + 1
end

for i=10, 1, -1
do
    print(i)
end

a = 10
repeat
    print("value of a:", a)
    a = a + 1
until(a > 15)

-- Branching
a = 10;
if ( a < 20)
then
    print("a is less than 20");
else
    print("a is not less than 20");
end

-- Functions
function max(num1, num2)
    if (num1 > num2) then
        result = num1;
    else
        result = num2;
    end

    return result;
end

print("The max of 10 and 4 is ", max(10, 4))

-- Passing functions
myprint = function(param)
    print("This is my print function - ##",param,"##")
end

function add(num1, num2, functionPrint)
    result = num1 + num2
    functionPrint(result)
end

myprint(10)
add(2, 5, myprint)

-- Var args
function average(...)
    result = 0
    local arg = {...}
    for i, v in ipairs(arg) do
        result = result + v
    end
    return result / #arg
end

print("The average is", average(10,5,3,4,5,6))

-- Strings
string1 = "Lua"
print("\"String 1 is\"", string1)
string2 = 'Tutorial'
print("String 2 is", string2)
string3 = [["Lua Tutorial"]]
print("String3 is", string3)

string1 = "Lua";
print(string.upper(string1))
print(string.lower(string1))

newstring = string.gsub(string1, "a", "b")
print("The new string is: ", newstring)

print(string.find(string1, "Tutorial"))
reversed = string.reverse(string1)
print("reversed:", reversed)

number1 = 10
number2 = 20
print(string.format("Basic formatting %s %s", string1, string2))
date = 2; month = 1; year = 2014
print(string.format("Date formatting %02d/%02d/%03d", date, month, year))
print(string.format("%.4f",1/3))

-- Byte conversion
print(string.byte("Lua"))
print(string.byte("Lua",3))
print(string.byte("Lua",-1))
print(string.byte("Lua",2))
print(string.char(97))

print("Concatenation", string1..string2)
print("Length of string1 is", string.len(string1))
print("Repeated string is ", string.rep(string1, 3))

-- Arrays
array = {"Lua", "Tutorial"}
for i = 0, 2 do
    print(array[i])
end

-- ^indexing starts at 1!

array = {}
for i = -2, 2 do
    array[i] = i *2
end

for i = -2,2 do
    print(array[i])
end

-- Initializing the array
array = {}
for i = 1,3 do
    array[i] = {}
    
    for j=1,3 do
        array[i][j] = i * j
    end
end

-- Accessing the array
for i = 1,3 do
    for j = 1,3 do
        print(array[i][j])
    end
end

-- Manipulating indices
array = {}
maxRows = 3
maxColumns = 3

for row = 1, maxRows do

    for col = 1, maxColumns do
        array[row * maxColumns + col] = row * col
    end

end

for row = 1, maxRows do
    for col = 1, maxColumns do
        print(array[row * maxColumns + col])
    end
end

-- iterators
array = {"Lua", "Tutorial"}
for key, value in ipairs(array)
do
    print(key, value)
end

function square(iteratorMaxCount, currentNumber)
    if currentNumber < iteratorMaxCount
    then
        currentNumber = currentNumber + 1
        return currentNumber, currentNumber * currentNumber
    end
end

for i, n in square, 3, 0
do
    print(i, n)
end


-- https://www.tutorialspoint.com/lua/lua_iterators.htm
