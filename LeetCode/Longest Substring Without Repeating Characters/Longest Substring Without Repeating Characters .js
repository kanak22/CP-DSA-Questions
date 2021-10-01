var lengthOfLongestSubstring = function (s) {
  let start = 0;
  let end = 0;
  let maxLength = 0;
  const uniqueCharacters = new Set();
  // Loop for each character in the string
  while (end < s.length) {
    // check if char is in checklist
    if (!uniqueCharacters.has(s[end])) {
      uniqueCharacters.add(s[end]);
      end++;
      // Getting longest between maxlength and uniquecharacters
      maxLength = Math.max(maxLength, uniqueCharacters.size);
    } else {
      uniqueCharacters.delete(s[start]);
      start++;
    }
  }
  return maxLength;
};

console.log(lengthOfLongestSubstring("abcabcbb"));
