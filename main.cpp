#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
class Generator
{
	public:
		Generator(short int incount, string incharset);
	private:
		short int count;
		short int current;
		short int *counter;
		string charset;
		void nest();
};
int main(int argc, char* argv[])
{
	short int min, max;
	if(argc != 4 || !(stringstream(argv[1]) >> min) || !(stringstream(argv[2]) >> max) || !sizeof(argv[3])) {
		cout << "Usage: ./gen {min} {max} {charset}\n";
		exit(1);
	}
	for(int i = min; i <= max; i++)
		Generator gen(i, argv[3]);
	return 0;
}
Generator::Generator(short int incount, string incharset) {
	count = incount;
	charset = incharset;
	current = 0;
	counter = new short int[count];
	nest();
}
void Generator::nest() {
	short int index = 0;
	while(index < charset.length()) {
		if(current == count-1) {
			string buffer;
			for(int i = 0; i < count; i++)
				buffer += charset[counter[i]];
			cout << buffer << "\n";
		} else {
			current++;
			nest();
			current--;
		}
		counter[current]++;
		index++;
	}
	counter[current] = 0;
}