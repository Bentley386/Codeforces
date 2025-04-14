import itertools

import numpy as np
import collections as col
import functools
import re
import matplotlib.pyplot as plt
import sys
import networkx as nx

def day1Part1():
    data = np.loadtxt("input.txt")
    arr1 = np.sort(data[:,0])
    arr2 = np.sort(data[:,1])
    print(np.sum(np.abs(arr1-arr2)))

def day1Part2():
    data = np.loadtxt("input.txt")
    arr1 = data[:,0]
    arr2 = data[:,1]
    similarity = 0
    c = col.Counter(arr2)
    print(functools.reduce(lambda x,y : x+y*c[y],arr1,0))

def day2Part1():
    with open("input.txt","r") as f:
        lines = f.readlines()
    data = [np.array(list(map(int,line.split()))) for line in lines]
    def checkSafe(record):
        if len(record) < 2:
            return True
        record_s = np.sort(record)
        if np.any(record != record_s) and np.any(record != record_s[::-1]):
            return False
        differences = np.abs(np.roll(record,-1)-record)[:-1]
        return np.all((differences >= 1) & (differences <= 3))
    print(sum([1 if checkSafe(x) else 0 for x in data]))

def day2Part2():
    # Idea: Brute force remove each possible digit and repeat Part 1

    with open("input.txt","r") as f:
        lines = f.readlines()
    data = [np.array(list(map(int,line.split()))) for line in lines]
    def checkSafe(record):
        if len(record) < 2:
            return True
        record_s = np.sort(record)
        if np.any(record != record_s) and np.any(record != record_s[::-1]):
            return False
        differences = np.abs(np.roll(record,-1)-record)[:-1]
        return np.all((differences >= 1) & (differences <= 3))
    def checkSafeWithRemoval(record):
        if checkSafe(record):
            return True
        N = len(record)
        for i in range(N):
            if checkSafe(np.delete(record,i)):
                return True
        return False

    print(sum([1 if checkSafeWithRemoval(x) else 0 for x in data]))

def day3Part1():
    pattern = r'mul\(\d+,\d+\)' #it seems data has no negative integers or integers starting with 0
    with open("input.txt","r") as f:
        data = f.read()
    matches = re.findall(pattern,data)
    def parse(match):
        match = match[4:-1].split(",")
        return int(match[0])*int(match[1])
    print(sum([parse(x) for x in matches]))

def day3Part2():
    with open("input.txt","r") as f:
        data = f.read()

    #There is definitely at least one don't() in the data and the data doesn't start with don't()
    splitData = data.split("don't()")
    goodData = [splitData[0]]
    for i in range(1,len(splitData)):
        split2Data = splitData[i].split("do()")
        if len(split2Data) == 1:
            continue
        else:
            for j in range(1,len(split2Data)):
                goodData.append(split2Data[j])
    newStr = "".join(goodData)
    pattern = r'mul\(\d+,\d+\)' #it seems data has no negative integers or integers starting with 0
    matches = re.findall(pattern,newStr)
    def parse(match):
        match = match[4:-1].split(",")
        return int(match[0])*int(match[1])
    print(sum([parse(x) for x in matches]))

def day4Part1():
    with open("input.txt","r") as f:
        lines = f.readlines()

    lines = [i.strip() for i in lines]
    Nx = len(lines[0])
    Ny = len(lines)
    def check(x,y):
        count=0
        for i in [-1,0,1]:
            for j in [-1,0,1]:
                words = [lines[y][x]]
                for k in range(1,4):
                    newy = y+k*i
                    newx = x+k*j
                    if newy < 0 or newy >=Ny or newx<0 or newx >= Nx:
                        break
                    words.append(lines[newy][newx])
                if "".join(words) == "XMAS":
                    count+=1
        return count
    print(sum([check(x,y) for x in range(Nx) for y in range(Ny)]))

def day4Part2():
    with open("input.txt","r") as f:
        lines = f.readlines()

    lines = [i.strip() for i in lines]
    Nx = len(lines[0])
    Ny = len(lines)
    def check(x,y):
        if lines[y][x] != 'A':
            return 0
        if x == 0 or x == Nx-1 or y==0 or y == Ny-1:
            return 0
        if lines[y+1][x+1] not in ['M','S'] or lines[y-1][x-1] not in ['M','S'] or lines[y-1][x-1] == lines[y+1][x+1]:
            return 0
        if lines[y-1][x+1] not in ['M','S'] or lines[y+1][x-1] not in ['M','S'] or lines[y-1][x+1] == lines[y+1][x-1]:
            return 0
        return 1
    print(sum([check(x,y) for x in range(Nx) for y in range(Ny)]))

def day5Part1():
    with open("input.txt","r") as f:
        data = f.read()
    parts = data.split("\n\n")
    first = parts[0].split("\n")
    myMap = {}
    for i in first:
        num1,num2 = i.split("|")
        if int(num1) in myMap:
            myMap[int(num1)].add(int(num2))
        else:
            myMap[int(num1)] = {int(num2)}

    second = parts[1].split("\n")[:-1]
    result = 0
    for i in second:
        mylist = list(map(int,i.strip().split(",")))
        seen = set()
        valid = True
        for k in mylist:
            if not seen.isdisjoint(myMap[k]):
                valid = False
                break
            seen.add(k)
        if valid:
            result += mylist[len(mylist)//2]
    print(result)

def day5Part2():
    # Idea: loop through the numbers and simply swap if two are in wrong order
    with open("input.txt","r") as f:
        data = f.read()
    parts = data.split("\n\n")
    first = parts[0].split("\n")
    myMap = {}
    for i in first:
        num1,num2 = i.split("|")
        if int(num1) in myMap:
            myMap[int(num1)].add(int(num2))
        else:
            myMap[int(num1)] = {int(num2)}


    def fix(update):
        seen = set()
        seenNumOnly = set()
        i=0
        while i<len(update):
            x = update[i]
            if seenNumOnly.isdisjoint(myMap[x]):
                seen.add((i,x))
                seenNumOnly.add(x)
            else:
                #find what in set is problematic
                for k in seen:
                    if k[1] in myMap[x]:
                        update[k[0]], update[i] = x, k[1]
                        seen = set()
                        seenNumOnly = set()
                        i=-1
                        break
            i+=1
        return update[len(update)//2]

    second = parts[1].split("\n")[:-1]
    result = 0
    for i in second:
        mylist = list(map(int,i.strip().split(",")))
        seen = set()
        valid = True
        for k in mylist:
            if not seen.isdisjoint(myMap[k]):
                valid = False
                break
            seen.add(k)
        if valid:
            pass
        else:
            result += fix(mylist)

    print(result)

def day6Part1():
    with open("input.txt","r") as f:
        data = f.readlines()
    data = [i.strip() for i in data]
    Nx = len(data[0])
    Ny = len(data)
    pos = np.array([-1,-1])
    direction = np.array([-1,0])

    visited = np.zeros((Ny,Nx))
    for i in range(Ny):
        for j in range(Nx):
            if data[i][j] == "^":
                pos = np.array([i,j])
                visited[i][j] = 1

    def valid(pos):
        if pos[0] < 0 or pos[0] >= Ny or pos[1] < 0 or pos[1] >= Nx:
            return False
        return True

    while True:
        pos += direction
        if not valid(pos):
            break
        while data[pos[0]][pos[1]] == "#":
            pos -= direction
            direction[1], direction[0] = -direction[0],direction[1]
            pos += direction
            if not valid(pos):
                break
        if not valid(pos):
            break
        visited[pos[0],pos[1]] = 1
    print(np.sum(visited))

def day6Part2():
    #Idea: check if the pair position, direction appears twice during the simulation (implying a loop)
    with open("input.txt", "r") as f:
        data = f.readlines()
    data = [list(i.strip()) for i in data]
    Nx = len(data[0])
    Ny = len(data)
    startingPos = np.array([-1, -1])
    startingDirection = np.array([-1, 0])


    for i in range(Ny):
        for j in range(Nx):
            if data[i][j] == "^":
                startingPos = np.array([i, j])

    def valid(pos):
        if pos[0] < 0 or pos[0] >= Ny or pos[1] < 0 or pos[1] >= Nx:
            return False
        return True


    def simulate(data):

        pos = np.array(startingPos)
        direction = np.array(startingDirection)
        visited = {tuple(pos.tolist()+direction.tolist())}

        while True:
            pos += direction
            if not valid(pos):
                break
            while data[pos[0]][pos[1]] == "#":
                pos -= direction
                direction[1], direction[0] = -direction[0], direction[1]
                pos += direction
                if not valid(pos):
                    break
            if not valid(pos):
                break
            if tuple(pos.tolist()+direction.tolist()) in visited:
                return True
            visited.add(tuple(pos.tolist()+direction.tolist()))
        return False


    answer = 0
    for i in range(Ny):
        for j in range(Nx):
            if data[i][j] in ["#","^"]:
                continue
            else:
                data[i][j] = "#"
                if simulate(data):
                    answer+=1
                data[i][j] = "."
    print(answer)

def day7Part1():
    # Idea - brute force
    with open("input.txt","r") as f:
        lines = f.readlines()
    answer = 0
    for line in lines:
        target, nums = line.split(":")
        target = int(target.strip())
        nums = list(map(int,nums.strip().split()))
        available = {nums[0]}
        for num in nums[1:]:
            newAvailable = set()
            for j in available:
                newAvailable.add(num*j)
                newAvailable.add(num+j)
            available = newAvailable
        if target in available:
            answer+=target
    print(answer)

def day7Part2():
    with open("input.txt","r") as f:
        lines = f.readlines()
    answer = 0
    for line in lines:
        target, nums = line.split(":")
        target = int(target.strip())
        nums = list(map(int,nums.strip().split()))
        available = {nums[0]}
        for num in nums[1:]:
            newAvailable = set()
            for j in available:
                newAvailable.add(num*j)
                newAvailable.add(num+j)
                newAvailable.add(int(str(j)+str(num)))
            available = newAvailable
        if target in available:
            answer+=target
    print(answer)

def day8Part1():
    # Idea: Maintain a set of all antinodes and add them as needed
    with open("input.txt","r") as f:
        data = f.readlines()
    data = [list(i.strip()) for i in data]
    Ny = len(data)
    Nx = len(data[0])
    antennas = {}
    for i in range(Ny):
        for j in range(Nx):
            if data[i][j] != ".":
                if data[i][j] in antennas:
                    antennas[data[i][j]].append(np.array([i,j]))
                else:
                    antennas[data[i][j]] = [np.array([i,j])]

    uniques = set()
    for v in antennas.values():
        n = len(v)
        for i in range(n):
            for j in range(i+1,n):
                cand1 = v[i] + v[i]-v[j]
                cand2 = v[j] + v[j]-v[i]
                for cand in [cand1,cand2]:
                    if cand[0] < 0 or cand[0] >= Ny or cand[1] < 0 or cand[1] >= Nx:
                        continue
                    uniques.add((cand[0],cand[1]))
    print(len(uniques))

def day8Part2():
    with open("input.txt","r") as f:
        data = f.readlines()
    data = [list(i.strip()) for i in data]
    Ny = len(data)
    Nx = len(data[0])
    antennas = {}
    for i in range(Ny):
        for j in range(Nx):
            if data[i][j] != ".":
                if data[i][j] in antennas:
                    antennas[data[i][j]].append(np.array([i,j]))
                else:
                    antennas[data[i][j]] = [np.array([i,j])]

    uniques = set()
    for v in antennas.values():
        n = len(v)
        for i in range(n):
            for j in range(i+1,n):
                for y in range(Ny):
                    for x in range(Nx):
                        pos = np.array([y,x])
                        vec1 = pos-v[i]
                        vec2 = pos-v[j]
                        if vec1[0]*vec2[1] == vec1[1]*vec2[0]:
                            uniques.add((y,x))
    print(len(uniques))

def day9Part1():
    with open("input.txt") as f:
        data = f.read().strip()
    augdata = []
    for i in range(len(data)):
        if i%2 == 0:
            for j in range(int(data[i])):
                augdata.append(i//2)
        else:
            for j in range(int(data[i])):
                augdata.append(-1)

    n = len(augdata)
    l=0
    r= n-1
    while l<r:
        while r>=0 and augdata[r] == -1:
            r -= 1
        while l<n and augdata[l] != -1:
            l += 1
        if r<l:
            break
        augdata[r],augdata[l] = augdata[l],augdata[r]

    answer= sum([i*j for i,j in enumerate(augdata) if j != -1])
    print(answer)

def day9Part2():
    with open("input.txt") as f:
        data = f.read().strip()
    augdata = []
    for i in range(len(data)):
        if i%2 == 0:
            if int(data[i]) > 0:
                augdata.append([i//2,int(data[i])])
        else:
            if int(data[i]) > 0:
                augdata.append([-1,int(data[i])])

    n = len(augdata)
    r= n-1
    while r>=0:
        while r>=0 and augdata[r][0] == -1:
            r -= 1
        if r<0:
            break
        fileSize = augdata[r][1]
        #find earliest empty spot
        for i in range(n):
            if i>=r:
                break
            if augdata[i][0] == -1 and augdata[i][1] >= fileSize:
                augdata[i][0] = augdata[r][0]
                if augdata[i][1] > fileSize:
                    augdata.insert(i+1,[-1,augdata[i][1]-fileSize])
                    n+=1
                    r+=1
                augdata[i][1] = fileSize
                augdata[r][0] = -1
                break
        r-=1
    answer=0
    counter=0
    for i in range(len(augdata)):
        if augdata[i][0] == -1:
            counter += augdata[i][1]
            continue
        else:
            for j in range(augdata[i][1]):
                answer += counter*augdata[i][0]
                counter+=1

    print(answer)

def day10Part1():
    # Idea: Count all the possibilities with depth-first-search
    with open("input.txt") as f:
        data = f.readlines()
        data = [list(map(int,list(i.strip()))) for i in data]
    Ny = len(data)
    Nx = len(data[0])

    visited = np.zeros((Ny,Nx))

    def countTrails(i,j,num):
        if num == 9:
            if visited[i][j]:
                return 0
            else:
                visited[i][j]=1
                return 1
        answer = 0
        if i>0 and data[i-1][j] == num+1:
            answer += countTrails(i-1,j,num+1)
        if i<Ny-1 and data[i+1][j] == num+1:
            answer += countTrails(i+1,j,num+1)
        if j>0 and data[i][j-1] == num+1:
            answer += countTrails(i,j-1,num+1)
        if j<Nx-1 and data[i][j+1] == num+1:
            answer += countTrails(i,j+1,num+1)
        return answer

    answer=0
    for i in range(Ny):
        for j in range(Nx):
            if data[i][j] == 0:
                answer += countTrails(i,j,0)
                visited = np.zeros((Ny,Nx))
    print(answer)

def day10Part2():
    with open("input.txt") as f:
        data = f.readlines()
        data = [list(map(int,list(i.strip()))) for i in data]
    Ny = len(data)
    Nx = len(data[0])


    def countTrails(i,j,num):
        if num == 9:
            return 1
        answer = 0
        if i>0 and data[i-1][j] == num+1:
            answer += countTrails(i-1,j,num+1)
        if i<Ny-1 and data[i+1][j] == num+1:
            answer += countTrails(i+1,j,num+1)
        if j>0 and data[i][j-1] == num+1:
            answer += countTrails(i,j-1,num+1)
        if j<Nx-1 and data[i][j+1] == num+1:
            answer += countTrails(i,j+1,num+1)
        return answer

    answer=0
    for i in range(Ny):
        for j in range(Nx):
            if data[i][j] == 0:
                answer += countTrails(i,j,0)
    print(answer)

def day11Part1():
    with open("input.txt") as f:
        data = f.read()
        stones = data.strip().split()
    for i in range(25):
        afterStep = []
        for s in stones:
            if s=="0":
                afterStep.append("1")
            elif len(s)%2 == 0:
                afterStep.append(str(int(s[:len(s)//2])))
                afterStep.append(str(int(s[len(s)//2:])))
            else:
                afterStep.append(str(int(s)*2024))
        stones = afterStep
    print(len(stones))

def day11Part2():
    # Idea: Same as Part 1 with memoization
    with open("input.txt") as f:
        data = f.read()
        stones = data.strip().split()

    @functools.cache
    def simulate(s,turn):
        if turn==75:
            return 1
        if s == "0":
            return simulate("1",turn+1)
        elif len(s)%2 == 0:
            s1 = simulate(str(int(s[:len(s) // 2])),turn+1)
            s2 = simulate(str(int(s[len(s)//2:])),turn+1)
            return s1+s2
        else:
            return simulate(str(int(s)*2024),turn+1)

    answer=0
    for stone in stones:
        answer += simulate(stone,0)

    print(answer)

def day12Part1():
    with open("input.txt") as f:
        data = f.readlines()
        garden = [list(line.strip()) for line in data]

    Ny = len(garden)
    Nx = len(garden[0])
    visited = [[False for _ in range(Nx)] for _ in range(Ny)]

    def calcGeom(i,j,plot):

        visited[i][j] = True
        perim = 0
        area = 1
        if i==0 or i==Ny-1:
            perim+=1
        if j==0 or j==Nx-1:
            perim+=1

        if i>0:
            if garden[i-1][j] == plot and not visited[i-1][j]:
                perimTemp,areaTemp = calcGeom(i-1,j,plot)
                perim+=perimTemp
                area+=areaTemp
            elif garden[i-1][j] != plot:
                perim+=1

        if i<Ny-1:
            if garden[i+1][j] == plot and not visited[i+1][j]:
                perimTemp, areaTemp = calcGeom(i+1, j, plot)
                perim+=perimTemp
                area+=areaTemp
            elif garden[i+1][j] != plot:
                perim+=1

        if j>0:
            if garden[i][j-1] == plot and not visited[i][j-1]:
                perimTemp,areaTemp = calcGeom(i,j-1,plot)
                perim+=perimTemp
                area+=areaTemp
            elif garden[i][j-1] != plot:
                perim+=1

        if j<Nx-1:
            if garden[i][j+1] == plot and not visited [i][j+1]:
                perimTemp, areaTemp = calcGeom(i, j+1, plot)
                perim+=perimTemp
                area+=areaTemp
            elif garden[i][j+1] != plot:
                perim+=1

        return [perim,area]

    price = 0
    for i in range(Ny):
        for j in range(Nx):
            if not visited[i][j]:
                perim, area = calcGeom(i,j,garden[i][j])
                price += perim*area

    print(price)


def day12Part2():
    # Idea - Count number of sides indirectly by counting vertices (V-E+F=2)
    with open("input.txt") as f:
        data = f.readlines()
        garden = [list(line.strip()) for line in data]

    Ny = len(garden)
    Nx = len(garden[0])
    visited = [[False for _ in range(Nx)] for _ in range(Ny)]

    def calcGeom(i,j,plot):

        visited[i][j] = True
        corners=0
        area = 1
        if (i==0 and (j==0 or j==Nx-1)) or (i==Ny-1 and (j==0 or j==Nx-1)):
            corners+=1

        if i>0:
            if garden[i-1][j] == plot and not visited[i-1][j]:
                cornersTemp,areaTemp = calcGeom(i-1,j,plot)
                corners += cornersTemp
                area+=areaTemp

        if i<Ny-1:
            if garden[i+1][j] == plot and not visited[i+1][j]:
                cornersTemp, areaTemp = calcGeom(i+1, j, plot)
                corners += cornersTemp
                area+=areaTemp

        if j>0:
            if garden[i][j-1] == plot and not visited[i][j-1]:
                cornersTemp,areaTemp = calcGeom(i,j-1,plot)
                corners += cornersTemp
                area+=areaTemp

        if j<Nx-1:
            if garden[i][j+1] == plot and not visited [i][j+1]:
                cornersTemp, areaTemp = calcGeom(i, j+1, plot)
                corners+=cornersTemp
                area+=areaTemp


        if i==0 or i==Ny-1:
            if j>0 and garden[i][j-1] != plot:
                corners+=1
            if j<Nx-1 and garden[i][j+1] != plot:
                corners+=1

        if j==0 or j==Nx-1:
            if i>0 and garden[i-1][j] != plot:
                corners+=1
            if i<Ny-1 and garden[i+1][j] != plot:
                corners+=1

        #Have to take care also of double counting (corner happening, for example at i=j=0)
        #But it doesn't happen in the input.txt so nvm

        if i>0:
            if garden[i-1][j] == plot:
                if j>0 and garden[i][j-1] == plot and garden[i-1][j-1] != plot:
                    corners+=1
                if j<Nx-1 and garden[i][j+1] == plot and garden[i-1][j+1] != plot:
                    corners+=1
            elif garden[i-1][j] != plot:
                if j>0 and garden[i][j-1] != plot:
                    corners+=1
                if j<Nx-1 and garden[i][j+1] != plot:
                    corners+=1

        if i<Ny-1:
            if garden[i+1][j] == plot:
                if j>0 and garden[i][j-1] == plot and garden[i+1][j-1] != plot:
                    corners+=1
                if j<Nx-1 and garden[i][j+1] == plot and garden[i+1][j+1] != plot:
                    corners+=1
            elif garden[i+1][j] != plot:
                if j>0 and garden[i][j-1] != plot:
                    corners+=1
                if j<Nx-1 and garden[i][j+1] != plot:
                    corners+=1

        return [corners,area]

    price = 0
    for i in range(Ny):
        for j in range(Nx):
            if not visited[i][j]:
                sides, area = calcGeom(i,j,garden[i][j])
                price += (sides)*area
                print(i,j,price)

    print(price)


def day13Part1():
    # Idea: Loop over the number of times you have to press Button A. Number of times for B are then determined.
    buttonsA = []
    buttonsB = []
    prizes = []

    with open("input.txt") as f:
        data = f.readlines()
        buttonsA = data[::4]
        buttonsB = data[1::4]
        prizes = data[2::4]

    for i in range(len(buttonsA)):
        button = buttonsA[i].split("+")
        buttonsA[i] = [int(button[1].split(",")[0]),int(button[2])]
        button = buttonsB[i].split("+")
        buttonsB[i] = [int(button[1].split(",")[0]),int(button[2])]
        button = prizes[i].split("=")
        prizes[i] = [int(button[1].split(",")[0]),int(button[2])]


    def calculateLowestCost(buttonA,buttonB,prize):
        minimumCost = 1000000000

        for pressA in range(101):
            x = pressA*buttonA[0]
            if x>prize[0]:
                continue
            if (prize[0]-x) % buttonB[0] != 0:
                continue
            pressB = (prize[0]-x) // buttonB[0]
            if pressB > 100:
                continue
            if prize[1] == buttonA[1]*pressA + buttonB[1]*pressB:
                minimumCost = min(minimumCost,3*pressA+pressB)

        if minimumCost == 1000000000:
            return 0
        else:
            return minimumCost

    cost = 0
    for i in range(len(buttonsA)):
        cost += calculateLowestCost(buttonsA[i],buttonsB[i],prizes[i])

    print(cost)

def day13Part2():
    # Idea: Just solve the two equations and check if the solution (rounded to int) works

    buttonsA = []
    buttonsB = []
    prizes = []

    with open("input.txt") as f:
        data = f.readlines()
        buttonsA = data[::4]
        buttonsB = data[1::4]
        prizes = data[2::4]

    addition = 10000000000000
    for i in range(len(buttonsA)):
        button = buttonsA[i].split("+")
        buttonsA[i] = [int(button[1].split(",")[0]),int(button[2])]
        button = buttonsB[i].split("+")
        buttonsB[i] = [int(button[1].split(",")[0]),int(button[2])]
        button = prizes[i].split("=")
        prizes[i] = [int(button[1].split(",")[0])+addition,int(button[2])+addition]


    def calculateLowestCost(buttonA,buttonB,prize):

        determinant = buttonA[0]*buttonB[1] - buttonB[0]*buttonA[1]

        if determinant == 0:
            return 0

        pressA = (buttonB[1]*prize[0] - buttonB[0]*prize[1])//determinant
        pressB = (-buttonA[1]*prize[0] + buttonA[0] * prize[1]) // determinant

        if (pressA*buttonA[0]+pressB*buttonB[0] == prize[0]) and (pressA*buttonA[1]+pressB*buttonB[1] == prize[1]):
            return 3*pressA + pressB
        else:
            return 0

    cost = 0
    for i in range(len(buttonsA)):
        cost += calculateLowestCost(buttonsA[i],buttonsB[i],prizes[i])

    print(cost)

def day14Part1():

    positions = []
    velocities = []

    with open("input.txt") as f:
        data = f.readlines()
    for line in data:
        split = line[2:].split(" ")
        pos = split[0]
        v = split[1][2:]
        positions.append(list(map(int,pos.split(","))))
        velocities.append(list(map(int,v.split(","))))
    height = 103
    width = 101

    def simulate(pos,v):

        newX = (pos[0] + 100*v[0]) % width
        newY = (pos[1] + 100*v[1]) % height

        if newX == 50 or newY == 51:
            return np.zeros(4)
        if newX > 50 and newY < 51:
            return np.array([1,0,0,0])
        if newX < 50 and newY < 51:
            return np.array([0,1,0,0])
        if newX > 50 and newY > 51:
            return np.array([0,0,0,1])
        if newX < 50 and newY > 51:
            return np.array([0,0,1,0])

    quadrants = np.zeros(4)
    for pos,v in zip(positions,velocities):
        quadrants += simulate(pos,v)

    print(quadrants[0]*quadrants[1]*quadrants[2]*quadrants[3])

def day14Part2():
    # Idea: Idk just trying, turned out it makes sense to wait until the robots aren't in the same place
    positions = []
    velocities = []

    with open("input.txt") as f:
        data = f.readlines()
    for line in data:
        split = line[2:].split(" ")
        pos = split[0]
        v = split[1][2:]
        positions.append(list(map(int,pos.split(","))))
        velocities.append(list(map(int,v.split(","))))
    height = 103
    width = 101

    image = np.zeros((height,width))

    def populate(image):
        for pos in positions:
            image[pos[1]][pos[0]] = 1


    def simulate(pos,v):

        newX = (pos[0] + v[0]) % width
        newY = (pos[1] + v[1]) % height
        return [newX,newY]



    for i in range(100000):

        image = np.zeros((height,width))
        populate(image)

        if np.sum(image) == 500:
            plt.imshow(image)
            plt.savefig(f"{i}.png")
        for j in range(len(positions)):
            positions[j] = simulate(positions[j],velocities[j])

def day15Part1():
    # Idea: Just simulate, where the movement of the boxes can be done recursively
    with open("input.txt","r") as f:
        data = f.read()
    theMap, moves = data.split("\n\n")
    theMap = theMap.split("\n")
    theMap = [list(i) for i in theMap]

    Ny = len(theMap)
    Nx = len(theMap[0])

    moves = moves.replace("\n","")

    moveDict = {"<":[-1,0],">":[1,0],"v":[0,1],"^":[0,-1]}

    def makeMove(posX,posY,move,char,theMap):

        moveX, moveY = moveDict[move]

        newX = posX + moveX
        newY = posY + moveY
        if theMap[newY][newX] == "#":
            return [False,posX,posY]
        elif theMap[newY][newX] == ".":
            theMap[posY][posX] = "."
            theMap[newY][newX] = char
            return [True,newX,newY]
        elif theMap[newY][newX] == "O":
            if makeMove(newX,newY,move,"O",theMap)[0]:
                theMap[posY][posX] = "."
                theMap[newY][newX] = char
                return [True,newX,newY]
            else:
                return [False,posX,posY]

    posX = posY = -1
    for i in range(Ny):
        for j in range(Nx):
            if theMap[i][j] == "@":
                posY = i
                posX = j
                break

    def printMap():
        map2 = ["".join(i) for i in theMap]
        print("\n".join(map2))

    for move in moves:
        _,posX,posY = makeMove(posX,posY,move,"@",theMap)

    gps = 0
    for i in range(Ny):
        for j in range(Nx):
            if theMap[i][j] == "O":
                gps += 100*i + j
    print(gps)

def day15Part2():
    with open("input.txt","r") as f:
        data = f.read()
    theMap, moves = data.split("\n\n")
    theMap = theMap.split("\n")
    theMap = [list(i) for i in theMap]

    Ny = len(theMap)
    Nx = len(theMap[0])

    newMap = []
    for i in range(Ny):
        row = ""
        for j in theMap[i]:
            if j=="#":
                row += "##"
            elif j=="O":
                row +="[]"
            elif j==".":
                row += ".."
            elif j=="@":
                row+="@."
        newMap.append(list(row))

    theMap = newMap
    Ny = len(theMap)
    Nx = len(theMap[0])

    def printMap():
        map2 = ["".join(i) for i in theMap]
        print("\n".join(map2))

    moves = moves.replace("\n","")

    moveDict = {"<":[-1,0],">":[1,0],"v":[0,1],"^":[0,-1]}

    def makeMove(posX,posY,move,char,theMap, justCheck=False):

        moveX, moveY = moveDict[move]

        newX = posX + moveX
        newY = posY + moveY

        newChar = theMap[newY][newX]

        problematic = ["[","]"]

        if newChar in problematic and move in ["v","^"]:
            if newChar == "[":
                twinChar = "]"
                twinX = newX+1
            else:
                twinChar = "["
                twinX = newX-1

            movementPossible = True
            if theMap[newY][newX] == "#" or theMap[newY][twinX] == "#":
                return [False,posX,posY]
            elif theMap[newY][newX] in problematic or theMap[newY][twinX] in problematic:
                if makeMove(newX,newY,move,theMap[newY][newX],theMap,True)[0] == False:
                    movementPossible = False
                if makeMove(twinX, newY, move, theMap[newY][twinX], theMap, True)[0] == False:
                    movementPossible = False
                if movementPossible == False:
                    return [False,posX,posY]
                else:
                    if justCheck:
                        return [True, posX, posY]
                    else:
                        makeMove(newX,newY,move,theMap[newY][newX],theMap)
                        makeMove(twinX,newY,move,theMap[newY][twinX],theMap)
                        theMap[posY][posX] = "."
                        theMap[newY][newX] = char
                        #theMap[posY][twinX] = "."
                        #theMap[newY][twinX] = twinChar
                        return [True,newX,newY]

            else:
                if justCheck:
                    return [True,posX,posY]
                else:
                    theMap[posY][posX] = "."
                    theMap[newY][newX] = char
                    theMap[posY][twinX] = "."
                    theMap[newY][twinX] = twinChar
                    return [True,newX,newY]


        else:
            if newChar == "#":
                return [False,posX,posY]
            elif newChar == ".":
                if justCheck:
                    return [True, posX, posY]
                else:
                    theMap[posY][posX] = "."
                    theMap[newY][newX] = char
                    return [True,newX,newY]

            elif newChar in problematic and move in ["<",">"]:
                if makeMove(newX,newY,move,newChar,theMap)[0]:
                    theMap[posY][posX] = "."
                    theMap[newY][newX] = char
                    return [True,newX,newY]
                else:
                    return [False,posX,posY]


    posX = posY = -1
    for i in range(Ny):
        for j in range(Nx):
            if theMap[i][j] == "@":
                posY = i
                posX = j
                break

    #printMap()
    for move in moves:
        _,posX,posY = makeMove(posX,posY,move,"@",theMap)
        #print(move)
        #printMap()

    gps = 0
    for i in range(Ny):
        for j in range(Nx):
            if theMap[i][j] == "[":
                gps += 100*i + j
    print(gps)

sys.setrecursionlimit(3000)
def day16Part1():
    # Idea: Make 4 nodes for each node (4 directions) and connect them with costs, run Dijkstra
    with open("input.txt","r") as f:
        data = f.read().split("\n")

    #G = nx.Graph()
    G = nx.DiGraph()
    Ny = len(data)
    Nx = len(data[0])
    visited = np.zeros((Ny,Nx))

    for i in range(Ny):
        for j in range(Nx):
            if data[i][j] != "#":
                G.add_node((i,j,0)) #<
                G.add_node((i,j,1)) #>
                G.add_node((i,j,2)) #^
                G.add_node((i,j,3)) #v

    print("made graph")

    directions = {0 : [0,-1], 1 : [0,1], 2 : [-1,0], 3: [1,0]}
    oppositeDir = {0 : 1, 1: 0, 2 : 3, 3 : 2}
    turn1K = {0 : [2,3], 1 : [2,3], 2 : [0,1], 3: [0,1]} #1k cost turns from a given dir
    def dfs(i,j):
        visited[i][j] = 1
        for dir in range(4):
            vector = directions[dir]
            neighbourI = i+vector[0]
            neighbourJ = j+vector[1]
            if visited[neighbourI][neighbourJ] or data[neighbourI][neighbourJ] == "#":
                continue
            for start in range(4):
                #turning cost
                if dir == start:
                    cost = 0
                elif dir in turn1K[start]:
                    cost = 1000
                else:
                    cost = 2000
                for end in range(4):
                    if dir == end:
                        newCost = cost+1
                    elif end in turn1K[dir]:
                        newCost = cost+1001
                    else:
                        newCost = cost+2001
                    G.add_edge((i,j,start),(neighbourI,neighbourJ,end),weight=newCost)

            dir = oppositeDir[dir]
            for start in range(4):
                #turning cost
                if dir == start:
                    cost = 0
                elif dir in turn1K[start]:
                    cost = 1000
                else:
                    cost = 2000
                for end in range(4):
                    if dir == end:
                        newCost = cost+1
                    elif end in turn1K[dir]:
                        newCost = cost+1001
                    else:
                        newCost = cost+2001
                    G.add_edge((neighbourI,neighbourJ,start),(i,j,end),weight=newCost)


        for dir in range(4):
            vector = directions[dir]
            neighbourI = i+vector[0]
            neighbourJ = j+vector[1]
            if visited[neighbourI][neighbourJ] or data[neighbourI][neighbourJ] == "#":
                continue
            dfs(neighbourI,neighbourJ)


    #populate with edges
    dfs(Ny-2,1)
    print("finished dfs")
    start = (Ny-2,1,1)
    minimum = 2000000000
    for i in range(4):
        target = (1,Nx-2,i)
        try:
            dist = nx.single_source_dijkstra(G, start, target, weight='weight')[0]
        except:
            continue
        minimum = min(minimum,dist)
    print(minimum)

def day16Part2():
    # Idea: Run dijkstra from starting and ending node. A middle node is on a best path if
    # the distance from start + distance from end equals optimal distance
    with open("input.txt","r") as f:
        data = f.read().split("\n")

    #G = nx.Graph()
    G = nx.DiGraph()
    Ny = len(data)
    Nx = len(data[0])
    visited = np.zeros((Ny,Nx))

    for i in range(Ny):
        for j in range(Nx):
            if data[i][j] != "#":
                G.add_node((i,j,0)) #<
                G.add_node((i,j,1)) #>
                G.add_node((i,j,2)) #^
                G.add_node((i,j,3)) #v

    print("made graph")

    directions = {0 : [0,-1], 1 : [0,1], 2 : [-1,0], 3: [1,0]}
    oppositeDir = {0 : 1, 1: 0, 2 : 3, 3 : 2}
    turn1K = {0 : [2,3], 1 : [2,3], 2 : [0,1], 3: [0,1]} #1k cost turns from a given dir
    def dfs(i,j):
        visited[i][j] = 1
        for dir in range(4):
            vector = directions[dir]
            neighbourI = i+vector[0]
            neighbourJ = j+vector[1]
            if visited[neighbourI][neighbourJ] or data[neighbourI][neighbourJ] == "#":
                continue
            for start in range(4):
                #turning cost
                if dir == start:
                    cost = 0
                elif dir in turn1K[start]:
                    cost = 1000
                else:
                    cost = 2000
                for end in range(4):
                    if dir == end:
                        newCost = cost+1
                    elif end in turn1K[dir]:
                        newCost = cost+1001
                    else:
                        newCost = cost+2001
                    G.add_edge((i,j,start),(neighbourI,neighbourJ,end),weight=newCost)

            dir = oppositeDir[dir]
            for start in range(4):
                #turning cost
                if dir == start:
                    cost = 0
                elif dir in turn1K[start]:
                    cost = 1000
                else:
                    cost = 2000
                for end in range(4):
                    if dir == end:
                        newCost = cost+1
                    elif end in turn1K[dir]:
                        newCost = cost+1001
                    else:
                        newCost = cost+2001
                    G.add_edge((neighbourI,neighbourJ,start),(i,j,end),weight=newCost)


        for dir in range(4):
            vector = directions[dir]
            neighbourI = i+vector[0]
            neighbourJ = j+vector[1]
            if visited[neighbourI][neighbourJ] or data[neighbourI][neighbourJ] == "#":
                continue
            dfs(neighbourI,neighbourJ)

    start = (Ny-2,1,1)

    #populate with edges
    dfs(Ny-2,1)
    fromStart = nx.single_source_dijkstra_path_length(G,start,weight="weight")
    fromEndLeft = nx.single_source_dijkstra_path_length(G,(1,Nx-2,0),weight="weight")
    fromEndDown = nx.single_source_dijkstra_path_length(G,(1,Nx-2,3), weight="weight")

    distance = 98484 #part 1 answer, could also recalc here
    counter = 2
    for i in range(Ny):
        for j in range(Nx):
            if i==Ny-2 and j == 1 or i==1 and j==Nx-2:
                continue
            #check distance for path that passes through i,j
            for k in range(4): #orientations of intermediate node
                if (i,j,k) in fromStart:
                    dist1 = fromStart[(i,j,k)]
                else:
                    continue
                oppK = oppositeDir[k]
                dist2 = 2000000000
                if (i,j,oppK) in fromEndLeft:
                    dist2 = fromEndLeft[(i,j,oppK)]
                if (i,j,oppK) in fromEndDown:
                    dist2 = min(dist2,fromEndDown[(i,j,oppK)])
                if dist1+dist2 == distance:
                    counter+=1
                    break
    print(counter)

def day17Part1():
    with open("input.txt","r") as f:
        data = f.readlines()
        A = int(data[0].split(":")[1])
        B = int(data[1].split(":")[1])
        C = int(data[2].split(":")[1])
        program = data[4].split(":")[1]
        program = program.strip().split(",")
        program = list(map(int,program))

    print(A)
    print(B)
    print(C)
    print(program)
    n = len(program)
    pointer = 0
    output = []
    while pointer<n:
        instruct = program[pointer]
        value = program[pointer+1]
        literalValue = value
        if value==4:
            value=A
        elif value==5:
            value=B
        elif value==6:
            value = C
        if instruct == 0:
            A = A // (2**value)
        elif instruct == 1:
            B = B ^ literalValue
        elif instruct == 2:
            B = value % 8
        elif instruct == 3:
            if A!=0:
                pointer = literalValue
                continue
        elif instruct == 4:
            B = B ^ C
        elif instruct == 5:
            output.append(str(value % 8))
        elif instruct == 6:
            B = A // (2 ** value)
        elif instruct == 7:
            C = A // (2 ** value)
        pointer+=2

    print(",".join(output))

def day17Part2():
    # Idea: Inspecting the algorithm, only the last 3 bits are ever printed and only the last 9 bits
    # are relevant at the time. Brute force those 9 for each number.
    with open("input.txt","r") as f:
        data = f.readlines()
        program = data[4].split(":")[1]
        program = program.strip().split(",")
        program = list(map(int,program))



    program = program[::-1]
    suffixes = [(i,i) for i in range(2**9+1)]
    for number in program:
        newSuffixes = []
        for suffix in suffixes:
            for newTriple in range(8):
                candidateA = (suffix[0] << 3) | newTriple
                B0 = newTriple ^ 3
                C = (candidateA >> B0) % 8
                result = B0 ^ 5 ^ C
                if result != number:
                    continue
                else:
                    newSuffixes.append((candidateA % 2**9,(suffix[1] << 3) | newTriple))
        suffixes = newSuffixes[:]

    lowestNum = 1e100
    for (suff,cand) in newSuffixes:
        lowestNum = min(lowestNum,cand)
    print(lowestNum)

from queue import Queue

def day18Part1():
    # Idea: Breadth-first-search to find distance to end
    with open("input.txt","r") as f:
        data = f.readlines()
    grid = np.zeros((71,71))
    visited = np.zeros((71,71))
    distances = np.ones((71,71))*(-1)
    for line in data[:1024]:
        i,j = list(map(int,line.split(",")))
        grid[i][j] = 1

    queue = Queue()
    queue.put((0,0))
    distances[0][0] = 0
    visited[0][0] = 1
    while not queue.empty():
        i, j = queue.get()


        if i>0 and not visited[i-1][j] and grid[i-1][j] == 0:
            distances[i-1][j] = distances[i][j]+1
            queue.put((i-1,j))
            visited[i-1][j] = 1
        if i<70 and not visited[i+1][j] and grid[i+1][j] == 0:
            distances[i+1][j] = distances[i][j]+1
            queue.put((i+1,j))
            visited[i+1][j] = 1
        if j>0 and not visited[i][j-1] and grid[i][j-1] == 0:
            distances[i][j-1] = distances[i][j]+1
            queue.put((i,j-1))
            visited[i][j-1] = 1
        if j<70 and not visited[i][j+1] and grid[i][j+1] == 0:
            distances[i][j+1] = distances[i][j]+1
            queue.put((i,j+1))
            visited[i][j+1]=1
    print(distances[70][70])

def day18Part2():
    # Idea, again with BFS check if end is reachable. We know at step 1024 it is, at maximum it is not.
    # There is some point x, such that it is reachable for steps <x and not for those over. Find x with binary search.
    with open("input.txt","r") as f:
        data = f.readlines()


    def reachable(x):
        #is the end reachable after x iterations, if yes return x-th byte coorinate else (-1,-1)

        grid = np.zeros((71,71))
        visited = np.zeros((71,71))
        lastI = -1
        lastJ = -1
        for line in data[:x]:
            i,j = list(map(int,line.split(",")))
            grid[i][j] = 1
            lastI=i
            lastJ=j

        queue = Queue()
        queue.put((0,0))
        visited[0][0] = 1
        while not queue.empty():
            i, j = queue.get()

            if i>0 and not visited[i-1][j] and grid[i-1][j] == 0:
                queue.put((i-1,j))
                visited[i-1][j] = 1
            if i<70 and not visited[i+1][j] and grid[i+1][j] == 0:
                queue.put((i+1,j))
                visited[i+1][j] = 1
            if j>0 and not visited[i][j-1] and grid[i][j-1] == 0:
                queue.put((i,j-1))
                visited[i][j-1] = 1
            if j<70 and not visited[i][j+1] and grid[i][j+1] == 0:
                queue.put((i,j+1))
                visited[i][j+1]=1
        if visited[70][70]:
            return (lastI,lastJ)
        else:
            return (-1,-1)

    l = 1024
    r = len(data)
    while l<=r:
        mid = (l+r)//2
        if reachable(mid) == (-1,-1):
            r = mid-1
        else:
            l = mid+1
    print(mid, reachable(mid), data[mid-1])
    print(mid-1, reachable(mid-1), data[mid-2])
    print(mid+1, reachable(mid+1), data[mid])

def day19Part1():
    with open("input.txt","r") as f:
        data = f.readlines()
    patterns = data[0].strip().split(",")
    patterns = [i.strip() for i in patterns]
    N = max([len(i) for i in patterns])
    patterns = set(patterns)

    @functools.cache
    def possible(design):
        if design == "" or design in patterns:
            return True

        localN = min(len(design),N)
        for i in range(localN-1,0,-1):
            if design[:i] in patterns and possible(design[i:]):
                return True
        return False

    counter = 0
    for line in data[2:]:
        design = line.strip()
        if possible(design):
            counter+=1

    print(counter)

def day19Part2():
    with open("input.txt","r") as f:
        data = f.readlines()
    patterns = data[0].strip().split(",")
    patterns = [i.strip() for i in patterns]
    N = max([len(i) for i in patterns])
    patterns = set(patterns)

    @functools.cache
    def possible(design):
        if design == "":
            return 1

        ways=0

        localN = min(len(design),N)
        for i in range(localN,0,-1):
            if design[:i] in patterns:
                ways += possible(design[i:])
        return ways

    counter = 0
    for line in data[2:]:
        design = line.strip()
        counter += possible(design)
    print(counter)


def day20Part1():
    # Idea: BFS to get distances to start and end node from anywhere. Cheating can be quickly calculated with those.
    with open("input.txt","r") as f:
        data = f.readlines()
    data = [list(i.strip()) for i in data]
    Ny = len(data)
    Nx = len(data[0])
    start = -1
    end = -1
    for i in range(Ny):
        for j in range(Nx):
            if data[i][j] == "S":
                start = (i,j)
            if data[i][j] == "E":
                end = (i,j)

    visited = np.zeros((Ny,Nx))
    distances = np.ones((Ny,Nx))*1000000000

    queue = Queue()
    queue.put(end)
    distances[end[0]][end[1]] = 0
    visited[end[0]][end[1]] = 1
    while not queue.empty():
        i, j = queue.get()
        if not visited[i-1][j] and data[i-1][j] != "#":
            distances[i-1][j] = distances[i][j]+1
            queue.put((i-1,j))
            visited[i-1][j] = 1
        if not visited[i+1][j] and data[i+1][j] != "#":
            distances[i+1][j] = distances[i][j]+1
            queue.put((i+1,j))
            visited[i+1][j] = 1
        if not visited[i][j-1] and data[i][j-1] != "#":
            distances[i][j-1] = distances[i][j]+1
            queue.put((i,j-1))
            visited[i][j-1] = 1
        if not visited[i][j+1] and data[i][j+1] != "#":
            distances[i][j+1] = distances[i][j]+1
            queue.put((i,j+1))
            visited[i][j+1] = 1


    visited = np.zeros((Ny,Nx))
    distancesStart = np.ones((Ny,Nx))*1000000000
    queue = Queue()
    queue.put(start)
    distancesStart[start[0]][start[1]] = 0
    visited[start[0]][start[1]] = 1
    while not queue.empty():
        i, j = queue.get()
        if not visited[i-1][j] and data[i-1][j] != "#":
            distancesStart[i-1][j] = distancesStart[i][j]+1
            queue.put((i-1,j))
            visited[i-1][j] = 1
        if not visited[i+1][j] and data[i+1][j] != "#":
            distancesStart[i+1][j] = distancesStart[i][j]+1
            queue.put((i+1,j))
            visited[i+1][j] = 1
        if not visited[i][j-1] and data[i][j-1] != "#":
            distancesStart[i][j-1] = distancesStart[i][j]+1
            queue.put((i,j-1))
            visited[i][j-1] = 1
        if not visited[i][j+1] and data[i][j+1] != "#":
            distancesStart[i][j+1] = distancesStart[i][j]+1
            queue.put((i,j+1))
            visited[i][j+1] = 1

    distanceToBeat = distancesStart[end[0]][end[1]]-100
    distanceToBeat2 = distances[start[0]][start[1]]-100
    counter = 0
    for i in range(Ny):
        for j in range(Nx):
            originalDistance = distancesStart[i][j]
            for direction in [(-2,0),(2,0),(0,-2),(0,2),(1,1),(1,-1),(-1,1),(-1,-1)]:
                newPos = (i+direction[0],j+direction[1])
                if newPos[0] < 0 or newPos[0] >= Ny or newPos[1] < 0 or newPos[1] >= Nx:
                    continue
                if originalDistance + 2 + distances[newPos[0]][newPos[1]] <= distanceToBeat:
                    counter+=1
    print(counter)

def day20Part2():
    with open("input.txt","r") as f:
        data = f.readlines()
    data = [list(i.strip()) for i in data]
    Ny = len(data)
    Nx = len(data[0])
    start = -1
    end = -1
    for i in range(Ny):
        for j in range(Nx):
            if data[i][j] == "S":
                start = (i,j)
            if data[i][j] == "E":
                end = (i,j)

    visited = np.zeros((Ny,Nx))
    distances = np.ones((Ny,Nx))*1000000000

    queue = Queue()
    queue.put(end)
    distances[end[0]][end[1]] = 0
    visited[end[0]][end[1]] = 1
    while not queue.empty():
        i, j = queue.get()
        if not visited[i-1][j] and data[i-1][j] != "#":
            distances[i-1][j] = distances[i][j]+1
            queue.put((i-1,j))
            visited[i-1][j] = 1
        if not visited[i+1][j] and data[i+1][j] != "#":
            distances[i+1][j] = distances[i][j]+1
            queue.put((i+1,j))
            visited[i+1][j] = 1
        if not visited[i][j-1] and data[i][j-1] != "#":
            distances[i][j-1] = distances[i][j]+1
            queue.put((i,j-1))
            visited[i][j-1] = 1
        if not visited[i][j+1] and data[i][j+1] != "#":
            distances[i][j+1] = distances[i][j]+1
            queue.put((i,j+1))
            visited[i][j+1] = 1


    visited = np.zeros((Ny,Nx))
    distancesStart = np.ones((Ny,Nx))*1000000000
    queue = Queue()
    queue.put(start)
    distancesStart[start[0]][start[1]] = 0
    visited[start[0]][start[1]] = 1
    while not queue.empty():
        i, j = queue.get()
        if not visited[i-1][j] and data[i-1][j] != "#":
            distancesStart[i-1][j] = distancesStart[i][j]+1
            queue.put((i-1,j))
            visited[i-1][j] = 1
        if not visited[i+1][j] and data[i+1][j] != "#":
            distancesStart[i+1][j] = distancesStart[i][j]+1
            queue.put((i+1,j))
            visited[i+1][j] = 1
        if not visited[i][j-1] and data[i][j-1] != "#":
            distancesStart[i][j-1] = distancesStart[i][j]+1
            queue.put((i,j-1))
            visited[i][j-1] = 1
        if not visited[i][j+1] and data[i][j+1] != "#":
            distancesStart[i][j+1] = distancesStart[i][j]+1
            queue.put((i,j+1))
            visited[i][j+1] = 1

    distanceToBeat = distancesStart[end[0]][end[1]]-100
    counter = 0
    for i in range(Ny):
        for j in range(Nx):
            originalDistance = distancesStart[i][j]
            for directionX in range(-20,21):
                for directionY in range(-20,21):
                    time = abs(directionX) + abs(directionY)
                    if time > 20:
                        continue
                    newPos = (i+directionX,j+directionY)
                    if newPos[0] < 0 or newPos[0] >= Ny or newPos[1] < 0 or newPos[1] >= Nx:
                        continue
                    if originalDistance + time + distances[newPos[0]][newPos[1]] <= distanceToBeat:
                        counter+=1
    print(counter)

def day21Part1():
    # Brute force, move in straight lines as much as possible, check all paths return the fastest.

    with open("input.txt","r") as f:
        data = f.readlines()
        data = [i.strip() for i in data]

    codeKeypad = [["7","8","9"],["4","5","6"],["1","2","3"],["-1","0","A"]]
    directionalKeypad = [["-1","^","A"],["<","v",">"]]


    @functools.cache
    def possibilities(keypadFlag,endNumber,start):

        if keypadFlag == "code":
            keypad = codeKeypad
        elif keypadFlag == "dir":
            keypad = directionalKeypad

        Ny = len(keypad)
        Nx = len(keypad[0])
        possible = [(i,j) for i in range(Ny) for j in range(Nx)]
        for position in possible:
            if keypad[position[0]][position[1]] == endNumber:
                movementUp = position[0]-start[0]
                movementRight = position[1]-start[1]
                endingNode = (position[0],position[1])
                break
        if movementRight >= 0:
            horizontal = ">"
        elif movementRight < 0:
            horizontal = "<"
        if movementUp >= 0:
            vertical = "v"
        elif movementUp < 0:
            vertical = "^"

        totalMovesH = abs(movementRight)
        totalMovesV = abs(movementUp)
        totalMoves = totalMovesH + totalMovesV


        def sgn(x):
            if x > 0:
                return 1
            elif x<0:
                return -1
            return 0

        allMoves = []

        def findPath(node,path, movesH,movesV):
            i,j = node
            if movesH + movesV == totalMoves:
                allMoves.append(path+"A")
            if keypad[i][j] == "-1":
                return

            if movesH < totalMovesH:
                findPath([i,j+sgn(movementRight)],path+horizontal,movesH+1,movesV)
            if movesV < totalMovesV:
                findPath([i+sgn(movementUp),j],path+vertical,movesH,movesV+1)

        findPath(start, "",0,0)
        return (allMoves,endingNode)


    @functools.cache
    def typeCode(keypadFlag,code):
        # For a given keypad, return all strings that write code from start

        if keypadFlag == "code":
            start = (3,2)
        elif keypadFlag == "dir":
            start = (0,2)

        oldStrings = [""]
        for number in code:
            newStrings = []
            possibleStrings, start = possibilities(keypadFlag,number,start)
            for old in oldStrings:
                for new in possibleStrings:
                    newStrings.append(old+new)
            oldStrings = newStrings
        return oldStrings

    finalResult = 0

    for code in data:
        result = typeCode("code",code)
        newResult = []
        for i in result:
             newResult = newResult + typeCode("dir",i)

        newNewResult = []
        for i in newResult:
            newNewResult = newNewResult + typeCode("dir",i)
        finalResult += min([len(i) for i in newNewResult]) * int(code[:-1])

    print(finalResult)


def day21Part2(strategy):
    # For a given strategy (which tells us how to move) simulate the problem. There aren't many strategies so pick the
    # value that corresponds to the best strategy after.

    with open("input.txt","r") as f:
        data = f.readlines()
        data = [i.strip() for i in data]

    codeKeypad = [["7","8","9"],["4","5","6"],["1","2","3"],["-1","0","A"]]
    directionalKeypad = [["-1","^","A"],["<","v",">"]]


    @functools.cache
    def moveDirPad(target,start,strategy,k):
        #total number of moves to move from start to target (and click it), with a given strategy if we are on k-th robot.

        if k==26: #human using this
            return (start,1)

        keypad = directionalKeypad


        numberMoves = 0
        Ny = len(keypad)
        Nx = len(keypad[0])
        possible = [(i,j) for i in range(Ny) for j in range(Nx)]
        for position in possible:
            if keypad[position[0]][position[1]] == target:
                movementUp = position[0]-start[0]
                movementRight = position[1]-start[1]
                endingNode = (position[0],position[1])
                break

        if movementRight >= 0:
            horizontal = ">"
        elif movementRight < 0:
            horizontal = "<"
        if movementUp >= 0:
            vertical = "v"
        elif movementUp < 0:
            vertical = "^"


        totalMovesH = abs(movementRight)
        totalMovesV = abs(movementUp)

        def firstHthenV():
            numberMoves = 0
            start = (0,2)
            for i in range(totalMovesH):
                start, moves = moveDirPad(horizontal,start,strategy,k+1)
                numberMoves += moves
            for i in range(totalMovesV):
                start, moves = moveDirPad(vertical,start,strategy,k+1)
                numberMoves += moves

            start, moves = moveDirPad("A",start,strategy,k+1)
            numberMoves += moves
            return numberMoves

        def firstVthenH():
            numberMoves = 0
            start = (0, 2)
            for i in range(totalMovesV):
                start, moves = moveDirPad(vertical, start, strategy, k+1)
                numberMoves += moves
            for i in range(totalMovesH):
                start, moves = moveDirPad(horizontal, start, strategy, k+1)
                numberMoves += moves

            start, moves = moveDirPad("A", start, strategy, k+1)
            numberMoves += moves
            return numberMoves


        if start == (1,0) and endingNode[0] == 0:
            numberMoves += firstHthenV()
        elif start[0] == 0 and endingNode == (1,0):
            numberMoves += firstVthenH()


        elif movementUp >= 0 and movementRight >= 0:
            if strategy[0]:
                numberMoves += firstHthenV()
            else:
                numberMoves += firstVthenH()

        elif movementUp >=0 and movementRight < 0:
            if strategy[1]:
                numberMoves += firstHthenV()
            else:
                numberMoves += firstVthenH()

        elif movementUp <0 and movementRight >= 0:
            if strategy[2]:
                numberMoves += firstHthenV()
            else:
                numberMoves += firstVthenH()

        elif movementUp <0 and movementRight < 0:
            if strategy[3]:
                numberMoves += firstHthenV()
            else:
                numberMoves += firstVthenH()


        return (endingNode,numberMoves)


    @functools.cache
    def moveCodePad(endNumber,start, strategy):

        keypad = codeKeypad
        numberMoves=0

        Ny = len(keypad)
        Nx = len(keypad[0])
        possible = [(i,j) for i in range(Ny) for j in range(Nx)]
        for position in possible:
            if keypad[position[0]][position[1]] == endNumber:
                movementUp = position[0]-start[0]
                movementRight = position[1]-start[1]
                endingNode = (position[0],position[1])
                break

        if movementRight >= 0:
            horizontal = ">"
        elif movementRight < 0:
            horizontal = "<"
        if movementUp >= 0:
            vertical = "v"
        elif movementUp < 0:
            vertical = "^"


        totalMovesH = abs(movementRight)
        totalMovesV = abs(movementUp)

        def firstHthenV():
            numberMoves = 0
            start = (0,2)
            for i in range(totalMovesH):
                start, moves = moveDirPad(horizontal,start,strategy,1)
                numberMoves += moves
            for i in range(totalMovesV):
                start, moves = moveDirPad(vertical,start,strategy,1)
                numberMoves += moves

            start, moves = moveDirPad("A",start,strategy,1)
            numberMoves += moves
            return numberMoves

        def firstVthenH():
            numberMoves = 0
            start = (0, 2)
            for i in range(totalMovesV):
                start, moves = moveDirPad(vertical, start, strategy, 1)
                numberMoves += moves
            for i in range(totalMovesH):
                start, moves = moveDirPad(horizontal, start, strategy, 1)
                numberMoves += moves

            start, moves = moveDirPad("A", start, strategy, 1)
            numberMoves += moves
            return numberMoves

        if start[1] == 0 and endingNode[0] == 3: #going from left col to bottom row
            numberMoves += firstHthenV()

        elif start[0] == 3 and endingNode[1] == 0: #opposite
            numberMoves += firstVthenH()

        elif movementUp >= 0 and movementRight >= 0:
            if strategy[0]:
                numberMoves += firstHthenV()
            else:
                numberMoves += firstVthenH()

        elif movementUp >=0 and movementRight < 0:
            if strategy[1]:
                numberMoves += firstHthenV()
            else:
                numberMoves += firstVthenH()

        elif movementUp <0 and movementRight >= 0:
            if strategy[2]:
                numberMoves += firstHthenV()
            else:
                numberMoves += firstVthenH()

        elif movementUp <0 and movementRight < 0:
            if strategy[3]:
                numberMoves += firstHthenV()
            else:
                numberMoves += firstVthenH()

        return (endingNode,numberMoves)


    @functools.cache
    def typeCode(code, strategy):

        start = (3,2)
        solution = 0
        for number in code:
            start, numberMoves = moveCodePad(number,start,strategy)
            solution += numberMoves
        return solution

    finalResult = 0
    for code in data:
        result = typeCode(code,strategy)
        finalResult += result * int(code[:-1])

    return finalResult

"""
results = []
for i in range(2):
    for j in range(2):
        for k in range(2):
            for l in range(2):
                results.append(day21Part2((i,j,k,l)))
print(min(results))
"""




def day22Part1():
    with open("input.txt","r") as f:
        data = f.readlines()
        data = [int(i) for i in data]

    prune = 16777216
    for steps in range(2000):
        for i,d in enumerate(data):
            secret = ((d*64)^d) % prune
            secret = ((secret // 32) ^ secret) % prune
            secret = ((2048*secret)^secret) % prune
            data[i] = secret
    print(sum(data))

def day22Part2():
    # Store all the 4-tuples of changes that appear (the optimal answer must be one of  those), then pick the best one
    # make use of dicts/sets for efficiency

    with open("input.txt","r") as f:
        with open("input.txt", "r") as f:
            data = f.readlines()
            data = [int(i) for i in data]

        prune = 16777216
        secretNumbers = [[i] for i in data]

        for steps in range(2000):
            for i, d in enumerate(data):
                secret = ((d * 64) ^ d) % prune
                secret = ((secret // 32) ^ secret) % prune
                secret = ((2048 * secret) ^ secret) % prune
                data[i] = secret
                secretNumbers[i].append(secret)

        # secretNumbers =  numMonkeys x 2000 list of secret numbers
        values = [[i%10 for i in monkey] for monkey in secretNumbers]
        changes = [[monkey[i]-monkey[i-1] for i in range(1,len(monkey))] for monkey in values]

        possibilities = {} #key possible change 4-tuples, value: list of bananas from each monkex

        for monkeyNum, mChanges in enumerate(changes):
            seenChanges = set()
            for i in range(3,len(mChanges)):
                change = (mChanges[i-3],mChanges[i-2],mChanges[i-1],mChanges[i])
                if change in seenChanges:
                    continue
                seenChanges.add(change)
                if change not in possibilities:
                    possibilities[change] = [values[monkeyNum][i+1]]
                else:
                    possibilities[change].append(values[monkeyNum][i+1])

        maksimum = 0
        for k,v in possibilities.items():
            maksimum = max(maksimum,sum(v))
        print(maksimum)


def day23Part1():
    # Brute force check all triangles

    nodes = set()
    adjList = {}
    with open("input.txt","r") as f:
        for line in f.readlines():
            u,v = line.strip().split("-")
            nodes.add(u)
            nodes.add(v)
            if u in adjList:
                adjList[u].add(v)
            else:
                adjList[u] = {v}
            if v in adjList:
                adjList[v].add(u)
            else:
                adjList[v] = {u}

    triangles = set()
    for vertex1 in nodes:
        for vertex2 in adjList[vertex1]:
            for vertex3 in adjList[vertex1]:
                if vertex3 == vertex2:
                    continue
                if vertex3 in adjList[vertex2]:
                    sortedVertices = sorted([vertex1,vertex2,vertex3])
                    triangles.add((sortedVertices[0],sortedVertices[1],sortedVertices[2]))

    number = 0
    for tri in triangles:
        for v in tri:
            if v[0] == "t":
                number+=1
                break

    print(number)


def day23Part2():
    # This exercise is a max clique problem so just use one of the known libraries for that
    
    G = nx.Graph()
    numNodes = 0
    nodes = set()
    with open("input.txt","r") as f:
        for line in f.readlines():
            u,v = line.strip().split("-")
            if u not in nodes:
                nodes.add(u)
                G.add_node(u)
            if v not in nodes:
                nodes.add(v)
                G.add_node(v)
            G.add_edge(u,v)


    cliques = [(len(i),i) for i in list(nx.find_cliques(G))]
    clique = max(cliques, key=lambda x : x[0])[1]
    clique.sort()
    print(",".join(clique))

def day24Part1():

    variables = {}
    gates = {}

    G = nx.DiGraph()

    with open("input.txt","r") as f:
        for line in f.readlines():
            data = line.strip().split(" ")
            if len(data) == 2:
                variables[data[0][:-1]] = int(data[1])
            elif len(data) == 5:
                gates[data[-1]] = (data[0],data[1],data[2])
                G.add_edge(data[0],data[-1])
                G.add_edge(data[2],data[-1])

    topSort = list(nx.topological_sort(G))
    for vertex in topSort:
        if vertex not in gates:
            continue
        value = gates[vertex]
        if value[1] == "AND":
            variables[vertex] = variables[value[0]] & variables[value[2]]
        if value[1] == "OR":
            variables[vertex] = variables[value[0]] | variables[value[2]]
        if value[1] == "XOR":
            variables[vertex] = variables[value[0]] ^ variables[value[2]]

    result = 0
    for k,v in variables.items():
        if k[0] == "z" and v == 1:
            result += 2**(int(k[1:]))

    print(result)


def day24Part2Part1(x,y, gateChanges=[]):
    #Idea - go in with x=2**i, y=0 and see where it fails to get candidates for wrong gates, brute force all 4 pairs
    # from those candidates. It doesn't work so more visual inspection must be done on the adder... Which I don't like
    # doing so I will skip this.

    variables = {}
    gates = {}

    G = nx.DiGraph()

    with open("input.txt","r") as f:
        for line in f.readlines():
            data = line.strip().split(" ")
            if len(data) == 2:
                variables[data[0][:-1]] = int(data[1])
            elif len(data) == 5:
                gates[data[-1]] = (data[0],data[1],data[2])
                G.add_edge(data[0],data[-1])
                G.add_edge(data[2],data[-1])

    if len(gateChanges) > 0:
        gC = gateChanges
        for i in range(4):
            gates[gC[2*i]],gates[gC[2*i+1]] = gates[gC[2*i+1]],gates[gC[2*i]]
            changesFirstInput = []
            changesSecondInput = []
            for g in gates:
                if gC[2*i] == gates[g][0]:
                    changesFirstInput.append(g)
                elif gC[2*i+1] == gates[g][0]:
                    changesFirstInput.append(g)
                if gC[2*i] == gates[g][2]:
                    changesSecondInput.append(g)
                elif gC[2*i+1] == gates[g][2]:
                    changesSecondInput.append(g)
            for g in changesFirstInput:
                if gC[2*i] == gates[g][0]:
                    gates[g] = (gC[2*i+1],gates[g][1],gates[g][2])
                elif gC[2*i+1] == gates[g][0]:
                    gates[g] = (gC[2*i],gates[g][1],gates[g][2])
            for g in changesSecondInput:
                if gC[2*i] == gates[g][2]:
                    gates[g] = (gates[g][0],gates[g][1],gC[2*i+1])
                elif gC[2*i+1] == gates[g][2]:
                    gates[g] = (gates[g][0],gates[g][1],gC[2*i])






    for var in variables:
        if var[0] == "x":
            bit = int(var[1:])
            if (x >> bit) & 1:
                variables[var] = 1
            else:
                variables[var] = 0
        if var[0] == "y":
            bit = int(var[1:])
            if (y >> bit) & 1:
                variables[var] = 1
            else:
                variables[var] = 0


    topSort = list(nx.topological_sort(G))
    for vertex in topSort:
        if vertex not in gates:
            continue
        value = gates[vertex]
        if value[1] == "AND":
            variables[vertex] = variables[value[0]] & variables[value[2]]
        if value[1] == "OR":
            variables[vertex] = variables[value[0]] | variables[value[2]]
        if value[1] == "XOR":
            variables[vertex] = variables[value[0]] ^ variables[value[2]]

    result = 0
    for k,v in variables.items():
        if k[0] == "z" and v == 1:
            result += 2**(int(k[1:]))

    z = 0
    for var in variables:
        if var[0] == "z":
            bit = int(var[1:])
            if variables[var] == 1:
                z += 2**bit
    return z

"""
for x in range(45):
    if 2**x != day24Part2Part1(2**x,0):
        print(x)
for y in range(45):
    if 2**y != day24Part2Part1(0,2**y):
        print(y)
"""

#Problematic input bits: 5, 10, 15 ,30

def day24Part2Part2():


    variables = {}
    gates = {}

    G = nx.DiGraph()

    with open("input.txt","r") as f:
        for line in f.readlines():
            data = line.strip().split(" ")
            if len(data) == 2:
                variables[data[0][:-1]] = int(data[1])
            elif len(data) == 5:
                gates[data[-1]] = (data[0],data[1],data[2])
                G.add_edge(data[0],data[-1])
                G.add_edge(data[2],data[-1])

    problematic = ["x05","x10","x15","x30","y05","y10","y15","y30"]

    topSort = list(nx.topological_sort(G))
    outEdges = G.out_edges
    problematicGates = set()
    for wire in problematic:
        while True:
            for (s,e) in outEdges:
                if s==wire:
                    problematicGates.add(e)
                    wire=e
                    break
            if wire[0] == "z":
                break
    problematicGates = list(problematicGates)
    counter = 0
    for chooseFrom in itertools.combinations(problematicGates,8):
        allPairs = itertools.combinations(chooseFrom,2)
        for fourPairs in itertools.combinations(allPairs,4):
            gates = set()
            for pair in fourPairs:
                gates.add(pair[0])
                gates.add(pair[1])
            if len(gates) != 8:
                continue
            x = 144312453
            y = 9123414321
            z = x+y
            gateChanges = [fourPairs[0][0],fourPairs[0][1],fourPairs[1][0],fourPairs[1][1],fourPairs[2][0],fourPairs[2][1],fourPairs[3][0],fourPairs[3][1]]
            try:
                counter+=1
                if counter%100==0:
                    print(counter)
                if z == day24Part2Part1(x,y,gateChanges):
                    print(",".join(sorted(gateChanges)))
                    return
            except:
                continue


def day25Part1():
    # Idea: Since there are no duplicates we can easily make finding matches efficient by using sets

    locks = set()
    keys = set()
    with open("input.txt","r") as f:
        input = f.read()
        input = input.split("\n\n")
        for object in input:
            grid = object.split("\n")
            heights = []
            if grid[0][0] == "#":
                for i in range(5):
                    counter=0
                    while grid[counter][i] == "#":
                        counter+=1
                    heights.append(counter-1)
                locks.add(tuple(heights)) #there are no duplicates
            elif grid[0][0] == ".":
                for i in range(5):
                    counter=0
                    while grid[6-counter][i] == "#":
                        counter+=1
                    heights.append(counter-1)
                keys.add(tuple(heights)) #there are no duplicates

    print(len(locks))
    print(len(keys))

    matches = 0
    for lock in list(locks):
        for h1,h2,h3,h4,h5 in itertools.product(range(6-lock[0]),range(6-lock[1]),range(6-lock[2]),range(6-lock[3]),range(6-lock[4])):
            if (h1,h2,h3,h4,h5) in keys:
                matches+=1
    print(matches)

day25Part1()