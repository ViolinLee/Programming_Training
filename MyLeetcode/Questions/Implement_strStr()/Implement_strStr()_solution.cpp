class Solution { //����ƥ�� 
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;  //������ַ���Ϊ�գ��򷵻�0 
        int m = haystack.size(), n = needle.size();
        if (m < n) return -1;  //������ַ������ȴ���ĸ�ַ������ȣ��򷵻�-1 
        for (int i = 0; i <= m - n; ++i) { //������Ҫ��������ĸ�ַ��� 
            int j = 0;
            for (j = 0; j < n; ++j) { //����ÿһ���ַ�������һ�����ַ���
                if (haystack[i + j] != needle[j]) break; //����ַ���Ӧ�Ƚϣ�����Ӧλ���в��ȣ�������ѭ��
            }
            if (j == n) return i; //��һֱ��û������ѭ������˵���������ַ������򷵻���ʼλ��   
        }
        return -1;
    }
}; 
