#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
	int lastStoneWeightII(vector<int>& stones) {
		if (stones.empty()) return 0;
		if (stones.size() == 1) return stones[0];

		int target = accumulate(stones.begin(), stones.end(), 0);
		int weight = 0;
		vector<int> dp(target / 2 + 1, 0);
		//vector<vector<int>> dp((stones.size() + 1), vector<int>(target/2 + 1, 0));
		for (int i = 1; i <= stones.size(); ++i) {
			weight = stones[i - 1];
			for (int j = target/2; j >= 1; --j) {
				//if (j < stones[i-1])
				//	dp[i][j] = dp[i-1][j];
				//else {
				//	dp[i][j] = max(dp[i-1][j], dp[i-1][j - stones[i-1]] + stones[i-1]);
				//}
				if (j >= weight){
					dp[j] = max(dp[j], dp[j - weight] + weight);
				}
			}
		}
		return target - 2 * dp[target / 2];
	}
};
int main() {
	Solution solution;
	vector<int> vec = { 2,7,4,1,8,1 };
	int res = solution.lastStoneWeightII(vec);
	cout << res;
	return 0;
}