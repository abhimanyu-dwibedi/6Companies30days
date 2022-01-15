class Solution {
  public:	
  
	void quicksort(char nuts[], char bolts[], int l, int r) {
	    if(l >= r) return;
	    int c = partition(nuts, bolts, l, r);
	    quicksort(nuts, bolts, l, c - 1);
	    quicksort(nuts, bolts, c + 1, r);
	}
	
	int partition(char nuts[], char bolts[], int l, int r) {
	    int s = l, idx;
	    for(int i = l; i <= r; i++) {
	        if(bolts[i] < nuts[l]) swap(bolts[s++], bolts[i]);
	        if(bolts[i] == nuts[l]) idx = i;
	    }
	    swap(bolts[s], bolts[idx]);
    	for(int i = l; i <= r; i++) {
            nuts[i] = bolts[i];
	    }
	    return s;
	}
	
    // All solutions under the assumption that both the arrays have same set of characters
	void matchPairs(char nuts[], char bolts[], int n) {
	    
	   // Brute force
	   // TC: O(N^2), SC: O(1)
	    string order = "!#$%&*@^~";
	    int l = 0;
	    for(char ch: order) {
	        for(int r = l; r < n; r++) {
	            if(ch == bolts[r]) {
	                swap(bolts[l++], bolts[r]);
	                break;
	            }
	        }
	    }
	    for(int i = 0; i < n; i++) {
	        nuts[i] = bolts[i];
	    }
	   
	   // Hashmap 
	   // TC: O(N), SC: O(N)
	   string order = "!#$%&*@^~";
	   unordered_set<char> s;
	   for(int i = 0; i < n; i++) s.insert(nuts[i]);
	   int l = 0;
	   for(char ch: order) {
	       if(s.count(ch)) {
	           bolts[l] = ch;
	           nuts[l++] = ch;
	       }
	   }
	   
	   // Quicksort
	   // TC: O(NlogN), SC: O(N) for recursion stack
	   quicksort(nuts, bolts, 0, n - 1);
	}
};