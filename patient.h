// the header for the patient
#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <list>

using namespace std;

class patient
{
private:
	int Pnum;
	string lastname;
	string firstname;
	string birthdate;
	string floor;
	string DNA;
public:
	patient();
	~patient();
	int getPnum();
	void setPnum(int num);
	string getLastName();
	void setLastName(string ln);
	string getFirstName();
	void setFirstName(string fn);
	string getBirthdate();
	void setBirthdate(string birth);
	string getFloor();
	void setFloor(string fl);
	string getDNA();
	void setDNA(string dna);
	void setAll(int num, string ln, string fn, string birth, string fl, string dna);
	void clear();
};

class patientList
{
private:
	int n; //number of patients

	list<patient> pList;
public:
	void add(patient p);
	void del(patient p);
	bool find(int Pnum, patient &p);
	void find(string str, list<patient> &pl);
};

#endif


