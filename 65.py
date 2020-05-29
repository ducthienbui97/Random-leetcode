# Leetcode 65. Valid Number
class Solution:
    def isNumber(self, s: str) -> bool:
        try:
            float(s.strip())
            return True
        except:
            return False
        
