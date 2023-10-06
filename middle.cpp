#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>& st, int count, int size) {
    // Base case
    if (count == size / 2) {
        st.pop();
        return;
    }

    int num = st.top();
    st.pop();

    // Recursive call
    solve(st, count + 1, size);
    st.push(num);
}

void deleteMiddle(stack<int>& st, int N) {
    int count = 0;
    solve(st, count, N);
}

void printStack(stack<int>& st) {
    stack<int> tempStack;

    // Copy elements to temporary stack while printing
    while (!st.empty()) {
        int element = st.top();
        st.pop();
        cout << element << " ";
        tempStack.push(element);
    }

    cout << endl;

    // Restore elements to the original stack
    while (!tempStack.empty()) {
        int element = tempStack.top();
        tempStack.pop();
        st.push(element);
    }
}

int main() {
    stack<int> st;
    st.push(22);
    st.push(43);
    st.push(44);
    st.push(29);
    st.push(36);

    int N = st.size();

     cout << "Stack elements: ";

    printStack(st);


    deleteMiddle(st, N);
     cout << "Stack elements after deleting middle node: ";

    printStack(st);

    return 0;
}
