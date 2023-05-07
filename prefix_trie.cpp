#include <iostream>
#include <unordered_map>


using namespace std;

class Node {
public:
    char data;
    bool isTerminal;
    unordered_map<char, Node*> m;

    Node (char data) {
        this->data = data;
        this->isTerminal = false;
    }
};

class Trie {
private:
    Node *root;

public:
    Trie () {
        this->root = new Node('\0');
    }

    void insert(string word) {
        Node *temp = this->root;
        for (char c: word) {
            if (temp->m.find(c) == temp->m.end()) {
                temp->m[c] = new Node(c);
            }
            temp = temp->m[c];
        }
        temp->isTerminal = true;
    };

    bool search(string word) {
        Node *temp = this->root;

        for (char c: word) {
            if (temp->m.find(c) == temp->m.end()) return false;
            temp = temp->m[c];
        }

        return temp->isTerminal;
    };
};

int main(void) {
    string words[] = {"ape", "apple", "rhino", "always", "mango", "banana", "orange", "pineapple"};

    Trie t;
    for (string word: words) t.insert(word); 

    string input;
    do {
        cin >> input;
        cout << (t.search(input) ? "Found" : "Not Found") << endl;
    } while (input != "!");

    return 0;
}