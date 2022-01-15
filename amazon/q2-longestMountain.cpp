class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int base=0;
        int n=arr.size();
        int ans=0;
        while(base<n){
           
            int end=base;
            if(end+1<n&&arr[end]<arr[end+1]){
                
                while(end+1<n&&arr[end]<arr[end+1])end++;
                
                if(end+1<n&&arr[end]>arr[end+1]){
                    
                   while(end+1<n&&arr[end]>arr[end+1])end++;
                    ans=max(ans,end-base+1);
                    
                }
            }
           base=max(base+1,end); 
        }
        return ans;
    }
};