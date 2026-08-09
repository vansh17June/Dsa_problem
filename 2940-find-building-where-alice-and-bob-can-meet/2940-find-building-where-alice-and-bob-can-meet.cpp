class Solution {
public:
    int getQuery(int lr, int rr, int l, int r, int idx,
                 vector<int>& segment_tree, vector<int>& heights) {
        if (lr > r || rr < l) {
            return -1;
        }
        if (lr <= l && r <= rr) {
            return segment_tree[idx];
        }
        int mid = l + (r - l) / 2;
        int left_result =
            getQuery(lr, rr, l, mid, 2 * idx + 1, segment_tree, heights);
        int right_result =
            getQuery(lr, rr, mid + 1, r, 2 * idx + 2, segment_tree, heights);
        if (left_result == -1) {
            return right_result;
        } else if (right_result == -1) {
            return left_result;
        }
        int ans = (heights[left_result] > heights[right_result]) ? left_result
                                                                 : right_result;
        return ans;
    }
    void buildTree(int left, int right, int idx, vector<int>& segment_tree,
                   vector<int>& heights) {
        if (left == right) {
            segment_tree[idx] = left;
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(left, mid, 2 * idx + 1, segment_tree, heights);
        buildTree(mid + 1, right, 2 * idx + 2, segment_tree, heights);
        if (segment_tree[2 * idx + 1] == -1) {
            segment_tree[idx] = segment_tree[2 * idx + 2];
        } else if (segment_tree[2 * idx + 2] == -1) {
            segment_tree[idx] = segment_tree[2 * idx + 1];
        } else {
            segment_tree[idx] = (heights[segment_tree[2 * idx + 1]] >
                                 heights[segment_tree[2 * idx + 2]])
                                    ? segment_tree[2 * idx + 1]
                                    : segment_tree[2 * idx + 2];
        }
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> segment_tree(4 * n, -1);
        buildTree(0, n - 1, 0, segment_tree, heights);
        vector<int> temp;
        for (vector<int> x : queries) {
            int pos1 = x[0], pos2 = x[1];
            int start = max(pos1, pos2), end = n - 1, ans = -1;
            while (start <= end) {
                int mid = start + (end - start) / 2;
                int idx =
                    getQuery(start, mid, 0, n - 1, 0, segment_tree, heights);
                if (heights[pos1] < heights[idx] &&
                    heights[pos2] < heights[idx]) {
                    ans = idx;
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            if (pos1 == pos2) {
                temp.push_back(pos1);
            } else if (heights[max(pos1, pos2)] > heights[min(pos1, pos2)]) {
                temp.push_back(max(pos1, pos2));

            } else {
                temp.push_back(ans);
            }
        }
        return temp;
    }
};