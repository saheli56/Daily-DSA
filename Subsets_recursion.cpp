class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> pa ={{}}; // Start with the empty subset
        for(int num :nums){ // Iterate through each number in the input array 'nums'.
            int n = pa.size();
            for(int i =0; i<n;i++){
                vector<int> out= pa[i]; // Create a new subset based on the existing subset at index 'i' in the 'pa' vector.
                out.push_back(num); // Add the current number 'num' to the new subset 'out'.
                pa.push_back(out);// Add the new subset 'out' to the 'pa' vector, which stores all the subsets generated so far.
            }
        }
        return pa;
    }
};
// Time Complexity: O(2^N) in the worst case, where N is the number of elements in the input array. This is because in the worst case (when all elements are unique), we will generate 2^N subsets.
// Space Complexity: O(2^N) in the worst case, as we may store
