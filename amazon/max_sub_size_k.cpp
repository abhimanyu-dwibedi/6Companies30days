class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        unordered_map<int,int>ump;
        deque<int>dq;
        for(int i = 0;i < k ;i++){
            ump[arr[i]]++;

            while(!dq.empty() and dq.back() <= arr[i]) dq.pop_back();
            dq.push_back(arr[i]);

        }
        vector<int>ans;
        ans.push_back(dq.front());

        for(int i = k ; i < n; i++){
            // erase last
            ump[arr[i - k]]--;

            // add end
            while(!dq.empty() and dq.back() <= arr[i]) dq.pop_back();
            ump[arr[i]]++;
            dq.push_back(arr[i]);

            // calculate max
            while(!dq.empty() and ump[dq.front()] == 0) dq.pop_front();
            ans.push_back(dq.front());
        }
        
        return ans;
    }
};