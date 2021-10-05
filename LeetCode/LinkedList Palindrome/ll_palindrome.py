class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        curr = head

        # This is the key to O(1) space.
        stringified_list = ""

        while (curr):
            stringified_list += str(curr.val)
            curr = curr.next

        # Compares string with reversed string to see if they are the same string
        return stringified_list == stringified_list[::-1]