class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;
        vector<string> suggestions;  // Store suggestions dynamically

        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; ++i)
                children[i] = nullptr;
        }
    };

    // Insert a contact into the Trie
    void insert(TrieNode* root, const string& contact) {
        TrieNode* current = root;
        for (char ch : contact) {
            int index = ch - 'a';
            if (!current->children[index])
                current->children[index] = new TrieNode();
            current = current->children[index];
            current->suggestions.push_back(contact);  // Add contact to suggestions
        }
        current->isEndOfWord = true;
    }

    // Sort the suggestions lexicographically
    void sortTrieSuggestions(TrieNode* root) {
        if (!root) return;
        // Sort the suggestions of the current node
        sort(root->suggestions.begin(), root->suggestions.end());
        // Recursively sort suggestions for all child nodes
        for (int i = 0; i < 26; ++i) {
            sortTrieSuggestions(root->children[i]);
        }
    }

    // Get suggestions for a given prefix
    vector<string> getSuggestions(TrieNode* root, const string& prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (!current->children[index])
                return {"0"};  // If prefix not found, return {"0"}
            current = current->children[index];
        }
        return current->suggestions;  // Return all suggestions stored at the node
    }

    // Display contacts matching each prefix of the query string
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        TrieNode* root = new TrieNode();

        // Insert all contacts into the Trie
        for (int i = 0; i < n; ++i) {
            insert(root, contact[i]);
        }

        // Sort the Trie suggestions lexicographically
        sortTrieSuggestions(root);

        vector<vector<string>> result;
        string prefix = "";
        for (char ch : s) {
            prefix += ch;
            vector<string> suggestions = getSuggestions(root, prefix);
            result.push_back(suggestions);
        }

        return result;
    }
};
