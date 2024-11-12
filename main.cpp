#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int maxI=INT_MAX;
        vector<vector<int>> res={{0, 0, maxI}};
        sort(items.begin(), items.end());

        for(const auto& item: items){
            int price=item[0];
            int beuty=item[1];
            if(beuty>res.back()[1]){ //el ultimo vector, su segundo elemento de ese vector
                res.back()[2]=price;
                res.push_back({price, beuty, maxI});
            }
        }
        vector<int> ans;

        for(int x: queries){
            for(int i=res.size()-1; i>=0; i--){
                if(res[i][0]<=x){
                    ans.push_back(res[i][1]);
                    break;
                }
            }
        }

        return ans;
    }
};

int main(){
    return 0;
}