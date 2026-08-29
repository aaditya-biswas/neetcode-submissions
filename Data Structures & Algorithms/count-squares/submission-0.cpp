#include <vector>
#include <unordered_map>
#include <utility>
#include <cmath>

using namespace std;

// Custom hash function for std::pair<int, int>
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        auto h1 = hash<int>{}(p.first);
        auto h2 = hash<int>{}(p.second);
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};

class CountSquares {
public:
    unordered_map<pair<int, int>, int, PairHash> mp;

    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }

    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1];
        int cnt = 0;

        for (const auto& [pt, freq] : mp) {
            int x2 = pt.first;
            int y2 = pt.second;

            // Must form a non-zero diagonal
            if (x1 == x2 || y1 == y2) continue;
            if (abs(x1 - x2) != abs(y1 - y2)) continue;

            // Check existence using find() to avoid accidental insertions via operator[]
            auto it1 = mp.find({x1, y2});
            auto it2 = mp.find({x2, y1});

            if (it1 != mp.end() && it2 != mp.end()) {
                // Multiply frequency of options for each corner
                cnt += freq * it1->second * it2->second;
            }
        }
        return cnt;
    }
};