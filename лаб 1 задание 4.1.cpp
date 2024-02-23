#include <iostream>
#include <stack>
#include <queue>
using namespace std;
void reverseStack(std::stack<double>& numbers) {
    queue<double> tempqueue;

    while (!numbers.empty()) {
        double value = numbers.top();
        numbers.pop();
        tempqueue.push(value);
    }

    while (!tempqueue.empty()) {
        double value = tempqueue.front();
        tempqueue.pop();
        numbers.push(value);
    }
}

int main() {
    std::stack<double> numbers;
    numbers.push(10);
    numbers.push(20);
    numbers.push(30);
    numbers.push(55);
    numbers.push(50);
    numbers.push(55);
    numbers.push(60);
    numbers.push(70);

    std::stack<double> tempStack;
    reverseStack(numbers);
    bool found55 = false;
    // Переносим числа во временный стек до тех пор, пока не встретим значение 55
    while (!numbers.empty()) {
        if (numbers.top() == 55) {
            found55 = true;
            break;
        }
        tempStack.push(numbers.top());
        numbers.pop();
    }

    if (found55) {
        tempStack.pop(); // Удаляем элемент перед первым элементом со значением 55

        // Возвращаем числа из временного стека обратно в основной стек
        while (!tempStack.empty()) {
            numbers.push(tempStack.top());
            tempStack.pop();
        }
        // Выводим обновленный список
        while (!numbers.empty()) {
            std::cout << numbers.top() << " ";
            numbers.pop();
        }

        return 0;
    }
}