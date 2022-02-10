#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

//bool getPassword() {
//	for ( int attempts = 0; attempts <10; ++attempts ) {
//		string password;
//		cout << "Enter your password: " << password << endl;
//		getline(cin, password);
//
//		if ( password == "csc201" ) {
//			cout << "Welcome!";
//			return true;
//		}
//	}
//	return false;
//}

int grade_point(int gp) {
	if(gp<45) {
		gp=0;
	} else if(gp<50) {
		gp=2;
	} else if(gp<60) {
		gp=3;
	} else if(gp<70) {
		gp=4;
	} else if(gp>=70) {
		gp=5;
	}

	return gp;
}
float GPAS(int a, int b, int c, int d, int e) {
	float gpa;
	a = grade_point(a);
	b = grade_point(b);
	c = grade_point(c);
	d = grade_point(d);
	e = grade_point(e);

	gpa = (a+b+c+d+e)/5.0;
	return gpa;
}


string NAME[] = {"Kenenna EGBUNA","Anjolaoluwa OLOWOKERE", "Anjolaoluwa JUBA", "Chimaje Agada",  "Abba Ali-Concern", "Oluwapese ALO",  "Ogechukwu ATA", "Fareed Bello", "Nwanne EGBUNA",  "Sophia EZEH"};
string MATRIC[] = {"SST/2019/0001", "SST/2019/0002", "SST/2019/0003", "SST/2019/0004", "SST/2019/0005", "SST/2019/0006", "SST/2019/0007", "SST/2019/0008", "SST/2019/0009", "SST/2019/0010"};
int CSC201[] = {84,91,66,83,74,66,61,41,62,64};
int CSC205[] = {90,75,81,49,80,82,58,31,50,30};
int MTH201[] = {38,34,62,40,31,78,70,98,64,39};
int MTH205[] = {85,55,87,36,33,62,95,50,98,96};
int GST201[] = {97,87,47,74,80,70,61,60,97,65};
float GPA[] = {GPAS(CSC201[0], CSC205[0], MTH201[0], MTH205[0], GST201[0]),
               GPAS(CSC201[1], CSC205[1], MTH201[1], MTH205[1], GST201[1]),
               GPAS(CSC201[2], CSC205[2], MTH201[2], MTH205[2], GST201[2]),
               GPAS(CSC201[3], CSC205[3], MTH201[3], MTH205[3], GST201[3]),
               GPAS(CSC201[4], CSC205[4], MTH201[4], MTH205[4], GST201[4]),
               GPAS(CSC201[5], CSC205[5], MTH201[5], MTH205[5], GST201[5]),
               GPAS(CSC201[6], CSC205[6], MTH201[6], MTH205[6], GST201[6]),
               GPAS(CSC201[7], CSC205[7], MTH201[7], MTH205[7], GST201[7]),
               GPAS(CSC201[8], CSC205[8], MTH201[8], MTH205[8], GST201[8]),
               GPAS(CSC201[9], CSC205[9], MTH201[9], MTH205[9], GST201[9])
              };

int valid(string str) {
	int output;
	stringstream strs(str);
	strs>>output;
	char non_int[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM~!@#$%^&*()-=_+\\}|{:',.<>/?`'";
	int mistake = 0;
	int n = sizeof(str)/sizeof(str[0]);
	int m = sizeof(non_int)/sizeof(non_int[0]);
	n-=1;
	m-=1;
	int i=0,j=0;
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			if(non_int[j] == str[i]) {
				mistake+=1;
				break;
			}
			if(non_int[j]==str[i]) {
				mistake+=1;
				break;
			}
		}
	}
	if(mistake>0) {
		return -1;
	} else {
		return output;
	}
}

int main() {
//	string userName;
//	cout << "				Pan-Atlantic University\n 				Result Management System" << endl;
//	cout << "Provide your login details: " << endl;
//	cout << "Enter your username: ";
//	cin >> userName;
//	if ( !getPassword() )
//		cout << "Invalid Password \n Kindly re-enter a valid Password." << endl;
//	return true;
//	cout << endl;


	char option;
menu:
	cout <<"\t\tMain Menu\n\n";

	cout << "To SEARCH for a Student's Result Press F\n";
	cout << "To UPDATE a Student's Result Press U\n";
	cout << "To SAVE a Student's Result to a File Press P\n";
	cout << "To VIEW all Results Press A\n";
	cout << "EXIT Program Press E\n\n";
	cout << "Enter an option: \n";
	cin >> option;

	switch(option) {
		case 'F':
		case 'f': {
			//SEARCH
			int n = sizeof(MATRIC)/sizeof(MATRIC[0]); //gets the number of elements in an array
			string mat = "Empty";

			cout << "SEARCH RECORDS" << endl;
			cout << "Enter Student's Matriculation Number: ";
			cin >> mat;
			int c=0;
			//GET THE INDEX OF THE MATRIC NUMBER ENTERED
			while(c<n) {
				if(MATRIC[c] == mat) {
					break;
				}
				c++;
			}
			//IF THE MARTIC NUMBER IS INVAID
			if(c==n) {
				cout << "No such Matriculation Number exist" << endl;
				goto menu;
			}
			float gpa;
			cout << "Student's Name\t" << NAME[c];
			cout << "\nMatric No\t" << MATRIC[c];
			cout << "\nCSC201\t" << CSC201[c];
			cout << "\nCSC205\t" << CSC205[c];
			cout << "\nMTH201\t" << MTH201[c];
			cout << "\nMTH205\t" << MTH205[c];
			cout << "\nGST201\t" << GST201[c];
			cout << "\nGPA    \t" << GPA[c] << "\n";
			//cout << "\n";
			goto menu;
			break;
		}
		case 'U':
		case 'u': {
			//UPDATE
			int n = sizeof(MATRIC)/sizeof(MATRIC[0]); //gets the number of elements in an array
			string mat = "Empty";

			cout << "UPDATE RECORD" << endl;
			cout << "Enter Student's Matriculation Number: ";
			cin >> mat;
			int c=0;

			while(c<n) {
				if(MATRIC[c] == mat) {
					break;
				}
				c++;
			}

			if(c==n) {
				cout << "No such Matriculation Number exist" << endl;
				goto menu;
			}
			float gpa;
			cout << "Student's Name\t" << NAME[c];
			cout << "\nMatric No\t" << MATRIC[c];
			int loop = 0;
invalid:
			for(int i=loop; i<5; i++) {
				int score;
				string str = "abc";

				switch(i) {
					case 0:
						cout << "\nCSC201\t" << CSC201[c] << "\nUpdate CSC201 score\nEnter score: ";
						cin >> str;
						score = valid(str);
						if((score<0)||(score>100)) {
							cout << "Invalid Value\n";
							loop = i;
							goto invalid;
						} else {
							CSC201[c] = score;
						}
						break;
					case 1:
						cout << "\nCSC205\t" << CSC205[c] << "\nUpdate CSC205 score\nEnter score: ";
						cin >> str;
						score = valid(str);
						if((score<0)||(score>100)) {
							cout << "Invalid Value\n";
							loop = i;
							goto invalid;
						} else {
							CSC205[c] = score;
						}
						break;
					case 2:
						cout << "\nMTH201\t" << MTH201[c] << "\nUpdate MTH201 score\nEnter score: ";
						cin >> str;
						score = valid(str);
						if((score<0)||(score>100)) {
							cout << "Invalid Value\n";
							loop = i;
							goto invalid;
						} else {
							MTH201[c] = score;
						}
						break;
					case 3:
						cout << "\nMTH205\t" << MTH205[c] << "\nUpdate MTH205 score\nEnter score: ";
						cin >> str;
						score = valid(str);
						if((score<0)||(score>100)) {
							cout << "Invalid Value\n";
							loop = i;
							goto invalid;
						} else {
							MTH205[c] = score;
						}
						break;
					case 4:
						cout << "\nGST201\t" << GST201[c] << "\nUpdate GST201 score\nEnter score: ";
						cin >> str;
						score = valid(str);
						if((score<0)||(score>100)) {
							cout << "Invalid Value\n";
							loop = i;
							goto invalid;
						} else {
							GST201[c] = score;
						}
						break;
				}
			}
			cout << "Previous GPA: " << GPA[c] << endl;
			GPA[c] = GPAS(CSC201[c], CSC205[c], MTH201[c], MTH205[c], GST201[c]);
			cout << "Current GPA: " << GPA[c] << "\n";
			//	cout << "\n";
			goto menu;
			break;
		}
		case 'P':
		case 'p':
			break;
		case 'A':
		case 'a':
			break;
		case 'E':
		case 'e':
			break;
		default:
			cout<<"Invalid entry.\nTry again\n"<<endl;
			goto menu;
	}




	return 0;
}


