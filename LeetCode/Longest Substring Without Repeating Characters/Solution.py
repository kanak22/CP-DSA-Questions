class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        checklist = {}
        starting_index_of_current_substring = 0
        length_of_longest_substring = 0
        # Loop for each character in the string
        for i, v in enumerate(s):
            # check if char is in checklist
            if v in checklist:
                if checklist[v] >= starting_index_of_current_substring:
                    starting_index_of_current_substring = checklist[v] + 1

            length_of_current_substring = i - starting_index_of_current_substring + 1
            # Getting longest between length_of_current_substring and length_of_longest_substring
            length_of_longest_substring = max(
                length_of_current_substring, length_of_longest_substring)
            checklist[v] = i
        return length_of_longest_substring