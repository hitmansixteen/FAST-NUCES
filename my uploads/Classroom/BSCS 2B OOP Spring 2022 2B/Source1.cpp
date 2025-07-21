//#include<iostream>
//using namespace std;
//
//class tornadoException {
//	int _m;
//public:
//	tornadoException() { _m = -1; }
//	tornadoException(int m) { _m = m; }
//	void what() {
//		if (_m == -1)
//			cout << "Tornado: Take cover immediately!\n";
//		else
//			cout << "Tornado: " << _m << " miles away; and approaching!\n";
//	}
//};
//
//int main() {
//	try {
//		int m;
//		cin >> m;
//		if(!cin)
//			throw tornadoException();
//		throw tornadoException(m);
//		
//	}
//	catch(tornadoException t) {
//		t.what();
//	}
//	system("pause");
//	return 0;
//}