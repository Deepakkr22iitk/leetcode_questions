class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // int left1 = min(rec1[0], rec1[2]);
        // int right1 = max(rec1[0], rec1[2]);
        // int left2 = min(rec2[0], rec2[2]);
        // int right2 = max(rec2[0], rec2[2]);

        // int bottom1 = min(rec1[1], rec1[3]);
        // int top1 = max(rec1[1], rec1[3]);
        // int bottom2 = min(rec2[1], rec2[3]);
        // int top2 = max(rec2[1], rec2[3]);

        // if (right1 <= left2 || right2 <= left1)
        //     return false;

        // if (top1 <= bottom2 || top2 <= bottom1)
        //     return false;

        // return true;

        return rec1[0] < rec2[2] &&
               rec1[1] < rec2[3] &&
               rec2[0] < rec1[2] &&
               rec2[1] < rec1[3];
    }
};