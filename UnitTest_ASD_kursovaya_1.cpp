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
			string stroka = "8 + 9(*";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of application *", error.what());
			}
			stroka = "\0";
			stroka = "(+8 + 9";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of application +", error.what());
			}
			stroka = "\0";
			stroka = "8 + 9(-";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of application -", error.what());
			}
			stroka = "\0";
			stroka = "(/ 8 + 9";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of application /", error.what());
			}
			
			stroka = "\0";
			stroka = "8 + 9^)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of application ^", error.what());
			}
			stroka = "\0";
			stroka = "aoc(-4)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of the abs function", error.what());
			}
			stroka = "\0";
			stroka = "son(-4)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of the sin or sqrt function", error.what());
			}
			stroka = "\0";
			stroka = "socu(4)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of the sin or sqrt function", error.what());
			}
			stroka = "\0";
			stroka = "cin(-4)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of the cos or ctg function", error.what());
			}
			stroka = "\0";
			stroka = "cos4)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of arithmetics the cos or ctg function", error.what());
			}
			stroka = "\0";
			stroka = "ctg4)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of arithmetics the cos or ctg function", error.what());
			}
			stroka = "\0";
			stroka = "lon(10)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of the log or ln function", error.what());
			}
			stroka = "\0";
			stroka = "log10)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect arithmetics the log function", error.what());
			}
			stroka = "\0";
			stroka = "ln-e)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect arithmetics the ln function", error.what());
			}
			stroka = "\0";
			stroka = "ta(-4)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of the tg function", error.what());
			}
			stroka = "\0";
			stroka = "tg45)";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect arithmetics the tg function", error.what());
			}
			stroka = "\0";
			stroka = "pa";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect input of the pi const", error.what());
			}
			stroka = "\0";
			stroka = "e3";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Incorrect arithmetics the e const", error.what());
			}
			stroka = "\0";
			stroka = "8!";
			try {
				check_for_correct_input(stroka);
			}
			catch (std::invalid_argument error) {
				Assert::AreEqual("Invalid character. The calculator can use numbers like double, brackets, actions: +, -, *, /, ^ and functions: sin(), cos(), tg(), ctg(), sqrt(), log(), ln(), abs()", error.what());
			}
		}
		TEST_METHOD(TesthasPrecedence)
		{
			string stroka = "\0";
			stroka = "-";
			Assert::IsTrue(hasPrecedence(stroka) == 1);

			stroka = "\0";
			stroka = "+";
			Assert::IsTrue(hasPrecedence(stroka) == 1);

			stroka = "\0";
			stroka="*";
			Assert::IsTrue(hasPrecedence(stroka) == 2);

			stroka = "\0";
			stroka = "/";
			Assert::IsTrue(hasPrecedence(stroka) == 2);
			
			stroka = "\0";
			stroka = "^";
			Assert::IsTrue(hasPrecedence(stroka) == 3);

			stroka = "\0";
			stroka = "sin";
			Assert::IsTrue(hasPrecedence(stroka) == 4);

			stroka = "\0";
			stroka = "cos";
			Assert::IsTrue(hasPrecedence(stroka) == 4);

			stroka = "\0";
			stroka = "sqrt";
			Assert::IsTrue(hasPrecedence(stroka) == 4);

			stroka = "\0";
			stroka = "tg";
			Assert::IsTrue(hasPrecedence(stroka) == 4);

			stroka = "\0";
			stroka = "ctg";
			Assert::IsTrue(hasPrecedence(stroka) == 4);

			stroka = "\0";
			stroka = "abs";
			Assert::IsTrue(hasPrecedence(stroka) == 4);

			stroka = "\0";
			stroka = "log";
			Assert::IsTrue(hasPrecedence(stroka) == 4);

			stroka = "\0";
			stroka = "ln";
			Assert::IsTrue(hasPrecedence(stroka) == 4);
		}
		TEST_METHOD(Testpostfix)
		{
			string stroka("sin(30) + 3 * 4");
			string postcheck = postfix(stroka);
			string check("30 sin 3 4 * +");
			Assert::IsTrue(check == postcheck);
		}

		TEST_METHOD(Testcalculate)
		{
			string stroka("0.5 3 4 * +");
			double check = 12.5;
			Assert::IsTrue(check == calculate(stroka));
		}
	};
}