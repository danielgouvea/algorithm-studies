#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using std::cout;
using std::queue;
using std::stack;
using std::string;
using std::vector;

void printPermutation(const vector<unsigned> &permutation) {
    for (const unsigned value : permutation) {
        cout << value << ' ';
    }
    cout << '\n';
}

void printPermutationsRecursive(const vector<unsigned> &values, vector<unsigned> &permutation) {
    for (const unsigned value : values) {
        permutation.push_back(value);

        if (permutation.size() == values.size()) {
            printPermutation(permutation);
        } else {
            printPermutationsRecursive(values, permutation);
        }

        permutation.pop_back();
    }
}

void printPermutationsRecursive(const vector<unsigned> &values) {
    vector<unsigned> permutation;
    printPermutationsRecursive(values, permutation);
}

void printPermutations(const vector<unsigned> &values) {
    vector<unsigned> permutation;
    stack<unsigned> backtrack;

    for (unsigned currentValueIndex = 0; currentValueIndex < values.size();) {
        permutation.push_back(values[currentValueIndex]);
        backtrack.push(currentValueIndex);
        currentValueIndex = 0;

        while (!backtrack.empty()) {
            if (permutation.size() == values.size()) {
                printPermutation(permutation);

                do {
                    permutation.pop_back();
                    currentValueIndex = backtrack.top() + 1;
                    backtrack.pop();
                } while (currentValueIndex == values.size() && !backtrack.empty());
            } else {
                permutation.push_back(values[currentValueIndex]);
                backtrack.push(currentValueIndex);
                currentValueIndex = 0;
            }
        }
    }
}

int main() {
    printPermutations({1, 2, 3});
    return 0;
}
