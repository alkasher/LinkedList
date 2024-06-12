#include "LinkedList.hpp"

void test1() {
	std::cout << "test1\n\n";
	int* a = new int[10];
	for (int i = 0; i < 10; ++i) {
		a[i] = i;
	}
	LinkedList<int> list(a, 10);
	for (int i = 0; i < 10; ++i) {
		std::cout << list[i]->get_info() << " ";
	}
	list.push_back(12);
	std::cout << list[10]->get_info() << " ";
	std::cout << list.get_tail()->get_info() << " ";
}

void test2() {
	std::cout << "\n\ntest2\n\n";
	
	LinkedList<int> list;
	std::cout << "\nsize : \n";
	std::cout << list.size();
	list.push_back(6);
	std::cout << "\nsize : \n";
	std::cout << list.size() << std::endl;
	std::cout << list.get_tail()->get_info() << " ";
	std::cout << list.get_head()->get_info() << " ";
	list.push_back(8);
	std::cout << '\n';
	std::cout << list.get_tail()->get_info() << " ";
	std::cout << list.get_head()->get_info() << " ";
	list.push_back(4);
	std::cout << '\n';
	std::cout << list.get_tail()->get_info() << " ";
	std::cout << list.get_head()->get_info() << " ";
	std::cout << "\nList:\n";
	list.print();
	std::cout << "\nsize : \n";
	std::cout << list.size();
	for (int i = 0; i < 10; ++i) {
		list.push_back(i);
	}
	list.print();
	std::cout << "\nsize : \n";
	std::cout << list.size();

}

void test3() {
	std::cout << "\n\ntest3\n\n";
	LinkedList<int> list;
	list.push_back(6);
	int* a = new int[10];
	for (int i = 0; i < 10; ++i) {
		a[i] = i + 2;
	}
	list.push_back(a, 10);
	list.print();
	std::cout << " \n";
	std::cout << list.get_head()->get_info();
	std::cout << '\n';
	std::cout << list.get_tail()->get_info();
}

void test4() {
	std::cout << "\n\ntest4\n\n";
	LinkedList<int> list;
	list.insert(0, 5);
	list.print();
	std::cout << " \n";
	std::cout << "head: " << list.get_head()->get_info();
	std::cout << '\n';
	std::cout << "tail: " << list.get_tail()->get_info();
	list.insert(1, 6);
	std::cout << "\n\nList:\n\n";
	list.print();
	std::cout << " \n";
	std::cout << "head: " << list.get_head()->get_info();
	std::cout << '\n';
	std::cout << "tail: " << list.get_tail()->get_info();
	list.insert(0, 10);
	std::cout << "\n\nList:\n\n";
	list.print();
	std::cout << " \n";
	std::cout << "head: " << list.get_head()->get_info();
	std::cout << '\n';
	std::cout << "tail: " << list.get_tail()->get_info();
	list.insert(0, 11);
	std::cout << "\n\nList:\n\n";
	list.print();
	std::cout << " \n";
	std::cout << "head: " << list.get_head()->get_info();
	std::cout << '\n';
	std::cout << "tail: " << list.get_tail()->get_info();
	list.insert(1, 12);
	std::cout << "\n\nList:\n\n";
	list.print();
	std::cout << " \n";
	std::cout << "head: " << list.get_head()->get_info();
	std::cout << '\n';
	std::cout << "tail: " << list.get_tail()->get_info();
	list.insert(3, 14);
	std::cout << "\n\nList:\n\n";
	list.print();
	std::cout << " \n";
	std::cout << "head: " << list.get_head()->get_info();
	std::cout << '\n';
	std::cout << "tail: " << list.get_tail()->get_info();
	list.insert(5, 7);
	std::cout << "\n\nList:\n\n";
	list.print();
	std::cout << " \n";
	std::cout << "head: " << list.get_head()->get_info();
	std::cout << '\n';
	std::cout << "tail: " << list.get_tail()->get_info();
	list.insert(6, 8);
	std::cout << "\n\nList:\n\n";
	list.print();
	std::cout << " \n";
	std::cout << "head: " << list.get_head()->get_info();
	std::cout << '\n';
	std::cout << "tail: " << list.get_tail()->get_info();
	list.insert(8, 9);
	std::cout << "\n\nList:\n\n";
	list.print();
	std::cout << " \n";
	std::cout << "head: " << list.get_head()->get_info();
	std::cout << '\n';
	std::cout << "tail: " << list.get_tail()->get_info();
	list.insert(8, 100);
	std::cout << "\n\nList:\n\n";
	list.print();
	std::cout << " \n";
	std::cout << "head: " << list.get_head()->get_info();
	std::cout << '\n';
	std::cout << "tail: " << list.get_tail()->get_info();
	list.insert(10, 150);
	std::cout << "\n\nList:\n\n";
	list.print();
	std::cout << " \n";
	std::cout << "head: " << list.get_head()->get_info();
	std::cout << '\n';
	std::cout << "tail: " << list.get_tail()->get_info();
	list.insert(10, 200);
	std::cout << "\n\nList:\n\n";
	list.print();
	std::cout << " \n";
	std::cout << "head: " << list.get_head()->get_info();
	std::cout << '\n';
	std::cout << "tail: " << list.get_tail()->get_info();
	list.insert(1, 250);
	std::cout << "\n\nList:\n\n";
	list.print();
	std::cout << " \n";
	std::cout << "head: " << list.get_head()->get_info();
	std::cout << '\n';
	std::cout << "tail: " << list.get_tail()->get_info();
	list.insert(0, 300);
	std::cout << "\n\nList:\n\n";
	list.print();
	std::cout << " \n";
	std::cout << "head: " << list.get_head()->get_info();
	std::cout << '\n';
	std::cout << "tail: " << list.get_tail()->get_info();
}

void test5() {
	LinkedList<int> list;
	for (int i = 0; i < 10; ++i) {
		list.insert(i, i);
	}
	list.print();
	list.remove(9);
	list.print();
	list.remove(7);
	list.print();
	list.remove(7);
	list.print();
	list.remove(1);
	list.print();
	list.remove(0);
	list.print();
	list.remove(0);
	list.print();
	list.remove(2);
	list.print();
	list.remove(2);
	list.print();
	list.remove(1);//list.remove(0);
	list.print();
	list.remove(0);
	list.print();
}