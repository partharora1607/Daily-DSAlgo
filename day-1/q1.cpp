class Solution {
public:
  string decodeAtIndex(string s, int k) {
    long long decodedLength =
        0; // Use long long to handle large decoded lengths
    int i = 0;

    // Calculate the decoded length without expanding the string
    for (i = 0; i < s.size() && decodedLength < k; i++) {
      if (isdigit(s[i])) {
        int multiplier = s[i] - '0';
        decodedLength *= multiplier;
      } else {
        decodedLength++;
      }
    }

    // Backtrack to find the k-th character in the decoded string
    for (int j = i - 1; j >= 0; j--) {
      if (isdigit(s[j])) {
        int multiplier = s[j] - '0';
        decodedLength /= multiplier;
        k %= decodedLength; // Adjust k based on current multiplier
      } else {
        if (k == 0 || k == decodedLength) {
          return string(1, s[j]);
        }
        decodedLength--;
      }
    }

    return ""; // Should not reach here if input is valid
  }
};
