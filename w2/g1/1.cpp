#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string seq;
    cin >> seq;

    string opening = "([{";
    stack<char> st;

    for (char c: seq) {
        if (opening.find(c) != string::npos) {
            st.push(c);
        } else {
            if (!st.empty()) {
                char top = st.top();
                if ((top == '(' && c == ')')
                    || (top == '[' && c == ']')
                    || (top == '{' && c == '}')) {
                    st.pop();
                } else {
                    st.push(c);
                    break;
                }
            } else {
                st.push(c);
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