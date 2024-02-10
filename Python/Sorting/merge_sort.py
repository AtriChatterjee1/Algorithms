# Function that performs the sorting operation

def merge(arr, lt, mid, rt):
    i, j = lt, mid+1
    b = []
    # Compares the elements of the two arrays and sorts them
    while i<=mid and j<=rt:
        if arr[i]>arr[j]:
            b.append(arr[j])
            j+=1
        else:
            b.append(arr[i])
            i+=1
    # If the 1st array is exhausted, then copies the remaining elements of the 2nd array to the 1st array
    while j<=rt:
        b.append(arr[j])
        j+=1
    
    # If the 2nd array is exhausted, then copies the remaining elements of the 1st array to the 2nd array
    while i<=mid:
        b.append(arr[i])
        i+=1

    # Copies all the elements of the array 'b' to array 'arr'
    for i in range(lt, rt+1):
        arr[i] = b[i-lt]

    return arr

# Function that divides the array into half at each step and sorts them
def mergeSort(arr, lt, rt):
    if lt<rt:
        mid = int(lt + (rt-lt)/2)
        # Sorts the left array
        arr = mergeSort(arr, lt, mid)
        # Sorts the right array
        arr = mergeSort(arr, mid+1, rt)
        # Merges the left and the right array
        arr = merge(arr, lt, mid, rt)
    return arr

# Total number of elements in vector
n = int(input())
arr = []
for i in range(n):
    x = int(input())
    arr.append(x)

arr = mergeSort(arr, 0, n-1)
print("After sorting:")
for i in arr:
    print(i, end=" ")