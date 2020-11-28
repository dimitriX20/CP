class Solution {
     //NOCH NICHT KORREGIERT 
    int lengthOfLIS(vector<int>& nums, int s, int n) {
        vector<int> res; 
        for(int i = s; i < n; i++){
            if(res.size()== 0||nums[i]>res.back())res.push_back(nums[i]); 
            else *lower_bound(res.begin(),res.end(),nums[i])=nums[i]; 
        }
        return (n-s) - res.size(); 
        
    }  
    
     
    
/*int minRemove(vector<int>&arr, int start,int n) { 
    if(n == 0)return 0; 
    int LIS[n], len = 0; 
  
  for (int i = start; i < n; i++) 
        LIS[i] = 1; 
  
    for (int i = start; i < n; i++) { 
        for (int j = 0; j < i; j++) { 
            if (arr[i] > arr[j] && (i-j)<=(arr[i]-arr[j])){ 
                LIS[i] = max(LIS[i], LIS[j] + 1); 
            } 
        } 
        len = max(len, LIS[i]); 
    } 
  
    return n - len; 
} */
    
public:
    int minimumMountainRemovals(vector<int>& nums) {
        //if strictly decreasing: entferne vorderestes Element analag für strictly increasing 
        vector<int>c= nums; 
        reverse(c.begin(), c.end()); 
        int res = nums.size(); 
         for(int i=0; i < nums.size(); i++){n
              res = min(lengthOfLIS(nums,0,i+1) + lengthOfLIS(c,0, nums.size()-i), res); 
         }  
        return res; 
    }
};
