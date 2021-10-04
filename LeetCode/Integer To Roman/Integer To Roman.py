class Solution:
    def intToRoman(self, num: int) -> str:
        
        numeral_map = {
            1000: 'M',
            900: 'CM',
            500: 'D',
            400: 'CD',
            100: 'C',
            90: 'XC',
            50: 'L',
            40: 'XL',
            10: 'X',
            9: 'IX',
            5: 'V',
            4: 'IV',
            1: 'I'
        }
        
		# Use integer division to get the number of multiples of the value in the number
        # E.g. 994 // 100 == 9
		# Use modulo to get the remainder of num / value
        # E.g. 994 % 100 == 94
        roman = ""
        for value in numeral_map.keys():
            multiplier = num // value
            if multiplier > 0:
                roman += numeral_map[value] * multiplier  # Add the roman numeral multiplyer times
                num %= value
        
        return roman
