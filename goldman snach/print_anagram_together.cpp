class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
             vector<vector<string>> ans;
 unordered_map <string, vector<string>> mp;
       
 for(int i=0;i<string_list.size();i++) {
   string word = string_list[i];
   sort(word.begin(), word.end());
   mp[word].push_back(string_list[i]);
 }
       
 for(auto i : mp) {
   ans.push_back(i.second);
 }    
 return ans;
    }
};
