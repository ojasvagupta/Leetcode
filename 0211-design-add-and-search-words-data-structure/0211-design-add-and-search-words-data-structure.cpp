class Node{
    public:
    unordered_map<int,Node*> mp;
    bool end;
    Node()
    {
        end=false;
    }
};
class WordDictionary {
public:
Node* root;
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* head=root;
        for(int i=0;i<word.size();i++)
        {
            if(!head->mp.count(word[i]-'a'))
            {
                head->mp[word[i]-'a']=new Node();
            }
            head=head->mp[word[i]-'a'];
        }
        head->end=true;
    }
    
    bool search(string word) {
        Node* head=root;
        bool res=false;
        srch(word,head,0,res);
        return res;

        
    }
    void srch(string word,Node* root,int count,bool& res)
    {
        if(res==true)
        {
            return;
        }
        if(count==word.size() && root->end==true)
        {
            res=true;
            return;
        }
        if(word[count]=='.')
        {
            for(auto a : root->mp)
            {
                srch(word,a.second,count+1,res);
            }
        }
        else
        {
            if(root->mp.count(word[count]-'a'))
            {
                root=root->mp[word[count]-'a'];
                srch(word,root,count+1,res);
                
            }
            else
            {
                res=false;
            }
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */