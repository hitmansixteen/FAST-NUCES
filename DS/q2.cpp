#include<iostream>
#include<string>
#include<assert.h>
#include<fstream>

using namespace std;

template<typename v>
class HashMap {
	class HashItem {
	public:
		int key;
		v value;
		short status;
		HashItem() {
			key = 0;
			status = 0;
		}
		HashItem& operator=(HashItem& obj) {
			key = obj.key;
			value = obj.value;
			status = obj.status;

			return *this;
		}
	};
	HashItem* hashArray;
	int capacity;
	int currentElements;

	virtual int getNextCandidateIndex(int key, int i) { return key + i; }
public:
	HashMap() {
		hashArray = NULL;
		capacity = 0;
		currentElements = 0;
	}
	HashMap(int const c) {
		assert(c > 1);
		capacity = c;
		currentElements = 0;
		hashArray = new HashItem[capacity];
	}
	void setCapacity(int c) {
		assert(c > 1);
		capacity = c;
		currentElements = 0;
		hashArray = new HashItem[capacity];
	}
	int getCapacity() { return capacity; }
	void doubleCapacity() {
		HashItem* temp = new HashItem[capacity];

		for (int i = 0; i < capacity; i++)
			temp[i] = hashArray[i];
		delete[] hashArray;
		capacity *= 2;
		hashArray = new HashItem[capacity];
		for (int i = 0; i < capacity/2; i++)
			if (temp[i].status == 2)
				insert(temp[i].key, temp[i].value);
		delete[] temp;
	}
	void insert(int const key, v const value) {
		int index = key % capacity;
		if (hashArray[index].status == 2) {
			int i = 1;
			while (hashArray[index].status) {
				index = getNextCandidateIndex(key, i) % capacity;
				i++;
			}
		}
		hashArray[index].status = 2;
		hashArray[index].key = key;
		hashArray[index].value = value;
		currentElements++;
		if (static_cast<float>(currentElements) / static_cast<float>(capacity) >= 0.75)
			doubleCapacity();
	}
	bool deleteKey(int const key) {
		if (hashArray[key % capacity].key == key || hashArray[key % capacity].status == 2) {
			hashArray[key % capacity].status = 1;
			return true;
		}
		else {
			int index;
			int i = 1;
			do {
				index = getNextCandidateIndex(key, i) % capacity;
				i++;
			} while (hashArray[index].key != key && index != (key % capacity));
			if (hashArray[index].status == 2 && index != (key % capacity)){
				hashArray[index].status = 1;
				return true;
			}
		}
		return false;
	}
	v* get(int key) {
	
		if (hashArray[key % capacity].key == key || hashArray[key % capacity].status == 2)
			return &hashArray[key % capacity].value;
		else{
			int index;
			int i = 1;
			do {
				index = getNextCandidateIndex(key, i) % capacity;
				i++;
			} while (hashArray[index].key != key && index != (key % capacity));

			if (hashArray[index].status == 2 && index != (key % capacity))
				return &hashArray[index].value;
		}
		return NULL;
	}
	~HashMap() {
		delete[] hashArray;
	}
};
template<typename v>
class QHashMap :public HashMap<v> {
	int getNextCandidateIndex(int key, int i) { return key + (i ^ 2); }
};
template<typename v>
class DHashMap :public HashMap<v> {
	int getNextCandidateIndex(int key, int i) { 
		int firstValue = key % this->getCapacity();
		int secondValue = (17 - (key % 17));
		int candidateValue = (firstValue + i * secondValue) & this->getCapacity();
		return candidateValue;
	}
};

void populateHash(string filename, HashMap<string>* hash) {
	fstream file(filename);
	if (file.is_open()) {
		string value;
		int capacity;
		int key;

		file >> capacity;
		hash->setCapacity(capacity);
		while (!file.eof()) {
			file >> key;
			getline(file, value, '\n');
			hash->insert(key, value);
		}
	}
	else
		cout << "File can't be opened\n";
}

int main() {
	HashMap<string>* map;
	map = new HashMap<string>;
	populateHash("students.txt", map);
	cout << *map->get(9);
	map->deleteKey(9);
	delete map;
	map = new QHashMap<string>;
	populateHash("students.txt", map);
	cout << *map->get(98);
	map->deleteKey(98);
	delete map;
	map = new DHashMap<string>;
	populateHash("students.txt", map);
	cout << *map->get(101);
	map->deleteKey(101);
	delete map;
	return 0;
}

