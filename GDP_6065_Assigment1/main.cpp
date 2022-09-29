//Including an external file

#include <gtest/gtest.h>
#include <iostream>
#include <MyBlackBox.h>

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

int Factorial(int a) {
	if (a == 1)
		return 1;

	return a * Factorial(a - 1);
}

glm::vec3 MyScaledVector(const glm::vec3 vec, float scalar)
{
	glm::vec3 newVector;
	newVector.x = vec.x * scalar;
	newVector.y = vec.y * scalar;
	newVector.z = vec.z * scalar;
	return newVector;
}

float MyMagnitude(glm::vec3& vec) {
	return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

glm::vec3 MyNormalize(glm::vec3 vec) {
	float m = (int)MyMagnitude(vec);
	glm::vec3 newVector;
	newVector.x = vec.x / m;
	newVector.y = vec.y / m;
	newVector.z = vec.z / m;
	return newVector;
}


glm::vec3 MyInverse(glm::vec3 vec) {
	return glm::vec3(vec.x, vec.y, vec.z) * -1.f;
}

// WHITE BOX TESTING
TEST(FactorialTests, Factorial) {
	printf("\n(Whitebox) Factorial GOOGLE TEST: \n\n");
	EXPECT_EQ(120, Factorial(5));
	EXPECT_EQ(720, Factorial(6));
	EXPECT_EQ(24, Factorial(4));
}
TEST(InverseTests, MyInverse) {
	printf("\n(Whitebox) MyInverse GOOGLE TEST: \n\n");
	glm::vec3 testVec;
	testVec.x = 1;
	testVec.y = 1;
	testVec.z = 1;
	EXPECT_EQ(glm::vec3(-1, -1, -1), MyInverse(testVec));
}

TEST(MagnitudeTests, MyMagnitude) {
	printf("\n(Whitebox) MyMagnitude GOOGLE TEST: \n\n");
	glm::vec3 testVec;
	testVec.x = 1;
	testVec.y = 1;
	testVec.z = 1;
	EXPECT_EQ(1, (int)MyMagnitude(testVec));
}

TEST(NormalizeTests, MyNormalize) {
	printf("\n(Whitebox) MyNormalize GOOGLE TEST: \n\n");
	glm::vec3 testVec;
	testVec.x = 1;
	testVec.y = 1;
	testVec.z = 1;
	EXPECT_EQ(glm::vec3(1, 1, 1), MyNormalize(testVec));
}

TEST(ScaledVectorTests, MyScaledVector) {
	printf("\n(Whitebox) MyScaledVector GOOGLE TEST: \n\n");
	glm::vec3 testVec;
	testVec.x = 1;
	testVec.y = 2;
	testVec.z = 3;
	EXPECT_EQ(glm::vec3(2, 4, 6), MyScaledVector(testVec, 2));
}


//BLACK BOX TESTING
TEST(CPFTests1, CPFSizeTest) {
	printf("\n(Blackbox) CPF size test GOOGLE TEST: \n\n");
	EXPECT_TRUE(CPFSizeTest("40038621800"));
	EXPECT_FALSE(CPFSizeTest("400.386.218-00"));
	EXPECT_FALSE(CPFSizeTest("40012338621800"));
}

TEST(CPFTests2, CPFNumberTest) {
	printf("\n(Blackbox) CPF number test GOOGLE TEST: \n\n");
	EXPECT_TRUE(CPFNumberTest("40038621800"));
	EXPECT_FALSE(CPFNumberTest("400.386.218-00"));
	EXPECT_FALSE(CPFNumberTest("Bruno4008621800"));
}

TEST(CPFTests3, CPFOrigin) {
	printf("\n(Blackbox) CPF origin test GOOGLE TEST: \n\n");
	EXPECT_EQ("SP", CPFOrigin("40038621800"));
	EXPECT_EQ("PR-SC", CPFOrigin("40038621900"));
	EXPECT_EQ("RS", CPFOrigin("40038621000"));
}

TEST(FibonacciTests, Fibonacci) {
	printf("\n(Blackbox) Fibonacci GOOGLE TEST: \n\n");
	EXPECT_EQ(5, Fibonacci(5));
	EXPECT_EQ(8, Fibonacci(6));
	EXPECT_EQ(13, Fibonacci(7));
}

TEST(RandomTest, MyRandom) {
	printf("\n(Blackbox) MyRandom GOOGLE TEST: \n\n");
	float min = 5.0f;
	float max = 1500.6f;
	EXPECT_LE(min, MyRandom(min, max));
	EXPECT_GE(max, MyRandom(min, max));
}

// Main entry point to our program
int main(int argc, char** argv) {

	::testing::InitGoogleTest(&argc, argv);

	int result = RUN_ALL_TESTS();

	return result;
}