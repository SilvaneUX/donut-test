#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int n;
    unordered_map<int, int> mp;
    int t[2001][2001];

    bool solve(vector<int>& stones,int csi,int pj)
    {
        if(csi==n-1){
            return true;
        }
        bool res=false;

        if(t[csi][pj]!=-1)
        {
            return t[csi][pj];
        }
        
        for(int nj=pj-1;nj<=pj+1;nj++)
        {
            if(nj>0)
            {
                int next_s=stones[csi]+nj;

                if(mp.find(next_s)!=mp.end())
                {
                    res=res||solve(stones,mp[next_s],nj);
                }
            }
        }
        return t[csi][pj]=res;
    }
    bool canCross(vector<int>& stones) {
        n=stones.size();
        if(stones[1]!=1)
        {
            return false;
        }
        for(int i=0;i<n;i++)
        {
            mp[stones[i]]=i;
        }

        memset(t,-1,sizeof(t));
        return solve(stones,0,0);
    }
};
int main() {
    Solution solution;
    
    vector<int> stones1 = {0, 1, 3, 5, 6, 8, 12, 17};
    cout << "Can frog cross in example 1? " << (solution.canCross(stones1) ? "Yes" : "No") << endl;

    vector<int> stones2 = {0, 1, 2, 3, 4, 8, 9, 11};
    cout << "Can frog cross in example 2? " << (solution.canCross(stones2) ? "Yes" : "No") << endl;

    return 0;
}
