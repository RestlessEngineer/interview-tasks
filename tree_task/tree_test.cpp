#include <gtest/gtest.h>
#include "tree.h"

TEST(SimpleTreeTest, LeftNode) {
    auto head = make_shared<Tree<char>>('A');
    head->left = make_shared<Tree<char>>('B');
    head->right = make_shared<Tree<char>>('C');
    set<char> bunch = {'B'};
    auto [res, res_set] = find_common_head_for_set(head, bunch);
    EXPECT_EQ(head->left, res);
}

TEST(SimpleTreeTest, RightNode) {
    auto head = make_shared<Tree<char>>('A');
    head->left = make_shared<Tree<char>>('B');
    head->right = make_shared<Tree<char>>('C');
    set<char> bunch = {'C'};
    auto [res, res_set] = find_common_head_for_set(head, bunch);
    EXPECT_EQ(head->right, res);
}

TEST(SimpleTreeTest, CoreNode) {
    auto head = make_shared<Tree<char>>('A');
    head->left = make_shared<Tree<char>>('B');
    head->right = make_shared<Tree<char>>('C');
    set<char> bunch = {'A'};
    auto [res, res_set] = find_common_head_for_set(head, bunch);
    EXPECT_EQ(head, res);
}

TEST(SimpleTreeTest, TwoNodes) {
    auto head = make_shared<Tree<char>>('A');
    head->left = make_shared<Tree<char>>('B');
    head->right = make_shared<Tree<char>>('C');

    set<char> bunch = {'B','A','C'};
    auto [res, res_set] = find_common_head_for_set(head, bunch);
    EXPECT_EQ(head, res);
}

TEST(ComplexTreeTest, LeftSubtree) {
    auto head = make_shared<Tree<char>>('A');
    head->left = make_shared<Tree<char>>('B');
    head->right = make_shared<Tree<char>>('C');
    head->left->left = make_shared<Tree<char>>('B');
    head->left->right = make_shared<Tree<char>>('C');
    set<char> bunch = {'B','C'};
    auto [res, res_set] = find_common_head_for_set(head, bunch);
    EXPECT_EQ(head->left, res);
}

TEST(ComplexTreeTest, LeftSubSubtree) {
    auto head = make_shared<Tree<char>>('A');
    head->left = make_shared<Tree<char>>('A');
    head->left->left = make_shared<Tree<char>>('A');
    head->left->left->left = make_shared<Tree<char>>('A');
    head->left->left->left->left = make_shared<Tree<char>>('A');

    set<char> bunch = {'A'};
    auto [res, res_set] = find_common_head_for_set(head, bunch);
    EXPECT_EQ(head->left->left->left->left, res);
}

TEST(ComplexTreeTest, LeftSubTreeTwoNodes) {
    auto head = make_shared<Tree<char>>('A');
    head->left = make_shared<Tree<char>>('A');
    head->left->left = make_shared<Tree<char>>('A');
    head->left->right = make_shared<Tree<char>>('B');
    head->left->left->left = make_shared<Tree<char>>('A');
    head->left->left->left->left = make_shared<Tree<char>>('A');
    head->left->right->right = make_shared<Tree<char>>('C');
    set<char> bunch = {'C', 'B'};
    auto [res, res_set] = find_common_head_for_set(head, bunch);
    EXPECT_EQ(head->left->right, res);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
