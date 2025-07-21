#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<math.h> 
#include<string.h>


using namespace std;
template<class T>
class queue{
	class node{
	public:
		T data;
		node* next;
		node(){ next = nullptr; }
		node(T ele){
			data = ele;
			next = nullptr;
		}
	};
	node* head,*front,*rear;
	
	int size;
public:
	queue(){ 
		head = new node();
		head->next = NULL;
		front=rear=head; 
		size = 0;
	}
	bool isEmpty(){ return size == 0; }
	void enqueue(T ele){
		node* temp = new node(ele);
		if (isEmpty()){
			front = rear = temp;
			head->next = temp;
			temp->next = temp;
		}
		else{
			rear->next = temp;
			temp->next = front;
			rear = rear->next;
		}
		size++;
	}
	void dequeue(){
		node* temp = front;
		if (isEmpty())
			cout << "Empty Queue\n";
		else{
			front = front->next;
			rear->next = front;
			delete temp;
			size--;
		}
	}
	void print(sf::RenderWindow *window){
		node *p = front;
		float cx = window->getSize().x / 2.f;
		float cy = window->getSize().y / 2.f;
		float angle=0;
		float radius = 300;
		float radius_t = 330;
		float x, y, xt, yt;
		sf::CircleShape circle;
		sf::Texture player;
		player.loadFromFile("man.png");
		circle.setFillColor(sf::Color::White);
		circle.setRadius(15.0f);
		circle.setTexture(&player);

		sf::Text text;
		string num;
		text.setCharacterSize(16);
		text.setFillColor(sf::Color::White);
		sf::Font font;
		font.loadFromFile("arial.ttf");
		text.setFont(font);
		do {
			x = cx + radius * cos(angle * 3.14159 / 180);
			y = cy + radius * sin(angle * 3.14159 / 180);
			circle.setPosition(x, y);
			xt = cx + radius_t * cos(angle * 3.14159 / 180);
			yt = cy + radius_t * sin(angle * 3.14159 / 180);
			text.setPosition(xt, yt);
			num = to_string(p->data);
			text.setString(num);
			p = p->next;
			angle += 360.0 / size;
			window->draw(circle);
			window->draw(text);
		} while (p != front);

	}
	void print() {
		node* p = front;
		do{
			cout << p->data << " ";
			p = p->next;
		} while (p != front);
		cout << endl;
	}
	int Size(){ return size; }
	T Front(){ return front->data; }
	T Rear(){ return rear->data; }
	void next(){
		front = front->next;
		rear = rear->next;
	}
    ~queue(){while(size) dequeue();}
};