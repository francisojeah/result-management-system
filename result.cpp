#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

//This program checks for the gpa for the actual courses done by 200lvl csc students using the various grade points

//check number of students
int stunum() {
	string countlines;
	int count = -1;

	ifstream myfile ("students.txt");
	if (myfile.is_open()) {
		while (getline (myfile,countlines) ) {
			++count ;
		}
		myfile.close();
	} else cout << "Unable to open file";
	return count;
}
//check number of users
int usernum() {
	string countlines1;
	int count1 = -1;

	ifstream logfile ("logininfo.txt");
	if (logfile.is_open()) {
		while (getline (logfile,countlines1) ) {
			++count1;
		}
		logfile.close();
	} else cout << "Unable to open file";
	return count1;
}
//Assign grades
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
//Calculate GPA
float GPAS(int a, int b, int c, int d, int e, int f, int g, int h) {
	float gpa;
	a = grade_point(a);
	b = grade_point(b);
	c = grade_point(c);
	d = grade_point(d);
	e = grade_point(e);
	f = grade_point(f);
	g = grade_point(g);
	h = grade_point(h);
	//each course with different gradepoints
	gpa = round((((3*(a+b+c+d+e))+(2*(f+g+h)))/21.0)*10.0)/10.0;
	return gpa;
}
//Check for valid string
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

int ch(string messi) {
	getline(cin, messi);
	int re=0;
	for(int i=0; messi[i]!='\0'; i++) {
		if(messi[i]==' ') {
			re++;
		}
	}
	return re;
}

//color of text
void col(int r) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if((r%2==0)||(r<2)) {
		SetConsoleTextAttribute(hConsole, 7);
	} else {
		SetConsoleTextAttribute(hConsole, 112);
	}
}

//main function
int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//Array Declaration
	string MATRIC[stunum()];
	string NAME1[stunum()];
	string NAME2[stunum()];
	int CSC201[stunum()];
	int CSC205[stunum()];
	int MTH201[stunum()];
	int MTH203[stunum()];
	int STA205[stunum()];
	int ENT201[stunum()];
	int GST202[stunum()];
	int GST211[stunum()];
	float GPA[stunum()];
	//Assigning values from file to arrays
	string reader;
	int i = 0;
	int j = 0;
	int skip = 0;
	ifstream myfile3("students.txt");
	if(myfile3.is_open()) {
		while(myfile3>>reader) {
			skip++;
			if(skip>12) {
				i++;
				switch(i) {
					case 1: {
						if(reader[0]=='.') {
							reader.erase(reader.begin());
						}
						NAME1[j] = reader;
						break;
					}
					case 2: {
						NAME2[j] = reader;
						break;
					}
					case 3: {
						MATRIC[j] = reader;
						break;
					}
					case 4: {
						stringstream readers(reader);
						readers>>CSC201[j];
						break;
					}
					case 5: {
						stringstream readers(reader);
						readers>>CSC205[j];
						break;
					}
					case 6: {
						stringstream readers(reader);
						readers>>MTH201[j];
						break;
					}
					case 7: {
						stringstream readers(reader);
						readers>>MTH203[j];
						break;
					}
					case 8: {
						stringstream readers(reader);
						readers>>STA205[j];
						break;
					}
					case 9: {
						stringstream readers(reader);
						readers>>ENT201[j];
						break;
					}
					case 10: {
						stringstream readers(reader);
						readers>>GST202[j];
						break;
					}
					case 11: {
						stringstream readers(reader);
						readers>>GST211[j];
						break;
					}
					case 12: {
						stringstream readers(reader);
						readers>>GPA[j];
						break;
					}
				}
				if(i == 12) {
					i=0;
					j+=1;
				}
			}
		}
		myfile3.close();
	} else {
		cout << "Unable to open file\n";
	}
//Assigning user data from file to array
	string reader1;
	string user[usernum()];
	string pass[usernum()];

	int i1 = 0;
	int j1 = 0;
	int skip1 = 0;
	ifstream myfile4("logininfo.txt");
	if(myfile4.is_open()) {
		while(myfile4>>reader1) {
			skip1++;
			if(skip1>2) {
				i1++;

				switch(i1) {
					case 1: {
						user[j1] = reader1;
						break;
					}
					case 2: {
						pass[j1] = reader1;
						break;
					}
				}
				if(i1 == 2) {
					i1=0;
					j1+=1;
				}
			}
		}
		myfile4.close();
	} else {
		cout << "Unable to open file\n";
	}

	string userName, password;
	cout<< "\t\t\t\t-----------------------------"<<endl;
	cout<< "\t\t\t\t  Pan-Atlantic University"<<endl;
	cout<< "\t\t\t\t-----------------------------"<<endl;
	cout<< "\t\t\t\t  Result Management System" << endl;
	cout<< "\t\t\t\t-----------------------------"<<endl;
	cout << "\nProvide your login details. " << endl;

entry:
	cout << "Enter your username: ";
	cin >> userName;
	if(ch(userName)>0) {
		SetConsoleTextAttribute(hConsole,4);
		cout<<"Invalid Username\n"<<endl;
		SetConsoleTextAttribute(hConsole, 7);
		goto entry;
	};
	int p = 0;
	while(p<usernum()) {
		if(userName == user[p]) {
			cout << "Enter your password: ";
			cin >> password;
			if(ch(password)>0) {
				SetConsoleTextAttribute(hConsole,4);
				cout << "Invalid password. \nPlease check your username and password.\n" << endl;
				SetConsoleTextAttribute(hConsole, 7);
				goto entry;
			}
			if (password == pass[p]) {
				//green text
				SetConsoleTextAttribute(hConsole,2);
				cout << "\nWelcome " <<user[p]<<"\n"<< endl;
				//white text
				SetConsoleTextAttribute(hConsole, 7);
				break;
			} else {
				//red text
				SetConsoleTextAttribute(hConsole,4);
				cout << "Invalid password. \nPlease check your username and password.\n" << endl;
				SetConsoleTextAttribute(hConsole, 7);
				goto entry;
			}
		}
		p++;
	}

	if (p ==usernum()) {
		SetConsoleTextAttribute(hConsole,4);
		cout<<"Invalid Username\n"<<endl;
		SetConsoleTextAttribute(hConsole, 7);
		goto entry;
	}

	char option[]= " ";
	//Main Menu
menu:
	cout<<"\t\t--------------"<<endl;
	cout <<"\t\t  Main Menu"<<endl;
	cout<<"\t\t--------------"<<endl;

	cout << "\nTo SEARCH for a Student's Result Press F\n";
	cout << "To UPDATE a Student's Result Press U\n";
	cout << "To SAVE a Student's Result to a File Press P\n";
	cout << "To VIEW all Results Press A\n";
	cout << "EXIT Program Press E\n\n";
	cout << "Enter an option: \n";
	cin >> option;
	if(ch(option)>0) {
		SetConsoleTextAttribute(hConsole,4);
		cout<<"Invalid entry.\nTry again\n"<<endl;
		SetConsoleTextAttribute(hConsole, 7);
		goto menu;
	}
	//Check if option was string instead of character
	if (strlen(option)>1) {
		SetConsoleTextAttribute(hConsole,4);
		cout<<"Invalid entry.\nTry again\n"<<endl;
		SetConsoleTextAttribute(hConsole, 7);
		goto menu;
	}
	//Navigation
	switch(option[0]) {
		case 'F':
		case 'f': {
			//SEARCH
			int n = stunum(); //gets the number of elements in an array
			string mat = "Empty";
			cout << "----------------"<<endl;
			cout << " SEARCH RECORDS" << endl;
			cout << "----------------"<<endl;
			cout << "Enter Student's Matriculation Number: ";
			cin >> mat;
			if(ch(mat)>0) {
				SetConsoleTextAttribute(hConsole,4);
				cout << "No such Matriculation Number exist" << endl;
				SetConsoleTextAttribute(hConsole, 7);
				goto menu;
			}
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
				SetConsoleTextAttribute(hConsole,4);
				cout << "No such Matriculation Number exist" << endl;
				SetConsoleTextAttribute(hConsole, 7);
				goto menu;
			}
			float gpa;
			//Prints student's details
			cout << "Student's Name\t" << NAME1[c]<<" "<<NAME2[c];
			cout << "\nMatric No\t" << MATRIC[c];
			cout << "\nCSC201\t\t" << CSC201[c];
			cout << "\nCSC205\t\t" << CSC205[c];
			cout << "\nMTH201\t\t" << MTH201[c];
			cout << "\nMTH203\t\t" << MTH203[c];
			cout << "\nSTA205\t\t" << STA205[c];
			cout << "\nENT201\t\t" << ENT201[c];
			cout << "\nGST202\t\t" << GST202[c];
			cout << "\nGST211\t\t" << GST211[c];
			cout << "\n\nGPA\t\t" << GPA[c] << "\n";
			cout << "\n";
			goto menu;
			break;
		}
		case 'U':
		case 'u': {
			//UPDATE
			string mat = "Empty";
			cout << "----------------"<<endl;
			cout << " UPDATE RECORD" << endl;
			cout << "----------------"<<endl;
			cout << "Enter Student's Matriculation Number: ";
			cin >> mat;
			if(ch(mat)>0) {
				SetConsoleTextAttribute(hConsole,4);
				cout << "No such Matriculation Number exist" << endl;
				SetConsoleTextAttribute(hConsole, 7);
				goto menu;
			}
			int c=0;
			int n=stunum();

			while(c<n) {
				if(MATRIC[c] == mat) {
					break;
				}
				c++;
			}

			if(c==n) {
				SetConsoleTextAttribute(hConsole,4);
				cout << "No such Matriculation Number exist" << endl;
				SetConsoleTextAttribute(hConsole, 7);
				goto menu;
			}
			float gpa;
			cout << "Student's Name\t" << NAME1[c] << " " << NAME2[c];
			cout << "\nMatric No\t" << MATRIC[c];
			int loop = 0;
invalid:
			for(int i=loop; i<8; i++) {
				switch(i) {
					case 0: {
						string str;
						int score1;
						SetConsoleTextAttribute(hConsole,4);
						cout << "\nCSC201\t"<<CSC201[c] <<"\n";
						SetConsoleTextAttribute(hConsole, 7);
						cout << "Update CSC201 score\nEnter score: ";
						cin >> str;
						if(ch(str)>0) {
							SetConsoleTextAttribute(hConsole,4);
							cout << "Invalid Value\n";
							SetConsoleTextAttribute(hConsole, 7);
							loop = i;
							goto invalid;
						}
						score1 = valid(str);
						if((score1<0)||(score1>100)) {
							SetConsoleTextAttribute(hConsole,4);
							cout << "Invalid Value\n";
							SetConsoleTextAttribute(hConsole, 7);
							loop = i;
							goto invalid;
						} else {
							CSC201[c] = score1;
							SetConsoleTextAttribute(hConsole,2);
							cout << CSC201[c] << endl;
							SetConsoleTextAttribute(hConsole, 7);
						}
						break;
					}
					case 1: {
						string str1;
						int score2;
						SetConsoleTextAttribute(hConsole,4);
						cout << "\nCSC205\t"<<CSC205[c] <<"\n";
						SetConsoleTextAttribute(hConsole, 7);
						cout << "Update CSC205 score\nEnter score: ";
						cin >> str1;
						if(ch(str1)>0) {
							SetConsoleTextAttribute(hConsole,4);
							cout << "Invalid Value\n";
							SetConsoleTextAttribute(hConsole, 7);
							loop = i;
							goto invalid;
						}
						score2 = valid(str1);
						if((score2<0)||(score2>100)) {
							SetConsoleTextAttribute(hConsole,4);
							cout << "Invalid Value\n";
							SetConsoleTextAttribute(hConsole, 7);
							loop = i;
							goto invalid;
						} else {
							CSC205[c] = score2;
							SetConsoleTextAttribute(hConsole,2);
							cout << CSC205[c] << endl;
							SetConsoleTextAttribute(hConsole, 7);
						}
						break;
					}
					case 2: {
						string str2;
						int score3;
						SetConsoleTextAttribute(hConsole,4);
						cout << "\nMTH201\t"<<MTH201[c] <<"\n";
						SetConsoleTextAttribute(hConsole, 7);
						cout << "Update MTH201 score\nEnter score: ";
						cin >> str2;
						if(ch(str2)>0) {
							SetConsoleTextAttribute(hConsole,4);
							cout << "Invalid Value\n";
							SetConsoleTextAttribute(hConsole, 7);
							loop = i;
							goto invalid;
						}
						score3 = valid(str2);
						if((score3<0)||(score3>100)) {
							SetConsoleTextAttribute(hConsole,4);
							cout << "Invalid Value\n";
							SetConsoleTextAttribute(hConsole, 7);
							loop = i;
							goto invalid;
						} else {
							MTH201[c] = score3;
							SetConsoleTextAttribute(hConsole,2);
							cout << MTH201[c] << endl;
							SetConsoleTextAttribute(hConsole, 7);
						}
						break;
					}
					case 3: {
						string str3;
						int score4;
						SetConsoleTextAttribute(hConsole,4);
						cout << "\nMTH203\t"<<MTH203[c] <<"\n";
						SetConsoleTextAttribute(hConsole, 7);
						cout << "Update MTH203 score\nEnter score: ";
						cin >> str3;
						if(ch(str3)>0) {
							SetConsoleTextAttribute(hConsole,4);
							cout << "Invalid Value\n";
							SetConsoleTextAttribute(hConsole, 7);
							loop = i;
							goto invalid;
						}
						score4 = valid(str3);
						if((score4<0)||(score4>100)) {
							SetConsoleTextAttribute(hConsole,4);
							cout << "Invalid Value\n";
							SetConsoleTextAttribute(hConsole, 7);
							loop = i;
							goto invalid;
						} else {
							MTH203[c] = score4;
							SetConsoleTextAttribute(hConsole,2);
							cout << MTH203[c] << endl;
							SetConsoleTextAttribute(hConsole, 7);
						}
						break;
					}
					case 4: {
						string str4;
						int score5;
						SetConsoleTextAttribute(hConsole,4);
						cout << "\nSTA205\t"<<STA205[c] <<"\n";
						SetConsoleTextAttribute(hConsole, 7);
						cout << "Update STA205 score\nEnter score: ";
						cin >> str4;
						if(ch(str4)>0) {
							SetConsoleTextAttribute(hConsole,4);
							cout << "Invalid Value\n";
							SetConsoleTextAttribute(hConsole, 7);
							loop = i;
							goto invalid;
						}
						score5 = valid(str4);
						if((score5<0)||(score5>100)) {
							SetConsoleTextAttribute(hConsole,4);
							cout << "Invalid Value\n";
							SetConsoleTextAttribute(hConsole, 7);
							loop = i;
							goto invalid;
						} else {
							STA205[c] = score5;
							SetConsoleTextAttribute(hConsole,2);
							cout << STA205[c] << endl;
							SetConsoleTextAttribute(hConsole, 7);
						}
						break;
					}
					case 5: {
						string str5;
						int score6;
						SetConsoleTextAttribute(hConsole,4);
						cout << "\nENT201\t"<<ENT201[c] <<"\n";
						SetConsoleTextAttribute(hConsole, 7);
						cout << "Update ENT201 score\nEnter score: ";
						cin >> str5;
						if(ch(str5)>0) {
							SetConsoleTextAttribute(hConsole,4);
							cout << "Invalid Value\n";
							SetConsoleTextAttribute(hConsole, 7);
							loop = i;
							goto invalid;
						}
						score6 = valid(str5);
						if((score6<0)||(score6>100)) {
							SetConsoleTextAttribute(hConsole,4);
							cout << "Invalid Value\n";
							SetConsoleTextAttribute(hConsole, 7);
							loop = i;
							goto invalid;
						} else {
							ENT201[c] = score6;
							SetConsoleTextAttribute(hConsole,2);
							cout << ENT201[c] << endl;
							SetConsoleTextAttribute(hConsole, 7);
						}
						break;
					}
					case 6: {
						string str6;
						int score7;
						SetConsoleTextAttribute(hConsole,4);
						cout << "\nGST202\t"<<GST202[c] <<"\n";
						SetConsoleTextAttribute(hConsole, 7);
						cout << "Update GST202 score\nEnter score: ";
						cin >> str6;
						if(ch(str6)>0) {
							SetConsoleTextAttribute(hConsole,4);
							cout << "Invalid Value\n";
							SetConsoleTextAttribute(hConsole, 7);
							loop = i;
							goto invalid;
						}
						score7 = valid(str6);
						if((score7<0)||(score7>100)) {
							SetConsoleTextAttribute(hConsole,4);
							cout << "Invalid Value\n";
							SetConsoleTextAttribute(hConsole, 7);
							loop = i;
							goto invalid;
						} else {
							GST202[c] = score7;
							SetConsoleTextAttribute(hConsole,2);
							cout << GST202[c] << endl;
							SetConsoleTextAttribute(hConsole, 7);
						}
						break;
					}
					case 7: {
						string str7;
						int score8;
						SetConsoleTextAttribute(hConsole,4);
						cout << "\nGST211\t"<<GST211[c] <<"\n";
						SetConsoleTextAttribute(hConsole, 7);
						cout << "Update GST211 score\nEnter score: ";
						cin >> str7;
						if(ch(str7)>0) {
							SetConsoleTextAttribute(hConsole,4);
							cout << "Invalid Value\n";
							SetConsoleTextAttribute(hConsole, 7);
							loop = i;
							goto invalid;
						}
						score8 = valid(str7);
						if((score8<0)||(score8>100)) {
							SetConsoleTextAttribute(hConsole,4);
							cout << "Invalid Value\n";
							SetConsoleTextAttribute(hConsole, 7);
							loop = i;
							goto invalid;
						} else {
							GST211[c] = score8;
							SetConsoleTextAttribute(hConsole,2);
							cout << GST211[c] << endl;
							SetConsoleTextAttribute(hConsole, 7);
						}
						break;
					}
				}
			}
			SetConsoleTextAttribute(hConsole,4);

			cout << "Previous GPA: ";

			cout<< GPA[c] << endl;
			SetConsoleTextAttribute(hConsole, 7);
			GPA[c] = GPAS(CSC201[c], CSC205[c], MTH201[c], MTH203[c], STA205[c], ENT201[c], GST202[c], GST211[c]);
			SetConsoleTextAttribute(hConsole,2);
			cout << "Current GPA: ";

			cout << GPA[c] << "\n";
			SetConsoleTextAttribute(hConsole, 7);
			cout << "\n";
			//remove("students.txt");
			ofstream updated("students.txt");
			if(updated.is_open()) {
				for(int i=-1; i<n; i++) {
					string q;
					if(i >=0) {
						if (NAME1[i].size()+NAME2[i].size()>=17) {
							q = "\t";
						} else if (NAME1[i].size()+NAME2[i].size()>10 && NAME1[i].size()+NAME2[i].size()<17) {
							q = "\t\t";
						} else if (NAME1[i].size()+NAME2[i].size()<=10) {
							q = "\t\t\t";
						}
					}

					if(i==-1) {
						updated << "\tNAME                MAT NO        CSC201 CSC205 MTH201 MTH203 STA205 ENT201 GST202 GST211 GPA\n";
					} else if(i==c) {
						if(NAME1[c][0]!='.') {
							NAME1[c] = "."+NAME1[c];
						}
						updated << NAME1[c] << " " << NAME2[c] << q << MATRIC[c] << "     "<<CSC201[c] << "     "<<CSC205[c]<< "     "<<MTH201[c]<<"     "<<MTH203[c]<<"     "<<STA205[c]<<"     "<<ENT201[c]<<"     "<<GST202[c]<<"     "<<GST211[c]<<"     "<<GPA[c]<<"\n";
					} else {
						updated << NAME1[i] << " " << NAME2[i] << q<< MATRIC[i] << "     "<<CSC201[i] <<"     "<<CSC205[i]<<"     "<<MTH201[i]<<"     "<<MTH203[i]<<"     "<<STA205[i]<<"     "<<ENT201[i]<<"     "<<GST202[i]<<"     "<<GST211[i]<<"     "<<GPA[i]<<"\n";
					}
				}
				updated.close();
			}

			else {
				cout << "Unable to open file\n";
			}
			cout<<"Record updated and written to file\n"<<endl;
			goto menu;
			break;
		}
		case 'P':
		case 'p': {
			int m = stunum();
			string matt = "empty";
			cout<< "----------------------\n";
			cout<< " PRINT RESULT TO FILE\n";
			cout<< "----------------------\n";

			cout<< "Enter Student's Matriculation Number: ";
			cin>>matt;
			if(ch(matt)>0) {
				SetConsoleTextAttribute(hConsole,4);
				cout<<"Invalid Matric Number\n";
				SetConsoleTextAttribute(hConsole, 7);
				goto menu;
			}

			for(int i=0; i<m; i++) {
				string name1;
				if(matt == MATRIC[i]) {
					name1 = NAME1[i];
					if(name1[0]=='.') {
						name1.erase(name1.begin());
					}
					cout << "Student's Name\t" << name1<<" "<<NAME2[i];
					cout  << "\nMatric No\t" << MATRIC[i];
					cout  << "\nCSC201\t\t" << CSC201[i];
					cout  << "\nCSC205\t\t" << CSC205[i];
					cout  << "\nMTH201\t\t" << MTH201[i];
					cout  << "\nMTH203\t\t" << MTH203[i];
					cout  << "\nSTA205\t\t" << STA205[i];
					cout  << "\nENT201\t\t" << ENT201[i];
					cout  << "\nGST202\t\t" << GST202[i];
					cout  << "\nGST211\t\t" << GST211[i];
					cout  << "\n\nGPA\t\t" << GPA[i] << "\n";
					cout<<"Record written to file name "<< name1<<" "<<NAME2[i]<<".txt"<<endl;

					ofstream studentfile (name1+" "+NAME2[i]+".txt");
					if (studentfile.is_open()) {
						studentfile << "Student's Name\t" << name1<<" "<<NAME2[i];
						studentfile << "\nMatric No\t\t" << MATRIC[i];
						studentfile << "\nCSC201\t\t" << CSC201[i];
						studentfile << "\nCSC205\t\t" << CSC205[i];
						studentfile << "\nMTH201\t\t" << MTH201[i];
						studentfile << "\nMTH203\t\t" << MTH203[i];
						studentfile << "\nENT201\t\t" << ENT201[i];
						studentfile << "\nGST202\t\t" << GST202[i];
						studentfile << "\nGST211\t\t" << GST211[i];
						studentfile << "\n\nGPA\t\t\t" << GPA[i] << "\n";
						studentfile.close();
					} else {
						cout << "Unable to open file";

					}
					matt = "aa";

				}
			}
			if (matt != "aa") {
				SetConsoleTextAttribute(hConsole,4);
				cout<<"Invalid Matric Number\n";
				SetConsoleTextAttribute(hConsole, 7);
				goto menu;
			}
			cout<<"\n";
			goto menu;
			break;
		}
		case 'A':
		case 'a': {
			int n=stunum();
			ofstream up1("students.txt");
			if(up1.is_open()) {
				for(int i=-1; i<n; i++) {
					string qr;
					if(i==-1) {
						up1<<"------------------------------------------------------------------------------------------------------------------\n";
						up1 << "\tNAME                MAT NO        CSC201 CSC205 MTH201 MTH203 STA205 ENT201 GST202 GST211 GPA\n";
						up1<<"------------------------------------------------------------------------------------------------------------------\n";
					} else {
						if (NAME1[i].size()+NAME2[i].size()<15) {
							qr = "\t\t";
						} else {
							qr = "\t";
						}
						up1 << NAME1[i] << " " << NAME2[i] << qr<< MATRIC[i] << "     "<<CSC201[i] <<"     "<<CSC205[i]<<"     "<<MTH201[i]<<"     "<<MTH203[i]<<"     "<<STA205[i]<<"     "<<ENT201[i]<<"     "<<GST202[i]<<"     "<<GST211[i]<<"     "<<GPA[i]<<"\n";
					}
				}
				up1.close();
			} else {
				cout << "Unable to open file\n";
			}

			string all;
			ifstream myfile5 ("students.txt");
			if (myfile5.is_open()) {
				int l = 0;
				while ( getline (myfile5,all) ) {
					col(l);
					if(all[0]=='.') {
						if(l%2 ==0) {
							SetConsoleTextAttribute(hConsole,2);
							all.erase(all.begin());
							cout << all << '\n';
							SetConsoleTextAttribute(hConsole,7);
						} else {
							SetConsoleTextAttribute(hConsole,114);
							all.erase(all.begin());
							cout << all << '\n';
							SetConsoleTextAttribute(hConsole,7);
						}
					} else {
						cout << all << '\n';
					}
					l++;
				}
				myfile5.close();
			} else cout << "Unable to open file";

			ofstream up2("students.txt");
			if(up2.is_open()) {
				for(int i=-1; i<n; i++) {
					string qe;

					if(i==-1) {
						up2 << "\tNAME                MAT NO        CSC201 CSC205 MTH201 MTH203 STA205 ENT201 GST202 GST211 GPA\n";
					} else {
						if (NAME1[i].size()+NAME2[i].size()>=17) {
							qe = "\t";
						} else if (NAME1[i].size()+NAME2[i].size()>10 && NAME1[i].size()+NAME2[i].size()<17) {
							qe = "\t\t";
						} else if (NAME1[i].size()+NAME2[i].size()<=10) {
							qe = "\t\t\t";
						}
						up2 << NAME1[i] << " " << NAME2[i] << qe << MATRIC[i] << "     "<<CSC201[i] <<"     "<<CSC205[i]<<"     "<<MTH201[i]<<"     "<<MTH203[i]<<"     "<<STA205[i]<<"     "<<ENT201[i]<<"     "<<GST202[i]<<"     "<<GST211[i]<<"     "<<GPA[i]<<"\n";
					}
				}
				up2.close();
			} else {
				cout << "Unable to open file\n";
			}
			goto menu;
			break;
		}
		case 'E':
		case 'e': {
			SetConsoleTextAttribute(hConsole,4);
			cout<<"\nCode Exited"<<endl;
			SetConsoleTextAttribute(hConsole, 7);
			break;
		}
		default:
			SetConsoleTextAttribute(hConsole,4);
			cout<<"Invalid entry.\nTry again\n"<<endl;
			SetConsoleTextAttribute(hConsole, 7);
			goto menu;
	}

	return 0;
}

