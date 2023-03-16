// task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// graphicComponent.cpp: определяет точку входа для консольного приложения.
//

#include "Component.h"
#include "Container.h"
#include "Window.h"
#include "Panel.h"
#include "Button.h"
#include "Line.h"
#include "Label.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

static Window* rootWindow;
static int depth = 0;
void add();
void click();
void showAll();
void move();
string blank();
void toString(Component* c);
int find(string str, char ch);
bool isContainer(Component* c);

int main()
{
	rootWindow = new Window(0, 0, 120, 70);
	rootWindow->_isVisible = true;
	rootWindow->title = "Form";

	
	while (1) {
		int n = 0;
		cout << "Enter number 1-5:\n"
		<< "->1. Add new component\n"
		<< "->2. Click on component\n"
		<< "->3. Move component\n"
		<< "->4. Show all components\n"
		<< "->5. Exit\n"
		<< ">";
		cin >> n;

		switch (n) {
		case 1:
			add();
			break;
		case 2:
			click();
			break;
		case 3:
			move();
			break;
		case 4:
			showAll();
			break;
		case 5: exit(0);
		default: cout << "Wrong command\n";
		}

		
	}
	return 0;
}

void add() {
	try {
		cout << "Select type:\n"
			<< "->1. Window\n"
			<< "->2. Panel\n"
			<< "->3. Button\n"
			<< "->4. Line\n"
			<< "->5. Label\n"
			<< ">";
		int n = 0;
		cin >> n;
		Component* c;
		switch (n) {
		case 1: c = new Window(); break;
		case 2: c = new Panel(); break;
		case 3:  c = new Button(); break;
		case 4: c = new Line(); break;
		case 5: c = new Label(); break;
		default: {cout << "Wrong command";  return; }
		}
		cout << "Select container id:\n";
		showAll();
		int par_id = 0;
		cin >> par_id;
		if (isContainer(rootWindow->findChildById(par_id)))
			((Container*)rootWindow->findChildById(par_id))->addComponent(c);
		else {
			cout << "Component with id does not exist or it can not contain components\n";
			return;
		}
		if (!(dynamic_cast<Line*>(c) == nullptr))
		{
			auto* line = dynamic_cast<Line*>(c);
			int x;
			cout << "Enter x of startPoint: ";
			cin >> x;

			int y;
			cout << "Enter y of startPoint: ";
			cin >> y;

			line->setStartPoint(x, y);

			cout << "Enter x of endPoint: ";
			cin >> x;

			cout << "Enter y of endPoint: ";
			cin >> y;

			line->setEndPoint(x, y);

			string input;
			cout << "Is visible? [y/n] ";
			cin >> input;
			if (input._Equal("n")) line->_isVisible = false;

			cout << "Added\n";
		}
		else if (!(dynamic_cast<Label*>(c) == nullptr)) {
			auto* label = dynamic_cast<Label*>(c);
			string input;
			cout << "Enter x: ";
			cin >> input;
			label->setX(stoi(input));

			cout << "Enter y: ";
			cin >> input;
			label->setY(stoi(input));

			cout << "Enter width: ";
			cin >> input;
			label->setWidth(stoi(input));

			cout << "Enter height: ";
			cin >> input;
			label->setHeight(stoi(input));

			cout << "Enter text: ";
			cin >> input;
			label->setText(input);

			cout << "Is visible? [y/n] ";
			cin >> input;
			if (input._Equal("n")) label->_isVisible = false;

			cout << "Added\n";
		}
		else {
			string input;
			cout << "Enter x: ";
			cin >> input;
			c->setX(stoi(input));

			cout << "Enter y: ";
			cin >> input;
			c->setY(stoi(input));

			cout << "Enter width: ";
			cin >> input;
			c->setWidth(stoi(input));

			cout << "Enter height: ";
			cin >> input;
			c->setHeight(stoi(input));

			cout << "Is visible? [y/n] ";
			cin >> input;
			if (input._Equal("n")) c->_isVisible = false;

			cout << "Added\n";
		}
	}
	catch (exception e) {
		cout << "Wrong command\n";
	}
}


void click() {

	try {
		cout << "Enter x: ";
		int x = 0;
		cin >> x;
		cout << "Enter y: ";
		int y = 0;
		cin >> y;
		rootWindow->onClick(x, y);
	}
	catch (exception e) {
		cout << "Wrong command\n";
	}


}

void move() {
	try {
		cout << "Select component id:\n";
		showAll();
		int id = 0;
		cin >> id;

		Component* c = rootWindow->findChildById(id);
		if (!(dynamic_cast<Line*>(c) == nullptr))
		{
			auto* line = dynamic_cast<Line*>(c);
			int x1;
			cout << "Enter x of startPoint: ";
			cin >> x1;

			int y1;
			cout << "Enter y of startPoint: ";
			cin >> y1;

			int x2;
			cout << "Enter x of endPoint: ";
			cin >> x2;

			int y2;
			cout << "Enter y of endPoint: ";
			cin >> y2;

			line->move(x1, y1, x2, y2);

			cout << "Moved\n";
		}
		else 
		{
		cout << "Enter x: ";
		int x = 0;
		cin >> x;

		cout << "Enter y: ";
		int y = 0;
		cin >> y;

		(rootWindow->findChildById(id))->move(x, y);
		cout << "Moved\n";
	}
	}
	catch (exception e) {
		cout << "Wrong command\n";
	}
}

void showAll() {
	depth = 0;
	depth += 2;
	cout << rootWindow->toString() << "\n";

	for (auto* c: rootWindow->getComponents())
	{
		toString(c);
	}

}

void toString(Component* c) {
	cout << blank() << c->toString() << "\n";
	if (isContainer(c)) {
		list<Component*> list = ((Container*)c)->getComponents();
		depth += 2;
		for(auto* c1: list)
		{
			toString(c1);
		}
		depth -= 2;
	}
}

string blank() {
	string res = "";
	for (int i = 0; i < depth; i++) {
		res += " ";
	}
	return res;
}

int find(string str, char ch) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ch) return i;
	}
	return -1;

}

bool isContainer(Component* c) {
	return (!(dynamic_cast<Container*>(c) == nullptr));
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
