n = input('Height: ')

# checking if number
while not n.isdigit():
    n = input('Height: ')
n = int(n)

# checking numerical range
while n > 8 or n < 1:
    n = int(input('Height: '))

# printing in for loop
for i in range(1, n+1):
    print(' '*(n-i)+'#'*i+'  '+'#'*i)