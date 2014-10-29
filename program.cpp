// Author: Sifei Han
// E-mail: sehan2@g.uky.edu
// Date: 10/26/09
// for this program that user choose a way to display data.

#include <iostream> // input/outpout
#include <fstream>  // file input/output
#include <string>   
#include "patient.h"
#include "event.h"
using namespace std;

// to change the display for the birthdate and date.
static string Month[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

// t0 find out if the patient num in the range
void errorPnum(string pNumStr){
	//check if the patient number is a six digit number
	if(pNumStr.size() != 6){
		throw string(" pNum does not contain 6 digits\n");
	}
	//check if each digit is a number between 0 and 9
	for(int i=0; i<6; i++){
		if( !(pNumStr[i]>='0' && pNumStr[i]<='9') ){
			throw string(" conatins alphabetic characters\n");
		} 
	}
}

// to find out if the Last name correct
void errorLN(string LN){
	//check if the last name is less than 20 alphabets
	if(LN.size()>20){
		throw string(" too long\n");
	}
	//check if each letter is a valid letter
	for(int i=0; i<LN.size(); i++){
		if(!( (LN[i]>='a'&&LN[i]<='z')||(LN[i]>='A'&&LN[i]<='Z') ))
			throw string(" wrong last name");
	}
	return ;
}

// to find out if the First name correct
void errorFN(string FN){
	//check if the first name is less than 20 alphabets
	if(FN.size()>20){
		throw string(" too long\n");
	}
	//check if each letter is a valid letter
	for(int i=0; i<FN.size(); i++){
		if(!( (FN[i]>='a'&&FN[i]<='z')||(FN[i]>='A'&&FN[i]<='Z') ))
			throw string(" wrong first name");
	}
	return ;
}
// check if the floor number correct
void errorFl(string floor){
	//check if the floor is of size 2
	if(floor.size() != 2 ){
		throw string(" is invalid\n");
	}
	//check if the first element is a number and the second is a upper-case alphabet
	if(!(floor[0]>='0' && floor[0]<='9' && floor[1]>='A' && floor[1]<='Z')){
		throw string(" is invalid\n");
	}
	return ;
}

// check the DNA file
void errorDNA(string DNA){
	//check if the DNA is either a "NONE" or of size between 9 and 11
	if(DNA.size()==4 ){
		if(strcmp(DNA.c_str(),"NONE")!=0)
			throw string(" the wrong DNA for the patient\n");
		else
			return;
	}
	if(DNA.size()<9 || DNA.size()>11) {
		throw string(" is invalid\n");
	}
	else
	{//if the size is between 9 and 11
		//find the position of '.' 
		int pos = DNA.find('.');
		if(pos == string::npos){
			throw string(" is invalid\n");
		}
		else
		{//check if the first three elements are "DNA"
			if(strcmp(DNA.substr(0,3).c_str(),"DNA")!=0){
				throw string(" is invalid\n");
			}
			else
			{//check if the elements between the "DNA" and  "." are all numbers
				for(int k=3; k<pos; k++)
				{
					if( !(DNA[k]>='0' && DNA[k]<='9') ){
						throw string(" is unknow type DNA for the patient(type:0-999)\n");
					}
				}
				//check if the last four elements are "data"
				if(strcmp(DNA.substr(pos+1,4).c_str(),"data")!=0){
					throw string(" is invalid\n");
				}
			}
		}
	}
}

// check if the event ID correct
void errorEID(string eID){
	//check if the eID is of size 5
	if(eID.size() != 5){
		throw string(" is valid\n");
	}
	//check if the first element is a upper-case alphabet
	if( !(eID[0]>='A' && eID[0]<='Z') ){
		throw string(" contain wrong an alphabetic character\n");
	}
	//check if the last four digit are all numbers
	for(int i=1; i<5; i++)
	{
		if( !(eID[i]>='0' && eID[i]<='9') ){
			throw string(" contain wrong number for the Event ID\n");
		}
	}
}

//check if the Code ID correct
void errorCID(string cID){
	//check if the cID is of size 3
	if(cID.size() != 3){
		throw string(" is valid\n");
	}
	//check if each element is a upper-case alphabet
	for(int i=0; i<3; i++)
	{
		if( !(cID[i]>='A' && cID[i]<='Z') ){
			throw string(" contains wrong alphabetic characters\n");
		}
	}
}

void errorDate(string date)
{
	//check if the data is of size either 9 or 10
	if(date.size()!=10 && date.size()!=9){
		throw string(" is invalid\n");
	}
	//the position of the first slash, which is between the month and the dat
	int fPos = date.find('/');
	if(fPos!=1 && fPos!=2){
		throw string(" is invalid\n");
	}
	//the position of second slash, which is between the day and the year
	int sPos = date.find('/',fPos+1);
	if(sPos!=fPos + 3){
		throw string(" is invalid\n");
	}
	//check if each digit except the slash is a valid number
	for(int i=0; i<date.size(); i++){
		if(date[i] != '/'){
			if( !(date[i]>='0' && date[i]<='9') ){
				throw string(" is invalid\n");
			}
		}
	}
}
int main()
{
	ifstream inPatient, inEvent;// open two data file
	patient pData;				// save the patient data
	Event eData;				// save the event data
	patientList pList;			// linklist for the patient
	eventList eList;			// linklist for the event
	string error = "Too few or too many data items on a line:\n";
	bool eflag = false;

// opent the patient.data 	
	inPatient.open("patient.data");
	if(!inPatient)  // for the file didn't found or cannot open 
	{
		cout<<"Open for file patient.data failed \n";
		cout << "Where patient.data is the name of the file not found.\n";
		return 0;
	}
	int count=0;
	while(!inPatient.eof())
	{
		//read in all the fields of data within each line
		int pNum;
		string pNumStr, pLn, pFn, pBd, pFl, pDna;
		inPatient >> pNumStr >> pLn >> pFn >> pBd >> pFl >> pDna;
		count++;
		try{//check the patient number
			errorPnum(pNumStr);
		}
		catch(string str){//patient number is invalid
			if(eflag == false){
				cout << error;
				eflag = true;
			}
			cout << "Line " << count << " of patient.data patient number " << pNumStr << str;
		}
		//convert the patient numbe to a integer
		pNum = atoi(pNumStr.c_str());
		try{//check the last name
			errorLN(pLn);
		}
		catch(string str){//last name is invalid
			if(eflag == false){
				cout << error;
				eflag = true;
			}
			cout << "Line " << count << " of patient.data Last Name " << pLn << str;
		}
		try{//check the first name
			errorFN(pFn);
		}
		catch(string str){//first name is invalid
			if(eflag == false){
				cout << error;
				eflag = true;
			}
			cout << "Line " << count << " of patient.data First Name " <<pFn <<str;
		}
		try{//check the birthdate
			errorDate(pBd);
		}
		catch(string str){//birthdate is invalid
			if(eflag == false){
				cout << error;
				eflag = true;
			}
			cout << "Line " << count << " of patient.data Birth date " << pBd << str;
		}
		try{//check the floor
			errorFl(pFl);
		}
		catch(string str){//floor is invlid
			if(eflag == false){
				cout <<error;
				eflag = true;
			}
			cout << "Line " << count << " of patient.data Floor " << pFl << str;
		}
		try{//check the DNA
			errorDNA(pDna);
		}
		catch(string str){//DNA is invalid
			if(eflag == false){
				cout << error;
				eflag = true;
			}
			cout << "Line " << count << " of patient.data DNA " << pDna <<str;
		}
		string BdTemp = pBd;
		pBd.clear();
		int slashCount = 0;
		// change the display for the birthdate
		for(int i=0; (unsigned)i<BdTemp.size(); i++)
		{
			if(BdTemp[i] == '/')
			{
				if(slashCount == 0)
				{
					string sub = BdTemp.substr(0,i);
					pBd += Month[atoi(sub.c_str())-1] + " ";
					slashCount ++;
				}
				else if(slashCount == 1)
				{
					pBd += ",";
					slashCount ++;
				}
			}
			else if(slashCount != 0)
			{
				pBd += BdTemp[i];
			}
		}
		pData.setAll(pNum,pLn,pFn,pBd,pFl,pDna);
		pList.add(pData);
	}
// open the event.data
	inEvent.open("event.data");
	if(!inEvent)  // for the file didn't found or cannot open 
	{
		cout<<"Open for file event.data failed \n";
		cout << "Where event.data is the name of the file not found.\n";
		return 0;
	}
	int counte=0;
	while(!inEvent.eof())
	{
		//read in all the fields within each line
		int pNum;
		string pNumStr,eID, cID, Date;
		inEvent >> eID >> pNumStr >> cID >> Date;
		counte++;
		try{//check event id 
			errorEID(eID);
		}catch(string str){//event id invalid
			if(eflag == false){
				cout << error;
				eflag = true;
			}
			cout << "Line " << counte << " of event.data event ID " << eID <<str;
		}

		try {//check the patient number
			errorPnum(pNumStr);
		}catch(string str){//patient number invalid
			if(eflag == false){
				cout << error;
				eflag = true;
			}
			cout << "Line " << counte << " of event.data patient number " << pNumStr <<str;
		}
		//convert the patient number to integer
		pNum = atoi(pNumStr.c_str());

		try {//check the cID
			errorCID(cID);
		}catch(string str){//cID invalid
			if(eflag == false){
				cout << error;
				eflag = true;
			}
			cout << "Line " << counte << " of event.data code ID " << cID <<str;
		}
		try{//check the date
			errorDate(Date);
		}
		catch(string str){//date is invalid
			if(eflag == false){
				cout << error;
				eflag = true;
			}
			cout << "Line " << counte << " of event.data event date " << Date <<str;
		}
		string BdTemp = Date;
		Date.clear();
		int slashCount = 0;
		// change the display for the date
		for(int i=0; (unsigned)i<BdTemp.size(); i++)
		{
			if(BdTemp[i] == '/')
			{
				if(slashCount == 0)
				{
					string sub = BdTemp.substr(0,i);
					Date += Month[atoi(sub.c_str())-1] + " ";
					slashCount ++;
				}
				else if(slashCount == 1)
				{
					Date += ",";
					slashCount ++;
				}
			}
			else if(slashCount != 0)
			{
				Date += BdTemp[i];
			}
		}
		eData.setAll(eID, pNum, cID, Date);
		eList.add(eData);
		
	}
// Select an option to display:
	string option;
	cout << "1 patient data by patient number " << endl;
	cout << "2 patient data by patient last name " << endl;
	cout << "3 event data by event ID " << endl;
	cout << "4 event data IDs " << endl;
	cout << "5 end the program " << endl;
	cin >> option;
	cin.ignore(100,'\n');

	bool optionflag = false;
	while(1)
	{
		if(option == "1"){
			int fPnum; // save the patient number which the user wanna to find
			cout << "Enter patient number (0 to return to menu): ";
			cin >>fPnum;
			if(fPnum == 0){
				optionflag = true;
			}else
			{
				patient pTemp;
				bool pfind = pList.find(fPnum,pTemp);// test if the patient number find in the data;
				if(pfind)
				{
					cout << "Patient number		" << pTemp.getPnum() << endl;
					cout << "Last name		" << pTemp.getLastName() << endl;
					cout << "First name		" << pTemp.getFirstName() << endl;
					cout << "Birth date		" << pTemp.getBirthdate() << endl;
					cout << "Floor			" << pTemp.getFloor() << endl;
					cout << "DNA file name		" << pTemp.getDNA() << endl;
					list<Event> eTempList;
					eList.find(fPnum,eTempList);
					if(eTempList.size() > 0)
					{
						//cout << "Event ID(s):" << (*eTempList.begin()).getEventID() << endl;
						cout << "Event ID(s):" ;
						for(list<Event>::iterator it=eTempList.begin(); it!=eTempList.end(); it++)
							{
								cout<<" "<<(*it).getEventID();
							}
							cout<<endl;
					}
					else
					{
						cout << "Event ID(s): none" << endl;;
					}
				}else
				{
					cout << "This patient number: " << fPnum << " didn't find." << endl; 
				}
			}
		}
		else if(option == "2"){
			string fPname; // find patient name
			cout << "Enter patient last name (0 to return to menu): ";
			cin >> fPname;
			if(fPname == "0"){
				optionflag = true;
			}else
			{
			
				list<patient> pTempList;
				pList.find(fPname,pTempList);// test if the patient number find in the data;
				if(pTempList.size() > 0)
				{
					for(list<patient>::iterator pIt=pTempList.begin(); pIt!=pTempList.end(); pIt++)
					{
						cout << "Patient number		" << (*pIt).getPnum() << endl;
						cout << "Last name		" << (*pIt).getLastName() << endl;
						cout << "First name		" << (*pIt).getFirstName() << endl;
						cout << "Birth date		" << (*pIt).getBirthdate() << endl;
						cout << "Floor			" << (*pIt).getFloor() << endl;
						cout << "DNA file name		" << (*pIt).getDNA() << endl;
						list<Event> eTempList;
						eList.find((*pIt).getPnum(),eTempList);
						if(eTempList.size() > 0)
						{
							cout << "Event ID(s):";
							for(list<Event>::iterator it=eTempList.begin(); it!=eTempList.end(); it++)
							{
								cout<<" "<<(*it).getEventID();
							}
							cout<<endl;
						}
						else
						{
							cout << "Event ID(s): none"<<endl;
						}
					}
				}
				else
				{
					cout << "No such patient in the data" << endl;
				}
			}
			
		}
		else if(option == "3"){
			cout << "Enter event ID (0 to return to menu): ";
			string eid;
			cin >>	eid;	
			if(eid == "0"){
				optionflag = true;
			}else
			{
				Event eTemp;
				bool efind = eList.find(eid,eTemp);
				if(efind)
				{
					cout<<"Event ID "<<eTemp.getEventID()<<endl;
					cout<<"Patient number "<<eTemp.getPatientNum()<<endl;
					cout<<"Code ID "<<eTemp.getCodeID()<<endl;
					cout<<"Event date "<<eTemp.getDate()<<endl;
				}
				else
				{
					cout<<"Event ID: none"<<endl;
				}
			}
				
		}
		else if(option == "4"){
			cout << "Enter event ID (0 to return to menu): ";
			string eid; // find patient id
//			cin >> eid;
			char ch[10];
			cin.getline(ch, 10);
			int length = 0;
			length = (int)strlen(ch);
			for(int i = 0; i < 10 ; i++)
				eid += ch[i];
			
 			if(ch[0]== '0' && length == 1 ){
				optionflag = true;
			}else
			{
				list<Event> eTempList;
				eList.find(eid,eTempList);// test if the patient number find in the data;
				if(eTempList.size() > 0)
				{
					int count = 0;
					for(list<Event>::iterator eIt=eTempList.begin(); eIt!=eTempList.end() && count<5; eIt++)
					{
						count ++;
						cout<<(*eIt).getEventID()<<endl;
					}
				}
				else
				{
					cout<<"No event IDs available"<<endl;
				}
			}		
		}
		else if(option == "5"){
			return 0;
		}
		else
		{
			cout << "Invalid option enterd. Please enter a valid option." << endl;
			optionflag = true;
		}
		if(optionflag)
		{
			optionflag = false;
			cout << "1 patient data by patient number " << endl;
			cout << "2 patient data by patient last name " << endl;
			cout << "3 event data by event ID " << endl;
			cout << "4 event data IDs " << endl;
			cout << "5 end the program " << endl;
			cin >> option;
			cin.ignore(100,'\n');

		}
	}
	inPatient.close();
	inEvent.close();
	return 0;
}

