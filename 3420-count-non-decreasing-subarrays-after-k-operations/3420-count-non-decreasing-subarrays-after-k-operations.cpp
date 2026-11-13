
class Solution {
    using ll = long long;

    class SegmentTree {
        int n;
        vector<ll> tree, lazy;
        vector<bool> marked;

        void apply(int node, int l, int r, ll val) {
            tree[node] = (r - l + 1LL) * val;
            lazy[node] = val;
            marked[node] = true;
        }

        void push(int node, int l, int r) {
            if (!marked[node] || l == r) return;

            int mid = (l + r) / 2;

            apply(node * 2, l, mid, lazy[node]);
            apply(node * 2 + 1, mid + 1, r, lazy[node]);

            marked[node] = false;
        }

        void update(int node, int l, int r,
                    int ql, int qr, ll val) {

            if (r < ql || l > qr) return;

            if (ql <= l && r <= qr) {
                apply(node, l, r, val);
                return;
            }

            push(node, l, r);

            int mid = (l + r) / 2;

            update(node * 2, l, mid, ql, qr, val);
            update(node * 2 + 1, mid + 1, r, ql, qr, val);

            tree[node] = tree[node * 2] +
                         tree[node * 2 + 1];
        }

        // Find maximum valid right endpoint directly
        int findRight(int node, int l, int r,
                      int start, ll &budget,
                      vector<ll>& pref) {

            if (r < start)
                return start - 1;

            if (l >= start) {
                ll cost = tree[node] -
                          (pref[r + 1] - pref[l]);

                if (cost <= budget) {
                    budget -= cost;
                    return r;
                }
            }

            if (l == r)
                return l - 1;

            push(node, l, r);

            int mid = (l + r) / 2;

            int left = findRight(
                node * 2, l, mid,
                start, budget, pref
            );

            if (left < mid)
                return left;

            return findRight(
                node * 2 + 1, mid + 1, r,
                start, budget, pref
            );
        }

    public:
        SegmentTree(int n) : n(n) {
            tree.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
            marked.assign(4 * n, false);
        }

        void update(int l, int r, ll val) {
            if (l <= r)
                update(1, 0, n - 1, l, r, val);
        }

        int findRight(int start, ll k,
                      vector<ll>& pref) {
            return findRight(
                1, 0, n - 1, start, k, pref
            );
        }
    };

public:
    long long countNonDecreasingSubarrays(
        vector<int>& nums, int k) {

        int n = nums.size();

        // Next Greater Element
        vector<int> nge(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() &&
                   nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (!st.empty())
                nge[i] = st.top();

            st.push(i);
        }

        // Prefix sum
        vector<ll> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        SegmentTree seg(n);

        ll ans = 0;

        for (int l = n - 1; l >= 0; l--) {

            // Update required prefix maximums
            seg.update(l, nge[l] - 1, nums[l]);

            // Directly find maximum valid endpoint
            int r = seg.findRight(l, k, pref);

            ans += (r - l + 1LL);
        }

        return ans;
    }
};
