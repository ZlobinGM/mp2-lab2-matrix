#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(10);
	m[1] = 1;
	TMatrix<int> copy(m);

	EXPECT_EQ(m, copy);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(10);
	m[0][0] = 1;
	TMatrix<int> copy(m);
	copy[0][0] = 2;

	EXPECT_NE(m[0][0], copy[0][0]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(4);

	EXPECT_EQ(4, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(4);
	m[0][0] = 4;

	EXPECT_EQ(4, m[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(4);

	ASSERT_ANY_THROW(m[-1][-1]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(4);

	ASSERT_ANY_THROW(m[8][8]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(9);

	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m1(9), m2(9);
	m1[3][3] = 3;
	m2 = m1;

	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m1(2 * 9), m2(9);
	m2 = m1;

	EXPECT_EQ(m1.GetSize(), m2.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m1(2 * 9), m2(9);
	m1[3][3] = 3;
	m2 = m1;

	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m1(9), m2(9);

	EXPECT_EQ(true, m1 == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(9);

	EXPECT_EQ(true, m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m1(2 * 9), m2(9);

	EXPECT_NE(m1, m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m1(3), m2(3), m3(3);
	m1[1] = m1[1] + 3;
	m2[1] = m2[1] + 4;
	m3[1] = m3[1] + 7;

	EXPECT_EQ(m1 + m2, m3);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m1(3), m2(6);

	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m1(3), m2(3), m3(3);
	m1[1] = m1[1] + 11;
	m2[1] = m2[1] + 4;
	m3[1] = m3[1] + 7;

	EXPECT_EQ(m1 - m2, m3);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m1(3), m2(6);

	ASSERT_ANY_THROW(m1 - m2);
}

