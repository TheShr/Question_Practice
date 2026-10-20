class Solution {
public:
    void swapIfGreater(vector<int>& nums1, int idx1, vector<int>& nums2, int idx2){
        if(nums1[idx1] > nums2[idx2]){
            swap(nums1[idx1], nums2[idx2]);
        } 
              
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Applying Gap method

        int len = n + m, gap = (len / 2) + (len % 2);
        
        while(gap > 0){
            
            int l = 0, r = l + gap;

            while(r < len){
                // 3 conditions

                // where l -> nums1 , r -> nums2
                if(l < m && r >= m){
                    swapIfGreater(nums1, l, nums2, r-m);
                }

                // when l -> nums2 , r -> nums2
                else if(l >= m){
                    swapIfGreater(nums2, l-m, nums2, r-m);
                }

                // when l -> nums1, r -> nums1
                else{
                    swapIfGreater(nums1, l, nums1, r);
                }
                l++; r++;
            }
            if(gap == 1) break;
            gap = (gap / 2) + (gap % 2);
            
        }
        int idx = 0;
        while(idx < n){
            swap(nums1[idx+m], nums2[idx]);
            idx++;
        }
    }
};