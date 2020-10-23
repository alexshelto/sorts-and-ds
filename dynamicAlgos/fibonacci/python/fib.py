
import sys




def fib(n: int, solutions: list)-> int:
  if (n == 0): return 0
  elif (n == 1): return 1
  else:
    if(solutions[n] == 0):
      solutions[n] = fib(n-1, solutions) + fib(n-2, solutions)
  
  return solutions[n]




#driver function
#
if __name__ == '__main__':
  n = int(sys.argv[1])
  solutions = [0 for i in range(n+1)] #filling array with 0's

  answer = fib(n, solutions)
  print('The ' + str(n) + 'th fib number: ' + str(answer))