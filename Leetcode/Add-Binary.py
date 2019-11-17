'''
 Aki Saito
 Add-Binary.py
 Nov. 11, 2019
 LeetCode - Easy #66
'''

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # Get string length of each input and subtract 1 to use in loop
        index_a = len(a) - 1
        index_b = len(b) - 1
        
        result = ""
        carry = 0
        
        # Loop through as long as index is not out of bound
        while (index_a >= 0) or (index_b >= 0):
            # Here we check if we're at the last index, in that case, use 0
            if index_a < 0:
                bit_a = 0
            else:
                bit_a = int(a[index_a])
            # Same check as above
            if index_b < 0:
                bit_b = 0
            else:
                bit_b = int(b[index_b])
                
            # Here we calculate our result for current position
            xor_bit = bit_a ^ bit_b ^ carry
            # Here we check if update carry for possible 1 carry case
            carry = (bit_a & bit_b) | (bit_a & carry) | (bit_b & carry)
            
            # Append our result for current position 
            result = result + str(xor_bit)
            # Update each index
            index_a = index_a - 1
            index_b = index_b - 1
            
        # Check to see if we have a last 
        if carry:
            result = result + str(carry)
        
        # We calculated from the other way so we'll simply reverse result
        reversed_result = ''.join(reversed(result))
        return reversed_result
            