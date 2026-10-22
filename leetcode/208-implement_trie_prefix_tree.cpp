// https://leetcode.com/problems/implement-trie-prefix-tree/

#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct Node {
        Node* children[26] = {};
        bool is_end = false;
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* curr = root;

        for (char c : word) {
            int i = c - 'a';
            if (!curr->children[i]) curr->children[i] = new Node();
            curr = curr->children[i];
        }

        curr->is_end = true;
    }

    bool search(string word) {
        Node* curr = root;

        for (char c : word) {
            int i = c - 'a';
            if (!curr->children[i]) return false;
            curr = curr->children[i];
        }

        return curr->is_end;
    }

    bool startsWith(string prefix) {
        Node* curr = root;

        for (char c : prefix) {
            int i = c - 'a';
            if (!curr->children[i]) return false;
            curr = curr->children[i];
        }

        return true;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
