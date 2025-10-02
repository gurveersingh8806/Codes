n = int(input())
lst =  []
num = 2
while len(lst) < n:
    prime = 1
    for j in range(2,int(n**0.5)+1):
        if num%j ==0:
            prime = 0
            break
        if prime == 1:
            lst.append(num)
        num +=1    
print(lst)