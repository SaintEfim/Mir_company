#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
class Cfraction
{
public:
	Cfraction()//default constructor
	{
		this->a = 0;
		this->numerator = 0;
		this->denominator = 0;
	};
	Cfraction(float a)//constructor that creates an object according to the passed data
	{
		this->a = a;
		this->numerator = chis(a);
		this->denominator = znam(a);
	}
	Cfraction(const Cfraction& object)//copy constructor
	{
		this->a = object.a;
		this->numerator = object.numerator;
		this->denominator = object.denominator;
		this->vivod = object.vivod;
		this->parity = object.parity;
	}
	~Cfraction()//destructor
	{
		vivod.clear();
		parity.clear();
	};
	friend void pluss(Cfraction& company);//a+b
	friend void minuss(Cfraction& company);//a-b
	friend void multiply(Cfraction& company);//a*b
	friend void division(Cfraction& company);//a:b
	friend void a_and_b_plus_equals(Cfraction& company);//a=a+b
	friend void a_and_b_minus_equals(Cfraction& company);//a=a-b
	friend void a_and_b_multiply(Cfraction& company);//a=a*b
	friend void a_and_b_division(Cfraction& company);//a=a:b
	friend void a_plusplus(Cfraction& company);//a++
	friend void a_minus(Cfraction& company);//a--
	friend void operator_double(Cfraction& company);//new a
	friend void equals_equals(Cfraction& company);//==
	friend void not_equals(Cfraction& company);//!=
	friend void smaller(Cfraction& company);//<
	friend void more(Cfraction& company);//>
	friend void smaller_equals(Cfraction& company);//<=
	friend void more_equals(Cfraction& company);//>=
	friend void print(Cfraction& company, ofstream& File);//>=
private:
	size_t count_digit(const float& value)
	{
		stringstream ss;
		string s;
		ss << value;
		ss >> s;
		auto ind = s.find('.');
		return s.size() - ind - 1;
	}//counting the number of digits after the decimal point
	float chis(float& z) { return (int)z; }  //finds the numerator    
	float znam(float& z) {
		int i = z;
		if (((z - floor(z)) * pow(10, count_digit(a)))) {
			return  ((z - floor(z)) * pow(10, count_digit(a)));
		}
		else
			return 1;

	}  //finds the denominator
	float a;
	float numerator;
	float denominator;
	vector <double> vivod;   //   writes down answers (+,-,*,/)
	vector <bool> parity;    //   writes logic responses
};
void pluss(Cfraction& company) { company.vivod.push_back(company.numerator + company.denominator); }//a+b
void minuss(Cfraction& company) { company.vivod.push_back(company.numerator - company.denominator); }//a-b
void multiply(Cfraction& company) { company.vivod.push_back(company.numerator * company.denominator); }//a*b
void division(Cfraction& company) { company.vivod.push_back(company.numerator / company.denominator); }//a:b
void a_and_b_plus_equals(Cfraction& company) { company.vivod.push_back(company.numerator += company.denominator); }//a=a+b
void a_and_b_minus_equals(Cfraction& company) { company.vivod.push_back(company.numerator -= company.denominator); }//a=a-b
void a_and_b_multiply(Cfraction& company) { company.vivod.push_back(company.numerator *= company.denominator); }//a=a*b
void a_and_b_division(Cfraction& company) { company.vivod.push_back(company.numerator /= company.denominator); }//a=a:b
void a_plusplus(Cfraction& company) { company.vivod.push_back(++company.numerator); }//a++
void a_minus(Cfraction& company) { company.vivod.push_back(--company.numerator); }//a--
void operator_double(Cfraction& company) { company.a = company.numerator / company.denominator; }//new a
void equals_equals(Cfraction& company) { company.parity.push_back(company.numerator == company.denominator); }//==
void not_equals(Cfraction& company) { company.parity.push_back(company.numerator != company.denominator); }//!=
void smaller(Cfraction& company) { company.parity.push_back(company.numerator < company.denominator); }//<
void more(Cfraction& company) { company.parity.push_back(company.numerator > company.denominator); }//>
void smaller_equals(Cfraction& company) { company.parity.push_back(company.numerator <= company.denominator); }//<=
void more_equals(Cfraction& company) { company.parity.push_back(company.numerator >= company.denominator); }//>=
void print(Cfraction& company, ofstream& File) // recording in txt
{
	int i = 1;
	File << "new a=" << company.a << endl;
	File << "numerator:" << company.numerator << "\t" << "denominator:" << company.denominator << endl;
	for (auto const& a : company.vivod)
	{
		File << i << ")" << a << endl;
		i++;
	}
	for (auto const& a : company.parity)
	{
		File << i << ")" << a << endl;
		i++;
	}
}
int main()
{
	ofstream File; //for data storage
	Cfraction company;
	Cfraction copy(company); // copy data
	File.open("D:\\test.txt"); // txt for data storage
	float one, w = 0;
	while (w == 0) {
		cin >> one;
		system("cls");
		if (!cin.good()) {
			cin.clear();
			string ignore;
			cin >> ignore;
		}
		else {
			company = Cfraction(one);
			if (!File.is_open()) {
				cout << "Error!\n";
			}
			else {
				pluss(company);
				minuss(company);
				multiply(company);
				division(company);
				a_and_b_plus_equals(company);
				a_and_b_minus_equals(company);
				a_and_b_multiply(company);
				a_and_b_division(company);
				a_plusplus(company);
				a_minus(company);
				operator_double(company);
				equals_equals(company);
				not_equals(company);
				smaller(company);
				more(company);
				smaller_equals(company);
				more_equals(company);
				print(company, File);
				w++;
			}
		}
	}
	File.close();
	return 0;
}