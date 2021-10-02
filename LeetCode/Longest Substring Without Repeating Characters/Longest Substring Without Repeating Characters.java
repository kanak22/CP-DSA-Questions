import java.util.HashSet;
import java.util.Set;

public class LongestSubstringWithoutRepeatingCharacters {

    public static void main(String[] args) {
        // Example 1 - Output: 6
        System.out.println(calculateLongestSubstringWithoutRepeatingCharacters("abdefbasdf"));
        // Example 2 - Output: 2
        System.out.println(calculateLongestSubstringWithoutRepeatingCharacters("aaaahhhh"));
        // Example 3 - Output: 0
        System.out.println(calculateLongestSubstringWithoutRepeatingCharacters(""));
        // Example 4 - Output: 3
        System.out.println(calculateLongestSubstringWithoutRepeatingCharacters("java"));
    }

    /* For this solution we will use the sliding window approach
    Basically we will "slide" through the string, pushing characters into the set until we find a repeated character
    When we find a repeated character we will drop the first element of the set
    Everytime we push a new character, we calculate if the maxLength we have is greater than the size of the set
     */
    public static int calculateLongestSubstringWithoutRepeatingCharacters(String s) {
        if (s.length() == 0) {
            return 0;
        }
        int startIndex = 0, endIndex = 0, maxLength = 0;
        Set<Character> uniqueCharacters = new HashSet<>();
        for (int i = 0; i < s.length(); i++) {
            if (uniqueCharacters.contains(s.charAt(endIndex))) {
                uniqueCharacters.remove(s.charAt(startIndex));
                startIndex++;
            } else {
                uniqueCharacters.add(s.charAt(endIndex));
                endIndex++;
                maxLength = Math.max(maxLength, uniqueCharacters.size());
            }
        }
        return maxLength;
    }
}