#include<iostream>
using namespace std;

class Event{
	char* event_name;
	char* event_venue;
	char event_date[11];
	char event_time[9];
public:
	Event(){cout << "Default Constructor Called\n";}
	Event(char event_name[20], char event_venue[50], char event_date[11], char event_time[9]){ 
		cout << "Overloaded Constructor Called\n"; 

		char *arr = new char[strlen(event_name) + 1];
		int i = 0;
		for (; i < strlen(event_name) + 1; i++){
			arr[i] = event_name[i];
		}
		arr[i + 1] = '\0';
		this->event_name = arr;
		arr = nullptr;

		char *arr = new char[strlen(event_venue) + 1];
		i = 0;
		for (; i < strlen(event_venue) + 1; i++){
			arr[i] = event_venue[i];
		}
		arr[i + 1] = '\0';
		this->event_venue = arr;
		arr = nullptr;

		
		
		for (int i = 0; i < 11; i++){
			this->event_date[i] = event_date[i] ;
		}
		
		

		
		for (int i = 0; i < 9; i++){
			this->event_time[i] = event_time[i];
		}
		
	}

	void set_event_name(char* name){ event_name = name; }
	void set_event_venue(char* venue){ event_venue = venue; }
	void set_event_date(char date[]){ event_date = date; }
	void set_event_time(char time[]){ event_time = time; }

	char* get_event_name(){ return event_name; }
	char* get_event_venue(){ return event_venue; }
	char* get_event_date(){ return event_date; }
	char* get_event_time(){ return event_name; }


	~Event(){
		delete[] event_name;
		event_name = nullptr;
		delete[] event_venue;
		event_venue = nullptr;
	}

	void displayEvent(){
		cout << event_name<<endl;
		cout << event_venue<<endl;
		cout << event_date << endl;
		cout << event_time << endl;

	}

};
//void userinput(char* &event_name, char *&event_venue, char *&event_date, char *&event_time){
//	int size_name;
//	int size_venue;
//	cin >> size_name;
//	event_name = new char[size_name];
//	gets(event_name);
//	event_venue = new char[size_venue];
//	gets(event_venue);
//
//	gets(event_date);
//	gets(event_time);
//
//}
Event* addEventOver(Event *eve){
	int size_name;
	int size_venue;
	cin >> size_name;
	char*event_name = new char[size_name];
	gets(event_name);
	char*event_venue = new char[size_venue];
	gets(event_venue);
	char* event_date;
	gets(event_date);
	char* event_time;
	gets(event_time);

	
}

void addEventSet(Event eve){
	int size_name;
	int size_venue;
	cin >> size_name;
	char*event_name = new char[size_name];
	gets(event_name);
	char*event_venue = new char[size_venue];
	gets(event_venue);
	char* event_date;
	gets(event_date);
	char* event_time;
	gets(event_time);
}