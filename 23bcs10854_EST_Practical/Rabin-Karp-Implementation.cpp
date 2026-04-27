class Solution {
public:
    vector<int> search(string &pat, string &txt) {
        int n = txt.size(), m = pat.size();
        vector<int> ans;
        if (m > n) return ans;

        long long d = 256;    
        long long q = 1e9 + 7; 
        long long h = 1, pHash = 0, tHash = 0;

        for (int i = 0; i < m - 1; i++)
            h = (h * d) % q;

        for (int i = 0; i < m; i++) {
            pHash = (d * pHash + pat[i]) % q;
            tHash = (d * tHash + txt[i]) % q;
        }

        for (int i = 0; i <= n - m; i++) {
            if (pHash == tHash) {
                // Char-by-char check only on hash match
                if (txt.compare(i, m, pat) == 0) ans.push_back(i);
            }
            if (i < n - m) {
                tHash = (d * (tHash - txt[i] * h) + txt[i + m]) % q;
                if (tHash < 0) tHash += q;
            }
        }
        return ans;
    }
};
