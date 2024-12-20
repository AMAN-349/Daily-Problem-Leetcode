#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class WordDictionary {
public:
    vector<string> v;

    WordDictionary() {
    }

    void addWord(string word) {
        v.push_back(word);
    }

    bool search(string word) {
        for (const string& storedWord : v) {
            if (matches(storedWord, word)) {
                return true;
            }
        }
        return false;
    }

private:
    bool matches(const string& storedWord, const string& word) {
        if (storedWord.length() != word.length()) {
            return false;
        }

        for (int i = 0; i < word.length(); ++i) {
            if (word[i] != '.' && word[i] != storedWord[i]) {
                return false;
            }
        }
        return true;
    }
};

