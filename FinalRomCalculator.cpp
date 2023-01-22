#include "dsettle.hh"
#include "dsettle.cc"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void ShowList();
bool checkNumber(string );
int ToIntegers(string );
int DoOperation(int int1, int int2, string oper);
string ToNumerals(int FI);

void sapphire()   {



	string RomanNumeral1;
	string RomanNumeral2;
	string Operation;
	string FinalNumeral;

	vector<string> num_opr;
	vector<int> nums;
	vector<string> oprs;

	int Integer1 = 0;
	int FinalInteger = 0;
	string brk="wegsgsgsgsgse";
	int bl=1;

	

	

	while (brk != "exit")   {

		while (bl)   {
			cout << "Enter Another Roman Numeral Value: ";
			cin >> RomanNumeral1;
			bl=checkNumber(RomanNumeral1);
		}

		bl=1;

		while (bl)   {
			cout << "Enter Operation or exit: ";
			cin >> Operation;
			bl=checkNumber(Operation);
		}

		if (Operation == "exit")   {
			brk="exit";
			num_opr.push_back(RomanNumeral1);
		}
		else   {
			num_opr.push_back(RomanNumeral1);
			num_opr.push_back(Operation);
		}
	}

	ShowList();

	for (int i=0; i<num_opr.size(); i=i+2)   {
		int uy=ToIntegers(num_opr[i]);
		nums.push_back(uy);
		if(i < num_opr.size()-1)
			oprs.push_back(num_opr[i+1]);
	}

	for (int i=0; i<nums.size()-1; i++)   {
		int x1=nums[i];
		string xx=oprs[i];
		int x2=nums[i+1];
		FinalInteger = DoOperation(x1, x2, xx);
		nums[i+1]=FinalInteger;
	}

	FinalNumeral = ToNumerals(FinalInteger);

	//cout << endl << endl << "Operation: Roman Numeral 1 (" << Integer1 << ") " << Operation << " Roman Numeral 2 (" << Integer2 << ")";
	cout << endl << "Answer: " << FinalNumeral <<endl;;


}

void ShowList()   {
cout << "I";
cout << setw(10) << "1";
cout << endl << "V";
cout << setw(10) << "5";
cout << endl << "X";
cout << setw(10) << "10";
cout << endl << "L";
cout << setw(10) << "50";
cout << endl << "C";
cout << setw(10) << "100";
cout << endl << "D";
cout << setw(10) << "500";
cout << endl << "M";
cout << setw(10) << "1000";
cout<<endl;
}

bool checkNumber(string numb)   { 
    vector<char> r_num(numb.begin(), numb.end());  //es stringi romelic funqcias gadaeca chavshale charebad.
    vector<char> buf;             
    vector<char> buff;
    int sy=1;

    for (int i = 0; i < r_num.size(); i++)   {
		if (r_num[i] == 'C' || r_num[i] == 'L' || r_num[i] == 'X' || r_num[i] == 'V' || r_num[i] == 'I' || r_num[i] == '+' || r_num[i] == '-' || r_num[i] == '*' || r_num[i] == '/')   {
			if (sy == 1)   // es nishnavs rom axal simboos amowmebs da axalze (davushvat xxxx-ze) rom gadava es sy daxvdeba 1 rac nishnavs rom axali simbolos shemowmeba daiwyo
				buff.push_back(r_num[i]);   //
			if (r_num[i] == r_num[i+1] && i != r_num.size()-2)   {//Tu foris is biji razec vart da shemdegi udris ertmanets, mashin 
				buf.push_back(r_num[i]);  // am veqtorshi vyri gameorebuls minus erti
				sy++;
			}  
			else   {
				if (buf.size() != 0)   {
					if  (buf[0] == 'C' && buf.size() > 3)   {
						cout<<"Incorretc Roman Symbol"<<endl;
						return 1;
					}
					if (buf[0] == 'L' || buf[0] == 'V' && buf.size() >= 1)   {
						cout<<"Incorretc Roman Symbol"<<endl;
						return 1;
					}
					if  (buf[0] == 'X' && buf.size() > 3)   {
						cout<<"Incorretc Roman Symbol"<<endl;
						return 1;
					}
					if  (buf[0] == 'I' && buf.size() > 2)   {
						cout<<"Incorretc Roman Symbol"<<endl;
						return 1;
					}
				}
				buf.resize(0);
				sy=1;
			}
		}
		else   {  // es else mushaobs im shemtxvevashi tu shevida sxva simbolo garda L, C ...
			cout<<"Incorretc Symbol"<<endl;
			return 1;
		}
	}


	for (int i=0; i<buff.size()-1; i++)   { // am buff-shi vyri simboloebs ar vitvaliswineb raodenobas da vyri tanmimdevrobit, dublirebebs moacilebs
		for (int j=i+1; j<buff.size(); j++)   {  // amit vamowmeb romelime elementze rom vdgevar mas shemdeg elementebis dalageba sworea tu ara.
			if (buff[i] == 'I' && (buff[j] == 'V' || buff[j] == 'X' || buff[j] == 'L' || buff[j] == 'C'))   {
				cout<<"Incorretc Roman Symbol"<<endl;
				return 1;
			}
			if (buff[i] == 'V' && (buff[j] == 'X' || buff[j] == 'L' || buff[j] == 'C'))   {
				cout<<"Incorretc Roman Symbol"<<endl;
				return 1;
			}
			if (buff[i] == 'X' && (buff[j] == 'L' || buff[j] == 'C'))   {
				cout<<"Incorretc Roman Symbol"<<endl;
				return 1;
			}
			if (buff[i] == 'L' && buff[j] == 'C')   {
				cout<<"Incorretc Roman Symbol"<<endl;
				return 1;
			}
		}
	}

	return 0;
}

int ToIntegers(string RN)   {
	// string numString=0;
	string numString="";
	int burp = RN.length();
	int numInt=0;

	if (RN != "exit")
		for(int i = 0; i < burp; i++)
		{
			numString = RN.substr(i, 1);
			if(numString == "M")
				numInt +=1000;
			else if(numString == "D")
				numInt +=500;
			else if(numString == "C")
				numInt +=100;
			else if(numString == "L")
				numInt +=50;
			else if(numString == "X")
				numInt +=10;
			else if(numString == "V")
				numInt +=5;
			else //(numString == "I")
				numInt +=1;
		}
	else 
		numString = RN;

	return numInt;
}

int DoOperation(int int1, int int2, string oper)   {
	int IntegerFinal;
	if(oper == "+")
		IntegerFinal = int1 + int2;
	else if(oper == "-")
		IntegerFinal = int1 - int2;
	else if(oper == "*")
		IntegerFinal = int1 * int2;
	else if(oper == "/")
		IntegerFinal = int1 / int2;

	else cout << "INVALID OPERATOR!";
	return IntegerFinal;
}

string ToNumerals(int FI)   {
	string NumeralFinal="";

	while( FI >= 1000)   {
		NumeralFinal += "M";
		FI -= 1000;
	}
	while(FI >= 500)   {
		NumeralFinal +="D";
		FI -= 500;
	}

	while( FI >= 100)   {
		NumeralFinal += "C";
		FI -= 100;
	}
	while( FI >= 50)   {
		NumeralFinal += "L";
		FI -= 50;
	}
	while( FI >= 10)   {
		NumeralFinal += "X";
		FI -= 10;
	}
	while( FI >= 5)   {
		NumeralFinal += "V";
		FI -= 5;
	}
	while( FI >= 1)   {
		NumeralFinal += "I";
		FI -= 1;
	}

	return NumeralFinal;
}
Shecvlili faili!!!
