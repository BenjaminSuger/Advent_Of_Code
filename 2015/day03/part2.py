#!/bin/python3

def count(string : str) -> int:
    x = 0
    y = 0
    x_robot = 0
    y_robot = 0
    i = 0
    houses = {(x,y)}

    while i < len(string):
        match(string[i]):
            case "^":
                if (i % 2 == 0):
                    y +=1
                else: 
                    y_robot +=1
            case ">":
                if (i % 2 == 0):
                    x +=1
                else: 
                    x_robot +=1
            case "<":
                if (i % 2 == 0):
                    x -=1
                else: 
                    x_robot -=1
            case "v":
                if (i % 2 == 0):
                    y -=1
                else: 
                    y_robot -=1
        houses.add((x,y))
        houses.add((x_robot,y_robot))
        i += 1
    return (len(houses))

def main():
    file = open("input.txt")
    string = file.readline()
    file.close()
    print(count(string))

main()
