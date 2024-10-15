class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int l=0;
        int n=matrix[0].size();
        int h=matrix.size()*matrix[0].size();
        while(l<h)
        {
            int mid=l+(h-l)/2;
            if(matrix[mid/n][mid%n]==target) 
                return true;
            else if(matrix[mid/n][mid%n]>target)
                h=mid;
            else
                l=mid+1;
        }
        return false;
    }
};
