#
# Min heap implementation
#
#



import random 



#
# Min heap classe and methods
#
class MinHeap:
  def __init__(self):
    self.heap = []

  def parent_index(self, i: int) -> int:
    return (i // 2)

  def left_child_index(self, i: int) -> int:
    return (2 * i) + 1
  
  def right_child_index(self, i: int) -> int:
    return (2 * i) + 2
  
  def size(self) -> int:
    return len(self.heap)

  def heapify_up(self) -> None:
    index = self.size() - 1
    while(self.parent_index(index) >= 0 and self.heap[self.parent_index(index)] > self.heap[index]):
      self.heap[self.parent_index(index)], self.heap[index] = self.heap[index], self.heap[self.parent_index(index)]
      index = self.parent_index(index)


  def insert(self, value: int) -> None:
    """Inserts value into last index, bubbles up"""
    if (self.size() == 0):
      self.heap.append(value)
    else:
      self.heap.append(value)
      self.heapify_up()



  def extract_min(self) -> int:
    """Extracts min from heap(Root) then bubbles up"""
    if(self.size() == 0):
      print("Attempted to extract min from an empty heap")
      exit(1)
    elif (self.size() == 1):
      extracted = self.heap[0]
      self.heap.pop() #removing last element, no need to bubble up
      return extracted
    else:
      extracted = self.heap[0]
      self.heap[0], self.heap[self.size() - 1] = self.heap[self.size() - 1], self.heap[0]
      self.heap.pop() #remove the old min from heap
      self.heapify_down(0) #call heapify down on the root
      return extracted



  def heapify_down(self, index: int) -> None:
    """Makes swaps from root down to leaves if needed to keep heap rules"""
    lChild = self.left_child_index(index)
    rChild = self.right_child_index(index)
    swap_index = index

    if(rChild < self.size() and self.heap[rChild] < self.heap[index]): swap_index = rChild
    if(lChild < self.size() and self.heap[lChild] < self.heap[index]): swap_index = lChild
    
    #swapping with the min node
    if(lChild < self.size() and rChild < self.size()):
      if self.heap[rChild] < self.heap[lChild]: swap_index = rChild
      else: swap_index = lChild
    
    if(self.heap[swap_index] < self.heap[index]):
      # print("left: " + str(self.heap[lChild]) + " right: " + str(self.heap[rChild]) + "swapping " + str(self.heap[index]) + " with " + str(self.heap[swap_index]))
      self.heap[index], self.heap[swap_index] = self.heap[swap_index], self.heap[index]
      self.heapify_down(swap_index)


  def peek(self) -> int:
    """Returns heap root. index 0 without deletion"""
    if(len(self.heap) > 0):
      return self.heap[0]
    else:
      print("attempted to peek an empty heap")
      exit(1)





#
# Driver function
#
if __name__ == '__main__':
  heap = MinHeap()
  mins = [] #stores extracted mins

  #pushing random numbers into the heap
  for i in range(15):
    heap.insert(random.randint(0, 30))

  #displaying heap in array form
  print("Heap: ", end='')
  print(heap.heap)

  #extracting all of the elements into array
  while(heap.size() > 0):
    mins.append(heap.extract_min())
    print(heap.heap)

  #displaying all extracted mins
  print("List of mins extracted: ", end='')
  print(mins)

  exit(0)