#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm> // 為了 std::sort
#include <utility>   // 為了 std::pair (如果選擇用 pair)

using namespace std;

// DFS 函數 (如上所示)
void dfs(int r, int c, int H, int W, char target_lang,
         const vector<string>& world_map, vector<vector<bool>>& visited) {
    if (r < 0 || r >= H || c < 0 || c >= W || visited[r][c] || world_map[r][c] != target_lang) {
        return;
    }
    visited[r][c] = true;
    dfs(r + 1, c, H, W, target_lang, world_map, visited);
    dfs(r - 1, c, H, W, target_lang, world_map, visited);
    dfs(r, c + 1, H, W, target_lang, world_map, visited);
    dfs(r, c - 1, H, W, target_lang, world_map, visited);
}

// 排序用的比較函數 (選擇 pair 版本)
bool comparePairs(const pair<char, int>& a, const pair<char, int>& b) {
    if (a.second != b.second) {
        return a.second > b.second; // 按州數量遞減
    }
    return a.first < b.first; // 州數量相同，按字母升序
}

int main() {
    int N_test_cases;
    cin >> N_test_cases;
    for (int case_num = 1; case_num <= N_test_cases; ++case_num) {
        int H, W;
        cin >> H >> W;
        vector<string> world_map(H);
        for (int i = 0; i < H; ++i) {
            cin >> world_map[i];
        }

        map<char, int> lang_states_count;
        vector<vector<bool>> visited(H, vector<bool>(W, false));

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j]) {
                    char current_lang = world_map[i][j];
                    lang_states_count[current_lang]++;
                    dfs(i, j, H, W, current_lang, world_map, visited);
                }
            }
        }

        vector<pair<char, int>> sorted_langs;
        for (auto const& [lang, count] : lang_states_count) {
            sorted_langs.push_back({lang, count});
        }

        sort(sorted_langs.begin(), sorted_langs.end(), comparePairs);

        cout << "World #" << case_num << endl;
        for (const auto& p : sorted_langs) {
            cout << p.first << ": " << p.second << endl;
        }
    }
    return 0;
}