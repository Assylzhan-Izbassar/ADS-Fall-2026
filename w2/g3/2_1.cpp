#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string seq;
    cin >> seq;

    string opening = "([{";
    stack<char> st;

    for (int i=0; i < seq.size(); ++i) {
        if (opening.find(seq[i]) != string::npos) {
            st.push(seq[i]);
        } else {
            if (!st.empty()) {
                char top = st.top();
                if ((top == '(' && seq[i] == ')') 
                || (top == '{' && seq[i] == '}')
                || (top == '[' && seq[i] == ']')) {
                    st.pop();
                } else {
                    st.push(seq[i]);
                }
            } else {
                st.push(seq[i]);
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