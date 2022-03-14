/*给你一个整数数组 nums 。如果任一值在数组中
出现 至少两次 ，返回 true ；如果数组中每个元
素互不相同，返回 false 。
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for (vector<int>::iterator it = nums.begin()-1; it != nums.end(); it++)
        {
            if (*it == *(it+1))
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{

}