#Question-1: Write a Python program to read an entire text file.
#Solution: 
f = open("demo.txt", "r")
data = f.read()
print(data)


#Question-2: Write a Python program to read first n lines of a file.
#Solution: 
f = open("demo.txt", "r")
n = int(input("Enter any number: "))
for i in range(n):     
    l = f.readline()
    print(l)


#Question-3: Write a Python program to append text to a file and display the text.
#Solution: 
f = open("demo.txt", "a+")
data = f.write(" Now, I am preparing for my exams.")
f.seek(0)
r = f.read()
print(r)


#Question-4: Write a Python program to read last n lines of a file.
#Solution: 
f = open("demo.txt", "r")
l = len(f.readlines())
f.seek(0)
n = int(input("Enter any number: "))
i = 1
while i<=l-n:
    r = f.readline()
    i += 1
else:
    r = f.read()
    print(r)


#Question-5: Write a Python program to read a file line by line and store it into
#(a) a list
#Solution: 
f = open("demo.txt", "r")
store = f.readlines()
print(store)

#(b) a variable
#Solution: 
f = open("demo.txt", "r")
store = f.read()
print(store)


#Question-6: Write a Python program to count the number of lines in a text file.
#Solution: 
f = open("demo.txt", "r")
l = len(f.readlines())
print("Number of lines in the file is: ", l)


#Question-7: Write a Python program to copy the contents of a file to another file.
#Solution: 
f1 = open("demo.txt", "r")
data1 = f1.read()

f2 = open("New_file.txt", "w+")
f2.write(data1)
f2.seek(0)
data2 = f2.read()
print(data2)


#Question-8: Write a Python program that opens a text file named "data.txt" in binary read mode, reads the contents, and prints them to the console. Enumerate the different file modes available in Python (e.g., 'r', 'w', 'a',
# 'b', '+') and explain when you would use each one.
#Solution: 
f = open("data.txt", "rb")
data = f.read()
print(data)


#Question-9: Write a Python program that uses the format operator (%) to insert values into a string and print the resulting string to the console. Explain the purpose of the format operator in Python and how it can be
# used to format output.
#Solution: 
Name = input("Enter your name: ")
Course = input("Enter your course: ")
Branch = input("Enter your branch: ")
Institute = input("Enter the name of your Institute: ")
string = "I am %s doing %s course in %s branch in the institute %s" % (Name, Course, Branch, Institute)
print(string)


#Question-10: Write a Python program that uses f-strings to insert values into a string and print the resulting string to the console. Compare the use of the format operator and f-strings for string formatting in Python, and
# discuss the advantages of using f-strings
#Solution: 
Name = input("Enter your name: ")
Course = input("Enter your course: ")
Branch = input("Enter your branch: ")
Institute = input("Enter the name of your Institute: ")
string = f"I am {Name} doing {Course} course in {Branch} branch in the institute {Institute}"
print(string)