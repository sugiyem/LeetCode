class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int pos1 = num1.find("+");
        int real1 = stoi(num1.substr(0, pos1));
        int imaginary1 = stoi(num1.substr(pos1 + 1, num1.size() - pos1 - 2));
        int pos2 = num2.find("+");
        int real2 = stoi(num2.substr(0, pos2));
        int imaginary2 = stoi(num2.substr(pos2 + 1, num2.size() - pos2 - 2));
        string realAns = to_string(real1 * real2 - imaginary1 * imaginary2);
        string imaginaryAns = to_string(real1 * imaginary2 + real2 * imaginary1);
        return realAns + "+" + imaginaryAns + "i";
    }
};