#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		if (n > 0) generate(n, "", 0, 0, result);
		return result;
	}
	// l ��ʾ(���ֵĴ���(����Ķ���ʣ�µĴ���)
	// r ��ʾ)���ֵĴ���
	void generate(int n, string s, int l, int r, vector<string> &result) {
		if (l==n) {
			result.push_back(s.append(n-r, ')'));
			return;
		}
		generate(n, s + '(', 1 + l, r, result); // ·��1��һ������(l<n),��˲���Ҫ���� 
		if (l > r) generate(n, s + ')', l, r + 1, result); // ·��2���������if(l > r)���ж��򷵻����п�����Ͻ����(l > r)��֤���� 
	} 
};

class Solution2 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisDFS(n, n, "", res);
        return res;
    }
    void generateParenthesisDFS(int left, int right, string out, vector<string> &res) {
        if (left > right) return; // ����û����䣻����·�߽��е�left > rightʱ��ֱ����������·�ߣ����޷��� 
        if (left == 0 && right == 0) res.push_back(out);
        else {
            if (left > 0) generateParenthesisDFS(left - 1, right, out + '(', res);  // ·��1 
            if (right > 0) generateParenthesisDFS(left, right - 1, out + ')', res); // ·��2 
        }
    }
};


/******************************************************************************************************************/

void generator(vector<string>& result, int left, int right, string s);
vector<string> generateParenthesis(int n) {
    
    vector<string> result;
    string s;
    generator(result, n, n, s);
    return result;
}

void generator(vector<string>& result, int left, int right, string s){
    if (left==0 && right==0){
        result.push_back(s);
        return;
    } // ��׼����(base case) 
    
    if (left>0){
        generator(result, left-1, right, s+'(');
    } // ·��1 
    
    if (right>0 && right>left){  //������else if�����򲻻����ɶ�������rightʣ�µĸ�����left��ʱ���ܼ������� 
        generator(result, left, right-1, s+')');
    } // ·��2 
}
    
void printResult(vector<string>& result)
{
    for(int i=0; i<result.size(); i++){
        cout << result[i] <<endl;
    }
}

int main(int argc, char** argv) 
{
    int n=3;
    if (argc>1){
        n = atoi(argv[1]);
    }
    //vector<string> r = generateParenthesis(n);
    Solution2 solution;
    vector<string> r = solution.generateParenthesis(n);
    
    printResult(r);
    return 0;
}

