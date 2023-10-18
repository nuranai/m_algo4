#include "Stack.cpp"
#include "Queue.cpp"
#include "List.cpp"
#include <iostream>
#include <vector>
#include <cassert>
#include <windows.h>
#include <psapi.h>

#define USE_TEST true

SIZE_T getMemory() {
	HANDLE process = GetCurrentProcess();
	PROCESS_MEMORY_COUNTERS_EX memInfo;
	if (GetProcessMemoryInfo(process, (PROCESS_MEMORY_COUNTERS*)&memInfo, sizeof(memInfo))) {
		return memInfo.WorkingSetSize;
	}
	return 0;
}

int main() {

	if (USE_TEST) {
		// Тест для класса Queue
		Queue<int> queue;
		assert(queue.IsEmpty()); // Очередь должна быть пустой
		assert(queue.GetSize() == 0); // Размер очереди должен быть нулевым

		queue.Add(1);
		assert(!queue.IsEmpty()); // Очередь больше не пуста
		assert(queue.GetSize() == 1); // Размер очереди увеличился до 1

		int removedItem = queue.Remove();
		assert(removedItem == 1); // Удаленный элемент должен быть равен 1
		assert(queue.IsEmpty()); // Очередь снова пуста
		assert(queue.GetSize() == 0); // Размер очереди снова равен 0

		// Тест для класса List
		List<char> list;
		assert(list.IsEmpty()); // Список должен быть пустым
		assert(list.GetSize() == 0); // Размер списка должен быть нулевым

		list.AddTop('A');
		assert(!list.IsEmpty()); // Список больше не пуст
		assert(list.GetSize() == 1); // Размер списка увеличился до 1

		list.AddEnd('B');
		assert(list.GetSize() == 2); // Размер списка увеличился до 2

		char removedTop = list.RemoveTop();
		assert(removedTop == 'A'); // Удаленный элемент с вершины должен быть 'A'
		assert(list.GetSize() == 1); // Размер списка уменьшился до 1

		char removedEnd = list.RemoveEnd();
		assert(removedEnd == 'B'); // Удаленный элемент с конца должен быть 'B'
		assert(list.IsEmpty()); // Список снова пуст
		assert(list.GetSize() == 0); // Размер списка снова равен 0

		// Тест для класса Stack
		Stack<double> stack;
		assert(stack.IsEmpty()); // Стек должен быть пустым
		assert(stack.GetSize() == 0); // Размер стека должен быть нулевым

		stack.Push(3.14);
		assert(!stack.IsEmpty()); // Стек больше не пуст
		assert(stack.GetSize() == 1); // Размер стека увеличился до 1

		double poppedItem = stack.Pop();
		assert(poppedItem == 3.14); // Извлеченный элемент должен быть 3.14
		assert(stack.IsEmpty()); // Стек снова пуст
		assert(stack.GetSize() == 0); // Размер стека снова равен 0

		std::cout << "all test completed" << std::endl;
	}
	else {
		std::cout << "mem usage at start: " << getMemory() / 1024 << " kB" << std::endl;
		system("pause");
		Stack<std::vector<int>> bigStack;
		Stack<int> smallStack;

		for (int i = 0; i < 100; i++)
		{
			smallStack.Push(i);
		}
		std::cout << "mem usage afterSmall: " << getMemory() / 1024 << " kB" << std::endl;
		system("pause");

		std::cout << "filling array..." << std::endl;
		for (int i = 0; i < 100000; i++) {
			std::vector<int> vec;
			for (int j = 0; j < 100; j++)
			{
				vec.push_back(j);
			}
			bigStack.Push(vec);
		}
		std::cout << "mem usage after big: " << getMemory() / 1024 << " kB" << std::endl;
		system("pause");
		while (!bigStack.IsEmpty()) {
			bigStack.Pop();
		}
		std::cout << "mem usage after big clear: " << getMemory() / 1024 << " kB" << std::endl;
		system("pause");

		while (!smallStack.IsEmpty()) {
			smallStack.Pop();
		}
		std::cout << "mem usage after small clear: " << getMemory() / 1024 << " kB" << std::endl;
		system("pause");
	}
	return 0;
}