#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

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

	char non_int[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM~!@#$%^&*()-=_+\\}|{:',.<>/?`'";

	stringstream strs(str);
	strs>>output;

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
		}
		if(non_int[j]==str[i]) {
			break;
		}
	}
	if(mistake>0) {
		return -1;
	} else {
		stringstream strs(str);
		strs>>output;
		return output;
	}
}

int main() {
	int i;
	string userName, password;
	string user[] = {"moses", "desmond", "adaora", "patrick201", "patrick205"};
	string pass[] = {"csc201", "csc205", "gst201", "mth201", "mth205"};
	int zi= sizeof(user)/sizeof(user[0]);
	int xo = sizeof(pass)/sizeof(pass[0]);
	ofstream userpass("logininfo.txt");
	if (userpass.is_open()) {
		userpass << "Username\t\tPassword\n";
		for(int i=0; i<zi; i++) {
			userpass<< user[i]<<"\t\t"<<pass[i]<< endl;
		}
	} else cout << "Unable to open file.";

	cout << "				Pan-Atlantic University\n 				Result Management System" << endl;
	cout << "Provide your login details. " << endl;

entry:
	cout << "Enter your username: ";
	cin >> userName;
	int p = 0;
	while(p<zi) {
		if(userName == user[p]) {
			cout << "Enter your password: ";
			cin >> password;
			if (password == pass[p]) {
				cout << "Welcome " <<user[p]<< endl;
				break;
			} else {
				cout << "Invalid password. Please check your username and password." << endl;
				goto entry;
			}
		}
		p++;
	}
	if (p == zi) {
		cout<<"Invalid Username"<<endl;
		goto entry;
	}
	int arraySize = *(&NAME + 1) - NAME;

	ofstream result("results.txt");
	if (result.is_open()) {

		for(int count = 0; count < arraySize; count ++) {
			result << NAME[count] << "\t\t"<< MATRIC[count] << "\t" << CSC201[count] << "\t" << CSC205[count] << "\t" << MTH201[count] << "\t" << MTH205[count] << "\t" << GST201[count] << "\t" << GPA[count] << "\n";

		}
		result.close();

	} else {
		cout << "NO";
	}

	char option[]= " ";
menu:
	cout <<"\t\tMain Menu\n\n";

	cout << "To SEARCH for a Student's Result Press F\n";
	cout << "To UPDATE a Student's Result Press U\n";
	cout << "To SAVE a Student's Result to a File Press P\n";
	cout << "To VIEW all Results Press A\n";
	cout << "EXIT Program Press E\n\n";
	cout << "Enter an option: \n";
	cin >> option;
	if (strlen(option)>1){
		cout<<"Invalid option"<<endl;
  		goto menu;
	}

	switch(option[0]) {
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
			cout << "\nGST201\t" << GST201[c] ;
			cout << "\n\nGPA    \t" << GPA[c] << "\n";
			cout << "\n";
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
				//	int score;
				//string str = "abc";

				switch(i) {
					case 0: {
						string str;
						int score1;
						cout << "\nCSC201\t" << CSC201[c] << "\nUpdate CSC201 score\nEnter score: ";
						cin >> str;
						score1 = valid(str);
						if((score1<0)||(score1>100)) {
							cout << "Invalid Value\n";
							loop = i;
							goto invalid;
						} else {
							CSC201[c] = score1;
							cout << CSC201[c] << endl;
						}
						break;
					}
					case 1: {
						string str1;
						int score2;
						cout << "\nCSC205\t" << CSC205[c] << "\nUpdate CSC205 score\nEnter score: ";
						cin >> str1;
						score2 = valid(str1);
						if((score2<0)||(score2>100)) {
							cout << "Invalid Value\n";
							loop = i;
							goto invalid;
						} else {
							CSC205[c] = score2;
							cout << CSC205[c]<<endl;
						}
						break;
					}
					case 2: {
						string str2;
						int score3;
						cout << "\nMTH201\t" << MTH201[c] << "\nUpdate MTH201 score\nEnter score: ";
						cin >> str2;
						score3 = valid(str2);
						if((score3<0)||(score3>100)) {
							cout << "Invalid Value\n";
							loop = i;
							goto invalid;
						} else {
							MTH201[c] = score3;
							cout << MTH201[c] << endl;
						}
						break;
					}
					case 3: {
						string str3;
						int score4;
						cout << "\nMTH205\t" << MTH205[c] << "\nUpdate MTH205 score\nEnter score: ";
						cin >> str3;
						score4 = valid(str3);
						if((score4<0)||(score4>100)) {
							cout << "Invalid Value\n";
							loop = i;
							goto invalid;
						} else {
							MTH205[c] = score4;
							cout << MTH205[c] <<endl;
						}
						break;
					}
					case 4: {
						string str4;
						int score5;
						cout << "\nGST201\t" << GST201[c] << "\nUpdate GST201 score\nEnter score: ";
						cin >> str4;
						score5 = valid(str4);
						if((score5<0)||(score5>100)) {
							cout << "Invalid Value\n";
							loop = i;
							goto invalid;
						} else {
							GST201[c] = score5;
							cout << GST201[c] <<endl;
						}
						break;
					}
				}
			}
			cout << "Previous GPA: " << GPA[c] << endl;
			GPA[c] = GPAS(CSC201[c], CSC205[c], MTH201[c], MTH205[c], GST201[c]);
			cout << "Current GPA: " << GPA[c] << "\n";
			cout << "\n";
			goto menu;
			break;
		}
		case 'P':
		case 'p': {
			int m = sizeof(MATRIC)/sizeof(MATRIC[0]);
//saveindi:
			string matt = "empty";
			cout<< "PRINT RESULT TO FILE\n";

			cout<< "Enter Student's Matriculation Number: ";
			cin>>matt;

			for(int i=0; i<m; i++) {
				if(matt == MATRIC[i]) {
					cout << "Student's Name\t" << NAME[i];
					cout  << "\nMatric No\t" << MATRIC[i];
					cout  << "\nCSC201\t" << CSC201[i];
					cout  << "\nCSC205\t" << CSC205[i];
					cout  << "\nMTH201\t" << MTH201[i];
					cout  << "\nMTH205\t" << MTH205[i];
					cout  << "\nGST201\t" << GST201[i];
					cout  << "\n\nGPA    \t" << GPA[i] << "\n";
					cout<<"Record written to file name "<<NAME[i]<<".txt"<<endl;

					ofstream studentfile (NAME[i]+".txt");
					if (studentfile.is_open()) {
						studentfile << "Student's Name\t" << NAME[i];
						studentfile << "\nMatric No\t" << MATRIC[i];
						studentfile << "\nCSC201\t" << CSC201[i];
						studentfile << "\nCSC205\t" << CSC205[i];
						studentfile << "\nMTH201\t" << MTH201[i];
						studentfile << "\nMTH205\t" << MTH205[i];
						studentfile << "\nGST201\t" << GST201[i];
						studentfile << "\n\nGPA    \t" << GPA[i] << "\n";
						studentfile.close();
					} else {
						cout << "Unable to open file";

					}
					matt = "aa";

				}
			}
			if (matt != "aa") {
				cout<<"Invalid Matric Number\n";
//				for(int j=0; j<m; j++) {
//					cout<<MATRIC[j]<<", ";
//				}
//				cout<<"\n";
				goto menu;
			}
			cout<<"\n";
			goto menu;
			break;
		}
		case 'A':
		case 'a': {
			for(int count = -1; count < arraySize; count ++) {
				if(count==-1) {
					cout << "NAME" << "\t"<< "MATRIC" << "\t" << "CSC201" << "\t" << "CSC205" << "\t" << "MTH201" << "\t" << "MTH203" << "\t" << "GST201" << "\t" << "GPA" << "\n" <<endl;
				} else {
					cout << NAME[count] << "\t"<< MATRIC[count] << "\t" << CSC201[count] << "\t" << CSC205[count] << "\t" << MTH201[count] << "\t" << MTH205[count] << "\t" << GST201[count] << "\t" << GPA[count] << "\n\n";
				}
			}
			goto menu;
			break;
		}
		case 'E':
		case 'e':
			cout<<"Code Exited"<<endl;
			break;
		default:
			cout<<"Invalid entry.\nTry again\n"<<endl;
			goto menu;
	}

	return 0;
}





