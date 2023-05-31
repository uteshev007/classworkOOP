#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <fstream>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

// ----------- Ш А Б Л О Н Ы     К Л А С С О В --------------

template <typename Type = int>
class TSample
{
private:
	Type data;

public: 
	TSample() : data() { /*data = 0;*/ }
	TSample(const Type& val) : data(val) { data = val; }
	Type GetData() const { return data; }
	void SetData(Type val) { data = val; }
	
	friend ostream& operator << (ostream& os, const TSample<Type> & obj)
	{
		os << "(Type = " << typeid(Type).name() << ") ";
		os << obj.GetData();
		return os;
	}

	friend istream& operator >> (istream& is, TSample<Type> & obj)
	{
		cout << "Type = " << typeid(obj.data).name() << endl;
		cout << "Enter Data: ";
		is >> obj.data;
		return is;
	}

	//TSample a,b 
	//a + b

	TSample<Type> operator + (const TSample<Type>& right) const
	{
		TSample<Type> result;
		result.data = this->data + right.data;
		return result;
	}

}; //TSample




int main()
{
	TSample<int> A;
	TSample<double> B;
	TSample<> C;
	TSample<string> D;
	cin >> A;
	cout << "A = " << A << endl;	

	cin >> B;
	cout << "B = " << B << endl;

	cin >> C;
	cout << "C = " << C << endl;

	cin >> D;
	cout << "D = " << D << endl;


}