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
		// ���� ��� ������ Queue
		Queue<int> queue;
		assert(queue.IsEmpty()); // ������� ������ ���� ������
		assert(queue.GetSize() == 0); // ������ ������� ������ ���� �������

		queue.Add(1);
		assert(!queue.IsEmpty()); // ������� ������ �� �����
		assert(queue.GetSize() == 1); // ������ ������� ���������� �� 1

		int removedItem = queue.Remove();
		assert(removedItem == 1); // ��������� ������� ������ ���� ����� 1
		assert(queue.IsEmpty()); // ������� ����� �����
		assert(queue.GetSize() == 0); // ������ ������� ����� ����� 0

		// ���� ��� ������ List
		List<char> list;
		assert(list.IsEmpty()); // ������ ������ ���� ������
		assert(list.GetSize() == 0); // ������ ������ ������ ���� �������

		list.AddTop('A');
		assert(!list.IsEmpty()); // ������ ������ �� ����
		assert(list.GetSize() == 1); // ������ ������ ���������� �� 1

		list.AddEnd('B');
		assert(list.GetSize() == 2); // ������ ������ ���������� �� 2

		char removedTop = list.RemoveTop();
		assert(removedTop == 'A'); // ��������� ������� � ������� ������ ���� 'A'
		assert(list.GetSize() == 1); // ������ ������ ���������� �� 1

		char removedEnd = list.RemoveEnd();
		assert(removedEnd == 'B'); // ��������� ������� � ����� ������ ���� 'B'
		assert(list.IsEmpty()); // ������ ����� ����
		assert(list.GetSize() == 0); // ������ ������ ����� ����� 0

		// ���� ��� ������ Stack
		Stack<double> stack;
		assert(stack.IsEmpty()); // ���� ������ ���� ������
		assert(stack.GetSize() == 0); // ������ ����� ������ ���� �������

		stack.Push(3.14);
		assert(!stack.IsEmpty()); // ���� ������ �� ����
		assert(stack.GetSize() == 1); // ������ ����� ���������� �� 1

		double poppedItem = stack.Pop();
		assert(poppedItem == 3.14); // ����������� ������� ������ ���� 3.14
		assert(stack.IsEmpty()); // ���� ����� ����
		assert(stack.GetSize() == 0); // ������ ����� ����� ����� 0

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