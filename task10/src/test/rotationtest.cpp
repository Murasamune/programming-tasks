#include "../myproject/gvec_rotate.h"
#include <gtest/gtest.h>

std::vector<std::vector<int>> vec = {{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15}};
std::vector<std::vector<int>> rotate90_ans = {{13,10,7,4,1},{14,11,8,5,2},{15,12,9,6,3}};
std::vector<std::vector<int>> rotate180_ans = {{15,14,13},{12,11,10},{9,8,7},{6,5,4},{3,2,1}};
std::vector<std::vector<int>> rotate270_ans = {{3,6,9,12,15},{2,5,8,11,14},{1,4,7,10,13}};
std::vector<std::vector<int>> rotate360_ans = {{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15}};

TEST(rotate_90, wrong_result){
    EXPECT_EQ(vecRotate<int>(vec, 90), rotate90_ans);
    EXPECT_EQ(vecRotate<int>(vec, 90), rotate180_ans);
    EXPECT_EQ(vecRotate<int>(vec, 90), rotate270_ans);
    EXPECT_EQ(vecRotate<int>(vec, 90), rotate360_ans);
}
TEST(rotate_180, wrong_result){
    EXPECT_EQ(vecRotate<int>(vec, 180), rotate180_ans);
    EXPECT_EQ(vecRotate<int>(vec, 180), rotate360_ans);
}
TEST(rotate_270, wrong_result){
    EXPECT_EQ(vecRotate<int>(vec, 270), rotate270_ans);
    EXPECT_EQ(vecRotate<int>(vec, 270), rotate180_ans);
    EXPECT_EQ(vecRotate<int>(vec, 270), rotate90_ans);
    EXPECT_EQ(vecRotate<int>(vec, 270), rotate360_ans);
}
TEST(rotate_360, wrong_result){
    EXPECT_EQ(vecRotate<int>(vec, 360), rotate360_ans);
}
TEST(rotate_50, rotation_false){
    EXPECT_EQ(vecRotate<int>(vec, 50), vec);
}
