class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int na = a.size();
        int nb = b.size();
        int n = max(na, nb);
        bool carry = false;
        if (na > nb) {
            for (int i = 0; i < na - nb; ++i) b.insert(b.begin(), '0');
        }
        else if (na < nb) {
            for (int i = 0; i < nb - na; ++i) a.insert(a.begin(), '0');
        }
        
        for (int i = n - 1; i >= 0; --i) {
            int tmp = 0;
            if (carry) tmp = (a[i] - '0') + (b[i] - '0') + 1; // ��һ��if����͵�ֵ 
            else tmp = (a[i] - '0') + (b[i] - '0');
            
            if (tmp == 0) { // �ڶ���if�����λ 
                res.insert(res.begin(), '0');
                carry = false;
            }
            else if (tmp == 1) {
                res.insert(res.begin(), '1');
                carry = false;
            }
            else if (tmp == 2) {
                res.insert(res.begin(), '0');
                carry = true;
            }
            else if (tmp == 3) {
                res.insert(res.begin(), '1');
                carry = true;
            }
        }
        if (carry) res.insert(res.begin(), '1'); // ������ܳ�����ȵĽ�λ 
        
        return res;
    }
};

/* ע��
0.���ص㣺�������۵����������֣�carry=false��һ�֣�carry=true��һ�� 
1.string�Ĳ�ֵ a.insert(b,begin(), '0');
2.�ַ�ת���ֲ���ǿ��ת�������� -'0'; 
*/


class Solution { // ����� 
public:
    string addBinary(string a, string b) {
        string res = "";
        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        while (m >= 0 || n >= 0) { // ������"��0" 
            int p = m >= 0 ? a[m--] - '0' : 0;
            int q = n >= 0 ? b[n--] - '0' : 0;
            int sum = p + q + carry;
            res = to_string(sum % 2) + res; // sum%2��to_string 
            carry = sum / 2; // sum/2 
        }
        return carry == 1 ? "1" + res : res;
    }
};

// sum%2(����λֵ)��sum/2(������λ)̫�����ˣ��������߳��ķ������ۣ���Ȼ����������Ż�������� 

