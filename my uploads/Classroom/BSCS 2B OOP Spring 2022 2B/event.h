#include <iostream>
#include <cstring>

using namespace std;

class Event {
private:
	char* event_name;
	char* event_venue;
	char event_date[11];
	char event_time[9];

public:
	Event() {
		cout << "Default Constructor Called\n";
		
		event_name = nullptr;
		event_venue = nullptr;
		char date[11] = "00-00-0000";
		for (int i = 0; i < 11; i++)
			event_date[i] = date[i];

		char time[9] = "00:00 am";
		for (int i = 0; i < 9; i++)
			event_date[i] = time[i];
		
	}
	Event(char event_name[20], char event_venue[50], char event_date[11], char event_time[9]) {
		cout << "Overloaded Constructor Called\n";
		
		setName(event_name);
		setVenue(event_venue);
		setDate(event_date);
		setTime(event_time);

		
	}
	char* userInput(char ptr[]) {

		int size = strlen(ptr);

		char* arr = new char[size + 1];
		for (int i = 0; i <= size; i++)
			arr[i] = ptr[i];

		return arr;
	}

	void setName(char* name) {event_name = userInput(name);}
	void setVenue(char* venue) {event_venue = userInput(venue);}
	void setDate(char date[11]) {
		for (int i = 0; i < 11; i++)
			event_date[i] = date[i];
	}
	void setTime(char time[9]) {
		for (int i = 0; i < 9; i++)
			event_time[i] = time[i];
	}


	char* getName() { return event_name; }
	char* getVenue() { return event_venue; }
	void getDate() {  cout<< event_date; }
	void getTime() {  cout<< event_time; }


	~Event() {
		cout << "Destructor Called\n";
		delete[] event_name;
		delete[] event_venue;

		
	}
};

Event* addEventOver(Event* eve) {
	char name[20], venue[50], date[11], time[9];
	cin.ignore();
	cout << "Add New Event\n";

	cout << "Enter event name: ";
	cin.getline(name, 20);

	cout << "Enter event venue: ";
	cin.getline(venue, 50);

	cout << "Enter event date: ";
	cin.getline(date,11);

	cout << "Enter event time: ";
	cin.getline(time, 9);

	eve = new Event(name, venue, date, time);
	return eve;
}

void addEventSet(Event eve) {
	char name[20], venue[50], date[11], time[9];
	cin.ignore();
	cout << "Add New Event\n";

	cout << "Enter event name: ";
	cin.getline(name, 20);

	cout << "Enter event venue: ";
	cin.getline(venue, 50);

	cout << "Enter event date: ";
	cin.getline(date, 11);

	cout << "Enter event time: ";
	cin.getline(time, 9);

	eve.setName(name);
	eve.setVenue(venue);
	eve.setDate(date);
	eve.setTime(time);
}
void displayEvent(Event* eve) {
	cout << "Event name: " << eve->getName() << endl;
	cout << "Event venue: " << eve->getVenue() << endl;
	cout << "Event date: ";
	eve->getDate();
	cout << endl;
	cout << "Event time: ";
	eve->getTime();
	cout << endl;
}


