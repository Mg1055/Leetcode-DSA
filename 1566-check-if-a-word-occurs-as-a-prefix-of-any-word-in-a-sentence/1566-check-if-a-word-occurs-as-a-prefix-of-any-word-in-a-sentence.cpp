class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream ss(sentence);
        int count=0;
        string word;
        while(ss >> word){
           count++;
            if(word.substr(0,searchWord.size()) == searchWord)
                return count;
        }
        return -1;
    }
};