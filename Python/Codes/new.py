# def func_paren(n):
#     def combinations(s,left,right):
#         if len(s)==2*n:
#             combo.append(s)
#             return
#         if left < n:
#             combinations(s+"(",left+1,right)
#         if right < left:
#             combinations(s+")",left,right+1)
#     combo = []
#     combinations('',0,0)
#     return combo
# n = int(input())
# a = func_paren(n)
# for i in a:
#     print(i)

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
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