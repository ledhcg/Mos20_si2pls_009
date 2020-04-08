#include <iostream>
using namespace std;
int main()
{
	char a;
	cin >> a;
	if (a == 'U' || a == 'u' || a == 'E' || a == 'e' || a == 'O' || a == 'o' || a == 'A' || a == 'a' || a == 'I' || a == 'i')
		cout << "Char is a vowel!";
	else
		cout << "Char is a consonal!";
	return 0;
}



