#include <map>
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;


/*
https://en.wikipedia.org/wiki/Morse_code#Representation,_timing,_and_speeds
Let 1 unit = 120 milliseconds
	so, dits last 120
		dahs last 360
		space between parts of one letter lasts 120
		space between letters of one word lasts 360
		space between words of one sentence last 840
*/


//SOUND FUNCTIONS
void dit() {
	Beep(440, 120);
}

void dah() {
	Beep(440, 360);
}
//

//CONVERSION FUNCTIONS
void letter(char letter) {

	//char is the letter, int is a 4-digit integer that tells us when to dit or dah
	map<char, string> codex;

	/*
	0	-	silence
	1	-	dit
	2	-	dah

	*/
	codex['a'] = "1200";
	codex['b'] = "2111";
	codex['c'] = "2121";
	codex['d'] = "2110";
	codex['e'] = "1000";
	codex['f'] = "1121";
	codex['g'] = "2210";
	codex['h'] = "1111";
	codex['i'] = "1100";
	codex['j'] = "1222";
	codex['k'] = "2120";
	codex['l'] = "1211";
	codex['m'] = "2200";
	codex['n'] = "2100";
	codex['o'] = "2220";
	codex['p'] = "1221";
	codex['q'] = "2212";
	codex['r'] = "1210";
	codex['s'] = "1110";
	codex['t'] = "2000";
	codex['u'] = "1120";
	codex['v'] = "1112";
	codex['w'] = "1220";
	codex['x'] = "2112";
	codex['y'] = "2122";
	codex['z'] = "2211";

	string number = codex[letter];
	for (int i = 0; i < 4; i++) {
		if (number[i] == '1') {
			dit();
			Sleep(120);
		}

		else if (number[i] == '2') {
			dah();
			Sleep(120);
		}

	}
}


void sentence(string user_input) {

	//iterate through each character of the user input
	for (string::size_type i = 0; i < user_input.size(); i++) {

		//if the character is alphanumeric, pass it to letter()
		if (isalnum(user_input[i])) {
			letter(user_input[i]);
			Sleep(360);
		}

		//else, it is a space or punctuation
		else {
			Sleep(840);
		}
	}
}
//



//https://msdn.microsoft.com/en-us/library/windows/desktop/ms679277(v=vs.85).aspx
int main() {


	//this is our main loop
	string line;

	cout << "\nType your sentence to be converted:  ";
	while (getline(cin, line);) {

		sentence(line);

	}



	return 0;
}

