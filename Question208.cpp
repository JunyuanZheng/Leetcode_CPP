#include <string>
#include <unordered_map>

using namespace std;

class TrieNode {
private:
    bool end = false;
    char c;
    unordered_map<char, TrieNode *> map;

    TrieNode *create(char c) {
        map[c] = new TrieNode(c);
        return search(c);
    }

    TrieNode *search(char c) {
        return map[c];
    }

    TrieNode *getOrCreate(char c) {
        if (search(c))
            return search(c);
        else
            return create(c);
    }

public:
    TrieNode(char c) : c(c) {}

    void insert(string &word, int idx) {
        if (word.size() == idx) {
            this->end = true;
            return;
        }
        TrieNode *node = getOrCreate(word[idx]);
        node->insert(word, idx + 1);
    }

    bool search(string &word, int idx) {
        if (word.size() == idx) {
            return this->end;
        }
        TrieNode *node = search(word[idx]);
        return node ? node->search(word, idx + 1) : false;
    }

    bool prefix(string &word, int idx) {
        if (word.size() == idx) {
            return true;
        }
        TrieNode *node = search(word[idx]);
        return node ? node->prefix(word, idx + 1) : false;
    }
};


class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode(' ');
    }

    void insert(string word) {
        this->root->insert(word, 0);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return this->root->search(word, 0);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return this->root->prefix(prefix, 0);
    }
};