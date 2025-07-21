#include<iostream>
using namespace std;

template<typename v>
class HashMap{
	class HashItem{
	public:
		int key;
		v value;
		short status;
		HashItem(){
			key = 0;
			status = 0;
			value = NULL;
		}
	};
	HashItem* hashArray;
	int capacity;
	int currentElements;
	virtual int getNextCandidate(int key, int i){ return key + i }
	void doubleCapacity(){

	}
public:
	HashMap(){
		hashArray = new HashItem[10];
	}
	HashMap(int i){
		assert(i > 1);
		capacity = i;
		hashArray = new HashItem[capacity];
	}
	void insert(int const key, v const value){
		int index = key % capacity;
		if (hashArray[index].status == 0 || hashArray[index].status == 1){
			hashArray[index].value = value;
			hashArray[index].key = key;
			hashArray[index].status = 2;
			currentElements++;
			float loadfactor = currentElements / capacity;

			return;
		}
		else{
			int i = 1;
			while (hashArray[index].status == 2){
				key = getNextCandidate(key, i);
				i++;
				index = key % capacity;
			}	
		}
		insert(key, value);
	}
	bool deleteKey(int const key)const{
		int index = key % capacity;
		if (hashArray[index].key == key){
			hashArray[index].status = 1;
			currentElements--;
			return true;
		}
		else if (hashArray[index].status == 0 || hashArray[index].status == 1)
			return false;
		else{
			int i = 1;
			while (hashArray[index].key != key && hashArray[index].status != 0){
				key = getNextCandidate(key, i);
				i++;
				index = key % capacity;
			}
		}
			
		delete(key, value);
	}
	v* get(int const key) const{
		int index = key % capacity;
		if (hashArray[index].key == key){
			return hashArray[index].value;
		}
		else if (hashArray[index].status == 0 || hashArray[index].status == 1)
			return nullptr;
		else{
			int i = 1;
			while (hashArray[index].key != key && hashArray[index].status != 0){
				key = getNextCandidate(key, i);
				i++;
				index = key % capacity;
			}
		}
		get(key, value);
	}
	~HashMap(){ delete[] hashArray; }

};
template<typename v>
class QHashMap: public HashMap<v>{

};

int main()
{


	system("pause");
	return 0;
}