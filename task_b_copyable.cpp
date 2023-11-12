#include <iostream>

#include "bst_b_copyable.h"

using namespace std;
using namespace mff;

void print_tree(const Bst& tree) {
    for (auto&& x : tree.keys())
        cout << x << " ";
    cout << endl;
}

int main()
{
    Bst tree_old;
    Bst tree_old2(move(tree_old)); // OK
    // Move assignment
    Bst tree = move(tree_old2); // OK
    
     
    //
    // Building the tree
    //
    for (string line; cin >> line;) {
        if (line == "=end=") break;

        tree.insert(line);
    }

    
    cout << "`tree` before copy:" << endl;
    print_tree(tree);

    // Copy ctor
    Bst tree2(tree); // OK

    cout << "`tree` after copy:" << endl;
    print_tree(tree);
    cout << "`tree2` after copy:" << endl;
    print_tree(tree2);

    Bst tree3 = tree2; // OK

    cout << "`tree2` after copy=:" << endl;
    print_tree(tree2);
    cout << "`tree3` after copy=:" << endl;
    print_tree(tree3);

    // Hit CTRL+Z (Win), CTRL+D(Linux) in the terminal to send EOF and end this loop
    for (string line; cin >> line;) {
        optional<string> deleted = tree.erase(line);
        if (deleted) {
            cout << "D: " << deleted.value() << endl;
        }
    }

    for (auto&& x : tree2.keys())
        cout << x << " ";
    cout << endl;
}
