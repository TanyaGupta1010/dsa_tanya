class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size();
        while(i < j){
            while(i < j && !isvowel(s[i])){
                i++;
            }
            while(i < j && !isvowel(s[j])){
                j--;
            }
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
    bool isvowel(char c){
        c = tolower(c);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }
};