#include <iostream>

using namespace std;

int main(){

	int input;
	srand(time (NULL));

	do{

		input = (rand()%17) + 1;
	}while (input == 3 || input == 11 || input == 16 || input == 14 || input == 8 || input == 7 || input == 10 || input == 4 
		     || input == 2 || input == 1 || input == 15);

	cout << "Questao a responder: " << input << endl;

	return 0;
}