#include "tree.h"

int main(int argc, char *argv[])
{
    auto head = make_shared<Tree<char>>('A');
    
    head->left = make_shared<Tree<char>>('B');
    head->right = make_shared<Tree<char>>('C');
    
    head->left->left = make_shared<Tree<char>>('E');
    head->left->right = make_shared<Tree<char>>('E');
    
    head->left->right->left = make_shared<Tree<char>>('K');
    head->left->right->right = make_shared<Tree<char>>('K');
    
    head->right->left = make_shared<Tree<char>>('C');
    head->right->right = make_shared<Tree<char>>('K'); 
    set<char> bunch = {'K','E'};
    auto [res, res_set] = find_common_head_for_set(head, bunch);
    cout<<"res val = " << (res == head->left->right)<<endl; 

    return 0;
}
