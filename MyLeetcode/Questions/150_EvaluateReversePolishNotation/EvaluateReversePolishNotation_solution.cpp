class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    	if (tokens.size() == 1) return stoi(tokens[0]);
    	stack<int> st;
    	for (int i = 0; i < tokens.size(); ++i) {
    		if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
    			st.push(stoi(tokens[i]));
			} else {
				int num1 = st.top(); st.pop();
				int num2 = st.top(); st.pop();
				if (tokens[i] == "+") st.push(num2 + num1);
				if (tokens[i] == "-") st.push(num2 - num1);
				if (tokens[i] == "*") st.push(num2 * num1);
                if (tokens[i] == "/") st.push(num2 / num1);
			}
		}
		return st.top();
	}	
};
/* 
1.stoi������ʹ�ã�
2.string��������ֻ���������ַ�
*/ 



class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		int op = (int)tokens.size() - 1;
		return helper(tokens, op);
	}
	int helper(vector<string>& tokens, int& op) {
		string str = tokens[op];
		if (str != "+" && str != "-" && str != "*" && str != "-") return stoi(str);
		int num1 = helper(tokens, --op);
		int num2 = helper(tokens, --op);
		if (str == "+") return num2 + num1;
		if (str == "-") return num2 - num1;
		if (str == "*") return num2 * num1;
		return num2 / num1; 
	}
};



