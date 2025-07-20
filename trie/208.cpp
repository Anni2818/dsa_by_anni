//this is user friendly application of basics of trie data structure

struct Node
{
    Node* links[26];
    bool flag = false;

    bool hasKey(char c)
    {
        return links[c-'a'] != NULL;
    }

    void put(char c,Node* node)
    {
        links[c-'a'] = node;
    }

    Node* getLink(char c)
    {
        return links[c-'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(char c: word)
        {
            //create a new node for character if not already present
            if(!node->hasKey(c))
            {
                node->put(c,new Node());
            }
            //now move to the next letter or recently set letter
            node = node->getLink(c);
        }
        //set end flag to mark end of the word
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(char c: word)
        {
            //check if there is node for this letter
            if(!node->hasKey(c)) return false;
            //get to the next character
            node = node->getLink(c);
        }
        //return true if current node flag is true
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(char c: prefix)
        {
            //check if there is node for this letter
            if(!node->hasKey(c)) return false;
            //get to the next character
            node = node->getLink(c);
        }
        // no need to check for the end flag to be true..
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