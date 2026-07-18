class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(st.find(endWord) == st.end()){
            return 0;
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            string top = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if (top == endWord) {
                return cnt;
            }
            for (int i = 0; i < top.size(); i++) {
                string temp = top;
                for (int j = 0; j < 26; j++) {
                    if(temp[i] == 'a' + j) {
                        continue;
                    }
                    temp[i] = 'a' + j;
                    if (st.find(temp) != st.end()) {
                        q.push({temp, cnt + 1});
                        st.erase(temp); // this is the important step in the process
                    }
                }
            }
        }
        return 0;
    }
};