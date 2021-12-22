#include "pch.h"
#include "CppUnitTest.h"
#include "../ASD_kursovaya_1/ASD_kursovaya_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestASD_kursovaya_1
{
	TEST_CLASS(UnitTestASD_Kursovaya_1)
	{
	public:

		TEST_METHOD(Testcheck_for_correct_input)
		{
			string str = "8 + 9(*";
			try {
				check_for_correct_input(str);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of application *", error.what());
			}
			str = "\0";
			str = "(+8 + 9";
			try {
				check_for_correct_input(str);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of application +", error.what());
			}
			str = "\0";
			str = "8 + 9(-";
			try {
				check_for_correct_input(str);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of application -", error.what());
			}
			str = "\0";
			str = "(/ 8 + 9";
			try {
				check_for_correct_input(str);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of application /", error.what());
			}
			
			str = "\0";
			str = "8 + 9^)";
			try {
				check_for_correct_input(str);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of application ^", error.what());
			}
			str = "\0";
			str = "aoc(-4)";
			try {
				check_for_correct_input(str);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of the abs function", error.what());
			}
			str = "\0";
			str = "son(-4)";
			try {
				check_for_correct_input(str);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of the sin or sqrt function", error.what());
			}
			str = "\0";
			str = "socu(4)";
			try {
				check_for_correct_input(str);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of the sin or sqrt function", error.what());
			}
			str = "\0";
			str = "cin(-4)";
			try {
				check_for_correct_input(str);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of the cos or ctg function", error.what());
			}
			str = "\0";
			str = "cos4)";
			try {
				check_for_correct_input(str);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of arithmetics the cos or ctg function", error.what());
			}
			str = "\0";
			str = "ctg4)";
			try {
				check_for_correct_input(str);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of arithmetics the cos or ctg function", error.what());
			}
			str = "\0";
			str = "lon(10)";
			try {
				check_for_correct_input(str);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of the log or ln function", error.what());
			}
			str = "\0";
			str = "log10)";
			try {
				check_for_correct_input(str);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect arithmetics the log function", error.what());
			}
			str = "\0";
			str = "ln-e)";
			try {
				check_for_correct_input(str);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect arithmetics the ln function", error.what());
			}
			str = "\0";
			str = "ta(-4)";
			try {
				check_for_correct_input(str);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of the tg function", error.what());
			}
			str = "\0";
			str = "tg45)";
			try {
				check_for_correct_input(str);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect arithmetics the tg function", error.what());
			}
			str = "\0";
			str = "pa";
			try {
				check_for_correct_input(str);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of the pi const", error.what());
			}
			str = "\0";
			str = "e3";
			try {
				check_for_correct_input(str);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect arithmetics the e const", error.what());
			}
			str = "\0";
			str = "8!";
			try {
				check_for_correct_input(str);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Invalid character. The calculator can use numbers like double, brackets, actions: +, -, *, /, ^ and functions: sin(), cos(), tg(), ctg(), sqrt(), log(), ln(), abs()", error.what());
			}
		}
		TEST_METHOD(TesthasPrecedence)
		{
			string str = "\0";
			str = "-";
			Assert::IsTrue(hasPrecedence(str) == 1);

			str = "\0";
			str = "+";
			Assert::IsTrue(hasPrecedence(str) == 1);

			str = "\0";
			str="*";
			Assert::IsTrue(hasPrecedence(str) == 2);

			str = "\0";
			str = "/";
			Assert::IsTrue(hasPrecedence(str) == 2);
			
			str = "\0";
			str = "^";
			Assert::IsTrue(hasPrecedence(str) == 3);

			str = "\0";
			str = "sin";
			Assert::IsTrue(hasPrecedence(str) == 4);

			str = "\0";
			str = "cos";
			Assert::IsTrue(hasPrecedence(str) == 4);

			str = "\0";
			str = "sqrt";
			Assert::IsTrue(hasPrecedence(str) == 4);

			str = "\0";
			str = "tg";
			Assert::IsTrue(hasPrecedence(str) == 4);

			str = "\0";
			str = "ctg";
			Assert::IsTrue(hasPrecedence(str) == 4);

			str = "\0";
			str = "abs";
			Assert::IsTrue(hasPrecedence(str) == 4);

			str = "\0";
			str = "log";
			Assert::IsTrue(hasPrecedence(str) == 4);

			str = "\0";
			str = "ln";
			Assert::IsTrue(hasPrecedence(str) == 4);
		}
		TEST_METHOD(Testpostfix)
		{
			string str("sin(30) + 3 * 4");
			string postcheck = postfix(str);
			string check("30 sin 3 4 * +");
			Assert::IsTrue(check == postcheck);
		}

		TEST_METHOD(Testcalculate)
		{
			string str("0.5 3 4 * +");
			double check = 12.5;
			Assert::IsTrue(check == calculate(str));
		}
	};
}
