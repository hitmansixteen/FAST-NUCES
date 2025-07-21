#include<iostream>
#include<string.h>
using namespace std;

class person {
	string first_name;
	string last_name;
protected:
	int age;
public:
	void set_age(int a) { age = a; }
	void set_first_name(string fn) { first_name = fn; }
	void set_last_name(string ln) {  last_name = ln; }
	string get_first_name() { return first_name; }
	string get_last_name() { return last_name; }
};

class student : public person {
protected:
	int roll_no;
	float cgpa;
public:
};

class undergraduate:public student {
	string fyp_name;
	string supervisor_name;
public:
	int get_age() { return age; }
	int get_cgpa() { return cgpa; }
	void set_cgpa(int c) { cgpa = c; }
	int get_roll_no() { return roll_no; }
	void set_roll_no(int r) { roll_no = r; }
	string get_supervisor_name() { return supervisor_name; }
	void set_supervisor_name(string s) { supervisor_name = s; }
	string get_fyp_name() { return fyp_name; }
	void set_fyp_name(string f) { fyp_name = f; }
};

class graduate : public undergraduate {
	string thesis_topic;
	string supervisor_name;
public:
	int get_age() { return age; }
	int get_cgpa() { return cgpa; }
	void set_cgpa(int c) { cgpa = c; }
	int get_roll_no() { return roll_no; }
	void set_roll_no(int r) { roll_no = r; }
	string get_supervisor_name() { return supervisor_name; }
	void set_supervisor_name(string s) { supervisor_name = s; }
	string get_thesis_topic() { return thesis_topic; }
	void set_thesis_topic(string t) { thesis_topic = t; }
};

class faculty : public graduate{
	int course_count;
	int extension;
public:
	int get_age() {return age;}
	void set_course_count(int course) { course_count = course; }
	void set_extension(int ex) { extension = ex; }
	int get_course_count() { return course_count; }
	int get_extension() { return extension; }
};


int main() {
	/////////////faculty/////////////////
	faculty p1;
	p1.set_first_name("sonia "); p1.set_last_name("anum");
	cout << p1.get_first_name() << p1.get_last_name() << endl;
	p1.set_age(30);
	cout <<"age:" << p1.get_age() << endl;
	/////////////graduate/////////////////
	graduate p2;
	p2.set_first_name("abdullah "); p2.set_last_name("naeem");
	cout << p2.get_first_name() << p2.get_last_name() << endl;
	p2.set_age(20);
	cout << "age:" << p2.get_age() << endl;
	/////////////undergraduate/////////////////
	undergraduate p3;
	p2.set_first_name("laraib "); p2.set_last_name("akhtar");
	cout << p2.get_first_name() << p2.get_last_name() << endl;
	p3.set_age(16);
	cout << "age:" << p3.get_age() << endl;

	return 0;
	system("pause");
}