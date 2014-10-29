#include <string>
#include "event.h"

using namespace std;


Event::Event()
{
	
}

Event::~Event()
{

}

string Event::getEventID()
{
	return eventID;
}
void Event::setEventID(string eID)
{
	eventID = eID; 
}

int Event::getPatientNum()
{
	return patientNum;
}

void Event::setPatientNum(int num)
{
	patientNum= num;
}

string Event::getCodeID()
{
	return codeID;
}

void Event::setCodeID(string cID)
{
	codeID = cID;
}

string Event::getDate()
{
	return date;
}
void Event::setDate(string day)
{
	date = day;
}

void Event::setAll(string eID, int num, string cID, string day)
{
	setEventID(eID);
	setPatientNum(num);
	setCodeID(cID);
	setDate(day);
}

void Event::clear()
{
	eventID.clear();
	patientNum = 0;
	codeID.clear();
	date.clear();
}

void eventList::add(Event e)
{
	eList.insert(eList.end(),e);
}

void eventList::del(Event e)
{
	list<Event>::iterator it;
	for(it=eList.begin(); it!=eList.end(); it++)
	{
		if( (*it).getEventID() == e.getEventID()  && (*it).getPatientNum() == e.getPatientNum())
			break;
	}
	eList.erase(it);
}

void eventList::find(int Pnum, list<Event> &el)
{
	el.clear();
	list<Event>::iterator it;
	Event eTemp;
	for(it=eList.begin(); it!=eList.end(); it++)
	{
		if( (*it).getPatientNum() == Pnum)
		{
			eTemp = (*it);
			el.insert(el.end(),eTemp);
		}
	}
}

bool eventList::find(string str, Event &e)
{
	list<Event>::iterator it;
	for(it=eList.begin(); it!=eList.end(); it++)
	{
		if( (*it).getEventID() == str)
		{
			e = (*it);
			return true;
		}
	}
	return false;
}

bool compareEvent(Event e1, Event e2)
{
// for the linux
	int cp = strcasecmp(e1.getEventID().c_str(), e2.getEventID().c_str());
//	int cp = _stricmp(e1.getEventID().c_str(), e2.getEventID().c_str());
	if(cp >= 0)
		return false;
	else
		return true;
}

void eventList::find(string str, list<Event> &el)
{
	el.clear();
	list<Event>::iterator it;
	Event eTemp;
	for(it=eList.begin(); it!=eList.end(); it++)
	{
// for the linux
		if(strcasecmp((*it).getEventID().c_str(),str.c_str()) >= 0)
//		if( _stricmp((*it).getEventID().c_str(),str.c_str()) >= 0)
		{
			eTemp = (*it);
			el.insert(el.end(),eTemp);
		}
	}
	el.sort(compareEvent);
}


