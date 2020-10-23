


# S explained
# if match: 1       |  up and left on table
# if peel off x: 2  |  back in x coord
# if go back on y: 3| go back on y coord
#
# m[i][j] = 1: matched last character
# m[i][j] = 2: go back one in x, 
# m[i][j] = 3: go back 1 in y 




def LCS(X,Y, p, q):
  
  
  
  return S

  print(m)
  



if __name__ == '__main__':
  x = ['a', 'b', 'c', 'b', 'd', 'a', 'b']
  y = ['b', 'd', 'c', 'a', 'b', 'a']
  #number of subsequences without repeats; 2^n

  TableOutput = LCS(x,y,len(x), len(y))
  print(TableOutput)
