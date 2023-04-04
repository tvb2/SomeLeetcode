#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <stdint.h>
#include <bits/stdc++.h>
#include <iterator>
#include <functional>
#include <stack>
#include <queue>
using namespace std;

/*
589. N-ary Tree Preorder Traversal
Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

The number of nodes in the tree is in the range [0, 104].
0 <= Node.val <= 104
The height of the n-ary tree is less than or equal to 1000.
*/

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

//recursive solution going through all children and recursively pushing back each element to result vector
void helper(Node* root, std::vector<int> &result){
    result.push_back(root->val);
    for (auto &it:root->children){
        helper(it, result);
    }
}

vector<int> preorder(Node* root) {
    std::vector<int> result;
    if (!root)
        return result;
    helper(root, result);
    return result;    
}

int main(){
    //[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
    Node* root = new Node(1);
    std::vector<Node*> vec;

    Node* a = new Node(14);
    vec.push_back(a);
    Node* x = new Node(11, vec);
    
    vec.clear();
    vec.push_back(x);
    Node* y = new Node(7, vec);

    vec.clear();
    Node* z = new Node(6, vec);
    vec.push_back(z);
    vec.push_back(y);

    Node* three = new Node(3, vec);

    


    std::vector<int> result = preorder(three);
    for (auto i:result)
        std::cout << i << "\n";
}