class Solution {
public:
    struct Node {
        int prod;
        int cnt[5];

        Node(int k = 5) {
            prod = 1;
            memset(cnt, 0, sizeof(cnt));
        }
    };

    int k;

    Node merge(Node &L, Node &R) {
        Node res;
        res.prod = (L.prod * R.prod) % k;

        for (int r = 0; r < k; r++)
            res.cnt[r] = L.cnt[r];

        for (int r = 0; r < k; r++) {
            int nr = (L.prod * r) % k;
            res.cnt[nr] += R.cnt[r];
        }

        return res;
    }

    vector<Node> tree;

    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            int v = nums[l] % k;
            tree[node].prod = v;
            tree[node].cnt[v] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(nums, 2 * node, l, mid);
        build(nums, 2 * node + 1, mid + 1, r);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int pos, int val) {
        if (l == r) {
            val %= k;

            tree[node] = Node();
            tree[node].prod = val;
            tree[node].cnt[val] = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * node, l, mid, pos, val);
        else
            update(2 * node + 1, mid + 1, r, pos, val);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(2 * node, l, mid, ql, qr);

        if (ql > mid)
            return query(2 * node + 1, mid + 1, r, ql, qr);

        Node left = query(2 * node, l, mid, ql, qr);
        Node right = query(2 * node + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int K,
                            vector<vector<int>>& queries) {
        k = K;

        int n = nums.size();
        tree.resize(4 * n);

        build(nums, 1, 0, n - 1);

        vector<int> ans;

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Permanent update
            update(1, 0, n - 1, index, value);

            // Query nums[start ... n-1]
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};