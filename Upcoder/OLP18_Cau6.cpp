#include <bits/stdc++.h>

using namespace std;

string hexToBin (char hex) {
    switch (hex) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
        case 'a': return "1010";
        case 'b': return "1011";
        case 'c': return "1100";
        case 'd': return "1101";
        case 'e': return "1110";
        case 'f': return "1111";
    }
    return "";
}

string binToOct (string bin) {
    while (bin.size() % 3 != 0) {
        bin = "0" + bin;
    }
    string oct = "";
    for (auto i = 0; i < bin.size(); i += 3) {
        int val = (bin[i] - '0') * 4 + (bin[i + 1] - '0') * 2 + (bin[i + 2] - '0');
        oct += to_string(val);
    }
    return oct;
}

int main () {
    string hexStr; cin >> hexStr;
    string binStr = "";
    for (char c : hexStr) binStr += hexToBin(c);
    string octStr = binToOct(binStr);
    while (!octStr.empty() && octStr[0] == '0') octStr.erase(0, 1);
    if (octStr.empty()) return cout << 0, 0;
    cout << octStr;
}
