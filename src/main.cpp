#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	//File handlers
	ofstream coutFile;
	coutFile.open("cout.log");
	ofstream cerrFile;
	cerrFile.open("cerr.log");
	ofstream clogFile;
	clogFile.open("clog.log");

	//Store current buffers so we can reasign them when program ends it's execution
	streambuf* backupCout = cout.rdbuf();
	streambuf* backupCerr = cerr.rdbuf();
	streambuf* backupClog = clog.rdbuf();

	//Replace cout,cerr,clog buffers
	cout.rdbuf(coutFile.rdbuf());
	cerr.rdbuf(cerrFile.rdbuf());
	clog.rdbuf(clogFile.rdbuf());

	cout << "This will be printed into cout.log file" << endl;
	cerr << "This will be printed into cerr.log file" << endl;
	clog << "This will be printed into clog.log file" << endl;

	//Restore previous buffers
	cout.rdbuf(backupCout);
	cerr.rdbuf(backupCerr);
	clog.rdbuf(backupClog);

	return 0;
}
