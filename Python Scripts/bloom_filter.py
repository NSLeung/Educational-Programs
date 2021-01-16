import math

def main():
    foundIndex = False
    num_list = [x for x in range (100) if x % 3 == 0]
    arr = [0] * 64
    num_list = num_list[1:]
    print(num_list)
    # index = 0
    # while(foundIndex!=True):
    for index in range(len(num_list)):
        num = num_list[index]
        print("================num " + str(num) + "================")

        index1 = ((num**2) + num - 1) % 64
        index2 = ((num**4) + num - 2) % 64
        index3 =((num**6) + num - 3) % 64
        # print("index1 " + str(index1))
        # print("index2 " + str(index2))
        # print("index3 " + str(index3))
        # index1 = num % 64
        # index2 = ((2**(2*num)) + num - 2) % 64
        # index3 = ((3**(2*num)) + num - 3) % 64
        if(arr[index1] == 0 or arr[index2]== 0 or arr[index3] == 0):
            print("index1 " + str(index1) + "value: " + str(arr[index1]))
            print("index2 " + str(index2) + "value: " + str(arr[index2]))
            print("index3 " + str(index3) + "value: " + str(arr[index3]))
            arr[index1]= 1
            arr[index2]= 1
            arr[index3]= 1
            
        else:
            foundIndex = True
            print("index1 " + str(index1) + "value: " + str(arr[index1]))
            print("index2 " + str(index2) + "value: " + str(arr[index2]))
            print("index3 " + str(index3) + "value: " + str(arr[index3]))

            break
    print(arr)
    print(num)

if __name__ == "__main__":
    main()