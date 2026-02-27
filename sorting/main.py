import random


def merge(numList: [list], start: int, mid: int, end: int):
    leftArr = numList[start:mid+1]
    rightArr = numList[mid+1:end+1]
    combinedArray = []

    leftArrSize = len(leftArr)
    rightArrSize = len(rightArr)

    leftidx = 0
    rightidx = 0
    while leftidx < leftArrSize and rightidx < rightArrSize:
        if leftArr[leftidx] < rightArr[rightidx]:
            combinedArray.append(rightArr[rightidx])
            rightidx += 1
        else:
            combinedArray.append(leftArr[leftidx])
            leftidx += 1

    for i in range(leftidx, leftArrSize):
        combinedArray.append(leftArr[i])

    for i in range(rightidx, rightArrSize):
        combinedArray.append(rightArr[i])

    # for i in range(min(leftArrSize, rightArrSize)):



def mergeSort(numList: [list], start: int, end: int) -> None:
    # start, end = 0, len(numList) - 1
    mid = (start + end) // 2
    if end < start: return
    mergeSort(numList, start, mid - 1)
    mergeSort(numList, mid, end)
    merge(numList, start, mid, end)


def main() -> None:
    numList = [random.randint(1, 1000000) for _ in range(1000)]
    # numList = []
    # for i in range(1000):
    #     numList.append(random.randint(1, 1000000))

    mergeSort(numList, 0, len(numList) - 1)



if __name__ == '__main__':
    main()
