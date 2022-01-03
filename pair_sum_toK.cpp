 bool canPair(vector<int> nums, int k) {
       if(nums.size()%2==1){
           return false;
       }
      unordered_map<int,int>m;
      int n =nums.size();
      int c=0;
    for(int i=0;i<n;i++){
      int l=nums[i]%k;
      int s=k-l;
      if(s==k){
          if(m.find(0)!=m.end() && m[0]>0){
              c++;
              m[0]--;
              m[l]--;
          }
      }
     else if(m.find(s)!=m.end() && m[s]>0){
          c++;
          m[s]--;
          m[l]--;
      }
      m[l]++;
      
    }
    return c==n/2;
   }