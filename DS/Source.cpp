#include<iostream>
#include<SFML\Graphics.hpp>
#include<math.h> 
#include"mycircularqueue.h"
#include<cstdlib>
#include<time.h>
#include<Windows.h>

using namespace std;

int main() {
	queue<int> q;
	int k, N;
	cout << "Enter the number of people: ";
	cin >> N;
	cout << "Enter the number of passes: ";
	cin >> k;
	for (int i = 1; i <= N; i++)
		q.enqueue(i);
	int start = rand() % N;
	for (int i = 0; i < start; i++)
		q.next();
	bool flag=0;
	sf::RenderWindow window(sf::VideoMode(800, 800), "Josephus Problem",sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape obj;
	sf::Texture wall;
	wall.loadFromFile("your.png");
	obj.setSize(sf::Vector2f(800.f, 800.f));
	obj.setTexture(&wall);
	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				cout <<"width: " << evnt.size.width << " height: " << evnt.size.height << endl;
				break;
			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128)
					printf("%c", evnt.text.unicode);
				break;
			case sf::Event::KeyPressed:
				if (evnt.key.code == sf::Keyboard::Enter && q.Size() != 1) {
					std::cout << "Enter key pressed!" << std::endl;
					flag = 1;
				}
				if (evnt.key.code == sf::Keyboard::Enter && q.Size() == 1) {
					window.close();
				}
				break;
			}
		}
		
		window.clear();
		window.draw(obj);
		if (q.Size() != 1&& flag) {
			for (int i = 0; i < k; i++)
				q.next();
			q.dequeue();
			q.print(&window);
			q.print();
			flag = 0;
		}
		q.print(&window);
	
		window.display();

	}
	cout << "Winning Player is: " << q.Front() << endl;;
	
	
	return 0;
}