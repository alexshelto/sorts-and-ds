
import random


#node class
#responsible for insertion/deletion 
class Node:
  def __init__(self, value: int):
    self.left = None    #pointer to left child
    self.right = None   #pointer to right child
    self.data = value   #value contained in the node


  #insertion into binary tree
  def insert(self, value):
    #checking for empty tree:
    if self is None:
      self = Node(value)
      return
    
    #recurse down the tree
    if value < self.data:
      #left sub tree
      #if theres a left node value already, recursively call with left child as root
      if self.left:
        self.left.insert(value)
      else:
        self.left = Node(value)
        return
    #else we are checking the right subtree
    else:
      if self.right:
        self.right.insert(value)
      else:
        self.right = Node(value)
        return



#Binary Search Tree class
#responsible for 
class BST:
  def __init__(self, value):
    self.root = Node(value)

  def insert(self, value):
    self.root.insert(value)



""" 
Utility functions for binary search tree

Includes: inorder traversal, check duplicates 

"""

#traversal orders:
def inorderDisplay(root):
  if root is not None:
    inorderDisplay(root.left)
    print(root.data)
    inorderDisplay(root.right)


#main logic for checking duplicate
#checks each nodes value, if nodes value is in the set return true
def checkDuplicateUtil(root, s):
  if root == None: return False 
  if root.data in s:
    return True
  s.add(root.data)
  return checkDuplicateUtil(root.left, s) or checkDuplicateUtil(root.right, s)

#driver function for checking duplicate
#passes a set into the check duplicate function to keep track of new elements
def checkDuplicate(root):
  s = set()
  return checkDuplicateUtil(root, s)


#driver function
if __name__ == '__main__':
  tree = BST(12)

  #filling the tree with random values
  for i in range(8):
    tree.insert(random.randint(0,100))
  
  inorderDisplay(tree.root)
  
  print("Is there a duplicate? " + str(checkDuplicate(tree.root)))