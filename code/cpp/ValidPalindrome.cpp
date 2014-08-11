/**
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
**/

class Solution {
public:
    bool isc(char s) {
        if((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9')) {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int length = s.length();
        if(length <= 1) {
            return true;
        }
        int i = 0;
        int j = length - 1;
        while(i < j) {
            while(!isc(s[i]) && i < j) {
                i ++;
            }
            while(!isc(s[j]) && i < j) {
                j --;
            }
            if(i < j) {
                if(s[i] <= 'Z' && s[i] >= 'A') {
                    s[i] = s[i] - 'A' + 'a';
                }
                if(s[j] <= 'Z' && s[j] >= 'A') {
                    s[j] = s[j] - 'A' + 'a';
                }
                if(s[i] != s[j]) {
                    return false;
                }
                i ++;
                j --;
            }
            
        }
        return true;
    }
};