#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <fstream> //работа с файловым потоком
#include <chrono> //работа со временем
#include <ctime>
#include <string>
#include <cstring>
using namespace std;

void file(char* dt);

int main() {
	// current date/time based on current system
	time_t now = time(0);
	// convert now to string form
	char* dt = ctime(&now);
	cout << "The local date and time is: " << dt << endl;
	file(dt);
}

void file(char* dt)
{
	ofstream file;
	file.open("file.txt", ios_base::app);
	unsigned long milliseconds_since_epoch = chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(1);
	file << milliseconds_since_epoch << " ";
	file << dt << endl;
	file.close();

}
