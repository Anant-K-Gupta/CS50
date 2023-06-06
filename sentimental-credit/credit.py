

def luhns(num):
    c1 = []
    c2 = []
    # take first set of nums

    for i in range(len(num)-2, -1, -2):
        c1.append(int(num[i])*2)

    for i in range(len(num)-1, -1, -2):
        c2.append(int(num[i]))

    # take second set of nums.

    c1 = splitter(c1)
    final = sum(c1)+sum(c2)
    return (final % 10 == 0)


def splitter(c1):
    c1n = []
    # splitting into multiple nums

    for i in c1:
        if i > 9:
            c1n.append(i % 10)
            c1n.append(i // 10)
        else:
            c1n.append(i)
    return c1n


num = input("Number: ")

# multiple conditions to split into categories
if luhns(num):
    if len(num) == 15 and num[0:2] in ['34', '37']:
        print('AMEX')
    elif (len(num) == 13 or len(num) == 16) and num[0] == '4':
        print('VISA')
    elif len(num) == 16 and num[0:2] in ['51', '52', '53', '54', '55']:
        print('MASTERCARD')
    else:
        print('INVALID')
# incase no case applies return invalid
else:
    print('INVALID')

