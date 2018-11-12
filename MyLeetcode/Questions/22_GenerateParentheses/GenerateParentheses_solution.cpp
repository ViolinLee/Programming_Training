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
	// l 表示(出现的次数(下面的都是剩下的次数)
	// r 表示)出现的次数
	void generate(int n, string s, int l, int r, vector<string> &result) {
		if (l==n) {
			result.push_back(s.append(n-r, ')'));
			return;
		}
		generate(n, s + '(', 1 + l, r, result); // 路线1：一定满足(l<n),因此不需要条件 
		if (l > r) generate(n, s + ')', l, r + 1, result); // 路线2：如果少了if(l > r)的判断则返回所有可能组合结果，(l > r)保证合理 
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
        if (left > right) return; // 不能没有这句；当有路线进行到left > right时，直接跳出这条路线，即无返回 
        if (left == 0 && right == 0) res.push_back(out);
        else {
            if (left > 0) generateParenthesisDFS(left - 1, right, out + '(', res);  // 路线1 
            if (right > 0) generateParenthesisDFS(left, right - 1, out + ')', res); // 路线2 
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
    } // 基准情形(base case) 
    
    if (left>0){
        generator(result, left-1, right, s+'(');
    } // 路线1 
    
    if (right>0 && right>left){  //不能是else if，否则不会生成多个结果；right剩下的个数比left多时才能加右括号 
        generator(result, left, right-1, s+')');
    } // 路线2 
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

