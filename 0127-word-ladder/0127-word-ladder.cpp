class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        queue<pair<string, int>> q;
        set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) {
            return 0;
        } // case endWord Does not exit
        q.push({beginWord, 1});
        while (!q.empty()) {
            string top = q.front().first;
            int count = q.front().second;
            q.pop();
           
            if(top == endWord){
                return count;
            }
            for (int i = 0; i < top.size(); i++) {
                string temp  = top;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;
                    if(st.find(temp) != st.end()){ //string exist
                        q.push({temp,count+1});
                        st.erase(temp);
                    }  
                }
            }
        }
        return 0;
    }
};