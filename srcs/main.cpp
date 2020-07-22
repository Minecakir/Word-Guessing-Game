#include <iostream>
#include "Words.h"
using namespace std;
int main()
{
	srand(time(NULL));

	Words obj2;
	obj2.playGame();//Call playgame() function.

	cout << endl;
	system("pause");
	return 0;
}