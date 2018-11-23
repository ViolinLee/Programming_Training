class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end()); // HashSet��߲���Ч�� 
        unordered_map<string, int> pathCnt{{{beginWord, 1}}}; // ĳ·����β���ʺ͸�·�����ȵ�ӳ��
        
		queue<string> q{{beginWord}};
        while (!q.empty()) {  
            string word = q.front(); q.pop();
            for (int i = 0; i < word.size(); ++i) {
                string newWord = word;
                for (char ch = 'a'; ch <= 'z'; ++ch) { //����ÿ��λ���ϵ��ַ�����26����ĸ�����滻 
                    newWord[i] = ch;
                    if (wordSet.count(newWord) && newWord == endWord) return pathCnt[word] + 1; //����滻�����ֵ��д��ڣ��Һͽ�β������ͬ������ȡ�����ڹ�ϣ���е�ֵ��һ 
                    if (wordSet.count(newWord) && !pathCnt.count(newWord)) { // ����滻�����ֵ��д��ڵ��ڹ�ϣ���в����ڣ����滻����������У����ڹ�ϣ���е�ֵӳ��Ϊ֮ǰȡ���ʼ�һ 
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
BFSʹ��queue��ʹ������ͬ�����������Ԫ��(������Ȼ�ӽ���·����β����)������һ�飬���Ұ�һ����˳����(��·���������)��ʵ��һ��һ������ 
˼·�ϻ��ǱȽϼ򵥵ģ����������㷨 
*/ 

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q{{beginWord}};
        int res = 0;
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) { //������ǰ���У���·��Сtrick�� 
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
            ++res; //�����굱ǰ�㣬��������1 
        }
        return 0;
    }
};
