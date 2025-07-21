//#include<iostream>
//using namespace std;
//
//class invalidday{
//	int d;
//public:
//	invalidday(int _d) { d = _d; }
//	void what() {
//		cout << "invalid Day\n";
//	}
//
//};
//class invalidYear {
//	int y;
//public:
//	invalidYear(int _y) { y = _y; }
//	void what() {
//		cout << "invalid Year\n";
//	}
//
//};
//class invalidMonth{
//	int m;
//public:
//	invalidMonth(int _m) { m = _m; }
//	void what() {
//		cout << "invalid Month\n";
//	}
//
//};
//
//int main() {
//	try {
//		int m, d, y;
//		cin >> m >> d >> y;
//		if (d > 30 && d < 1) throw invalidday(d);
//		if (m > 12 && d < 1) throw invalidMonth(m);
//		if (y % 4 == 0 && y % 400) throw invalidYear(y);
//		if (m == 1) cout << "January ";
//		if (m == 2) cout << "February ";
//		if (m == 3) cout << "March ";
//		if (m == 4) cout << "April ";
//		if (m == 5) cout << "May ";
//		if (m == 6) cout << "June ";
//		if (m == 7) cout << "July ";
//		if (m == 8) cout << "August ";
//		if (m == 9) cout << "Septempber ";
//		if (m == 10) cout << "October ";
//		if (m == 11) cout << "November ";
//		if (m == 12) cout << "December ";
//		cout << d << ", " << y << endl;
//
//	}
//	catch (invalidday d) { d.what(); }
//	catch (invalidMonth m) { m.what(); }
//	catch (invalidYear y) { y.what(); }
//
//	
//
//	
//	
//	system("pause");
//	return 0;
//}