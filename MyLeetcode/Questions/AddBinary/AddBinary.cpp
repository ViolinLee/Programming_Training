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
            if (carry) tmp = (a[i] - '0') + (b[i] - '0') + 1; // 第一个if处理和的值 
            else tmp = (a[i] - '0') + (b[i] - '0');
            
            if (tmp == 0) { // 第二个if处理进位 
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
        if (carry) res.insert(res.begin(), '1'); // 处理可能超出最长度的进位 
        
        return res;
    }
};

/* 注：
0.最重点：分类讨论的种类有四种：carry=false的一种；carry=true的一种 
1.string的插值 a.insert(b,begin(), '0');
2.字符转数字不用强制转换，而用 -'0'; 
*/


class Solution { // 超简洁 
public:
    string addBinary(string a, string b) {
        string res = "";
        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        while (m >= 0 || n >= 0) { // 避免了"补0" 
            int p = m >= 0 ? a[m--] - '0' : 0;
            int q = n >= 0 ? b[n--] - '0' : 0;
            int sum = p + q + carry;
            res = to_string(sum % 2) + res; // sum%2，to_string 
            carry = sum / 2; // sum/2 
        }
        return carry == 1 ? "1" + res : res;
    }
};

// sum%2(决定位值)和sum/2(决定进位)太巧妙了，避免了冗长的分类讨论，虽然对其他题的优化借鉴不大 

