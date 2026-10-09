int removeDuplicates(vector<int>& nums) {
    int st=-1;
    int end=0;
    int count=0;
    if(nums.size()==1){
        return 1;
    }
    while(end<nums.size()){
        if(st==-1){
            st=0;
            nums[st]=nums[end];
            end++;
            count++;
        }else if(nums[st]!=nums[end]){
            st++;
            nums[st]=nums[end];
            end++;
            count++;
        }else if(nums[st]==nums[end]){
            end++;
        }
    }
    return count;
}
};
