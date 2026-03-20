#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n;
void backtrack(vector<int> &nums, set<vector<int>> &result, int idx, vector<int> &current) {
    if (idx == n) {
        if (!current.empty()) {
            result.insert(current);
        }
        return;
    }
    current.push_back(nums[idx]);
    backtrack(nums, result, idx + 1, current);
    current.pop_back();
    backtrack(nums, result, idx + 1, current);
}
int main() {
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < nums.size(); i++) {
        cin >> nums[i];
    }
    set<vector<int>> result;
    vector<int> current;
    backtrack(nums, result, 0, current);
    cout << "empty" << endl;
    for (auto it = result.begin(); it != result.end(); it++) {
        vector<int> temp = *it;
        for (int j = 0; j < temp.size(); j++) {
            if (j == 0) {
                cout << temp[j];
            } else {
                cout << " " << temp[j];
            }
        }
        cout << endl;
    }
    return 0;
}