
import sys
from random import randint 


def buildList(n: int) -> list:
  output = []
  for i in range(n):
    output.append(randint(0, 100))
  return output




def mergeSort(array: list):
  if len(array) > 1:
    q = len(array) // 2 #calculating the midpoint of the subarray
    L = array[:q] #creating a left sub array from 0 -> midpoint
    R = array[q:] #creating a right sub array from midpoint + 1 -> end 

    mergeSort(L) #calling merge sort recursively on left subarray
    mergeSort(R) #calling merge sort recursively on right subarry 

    #merge left and right sub arrays:
    i = j = k = 0 #i = left index, j = right index, k = array index

    #copy data into left and right sub arrays
    while(i < len(L) and j < len(R)):
      if(L[i] < R[j]):
        array[k] = L[i]
        i += 1
      else:
        array[k] = R[j]
        j += 1
      k += 1 #itterate value of k
    #end while
    
    #copy the rest of the values from both r and l subarrays
    #either none or 1 loop will be called
    while(i < len(L)):
      array[k] = L[i]
      i += 1
      k += 1
    
    while(j < len(R)):
      array[k] = R[j]
      j += 1
      k += 1
    


#driver function 
if __name__ == '__main__':
  n = int(sys.argv[1])
  array = buildList(n)
  print(array) #printing array before merge
  mergeSort(array)
  print(array) #printing array after merge