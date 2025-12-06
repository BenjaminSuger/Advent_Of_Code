#!/bin/python3

def count(string : str) -> int:
    
    x = 0
    y = 0
    houses = {(x,y)} #here I set up a set() with the original coordonnates

    for i in string:
        match(i):
            case "^":
                y += 1
                houses.add((x,y)) # I add each time the new house visited if already inside the set, it's not add 
            case ">":
                x += 1
                houses.add((x,y))
            case "<":
                x -= 1
                houses.add((x,y))
            case "v":
                y -= 1 
                houses.add((x,y))
    return len(houses) #I count only the number of houses I have

def main():
    file = open("input.txt")
    string = file.readline()
    file.close()
    print(count(string))

main()
