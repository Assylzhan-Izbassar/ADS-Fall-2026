#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    stack<char> st; // declare
    string opening = "([{";

    for (int i=0; i < s.size(); ++i) {
        if (opening.find(s[i]) != string::npos) {
            st.push(s[i]);
        } else {
            char top = st.top();
            // bool isValid = false;
            if (top == '(' && s[i] == ')') {
                st.pop();
            } else if (top == '[' && s[i] == ']') {
                st.pop();
            } else if (top == '{' && s[i] == '}') {
                st.pop();
            } else {
                st.push(s[i]);
                break;
            }
        }
    }

    if (st.empty()) {
        cout << "VALID\n";
    } else {
        cout << "INVALID\n";
    }

    return 0;
}