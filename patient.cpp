#include <string>
#include "patient.h"

using namespace std;


patient::patient()
{
	
}

patient::~patient()
{
}

int patient::getPnum()
{
	return Pnum;
}

void patient::setPnum(int num)
{
	Pnum = num;
}

string patient::getLastName()
{
	return lastname;
}

void patient::setLastName(string ln)
{
	lastname = ln;
}

string patient::getFirstName()
{
	return firstname;
}

void patient::setFirstName(string fn)
{
	firstname = fn;
}

string patient::getBirthdate()
{
	return birthdate;
}

void patient::setBirthdate(string birth)
{
	birthdate = birth;
}

string patient::getFloor()
{
	return floor;
}

void patient::setFloor(string fl)
{
	floor = fl;
}

string patient::getDNA()
{
	return DNA;
}

void patient::setDNA(string dna)
{
	DNA = dna;
}

void patient::setAll(int num, string ln, string fn, string birth, string fl, string dna)
{
	setPnum(num);
	setLastName(ln);
	setFirstName(fn);
	setBirthdate(birth);
	setFloor(fl);
	setDNA(dna);
}

void patient::clear()
{
	Pnum = 0;
	lastname.clear();
	firstname.clear();
	birthdate.clear();
	floor.clear();
	DNA.clear();
}


void patientList::add(patient p)
{
	pList.insert(pList.end(),p);
}

void patientList::del(patient p)
{
	list<patient>::iterator it;
	for(it=pList.begin(); it!=pList.end(); it++)
	{
		if( (*it).getPnum() == p.getPnum() )
			break;
	}
	pList.erase(it);
}

bool patientList::find(int Pnum, patient &p)
{
	list<patient>::iterator it;
	for(it=pList.begin(); it!=pList.end(); it++)
	{
		if( (*it).getPnum() == Pnum )
		{
			p = (*it);
			return true;
		}
	}
	return false;
}


void patientList::find(string str, list<patient> &pl)
{
	pl.clear();
	list<patient>::iterator it;
	patient pTemp;
	for(it=pList.begin(); it!=pList.end(); it++)
	{
//		if( _stricmp((*it).getLastName().c_str(), str.c_str()) == 0 )
// for the linux
		if(strcasecmp((*it).getLastName().c_str(), str.c_str()) == 0)
		{
			pTemp = (*it);
			pl.insert(pl.end(),pTemp);
		}
	}
}


