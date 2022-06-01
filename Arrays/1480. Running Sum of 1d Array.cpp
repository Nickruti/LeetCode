// Using a temp Variable
    vector<int> runningSum(vector<int>& nums) {
        int sum = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
            sum += nums[i];
            nums[i] = sum;
        }
        
        return nums;
    }
	
// Without using extra Variable - 0ms 
	vector<int> runningSum(vector<int>& nums) {
        
        for(int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i-1];
        }
        
        return nums;
    }