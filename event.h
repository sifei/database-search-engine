// the header for the event 
#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <list>

using namespace std;

class Event
{
private:
	string eventID;
	int patientNum;
	string codeID;
	string date;
public:
	Event();
	~Event();
	string getEventID();
	void setEventID(string eventID);
	int getPatientNum();
	void setPatientNum(int pNum);
	string getCodeID();
	void setCodeID(string codeID);
	string getDate();
	void setDate(string date);
	void setAll(string eId, int num, string cID, string day);
	void clear();
};
class eventList
{
private:
	int n; //number of patients

	list<Event> eList;
public:
	void add(Event p);
	void del(Event p);
	void find(int Pnum, list<Event> &el);
	bool find(string str, Event &e);
	void find(string str, list<Event> &el);

};

#endif


