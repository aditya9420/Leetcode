class Solution {
public:
    Solution()
    {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    int lengthOfLongestSubstring(string s) {
        // Array to store the most recent index of each of the 128 ASCII characters
        vector<int> alb(128, -1);
        
        // Tracks the start index of our current valid window (characters before this are "deprecated")
        int deprecated = 0; 
        int index = 0;
        int count = 0;
        int max_count = 0;
        
        for (auto v : s) {
            // Case 1: The character has not been visited yet
            if (alb[v] == -1) {
                count++;
                alb[v] = index; // Update to the latest index of the character
            }
            // Case 2: The character was visited AND is inside our current valid window
            else if (alb[v] >= deprecated) {
                // Shift the start of our window to the last seen index of this character
                deprecated = alb[v]; 
                
                // Calculate the new valid substring length
                count = index - alb[v];
                
                alb[v] = index; // Update to the latest index of the character
            }
            // Case 3: The character was visited, but it falls outside our current window 
            // (it is already "deprecated", so we treat it as a normal addition to the window)
            else if (alb[v] < deprecated) {
                count++;
                alb[v] = index; // Update to the latest index of the character
            }
            
            // Keep track of the maximum length found so far
            max_count = max(max_count, count);
            index++;
        }
        
        return max_count;
    }
};