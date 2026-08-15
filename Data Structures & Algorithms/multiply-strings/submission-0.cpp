#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Number {
  public:
    string number1 = "";

    Number(string num1) : number1(num1) {}

    string multiplyUnit(char m) {
        if (m == '0') return "0";

        string res = "";
        int carry = 0;
        int u2 = m - '0';

        for (int i = number1.size() - 1; i >= 0; i--) {
            int u1 = number1[i] - '0';
            int val = u1 * u2 + carry;
            carry = val / 10;
            res.push_back((val % 10) + '0'); // Efficient O(1) append
        }

        if (carry > 0) {
            res.push_back(carry + '0');
        }

        reverse(res.begin(), res.end()); // Reverse once at the end
        return res;
    }

    string add(string number2) {
        int carry = 0;
        int sz1 = number1.size();
        int sz2 = number2.size();
        string res = ""; 

        for (int i = 0; i < max(sz1, sz2); i++) {
            int u = 0, v = 0;
            if (sz1 - 1 - i >= 0) u = number1[sz1 - 1 - i] - '0';
            if (sz2 - 1 - i >= 0) v = number2[sz2 - 1 - i] - '0';

            int val = u + v + carry;
            res.push_back((val % 10) + '0'); // Efficient O(1) append
            carry = val / 10;
        }

        if (carry > 0) {
            res.push_back(carry + '0');
        }

        reverse(res.begin(), res.end());
        number1 = res;
        return res;
    }
};

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        Number a(num1);
        Number res("0");
        string exp = "";

        for (int i = num2.size() - 1; i >= 0; i--) {
            string inter = a.multiplyUnit(num2[i]);
            if (inter != "0") {
                res.add(inter + exp);
            }
            exp += "0";
        }

        return res.number1;
    }
};