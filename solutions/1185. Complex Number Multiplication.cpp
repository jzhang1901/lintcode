/*
1185. Complex Number Multiplication
Description 

Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i^2 = -1 according to the definition.

1.The input strings will not have extra blank.
2.The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
Have you met this question in a real interview?  
Example

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i^2 + 2 * i = 2i, and you need convert it to the form of 0+2i.

Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i^2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.


*/

class Solution {
public:
    /**
     * @param a: a string
     * @param b: a string
     * @return: a string representing their multiplication
     */
    pair<int, int> parseComplex(string &s) {
        int a = 0, b = 0;
        const int l = s.length();
        int i;
        int sign1 = 1;
        for(i = 0; i < l; i++) {
            if(i == 0 && s[i] == '-') {
                sign1 = -1;
                continue;
            }
            if(s[i] == '+') break;
            a = a * 10 + (s[i] - '0');
        }

        int sign2 = 1;

        for(int j = i+1; j < l; j++) {
            if(s[j] == '-') {
                sign2 = -1;
                continue;
            }
            if(s[j] == 'i') break; //这里出错了　忘记检查'i'了
               
            b = b * 10 + (s[j] - '0');
        }
        return make_pair(sign1*a, sign2 * b);
    }

    string complexNumberMultiply(string &a, string &b) {
        pair<int, int> numa = parseComplex(a);
        pair<int, int> numb = parseComplex(b);
        int real = numa.first * numb.first - numa.second * numb.second;
        int image = numa.first * numb.second + numa.second * numb.first;
        
        int sign1 = real < 0 ? -1 : 1;
        int sign2 = image < 0 ? -1 : 1;
        ostringstream oss;
        if(sign1 < 0) oss << "-";
        oss << abs(real) << "+";
        if(sign2 < 0) oss << "-";
        oss << abs(image) << "i";
        std::cout << oss.str() << endl;
        return oss.str();
    }
};