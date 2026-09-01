class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sr = -1, sc = -1, litterCount = 0;
        int litterId[20][20];
        memset(litterId, -1, sizeof(litterId));
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                } else if (classroom[r][c] == 'L') {
                    litterId[r][c] = litterCount++;
                }
            }
        }
        
        if (litterCount == 0) return 0;
        int targetMask = (1 << litterCount) - 1;
        
        static int bestEnergy[20][20][1024];
        memset(bestEnergy, -1, sizeof(bestEnergy));
        
        queue<tuple<int, int, int, int, int>> q;
        q.push({sr, sc, 0, energy, 0});
        bestEnergy[sr][sc][0] = energy;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            auto [r, c, mask, e, moves] = q.front();
            q.pop();
            
            if (e == 0) continue;
            
            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') continue;
                
                int ne = (classroom[nr][nc] == 'R') ? energy : (e - 1);
                int nmask = mask;
                
                if (classroom[nr][nc] == 'L') {
                    nmask |= (1 << litterId[nr][nc]);
                }
                
                if (nmask == targetMask) {
                    return moves + 1;
                }
                
                if (ne > bestEnergy[nr][nc][nmask]) {
                    bestEnergy[nr][nc][nmask] = ne;
                    q.push({nr, nc, nmask, ne, moves + 1});
                }
            }
        }
        
        return -1;
    }
};