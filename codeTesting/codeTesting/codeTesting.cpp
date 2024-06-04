// Online C++ compiler to run C++ program online
#include <iostream>
#include<assert.h>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;



//int getPrecisionIntFromDouble(double precisionVal)
//{
//	int precisionCount = 0;
//	if (precisionVal < 0)
//		precisionVal = std::abs(precisionVal);
//
//	auto fractionalPart = precisionVal - std::floor(precisionVal);
//	if (fractionalPart < 1e-8)
//	{
//		return precisionCount;
//	}
//	double scalingFactor = 10.0;
//
//	double tolerance = std::numeric_limits<double>::epsilon()/*10e-16*/ * fractionalPart;
//
//	auto diff = (1 - tolerance);
//
//	while ((fractionalPart > tolerance /*&& fractionalPart < (1 - tolerance)*/) && precisionCount < std::numeric_limits<double>::max_digits10)
//	{
//		//auto diff = (1 - tolerance);
//		fractionalPart = precisionVal * scalingFactor;
//
//		fractionalPart = fractionalPart - std::floor(fractionalPart);
//
//		scalingFactor *= 10.0;
//
//		tolerance = std::numeric_limits<double>::epsilon()/*1e-16*/ * precisionVal * scalingFactor;
//
//		precisionCount++;
//	}
//
//	return precisionCount;
//}
int GetPrecisionIntFromDouble(double precisionVal)
{
	int precisionCount = 0;
	if (precisionVal < 0)
		precisionVal = std::abs(precisionVal);

	auto fractionalPart = precisionVal - std::floor(precisionVal);
	if (fractionalPart < 1e-8)
	{
		return precisionCount;
	}

	double scalingFactor = 10.0;
	double tol = 1e-16;

	double varialbeTol = tol * fractionalPart;

	// If number of digits after decimal point in precisionVal is greater than 8, we limit it to 8.
	// e.g. if precisionVal is 0.423425252664, for this case actual precision is 12
	// but we have limited it to 8.
	while ((fractionalPart > varialbeTol) && (precisionCount < 8))
	{
		fractionalPart = precisionVal * scalingFactor;

		fractionalPart = fractionalPart - std::floor(fractionalPart);

		scalingFactor *= 10.0;

		varialbeTol = tol * precisionVal * scalingFactor;

		precisionCount++;
	}

	return precisionCount;
}


//int getPrecisionIntFromDouble(double precisionVal)
//{
//	int count = 0;
//	while (fabs(precisionVal - (int)(precisionVal)) >1e-8)
//	{
//		precisionVal *= 10;
//		++count;
//	}
//
//	return count;
//}

void TestPrecisionIntFromDouble()
{
	//// Test Case 1: Testing a double value representing 0.0
	////////assert(getPrecisionIntFromDouble(0.0) == 0);
	//cout << GetPrecisionIntFromDouble(0.0) << endl;

	//// Test Case 2: Testing a double value representing a whole number (123.0)
	////assert(getPrecisionIntFromDouble(123.0) == 0); 
	//cout << GetPrecisionIntFromDouble(123.0) << endl;

	//// Test Case 3: Testing a double value with precision (123.456)
	////assert(getPrecisionIntFromDouble(123.456) == 3);
	//cout << GetPrecisionIntFromDouble(123.456) << endl;

	//// Test Case 4: Testing a negative double value with precision (-123.456)
	////assert(getPrecisionIntFromDouble(-123.456) == 3); 
	//cout << GetPrecisionIntFromDouble(-123.456) << endl;

	//// Test Case 5: Testing a very small double value (0.00000000012)
	////assert(getPrecisionIntFromDouble(0.00000000012) == 0); 
	//cout << GetPrecisionIntFromDouble(0.00000000012) << endl;

	//// Test Case 6: Testing a double value with large precision (123456789.012345)
	////assert(getPrecisionIntFromDouble(123456789.012345) == 6); 
	//cout << GetPrecisionIntFromDouble(123456789.012345) << endl;

	//// Test Case 7: Testing a very large double value (1.0e20)
	////assert(getPrecisionIntFromDouble(1.0e20) == 0); 
	//cout << GetPrecisionIntFromDouble(1.0e20) << endl;

	//// Test Case 8: Testing a double value with decimal precision (1.1)
	////assert(getPrecisionIntFromDouble(1.1) == 1); 
	//cout << GetPrecisionIntFromDouble(1.1) << endl;

	//// Test Case 9: Testing a negative integer value (-2323000)
	////assert(getPrecisionIntFromDouble(-2323000) == 0);
	//cout << GetPrecisionIntFromDouble(-2323000) << endl;

	//// Test Case 10: Testing a double value with precision (100.0001)
	////assert(getPrecisionIntFromDouble(100.0001) == 4); 
	//cout << GetPrecisionIntFromDouble(100.0001) << endl;

	//cout << GetPrecisionIntFromDouble(25.252525257) << endl;


	//// Test Case 11: Testing a negative double value with precision (-2134.252525255)
	////assert(getPrecisionIntFromDouble(-123.456) == 9); 
	//cout << GetPrecisionIntFromDouble(12345.6789123456789) << endl;
	//cout << GetPrecisionIntFromDouble(0.9999999999999999) << endl;
	//cout << GetPrecisionIntFromDouble(0.1234567890123456) << endl;

	//cout << GetPrecisionIntFromDouble(62.230000000248829) << endl;
	//
	//
	////cout << getPrecisionIntFromDouble(0.1234567890123456) << endl;

	cout << GetPrecisionIntFromDouble(0.0) << endl;
	cout << GetPrecisionIntFromDouble(123.456) << endl;
	cout << GetPrecisionIntFromDouble(-2323000) << endl;
	cout << GetPrecisionIntFromDouble(0.00000000012) << endl;
	cout << GetPrecisionIntFromDouble(100.0001) << endl;
	cout << GetPrecisionIntFromDouble(0.00000001) << endl;
	cout << GetPrecisionIntFromDouble(0.000001) << endl;
	cout << GetPrecisionIntFromDouble(-2134.25252525) << endl;
	cout << GetPrecisionIntFromDouble(43.53536367748848) << endl;




}

int main() {

	TestPrecisionIntFromDouble();



	return 0;
}











