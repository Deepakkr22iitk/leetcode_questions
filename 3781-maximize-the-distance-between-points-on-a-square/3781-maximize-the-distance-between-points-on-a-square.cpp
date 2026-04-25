uint32_t dists[15000];
uint16_t nxt[15000];

class Solution {
public:
    int maxDistance(int s, vector<vector<int>>& points, int k) {
        const uint64_t n = points.size(), perim = 4UL * s;
        // map 2D points into distance along the perimeter
        for (uint i = 0; i < n; i++) {
            uint64_t x = points[i][0], y = points[i][1];
            dists[i] = (x == 0 || y == s) ? perim - x - y : x + y;
        }
        // sort distances to enable greedy jumps
        sort(dists, dists + n);
        const auto check = [&](uint64_t x) -> bool {
            // nxt[i] = first index j where dists[j] >= dists[i] + x
            for (uint i = 0, j = 0; i < n; i++) {
                j = max(j, i + 1);
                while (j < n && dists[j] < dists[i] + x) j++;
                nxt[i] = j;
            }
            // maximum allowed span between first and last chosen point
            auto limit = perim - x;
            // try each starting point
            bool found = false;
            for (uint i = 0; i < n && !found; i++) {
                uint j = i;
                for (uint kk = k - 1; kk > 0 && j != n; kk--) {
                    j = nxt[j];
                }
                found = j != n && dists[j] - dists[i] <= limit;
            }
            return found;
        };
        // binary search the maximum feasible minimum distance
        uint lo = 1, hi = perim / k;
        while (lo < hi) {
            auto mid = (lo + hi + 1) / 2;
            auto mask = -check(mid);
            lo ^= (lo ^ mid) & mask;
            hi ^= (hi ^ (mid - 1)) & ~mask;
            // same thing as
            // if (check(mid)) lo = mid;
            // else hi = mid - 1;
        }
        return hi;
    }
};