#include<iostream>
#include<windows.h>
using namespace std;



char **Generate_system(int &rows, int &cols){
	rows = 6; cols = 6;
	char **system = new char*[rows];
	for (int i = 0; i < rows; i++){
		system[i] = new char[cols];
	}

	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			*(*(system + i) + j) = '*';
		}
	}

	return system;
}

void Reserved_Ticket(char **&seat_plan, int &rows, int &cols, char ticket_type){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			cout << "Enter your ticket type: ";
			cin >> ticket_type;
			if (ticket_type == 'F'){
				for (int i = 0; i < 2; i++){
					for (int j = 0; j < cols; j++){
						if (seat_plan[i][j] != 'X'){
							seat_plan[i][j] = 'X';
							break;
						}
							
					}
				}
			}
			else if (ticket_type == 'B'){
				for (int i = 2; i < 4; i++){
					for (int j = 0; j < cols; j++){
						if (seat_plan[i][j] != 'X'){
							seat_plan[i][j] = 'X';
							break;
						}
							
					}

				}
			}
			else if (ticket_type == 'E'){
				for (int i = 4; i < 6; i++){
					for (int j = 0; j < cols; j++){
						if (seat_plan[i][j] != 'X'){
							seat_plan[i][j] = 'X';
							break;

						}
							
					}

				}
			}
			else if (ticket_type == '1'){
				return;

			}
		}

	}
}
	void show_record(char **&seat_plan, int &rows, int &cols){
		int count_f = 0;
		int count_b = 0;
		int count_e = 0;
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < cols; j++){
				if (seat_plan[i][j] == 'X')
					count_f++;
			}
		}
		for (int i = 2; i < 4; i++){
			for (int j = 0; j < cols; j++){
				if (seat_plan[i][j] == 'X')
					count_b++;
			}
		}
		for (int i = 4; i < 6; i++){
			for (int j = 0; j < cols; j++){
				if (seat_plan[i][j] == 'X')
					count_e++;
			}
		}

		cout << "Total No. of reserved seats in First class: " << count_f << endl;
		cout << "Total No. of reserved seats in BUSINESS class: " << count_b << endl;
		cout << "Total No. of reserved seats in ECONOMY class: " << count_e << endl;
		cout << "Total No. of available seats in First class: " << 12 - count_f << endl;
		cout << "Total No. of available seats in business class: " << 12 - count_b << endl;
		cout << "Total No. of available seats in econonmy class: " << 12 - count_e << endl;

		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				cout << *(*(seat_plan + i) + j) << " ";
			}
			cout << endl;
		}
	}

	int main(){
		int rows, cols;
		char ticket_type='0';
		char **system = Generate_system(rows, cols);

		Reserved_Ticket(system, rows, cols, ticket_type);
		
		show_record(system, rows, cols);

		for (int i = 0; i < rows; i++){
			delete[] system[i];
			system[i] = nullptr;
		}
		delete[] system;
		system = nullptr;
		int x = 1;
		while (x == 1){

		}


		return 0;
	}