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

    // While it works... It isn't pretty. Let's comment it out.
//    void printAllNodeKeys(TrieNode* rootNode, std::string nodeName = "Root")
//    {
//        TrieNode* currentNode(rootNode);
//        std::cout << nodeName << " Node's Values: \n";
//        for(auto const& child : currentNode->childNodes)
//        {
//            std::cout << child.first << ' ';
//        }
//
//        std::cout << "\n\n";
//
//        for (auto const& child : currentNode->childNodes)
//        {
//            if(child.first != '*')
//            {
//                std::string childValue{child.first};
//                printAllNodeKeys(child.second, childValue);
//            }
//            else
//            {
//
//            }
//        }
//    }

std::string autoCorrect(TrieNode* node, std::string word)
{
    TrieNode* currentNode{node};

    std::string longestPrefix{""};

    for(char const& i : word)
    {
        if (currentNode->childNodes[i])
        {
            longestPrefix += i;
            currentNode = currentNode->childNodes[i];
        }
        else
        {
        }

    }

    std::vector<std::string> words{};

    currentNode = search(longestPrefix);
    collectAllWords(currentNode, words);

    return longestPrefix + words[0];
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

//    void printAllNodeKeys()
//    {
//        printAllNodeKeys(root);
//    }

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

    void autoCorrect(std::string word)
    {
        std::string longestPrefix{""};

        TrieNode* currentNode{search(word)};

        if(!currentNode)
        {
            std::cout << "That word doesn't seem to spelled correctly or it has not been added\n"
                         "to our auto complete program. Let me try to help.\n\n";

            std::cout << "Did you mean to spell : " << autoCorrect(root, word) << "?\n";
        }
        else
        {
            std::cout << word << " seems to be spelled correctly. Or we spelled it wrong.\n";
        };
    }

};


int main() {
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

//    std::cout << "Let's print out all the values in each node.\n";
//
//    words.printAllNodeKeys();
//
//    std::cout << "That worked... but it is a bit confusing... Let's comment it out for now... Including this line.\n\n";


    std::cout << "Let's see if we can get it to auto correct the spelling of a word by getting the longest\n"
              << "possible prefix. We will enter the word \"catnar\" and see if can return \"catnap\"\n";

    words.autoCorrect("catnar");
    return 0;
}