// Problem link: https://leetcode.com/problems/groups-of-strings
// 900ms 62MB
// Time complexity: O(nα(n)|∑|^2)
// Space complexity: O(n+2^|∑|)

// Union-find
struct NODE {
    NODE *pre = nullptr;
    unsigned points = 1;
};

NODE *getpre(NODE *node);

void unions(NODE *a, NODE *b) {
    a = getpre(a), b = getpre(b);
    if (a == b) return;

    if (a->points > b->points) swap(a, b);
    a->pre = b;
    b->points += a->points;
    a->points = 0;
}

NODE *getpre(NODE *node) {
    if (node->pre == nullptr)
        return node;

    return node->pre = getpre(node->pre);
}

class Solution {
public:
    vector<int> groupStrings(vector <string> &words) {
        NODE *nodes = new NODE[words.size()];
        unordered_map<unsigned, unsigned> stateId;
        for (unsigned index = 0; index < words.size(); ++index) {
            const string &str = words[index];
            unsigned state = 0;
            for (const char &c: str) state |= 1u << (c - 'a');
            auto tmp = stateId.find(state);
            if (tmp != stateId.end()) unions(nodes + index, nodes + tmp->second);
            else {
                stateId[state] = index;
                // Add or remove one bit
                for (unsigned i = 0; i < 26; ++i) {
                    unsigned nstate;
                    if (state & (1u << i)) nstate = state ^ (1u << i);
                    else nstate = state | (1u << i);

                    tmp = stateId.find(nstate);
                    if (tmp != stateId.end()) unions(nodes + index, nodes + tmp->second);
                }
                // Replace one bit with another
                for (unsigned i = 0; i < 26; ++i)
                    for (unsigned j = 0; j < 26; ++j) {
                        if ((state & (1u << i)) && (state & (1u << j)) == 0) {
                            unsigned nstate = state ^ (1u << i) | (1u << j);
                            tmp = stateId.find(nstate);
                            if (tmp != stateId.end()) unions(nodes + index, nodes + tmp->second);
                        }
                    }
            }
        }
        vector<int> ans = {0, 0};
        for (unsigned index = 0; index < words.size(); ++index) {
            if (nodes[index].pre != nullptr) continue;
            ++ans[0];
            ans[1] = max(ans[1], static_cast<int>(nodes[index].points));
        }
        delete[] nodes;
        return ans;
    }
};