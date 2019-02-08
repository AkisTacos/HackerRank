// Aki Saito
// HackerRank - Easy
// Alternating Characters
// February 8, 2019
// Language: Python 3
// 
/* Description:
	You are given a string containing characters A and B only.
  Your task is to change it into a string such that there are no matching ajdacent characters.
  To do this, you are allowed to delete zero or more characters in the string.
  
  Your task is to find the minimum number of required deletions.
*/

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the alternatingCharacters function below.
def alternatingCharacters(s):
    temp = s[0]
    result = -1
    for letters in s:
        if letters == temp:
            result += 1
        temp = letters
    return result    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s = input()

        result = alternatingCharacters(s)

        fptr.write(str(result) + '\n')

    fptr.close()
