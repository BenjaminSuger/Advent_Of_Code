#!/bin/python3
import linecache as lc

#aeiou 3 times
#ab cd pq and xy not in
#1 repetition

def check_line(line : str) -> int :
    double = 0
    count = 0
    vowels = ['a', 'e', 'i', 'o', 'u']
    forbidden = ["ab", "cd", "pq", "xy"]
    #list comprehension to check if it's forbidden
    temp = [x for x in forbidden if x in line]
    if len(temp) > 0:
        return 0
    #list comprehension to check if we have 3 vowels
    temp = [x for x in line if x in vowels]
    if (len(temp) < 3):
        return 0
    #need to check if we have repetition of letters
    temp = ''
    for i in line:
        if temp == i:
            return 1
        temp = i
    return 0


def main(file):
    i = 1
    count = 0
    line = lc.getline(file, i)
    while (len(line) > 0):
        count += check_line(line)
        i += 1
        line = lc.getline(file, i)
    print(f"the number of nice string is {count}")
        

        


main("input.txt")
