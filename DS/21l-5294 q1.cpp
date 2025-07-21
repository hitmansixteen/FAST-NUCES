#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int find(string c, string s) {
	int index = -1;
	int linelength = s.length();
	int length = c.length();
	for (int i = 0; i < linelength; i++) {
		if (s[i] == c[0] && s[i + 1] == c[1] && length == 2) {
			index = i; break;
		}
		else if (s[i] == c[0] && length == 1) {
			index = i; break;
		}
	}
	return index;
}
class XMLData {
public:
	string tag;
	int line;
	XMLData() { tag = '\0'; line = 0; }
	XMLData(string t) { tag = t; line = 1; }
	void setline(int l) { line = l; }
	void settag(string t) { tag = t; }
	friend ostream& operator<<(ostream& out, XMLData d) {
		out << d.line << ". " << d.tag;
		return out;
	}
};
template <class T>
class stack {
	class node {
	public:
		T data;
		node* next;
		node() { data = 0; next = NULL; }
		node(const T val) {
			data = val;
			next = NULL;
		}
	};
	node* top;
public:
	stack() { top = NULL; }
	bool isEmpty() {
		if (!top)
			return true;
		return false;
	}
	bool push(const T& val) {
		node* temp = new node(val);
		temp->next = top;
		top = temp;
		/*print();*/
		return true;
	}
	bool pop(T& val) {
		if (!isEmpty()) {
			val = top->data;
			node* temp = top;
			top = top->next;
			delete temp;
			/*print();*/
			return true;
		}
		return false;
	}
	bool Top(T &val) { 
		if (!isEmpty()) {
			val = top->data;
			return true;
		}
		return false;
	}
	void print() {
		node* temp = top;
		cout << endl;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

void checkxml(string filename) {
	stack<XMLData> s1;
	ifstream fin;
	fin.open(filename);
	int line = 0;
	bool comment = false;
	while (!fin.eof()) {
		bool prolog = 1;
		bool error = 0;
		comment = false;
		XMLData x1;
		string text;
		getline(fin, text);
		string maintext = text;
		line++;
		x1.settag(text);
		x1.setline(line);
		if (line == 1) {
			int opentag = find("<?", text);
			int closetag = find("?>", text);
			if (opentag == -1 && closetag == -1)
				cout << "Prolog does not exist!\n";
			else if(opentag == -1) {
				cout << "Opening tags of prolog not found at line " << line << endl;
				prolog = 0;
			}
			else if (opentag == -1) {
				cout << "Closing tags of prolog not found at line " << line << endl;
				prolog = 0;
			}
		}
		string starting_tag, ending_tag;
		string temp = text;
		int length = text.length();
		int opentag = find("<", text);
		int backslash = find("</", text);
		int closetag = find(">", text);
		starting_tag = temp.substr(opentag + 1, closetag - 1);
		int space = find(" ", starting_tag);
		starting_tag = starting_tag.substr(0, space);
		if (closetag < length)
			text = text.substr(closetag + 1, length);
		int backslash_close = find(">", text);
		if (backslash != -1){
			ending_tag = temp.substr(backslash + 2, backslash_close - 1);
			int len = ending_tag.length();
			ending_tag = ending_tag.substr(0, len - 1);
		}
		if (opentag != -1){
			string temp = maintext;
			if (temp[opentag + 1] == '!'){
				comment = true;
				if (temp[opentag + 2] == '-'){
					if (temp[opentag + 3] != '-'){
						cout << "Comment properly at line no " << line << endl;
						comment = true;
					}
				}
				else{
					cout << "Comment properly at line no " << line << endl;
					comment = true;
				}
				if (closetag == -1)
					cout << "Comment properly at line no " << line << endl;
			}
			if (closetag != -1){
				if (temp[closetag - 1] == '-'){
					if (temp[closetag - 2] != '-'){
						cout << "Comment properly at line no " << line << endl;
					}
				}
			}
		}
		if (line > 0 && prolog == 1 && comment == false){
			if (opentag == -1 && closetag == -1){
				cout << "Missing tag at line " << line << endl;
				error = true;
			}
			else if (opentag == -1 || (opentag == backslash && opentag != 0)){
				cout << "Missing tag at line " << line << endl;
				error = true;
			}
			else if (closetag == -1 || (closetag == -1 && backslash != -1 && backslash != 0) || (closetag > backslash && backslash != -1 && backslash != 0)){
				cout << "Missing tag at line " << line << endl;
				error = true;
			}
			if (backslash != -1 || backslash_close != -1){
				if (backslash == -1){
					cout << "Missing tag at line " << line << endl;
					error = true;
				}
				else if (backslash_close == -1 && backslash != -1 && backslash != 0 && closetag < backslash){
					cout << "Missing tag at line " << line << endl;
					error = true;
				}
			}
			if (starting_tag != ending_tag && backslash != -1 && backslash_close != -1 && opentag != -1 && closetag != -1){
				cout << "Tag mismatch at line " << line << endl;
				error = true;
			}

		}
		if (error == false && line > 1 && comment == false){
			if (backslash == -1 && backslash_close == -1){
				x1.settag(starting_tag);
				x1.setline(line);
				s1.push(x1);
			}
			else if (opentag == backslash && backslash != -1){
				XMLData x2;
				s1.pop(x2);
				if (x2.tag != ending_tag)
					cout << "Tag mismatch at line no " << x2.line << endl;
			}

		}
		int attribute = find("=", maintext);
		if (attribute != -1 && line > 1 && comment == false){
			string temp = maintext;
			int templen = temp.length();
			int quote = find("'", temp);
			if (quote != -1){
				temp = temp.substr(quote + 1, templen);
				quote = find("'", temp);
			}
			if (quote == -1){
				char qute = '"';
				string s(1, qute);
				quote = find(s, temp);
				if (quote != -1){
					temp = temp.substr(quote + 1, templen);
					quote = find(s, temp);
				}
			}
			if (quote == -1)
				cout << "Define attribute properly at line no " << line << endl;

		}

	}

	if (s1.isEmpty() == false && comment == false){
		while (s1.isEmpty()){
			XMLData x1;
			s1.pop(x1);
			cout << "Tag at line no " << line << endl;
		}
	}
	
}



int main() {
	checkxml("xml.txt");
	return 0;

}