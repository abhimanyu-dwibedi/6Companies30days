  void insert(string& word,Trie *curr,int pos)
    {
        if(pos==word.size())
        {
            curr->count++;
            curr->endofword=true;
            return;
        }
        
        curr->count++;
        if(!curr->child[word[pos]-'a'])
           curr->child[word[pos]-'a']=new Trie();
           
        insert(word,curr->child[word[pos]-'a'],pos+1);   
    }
    
    //search prefix word from dictonary
    pair<bool,Trie*>search(string &pre,Trie*curr,int pos,string &temp)
    {
        if(!curr)return {false,NULL};
        
        if(pre.size()==pos)return {true,curr};
        
        temp+=pre[pos];
        return search(pre,curr->child[pre[pos]-'a'],pos+1,temp);
    }
    
    //insert all the string which match with prefix
    void insertAll(Trie* curr,string &temp,vector<string>&t)
    {
        if(curr->endofword)
        {
            t.push_back(temp);
            for(int i=0;i<26;i++)
            {
                if(curr->child[i])
                {
                    temp+=char(i+97);
                    insertAll(curr->child[i],temp,t);
                    temp.pop_back();
                }
            }
            
            return ;
        }
        
        for(int i=0;i<26;i++)
        {
            if(curr->child[i])
            {
                temp+=char(i+97);
                insertAll(curr->child[i],temp,t);
                temp.pop_back();
            }
        }
    }
    
    //main fxn to return the final answer
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        
        vector<vector<string>>ans;  //to strore final ans
        
        Trie*root=new Trie();
        
        //insert in Trie
        for(int i=0;i<n;i++)
          insert(contact[i],root,0);
          
        string pre="";
        for(int i=0;i<s.length();i++)
        {
            pre+=s[i];
            string temp="";
            
            auto p=search(pre,root,0,temp);
            
            if(p.first)
            {
                vector<string>t;
                insertAll(p.second,temp,t);
                ans.push_back(t);
            }
            else
                ans.push_back({"0"});
            
            
        }
        
        return ans;
    }
};