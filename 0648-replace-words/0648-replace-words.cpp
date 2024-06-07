class Trie{
        public:
        Trie *childern[26];
        bool isEnd;

        Trie(){
            for(int i = 0 ; i < 26 ; i++){
                childern[i] = nullptr;
            }
            isEnd = false;
        }
};


class Solution {
public:
    Trie* root;

    Solution(){
        root = new Trie();
    }

    void insert(string word){
        Trie* node = root;
        for(char c: word){
            int i = c-'a';
            if(node->childern[i] == nullptr){
                node->childern[i] = new Trie();
            }
            node = node->childern[i];
        }
        node->isEnd = true;
    }

    string search(string word){
        Trie* node = root;
        string result;
        for(char c: word){
            int i = c - 'a';
            if(node->childern[i] == nullptr){
                return word;
            }
            result += c;
            if(node->childern[i]->isEnd){
                return result;
            }

            node = node->childern[i];
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        for(auto i : dictionary){
            insert(i);
        }

        stringstream ss(sentence);

        string word,result;
        while(ss >> word){
            if(!result.empty())
            {
                result += " ";
            }
            result += search(word);
        }
        return result;
    }
};