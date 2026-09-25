class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string , int>> q;

        unordered_set<string> s(wordList.begin(), wordList.end());
        
        if(s.find(endWord) == s.end()) return 0;

        q.push({beginWord, 1});
        s.erase(beginWord);

        while(!q.empty()){

            string node = q.front().first;
            int level = q.front().second;
            q.pop();
            int p = 0;
            if(node == endWord) return level;
            
            while(p < node.size()){
                char original = node[p];

                for(int i = 0; i<26; i++){
                    node[p] = char('a' + i);

                    if(s.find(node) != s.end()){
                        q.push({node, level+1});
                        s.erase(node);
                    }

                }
                node[p] = original;
                p++;
            }
        }
        return 0;
    }
};