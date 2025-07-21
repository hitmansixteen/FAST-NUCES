import sys
import time

def readMatrix(inputFile):
    startTime = time.time()
    with open(inputFile, 'r') as file:
        opcode = int(file.readline())
        dataType = int(file.readline().strip())

        rows, cols = map(int, file.readline().split())
        matrixA = []
        for i in range(rows):
            if dataType == 1:  # 32 bit integers
                matrixA.append(list(map(int, file.readline().split())))
            elif dataType == 2:  # 32 bit floats
                matrixA.append(list(map(float, file.readline().split())))
            elif dataType == 3:  # 64 bit ints
                matrixA.append(list(map(int, file.readline().split())))
            elif dataType == 4:  # 64 bit doubles
                matrixA.append(list(map(float, file.readline().split())))

        file.readline()

        matrixB = []
        for i in range(rows):
            if dataType == 1:  # 32 bit integers
                matrixB.append(list(map(int, file.readline().split())))
            elif dataType == 2:  # 32 bit floats
                matrixB.append(list(map(float, file.readline().split())))
            elif dataType == 3:  # 64 bit ints
                matrixB.append(list(map(int, file.readline().split())))
            elif dataType == 4:  # 64 bit doubles
                matrixB.append(list(map(float, file.readline().split())))

    readTime = time.time() - startTime    
    return readTime, opcode, dataType, matrixA, matrixB

def multiplyMatrix(matrixA, matrixB):
    startTime = time.time()
    result = []
    for i in range(len(matrixA)):
        result.append([])
        for j in range(len(matrixB[0])):
            result[i].append(0)
            for k in range(len(matrixA[0])):
                result[i][j] += matrixA[i][k] * matrixB[k][j]
        print(i)
    calcTime = time.time() - startTime

    return calcTime, result

def writeMatrix(outputFile, result,dataType):
    startTime = time.time()
    with open(outputFile, 'w') as file:
        file.write(f"{dataType}\n")
        file.write(f"{len(result)} {len(result[0])}\n")
        for i in range(len(result)):
            for j in range(len(result[0])):
                file.write(str(result[i][j]) + " ")
            file.write("\n")
    writeTime = time.time() - startTime
    return writeTime

def writeToGraph(opcode, dataType, readTime, calcTime, writeTime):
    with open("graph.txt", 'a') as file:
        file.write(f"{opcode} {dataType} {readTime} {calcTime} {writeTime}\n")


def main(inputFile, outputFile):
    readTime, opcode, dataType, matrixA, matrixB = readMatrix(inputFile)
    print(f"Time taken to read file: {readTime}")
    calcTime, result = multiplyMatrix(matrixA, matrixB)
    print(f"Time taken for Matrix Multiplication: {calcTime}")
    writeTime = writeMatrix(outputFile, result, dataType)
    print(f"Time taken to write file: {writeTime}")

    writeToGraph(opcode, dataType,readTime, calcTime, writeTime)

main(sys.argv[1], sys.argv[2])