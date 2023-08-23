#include <iostream>
#include <set>
#include <memory>
#include <algorithm>
#include <string>
#include <tuple>
#include <cmath>
using namespace std;

template <typename T>
struct Tree
{
    T val_;
    Tree(T val) : val_(val) {}

    shared_ptr<Tree<T>> left = nullptr;
    shared_ptr<Tree<T>> right = nullptr;
};

template <typename T>
tuple<shared_ptr<Tree<T>>, set<T>> find_common_head_for_set(const shared_ptr<Tree<T>>& head, const set<T> &key_set)
{
    if (head == nullptr)
        return {head, {}};
    
    auto [left, left_set] = find_common_head_for_set(head->left, key_set);
    auto [right, right_set] = find_common_head_for_set(head->right, key_set);
    
    if(left != nullptr && right != nullptr){
        bool is_left_included = includes(left_set.begin(), left_set.end(), key_set.begin(), key_set.end());
        bool is_right_included = includes(right_set.begin(), right_set.end(), key_set.begin(), key_set.end());
        
        //if both subtrees has solution we must return the lowest one
        if(is_left_included && is_right_included){
            if(left_set.size() < right_set.size())
                return {left, left_set};
            else
                return {right, right_set};
        }
        else if(is_left_included)
            return {left, left_set};
        else if(is_right_included)
            return {right, right_set};

        //if solution doesn't exist we have to merge sets and head   
        left_set.insert(head->val_);
        left_set.insert(right_set.begin(), right_set.end());
        return {head, left_set};
    }
    else if(left != nullptr)
        //if left set contain key set we must return that
        if(includes(left_set.begin(), left_set.end(), key_set.begin(), key_set.end()))
            return {left, left_set};
        else{ // or to insert head node to set
            left_set.insert(head->val_);
            return {head, left_set};
        }
    else if(right != nullptr)
        //if right set contain key set we must return that
        if(includes(left_set.begin(), left_set.end(), key_set.begin(), key_set.end()))
            return {right, right_set};
        else{ // or to insert head node to set
            right_set.insert(head->val_);
            return {head, right_set};
        }

    //if two subtrees is empty we have to create new one with head's val within 
    set<T> current_set{head->val_};
    return {head, current_set};
}
