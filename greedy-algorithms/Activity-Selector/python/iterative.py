import random



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
      if(L[i][1] < R[j][1]):
        array[k] = L[i]
        i += 1
      else:
        array[k] = R[j]
        j += 1
      k += 1 #itterate value of k

    while(i < len(L)):
      array[k] = L[i]
      i += 1
      k += 1
    
    while(j < len(R)):
      array[k] = R[j]
      j += 1
      k += 1
  

#sort: nlogn, function O(n) . therefore nlogn solution
def activity_select_iterative(arr: list) -> list:
  answer = []
  n = len(arr)
  i = 0
  answer.append(arr[0])

  for m in range(2, n):
    if arr[m][1] >= arr[i][2]:
      answer.append(arr[m])
      i = m
  return answer


#driver function
if __name__ == '__main__':
# [[activity #, start time, end time], [] ]  #format of 2d array
  activities = [[1, 1, 3], [2, 2, 2.5], [3, 3, 3.5], [4, 2, 4], [5, 3.5, 5]]
  print(f'Activities before sorting: \n{activities}')

  mergeSort(activities) #sorting by start time
  print(f'\nActivities after sorting: \n{activities}')

  result = activity_select_iterative(activities)
  print(f'\nsolution: {result}')