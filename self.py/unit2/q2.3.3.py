num = int(input("Enter three digits (each digit for one pig): "))
n1 = num % 10
n2 = num % 100 // 10
n3 = num // 100

print(n1 + n2 + n3)
print((n1 + n2 + n3) // 3)
print((n1 + n2 + n3) % 3)
print((n1 + n2 + n3) % 3 == 0)