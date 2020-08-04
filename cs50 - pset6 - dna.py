import csv
import sys

if len(sys.argv) != 3:

    print("Missing command line argument :E")
    exit(1)

# open the csv file and load contents into dictionary called data
with open(sys.argv[1], newline = '') as csvfile:

    data1 = csv.DictReader(csvfile)

    # iterate through the row grabbing STR values
    for row in data1:

        STRs = [key for key in row if key != 'name']
        break


# open text file and load dna sequence
with open(sys.argv[2], newline = '') as textfile:

    data2 = csv.reader(textfile)

    # store dna sequence in a string
    SQNs = (next(data2)[0])


# create a dictionary where we will store the sequences we are going to count
sequences = {}

# copy the list SRTs with genes in a dictionary as keys
for item in STRs:

    sequences[item] = 1

# iterates through the dna sequence, when it finds repetitions with keys from dictionary it counts them
for key in sequences:

    l = len(key)
    tempMax = 0
    temp = 0

    for i in range(len(SQNs)):
        # after counting a sequence it skips at the end to avoid counting again
        while temp > 0:
            temp -= 1
            continue

        # if the part of sequence matches the one of the keys and there is a repetition we start counting
        if SQNs[i: i + l] == key:
            while SQNs[i - l: i] == SQNs[i: i + l]:
                temp += 1
                i += l

            # compares the value to the previous longest sequence and if it is longer it overrides it
            if temp > tempMax:
                tempMax = temp

    # store the longes sequence in the dictionary at corresponding key
    sequences[key] += tempMax


# open and iterate through database of people treating each one as a dictionary so it can compare to the sequences one
with open(sys.argv[1], newline = '') as csvfile:

    data1 = csv.DictReader(csvfile)
    for person in data1:
        match = 0
        # compares the sequences to every person and prints name before leaving the program if there is a match
        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1
        if match == len(sequences):
            print(person['name'])
            exit()

    print("No match")



# my beggining


import csv
import sys

if len(sys.argv) != 3:

    print("Missing command line argument :E")
    exit(1)

# open the csv file and load contents into dictionary called data
with open(sys.argv[1], newline = '') as csvfile:

    data1 = csv.DictReader(csvfile)

    # iterate through the row grabbing STR values
    for row in data1:

        STRs = [key for key in row if key != 'name']
        break

    print(STRs)



# open text file and load sequence into list called sqns
with open(sys.argv[2], newline = '') as textfile:

    data2 = csv.reader(textfile)

    SQNs = (next(data2)[0])
    
    print(SQNs)
    
    