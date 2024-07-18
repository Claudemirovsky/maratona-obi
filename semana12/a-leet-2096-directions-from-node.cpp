class Solution {
  public:
    string pathsToDirection(string &start, string &dest) {
        if (start[0] == dest[0]) {
            int idx = 0, sts = start.size(), dts = dest.size();
            while (idx < sts && idx < dts && start[idx] == dest[idx])
                ++idx;
            start = start.substr(idx), dest = dest.substr(idx);
        }

        for (auto &c : start)
            c = 'U';

        return start + dest;
    }

    // Vlw hilbert, resolveu meu MLE
    bool getPath(TreeNode *root, int &target, string &d) {
        if (root->val == target)
            return true;

        if (root->left) {
            d += 'L';
            if (getPath(root->left, target, d))
                return true;
            d.pop_back();
        }

        if (root->right) {
            d += 'R';
            if (getPath(root->right, target, d))
                return true;
            d.pop_back();
        }

        return false;
    }

    string getDirections(TreeNode *root, int startValue, int destValue) {
        string pathStart, pathEnd;

        getPath(root, startValue, pathStart);
        getPath(root, destValue, pathEnd);

        return pathsToDirection(pathStart, pathEnd);
    }
};
