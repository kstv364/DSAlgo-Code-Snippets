class WordDictionary {

    bool end;
    WordDictionary * children[26];
public:
    /** Initialize your data structure here. */
    WordDictionary() {

        end = false;
        for (int i = 0; i < 26; i++)
            this->children[i] = nullptr;

    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary *root = this;
        int index;
        for (int i = 0; i < word.size(); i++) {
            index = word[i] - 'a';
            if (!root->children[index])
                root->children[index] = new WordDictionary();
            root = root->children[index];
        }
        root->end = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */

    bool searchUtil(WordDictionary * root, string &s, int l) {
        if (!root) return false;


        int index = s[l] - 'a';
        // if this is the last index
        if (l == s.size() - 1) {
            // if this is not wild carad
            if (s[l] != '.')   return root->children[index] and root->children[index]->end;

            //else if this is wild character
            for (int i = 0; i < 26; i++)
                if (root->children[i] and root->children[i]->end) return true;
            return false;
        }


        // if current character is wild character
        if (s[l] == '.') {
            for (int i = 0; i < 26; i++)
                if (root->children[i] and searchUtil(root->children[i], s, l + 1))   return true;
            return false;
        }

        if (root->children[index])   return searchUtil(root->children[index], s, l + 1);
        return false;


    }


    bool search(string word) {
        WordDictionary *root = this;
        return searchUtil(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */