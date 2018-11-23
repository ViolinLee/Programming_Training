class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end()); // HashSet提高查找效率 
        unordered_map<string, int> pathCnt{{{beginWord, 1}}}; // 某路径结尾单词和该路径长度的映射
        
		queue<string> q{{beginWord}};
        while (!q.empty()) {  
            string word = q.front(); q.pop();
            for (int i = 0; i < word.size(); ++i) {
                string newWord = word;
                for (char ch = 'a'; ch <= 'z'; ++ch) { //对其每个位置上的字符，用26个字母进行替换 
                    newWord[i] = ch;
                    if (wordSet.count(newWord) && newWord == endWord) return pathCnt[word] + 1; //如果替换词在字典中存在，且和结尾单词相同，返回取出词在哈希表中的值加一 
                    if (wordSet.count(newWord) && !pathCnt.count(newWord)) { // 如果替换词在字典中存在但在哈希表中不存在，则将替换词排入队列中，并在哈希表中的值映射为之前取出词加一 
                        q.push(newWord);
                        pathCnt[newWord] = pathCnt[word] + 1;
                    }   
                }
            }
        }
        return 0;
    }
};
/*
BFS使用queue，使具有相同或相近特征的元素(长度相等或接近的路径结尾单词)集中在一块，并且按一定的顺序处理(短路径先入队列)，实现一层一层扩大。 
思路上还是比较简单的，属于蛮力算法 
*/ 

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q{{beginWord}};
        int res = 0;
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) { //遍历当前队列（套路：小trick） 
                string word = q.front(); q.pop();
                if (word == endWord) return res + 1;
                for (int i = 0; i < word.size(); ++i) {
                    string newWord = word;
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        newWord[i] = ch;
                        if (wordSet.count(newWord) && newWord != word) {
                            q.push(newWord);
                            wordSet.erase(newWord);
                        }   
                    }
                }
            }
            ++res; //遍历完当前层，层数自增1 
        }
        return 0;
    }
};
