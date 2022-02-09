#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool getPassword() {
    for ( int attempts = 0; attempts <10; ++attempts ) {
        string password;
        cout << "Enter your password: " << password << endl;
        getline(cin, password);

        if ( password == "csc201" ) {
            cout << "Welcome!";
            return true;
        }
    }
    return false;
}


string NAME[] = {"Kenenna EGBUNA","Anjolaoluwa OLOWOKERE" , "Anjolaoluwa JUBA" , "Chimaje Agada" ,  "Abba Ali-Concern" , "Oluwapese ALO" ,  "Ogechukwu ATA" , "Fareed Bello" , "Nwanne EGBUNA" ,  "Sophia EZEH"}
    string MATRIC[] = {"SST/2019/0001", "SST/2019/0002", "SST/2019/0003", "SST/2019/0004", "SST/2019/0005", "SST/2019/0006", "SST/2019/0007", "SST/2019/0008", "SST/2019/0009", "SST/2019/0010"}
    int CSC201[] = {84,91,66,83,74,66,61,41,62,64}
    int CSC205[] = {90,75,81,49,80,82,58,31,50,30}
    int MTH201[] = {38,34,62,40,31,78,70,98,64,39}
    int MTH205[] = {85,55,87,36,33,62,95,50,98,96}
    int GST201[] = {97,87,47,74,80,70,61,60,97,65}


int main() {
	string userName;
	
	cout << "				Pan-Atlantic University\n 				Result Management System" << endl;
	cout << "Provide your login details: " << endl;
	cout << "Enter your username: ";
	cin >> userName;
    if ( !getPassword() )
    cout << "Invalid Password \n Kindly re-enter a valid Password." << endl;
        return true;
    cout << endl;
}

	char option;
	const char Search_Result = F;
			Update_Result = U;
			Save_Result = P;
			View_All = A;
			Exit_Program = E;
			
	cout <<"\t\tMain Menu\n\n";
	cout << "To SEARCH for a Student's Result\n";
	cout << "To UPDATE a Student's Result\n";
	cout << "To SAVE a Student's Result to a File\n";
	cout << "To VIEW all Results\n";
	cout << "EXIT Program\n";
	cout << "\t\tEnter an option\n";
	cin >> option;
	
	if (option == Search_Result)
	 
	 return 0;
}

//GPA CHECKER
int grade_point(int gp){
	if(gp<45){
		gp=0;
	}
	else if(gp<50){
		gp=2;
	}
	else if(gp<60){
		gp=3;
	}
	else if(gp<70){
		gp=4;
	}
	else if(gp>=70){
		gp=5;
	}
	
	return gp;
}
float GPA(int a, int b, int c, int d, int e){
	float gpa;
	a = grade_point(a);
	b = grade_point(b);
	c = grade_point(c);
	d = grade_point(d);
	e = grade_point(e);
	
	gpa = (a+b+c+d+e)/5;
	return gpa;
}

