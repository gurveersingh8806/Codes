# Q1. WAP to calculate the area of a rectangle
a = 5
b = 4
area = a*b
print(area)

# Q2. WAP to find the smallest value from the list of n numbers.
lst = [6,0,3,11,5]
small_num = lst[0]
for i in lst:
    if small_num >= i:
        small_num = i
    else:
        pass
print(small_num)

# Q3. WAP to calculate the greatest common divisor of two numbers.
a = int(input())
b = int(input())
lst = []
if a>= b:
    for i in range(1,a):
        for j in range(1,b+1):
            if a%i == 0:
                lst.append(i)
            if b%j == 0:
                lst.append(j)
if a<=b:
    for i in range(1,a+1):
        for j in range(1,b):
            if a%i == 0:
                lst.append(i)
            if b%j == 0:
                lst.append(j)
set = set(lst)
lst1 = list(set)
gcd = lst1[0]
for i in lst1:
    if gcd <= i:
        gcd = i
    else:
        pass
print(gcd)


# Q4. WAP to find the exponentiation of a number.
import math
n = int(input())
exp_n = math.exp(n)
print(exp_n)

# Q5. WAP to find first n prime numbers.
n = int(input())
lst = []
i = len(lst)
num = 2
while i <= n:
    for a in range(2,int(num**0.5)+1):
        if num%a != 0:
            lst.append(num)
    num += 1
print(lst)
# Q6. WAP to count the numbers of (i) characters, (ii) Vovels and (iii) Consonents in the string. Make
# saperate functions and call.
# Q7. Design a composite function area(radius(decide_here_what_you_will_pass)) for calculating the area
# of a circle. Center of the circle is stored in (x_c, y_c) coordinates. A point on the parameter of a circle is
# given by (x_p, y_p). All the coordinates are taken as input from the user.
# Q8. Define a function to sum n natural numbers. Use sum and n as a global variable (do not pass as an
# argument or local variable) and print the value of sum in the main function.
# Q9. Define a function in Python which takes a list as an argument, multiplies every element of the input
# list by 2 and appends new elements to the same list.
# For example:
# Input: [1,2,3]
# Output: [1,2,3,2,4,6]
# Show that the id of the list passed to the function is the same as the list processed within the function.
# Q10. Design a nested void function in Python (not-fruitful) to find the reverse of a number entered by a
# user. Address the following constraints:
# 1. Pass the number entered by the user as a positional argument to the outer function.
# 2. reverse() is an inner function (nested function) and no argument is passed to this function.
# 3. Both the functions are void i.e., they do not return any value to any function.
# 4. Do not use print statements with the functions.