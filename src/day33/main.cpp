#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

string encode(string p, int N, int k){
	char special[30] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '+', '-', '.', '~', '|', '<', '>', '=', '-', '_', '/', ':', ';', '?', '[', ']', '{', '}', '~', ' '};
	string out = "";

	for(int i = 0; i < N; i++){

		// Don't change special characters
		bool isSpecial = find(begin(special), end(special), p[i]) != end(special);
		if(isSpecial){
			out += p[i];
			continue;
		}

		// Shift plaintext
		char current = toupper(p[i]);
		out += ((current - 65 + k) % 26) + 65;
		
	}

	return out;
}

int main(){
	string plaintext;
	int key;

	cout << "Plaintext: ";
	getline(cin, plaintext);

	cout << "Key: ";
	cin >> key;

	string encoded = encode(plaintext, plaintext.length(), key);
	cout << encoded << endl;

	return 0;
}
