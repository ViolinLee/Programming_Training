// �ݹ�汾(���ѣ��������취) 
class Solution {
public:
	vector<vector<int> > permute(vector<int>& num) {
		sort(num.begin(), num.end());
		
		vector<vector<int> > result;
		vector<int> path;  // �м���
		
		dfs(num, path, result);
		return result; 
	}
private:
	void dfs(const vector<int>& num, vector<int>& path, vector<vector<int> >& result) {
		if (path.size() == num.size()) {   // ��������
		    result.push_back(path);
		    return;
		}
		// ��չ״̬
		for (auto i : num) {
			// ���� i �Ƿ��� path �г��ֹ�
			auto pos = find(path.begin(), path.end(), i);
			
			if (pos == path.end()) {
				path.push_back(i); // ����dfsǰ���ı�path���� 
				dfs(num, path, result);   
				path.pop_back(); // dfs = (push_back --> dfs --> pop_back) ����dfs������path���Ȳ��ı�  
			}
		} 
	}
}; 

// ����ⷨ�е���ת�䡣���� 
