# 1. The Fibonacci sequence is defined as a sequence of integers starting with 1 and 1, where each
# subsequent value is the sum of the preceding two. I.e.
# f(0) = 1
# f(1) = 1
# f(n) = f(n-1) + f(n-2) where n >= 2
# Write a program in a language of your choice to calculate the sum of the first 100 even-valued
# Fibonacci numbers

# Rather than brute forcing...
#   // f(n) = f(n-1) + f(n-2) where n >= 2
#   // f(n) is even every 3 numbers.
#   // e.g. 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
#   // even f(2), f(5), f(8) etc
#   // f(8) = f(7) + f(6) = 2f(6) + f(5) = 3f(5) + 2f(4) = 4f(5) + f(2)
#   // refactored in terms of even numbers. Should save 2/3 of the work


NUM_EVEN = 100
# if NUM_EVEN < 1, this won't work; could return 0 if so

def main():
  prev1 = 2
  prev2 = 0
  sum = prev1+prev2
  new = 0
  # NUM_EVEN -1 as we have already used the first even val in initialising
  for i in range(NUM_EVEN - 1):
    new = prev1*4 + prev2
    prev2 = prev1
    prev1 = new
    sum += new
  print(sum)
  return sum


if __name__ == ('__main__'):
  main()
