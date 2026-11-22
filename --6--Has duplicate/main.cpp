#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(auto& p : nums){
            if(!seen.insert(p).second){
                return p;
            }
        }
        return 0;
    }
};