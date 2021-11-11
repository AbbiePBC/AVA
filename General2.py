# 2. Write a function in a language of your choice which, when passed two sorted arrays of integers
# returns an array of any numbers which appear in both. No value should appear in the returned
# array more than once.


def check_matches(short_array, long_array, new_array, idx):
  array_len = len(short_array)
  for i in range(array_len - idx):
    i += idx
    num = short_array[i]
    if num in short_array and num in long_array and num not in new_array:
      new_array.append(num)
      # if space was a constraint, could take in the smaller array and pop values which aren't found in the second array
  return new_array


def common_nums(array1, array2):
  array1_len = len(array1)
  array2_len = len(array2)
  new_array = []
  if array1_len == 0 or array2_len == 0:
    return new_array
  min_len = 0
  idx = 0
  if (array1_len <= array2_len):
    min_len = array1_len
    check_matches(array1, array2, new_array, idx)
    check_matches(array2, array1, new_array, min_len -1)
  else:
    min_len = array2_len
    check_matches(array2, array1, new_array, idx)
    check_matches(array1, array2, new_array, min_len-1)


  print(new_array)
  return new_array


# for testing...

def main():
  common_nums([0,2,3,7,7,7,7,7], [2,4,7]) # expect [2,7]
  common_nums([-1,0,1,1,1,1000000000], [2,3,4,5,6]) # expect empty array, []
  common_nums([0.3,2.1,6], [0,2.1,6.7])
  # assume two arrays are inputted, i.e. not common_nums() with no input


if __name__ == ('__main__'):
  main()