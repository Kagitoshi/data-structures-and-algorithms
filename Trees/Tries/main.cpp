#include <iostream>
#include <map>
//#include <unordered_map> // This is faster but for now I will comment out until code in a way to sort it.
#include <vector>

struct TrieNode
{
    std::map<char, TrieNode*> childNodes{};
};

class Trie
{
private:
    TrieNode* root{new TrieNode};

    TrieNode* search(TrieNode* trieNode, std::string& currentWord)
    {
        TrieNode* currentNode{trieNode};

        for(char i : currentWord)
        {
            if (currentNode->childNodes[i])
            {
                currentNode = currentNode->childNodes[i];
            }
            else
            {
                std::cout << "The word \"" << currentWord << "\" is has not been inserted.\n";
                return nullptr;
            }
        }

        return currentNode;
    }

    void insertion(TrieNode* trieNode, std::string& currentWord)
    {
        TrieNode* currentNode{trieNode};

        for(char i : currentWord)
        {
            if (currentNode->childNodes[i])
            {
                currentNode = currentNode->childNodes[i];
            }
            else
            {
                TrieNode* nodeToAdd{new TrieNode};
                currentNode->childNodes[i] = nodeToAdd;
                currentNode = nodeToAdd;
            }
        }

        currentNode->childNodes['*'] = nullptr;
    }

    std::vector<std::string> collectAllWords(TrieNode* currentNode, std::vector<std::string>& words,
                                             std::string currentWord = "")
    {
        for(auto const& child : currentNode->childNodes)
        {
            if (child.first == '*')
            {
                words.push_back(currentWord);
            }
            else
            {
                collectAllWords(child.second, words, currentWord + child.first);
            }
        }

        return words;
    }


public:
    TrieNode* search(std::string& currentWord)
    {
        return search(root, currentWord);
    }

    void insertion(std::string currentWord)
    {
        insertion(root, currentWord);
    }

    void collectAllWords()
    {
        std::vector<std::string> words{};

        collectAllWords(root, words);

        std::cout << "Start of list of words in the trie:\n";
        for(std::string& word : words)
        {
            std::cout << word << '\n';
        }

        std::cout << "\nEnd of list.\n\n";

    }

    void autoComplete(std::string word)
    {
        std::vector<std::string> words{};

        TrieNode* currentNode{search(word)};

        if(!currentNode)
        {
            std::cout << "No matches found in the trie to autocomplete the word.\n";
            return;
        }
        else
        {
            collectAllWords(currentNode, words);
        };

        std::cout << "Start of list of words to autocomplete the word \"" << word << "\":\n";
        for(std::string& wordFromVector : words)
        {
            std::cout << word + wordFromVector << '\n';
        }

        std::cout << "\nEnd of list.\n\n";

    }
};


int main()
{
    std::cout << "Let's make an auto-completion programing using tries.\n"
              << "Tries use nodes of hashmaps using recursion to insert and retrieve words.\n"
              << "Also, that is were the word trie comes from, the word retrieval.\n"
              << "Unlike a binary tree, tries are trees with nodes that can hold more than two child nodes.\n"
              << "I should note that these tries can be made without using maps also.\n"
              << "Since, we are following the book, we will use an unordered map for now.\n"
              << "Let's start by creating a root node and adding some words into the trie.\n\n";

    Trie words;
    words.insertion("ace");
    words.insertion("act");
    words.insertion("bad");
    words.insertion("bake");
    words.insertion("bat");
    words.insertion("batter");
    words.insertion("cab");
    words.insertion("cat");
    words.insertion("catnap");
    words.insertion("catnip");

    std::cout << "Great. Let's see if we can print the whole trie.\n\n";

    words.collectAllWords();

    std::cout << "Now let's see if it can print out a list of words to help autocomplete the sting \"ca\"\n";

    words.autoComplete("ca");


    return 0;
}
