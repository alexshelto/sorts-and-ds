# doubly linked list python implementation
#
#




class Node:
  def __init__(self, key: int):
    self.next = None
    self.prev = None
    self.key = key

class LinkedList:
  def __init__(self):
    self.head = None
    self.tail = None


  def display(self):
    cursor = self.head
    while(cursor is not None):
      print(cursor.key, end=' ')
      cursor = cursor.next
    print('\n')

  def reverse_display(self):
    cursor = self.tail
    while(cursor is not None):
      print(cursor.key, end=' ')
      cursor = cursor.prev
    print('\n')


  def push(self, value: int):
    """ adds new node to the front of the linked list
    reassigns head value to new node """
    new_head = Node(value)
    if self.head is not None:
      new_head.next = self.head
      self.head.prev = new_head
      self.head = new_head
    else:
      self.head = self.tail = new_head

  def append(self, value: int):
    new_tail = Node(value)
    if self.tail is not None:
      new_tail.prev = self.tail
      self.tail.next = new_tail
      self.tail = new_tail

    else:
      self.head = self.tail = new_tail      


  def pop(self):
    """pop removes the first node in the list"""
    #1 element
    if self.head == self.tail:
      head = tail = None

    if self.head is not None:
      self.head = self.head.next #moving head forward
      self.head.prev = None #unlinking prev

  def remove_last(self):
    #1 element
    if self.head == self.tail:
      head = tail = None

    if self.tail is not None:
      self.tail = self.tail.prev #moving tail 1 behind
      self.tail.next = None      #unlinking old tail

  def remove_first_occurence(self, target: int):
    cursor = self.head
    while(cursor.key != target and cursor is not None):
      cursor = cursor.next
    
    if(cursor is None): return
    elif(cursor == self.head): self.pop()
    elif(cursor == self.tail): self.remove_last()
    else:
      cursor.prev.next = cursor.next
      cursor.next.prev = cursor.prev


  def remove_last_occurence(self, target: int):
    cursor = self.tail
    while(cursor.key != data and cursor is not None):
      cursor = cursor.prev
    
    if(cursor is None): return
    elif(cursor == self.tail): self.remove_last()
    elif(cursor == self.head): self.pop()
    else:
      cursor.prev.next = cursor.next
      cursor.next.prev = cursor.prev
    


# Driver function for the list
#
#
if __name__ == '__main__':
  list = LinkedList()
  for i in range(10):
    list.push(i)
    list.append(i)

  print("Doubly linked list")
  list.display()
  
  print("removed first node")
  list.pop()
  list.display()
  
  print("removed last node")
  list.remove_last()
  list.display()

  k = input("enter a number to remove the first occurence: ")
  print('removed the first ' + k + ' from the list')
  list.remove_first_occurence(int(k))
  list.display()


  k = input("enter a number to remove the last occurence: ")
  print('removed the last ' + k + ' from the list')
  list.remove_first_occurence(int(k))
  list.display()


  print("List in reverse:")
  list.reverse_display()
  
  exit(0)