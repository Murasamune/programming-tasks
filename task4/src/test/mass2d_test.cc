#include "gtest/gtest.h"
#include <../myproject/mass2d.h>

struct arith_param{
    Mass2D<double> arith1;
    Mass2D<double> arith2; 
    Mass2D<double> resultA;
};
struct logic_param{
    Mass2D<bool> logic1;
    Mass2D<bool> logic2;
    Mass2D<bool> resultL;
};

double arr1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
double arr2[9] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
bool arr3[9] = {0, 1, 1, 0, 0, 1, 0, 1, 1};
bool arr4[9] = {1, 0, 1, 0, 1, 0, 1, 0, 1};

class mass2d_test_sum: public ::testing::TestWithParam<arith_param>{};
class mass2d_test_diff: public ::testing::TestWithParam<arith_param>{};
class mass2d_test_prod: public ::testing::TestWithParam<arith_param>{};
class mass2d_test_quot: public ::testing::TestWithParam<arith_param>{};

class mass2d_test_AND: public ::testing::TestWithParam<logic_param>{};
class mass2d_test_OR: public ::testing::TestWithParam<logic_param>{};
class mass2d_test_NOT: public ::testing::TestWithParam<logic_param>{};

Mass2D<double> mass2d_obj_arith1(3, 3, arr1);
Mass2D<double> mass2d_obj_arith2(3, 3, arr2);
Mass2D<bool> mass2d_obj_logic1(3, 3, arr3);
Mass2D<bool> mass2d_obj_logic2(3, 3, arr4);

//sum
TEST_P(mass2d_test_sum, plswork){
    const arith_param &param = GetParam();
    Mass2D<double> res = param.arith1 + param.arith2;
    for(int i = 0; i < param.arith1.getRows(); i++){
        for (int j = 0; j < param.arith1.getColomns(); j++){
            EXPECT_EQ(res(i, j), param.resultA(i, j));
        }
    }
};

double arr_sum_res[9] = {3, 4, 5, 6, 7, 8, 9, 10, 11};
Mass2D<double> mass2d_obj_resultA_sum(3, 3, arr_sum_res);

INSTANTIATE_TEST_CASE_P(
    _,
    mass2d_test_sum,
    ::testing::Values(
        arith_param{mass2d_obj_arith1, mass2d_obj_arith2, mass2d_obj_resultA_sum}
    )
);

//diff
TEST_P(mass2d_test_diff, plswork){
    const arith_param &param = GetParam();
    Mass2D<double> res = param.arith1 - param.arith2;
    for(int i = 0; i < param.arith1.getRows(); i++){
        for (int j = 0; j < param.arith1.getColomns(); j++){
            EXPECT_EQ(res(i, j), param.resultA(i, j));
        }
    }
};

double arr_diff_res[9] = {-1, 0, 1, 2, 3, 4, 5, 6, 7};
Mass2D<double> mass2d_obj_resultA_diff(3, 3, arr_diff_res);

INSTANTIATE_TEST_CASE_P(
    _,
    mass2d_test_diff,
    ::testing::Values(
        arith_param{mass2d_obj_arith1, mass2d_obj_arith2, mass2d_obj_resultA_diff}
    )
);

//prod
TEST_P(mass2d_test_prod, plswork){
    const arith_param &param = GetParam();
    Mass2D<double> res = param.arith1 - param.arith2;
    for(int i = 0; i < param.arith1.getRows(); i++){
        for (int j = 0; j < param.arith1.getColomns(); j++){
            EXPECT_EQ(res(i, j), param.resultA(i, j));
        }
    }
};

double arr_prod_res[9] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
Mass2D<double> mass2d_obj_resultA_prod(3, 3, arr_prod_res);

INSTANTIATE_TEST_CASE_P(
    _,
    mass2d_test_prod,
    ::testing::Values(
        arith_param{mass2d_obj_arith1, mass2d_obj_arith2, mass2d_obj_resultA_prod}
    )
);

//quot
TEST_P(mass2d_test_quot, plswork){
    const arith_param &param = GetParam();
    Mass2D<double> res = param.arith1 - param.arith2;
    for(int i = 0; i < param.arith1.getRows(); i++){
        for (int j = 0; j < param.arith1.getColomns(); j++){
            EXPECT_EQ(res(i, j), param.resultA(i, j));
        }
    }
};

double arr_quot_res[9] = {0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5};
Mass2D<double> mass2d_obj_resultA_quot(3, 3, arr_quot_res);

INSTANTIATE_TEST_CASE_P(
    _,
    mass2d_test_quot,
    ::testing::Values(
        arith_param{mass2d_obj_arith1, mass2d_obj_arith2, mass2d_obj_resultA_quot}
    )
);

//AND
TEST_P(mass2d_test_AND, plswork){
    const logic_param &param = GetParam();
    Mass2D<bool> res = param.logic1 && param.logic2;
    for(int i = 0; i < param.logic1.getRows(); i++){
        for (int j = 0; j < param.logic1.getColomns(); j++){
            EXPECT_EQ(res(i, j), param.resultL(i, j));
        }
    }
};

bool arr_AND_res[9] = {0, 0, 1, 0, 0, 0, 0, 0, 1};
Mass2D<bool> mass2d_obj_resultL_AND(3, 3, arr_AND_res);

INSTANTIATE_TEST_CASE_P(
    _,
    mass2d_test_AND,
    ::testing::Values(
        logic_param{mass2d_obj_logic1, mass2d_obj_logic2, mass2d_obj_resultL_AND}
    )
);

//OR
TEST_P(mass2d_test_OR, plswork){
    const logic_param &param = GetParam();
    Mass2D<bool> res = param.logic1 || param.logic2;
    for(int i = 0; i < param.logic1.getRows(); i++){
        for (int j = 0; j < param.logic1.getColomns(); j++){
            EXPECT_EQ(res(i, j), param.resultL(i, j));
        }
    }
};

bool arr_OR_res[9] = {1, 1, 1, 0, 1, 1, 1, 1, 1};
Mass2D<bool> mass2d_obj_resultL_OR(3, 3, arr_OR_res);

INSTANTIATE_TEST_CASE_P(
    _,
    mass2d_test_OR,
    ::testing::Values(
        logic_param{mass2d_obj_logic1, mass2d_obj_logic2, mass2d_obj_resultL_OR}
    )
);

//NOT
TEST_P(mass2d_test_NOT, plswork){
    const logic_param &param = GetParam();
    Mass2D<bool> res = !param.logic1;
    for(int i = 0; i < param.logic1.getRows(); i++){
        for (int j = 0; j < param.logic1.getColomns(); j++){
            EXPECT_EQ(res(i, j), param.resultL(i, j));
        }
    }
};

bool arr_NOT_res[9] = {1, 0, 0, 1, 1, 0, 1, 0, 0};
Mass2D<bool> mass2d_obj_resultL_NOT(3, 3, arr_NOT_res);

INSTANTIATE_TEST_CASE_P(
    _,
    mass2d_test_NOT,
    ::testing::Values(
        logic_param{mass2d_obj_logic1, mass2d_obj_logic2, mass2d_obj_resultL_NOT}
    )
);
