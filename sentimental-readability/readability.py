text = input("Text: ")

# counting number of sentences

def num_sen(text):
    n = 0
    for i in text:
        if i in '.!?':
            n += 1
    return n

# counting number of letters

def num_letters(text):
    n = 0
    for i in text:
        if i.isalpha():
            n += 1
    return n


nsentences = num_sen(text)
nwords = len(text.split(' '))
nletters = num_letters(text)

# calculating avg per 100 words

lavg = (nletters/nwords)*100
savg = (nsentences/nwords)*100

# calculating index

index = (0.0588 * lavg - 0.296 * savg - 15.8)

# checking index value and giving suitable output

if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print("Grade", round(index))