#include <iostream>

using namespace std;

class Node { //объявление класса
public:
    int data; //Свойство data - целочисленное значение, которое будет храниться в узле списка
    Node* next; //Свойство next - указатель на следующий узел списка

    //Это конструктор класса Node, который принимает один аргумент - значение data.
    // Конструктор создает новый узел списка,
    // инициализирует свойство data значением переданного аргумента и свойство next - значением NULL.
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

//Класс LinkedList представляет собой односвязный список, который содержит указатель на голову списка head.
class LinkedList {
public:
    Node *head;

    LinkedList() { // конструктор класса, который инициализирует голову списка как NULL.
        head = NULL;
    }

    // Добавление элемента в конец списка
    void addToEnd(int data) {
        Node *newNode = new Node(data); //Создается новый узел newNode с переданным значением data

        if (head == NULL) { //Если список пуст, то новый узел становится головой списка.
            head = newNode;
            return;
        }

        Node *currNode = head; //создание указателя на головной элемент списка currNode.
        while (currNode->next != NULL) { //цикл проходит по списку до тех пор, пока не найдется последний элемент.
            currNode = currNode->next; //переход к следующему элементу списка.
        }
        currNode->next = newNode; //добавление нового элемента newNode в конец списка
    }

    // Добавление элемента в начало списка
    void addToStart(int data) {
        Node *newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        newNode->next = head; //Если список не пуст, то указатель next на новый узел устанавливается на текущую голову списка
        head = newNode; //Головой списка становится новый узел
    }

    // Добавление элемента в заданную позицию
    void add(int data, int pos) {
        Node *newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        //Проверяется, является ли позиция равной 0.
        // Если да, то новый узел становится головой списка, а его следующим элементом становится предыдущая голова.
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *currNode = head; //создание указателя на головной элемент списка currNode.
        //Этот цикл который проходит через узлы до позиции, переданной в параметрах функции.
        // Если достигнут конец списка, цикл прерывается.
        for (int i = 0; i < pos - 1; i++) {
            if (currNode->next == NULL) {
                break;
            }
            currNode = currNode->next; //если current не пустой то переходит на след. элемент
        }

        newNode->next = currNode->next;//Присваивает следующий указатель нового узла следующему узлу текущего узла.
        currNode->next = newNode; //добавление нового элемента newNode в конец списка
    }

    // Удаление элемента по значению
    void removeByValue(int data) {
        //Проверяет, есть ли элементы в списке.
        // Если голова списка равна NULL, значит список пуст, поэтому выходим из функции.
        if (head == NULL) {
            return;
        }
        //Проверяет, является ли голова списка элементом, который нужно удалить.
        // Если да, то изменяем голову на следующий элемент списка и выходим из функции.
        if (head->data == data) {
            head = head->next;
            return;
        }

        Node *currNode = head; //Создаём указатель на текущий узел, начиная с головы списка.
        //Ищем элемент со значением data в списке, пока не дойдём до конца списка или не найдём элемент с нужным значением.
        while (currNode->next != NULL && currNode->next->data != data) {
            currNode = currNode->next; //Переходим к следующему узлу.
        }
        //Если элемент со значением data найден, то удаляем его,
        // переключив указатель предыдущего элемента на следующий элемент после удаляемого.
        if (currNode->next != NULL) {
            currNode->next = currNode->next->next; //Удаляем элемент путём перенаправления указателя предыдущего элемента на следующий элемент после удаляемого.
        }
    }

    // Удаление элемента по номеру позиции
    void removeByPosition(int pos) {
        if (head == NULL) { //проверка, если head равен NULL, то список пустой и функция ничего не делает.
            return;
        }

        if (pos == 0) { //проверка, если pos равен 0, то элемент на позиции 0 должен быть удален.
            head = head->next; //установка head на следующий элемент в списке, таким образом удаляя первый элемент списка.
            return;
        }

        Node *currNode = head; //объявление указателя на текущий узел currNode и установка его на head.

        //цикл, который пробегает по списку до тех пор, пока не достигнет позиции, на которой нужно удалить элемент.
        for (int i = 0; i < pos - 1; i++) {
            if (currNode->next == NULL) { //если next указатель текущего узла равен NULL, то значит мы достигли конца списка, и удалять нечего.
                break;
            }
            currNode = currNode->next; //перейти к следующему узлу списка.
        }

        if (currNode->next != NULL) { //если следующий узел не равен NULL, значит элемент в позиции pos найден.
            currNode->next = currNode->next->next; //установить указатель next текущего узла на элемент, следующий за удаляемым, тем самым удаляя узел из списка.
        }
    }

    // Поиск элемента по значению
    int searchByValue(int value) {
        if (head == NULL) { //Проверяется, есть ли хотя бы один элемент в списке, если нет, то функция возвращает -1.
            return -1;
        }
        Node *temp = head; //Создается указатель temp, который указывает на начало списка
        int pos = 0;
        //На каждой итерации цикла проверяется значение data текущего узла, на которое указывает temp,
        // с искомым значением value. Если они равны, то функция возвращает текущую позицию pos.
        while (temp != NULL) {
            if (temp->data == value) {
                return pos;
            }
            //Если значения не совпадают, то переменная pos увеличивается на 1 и указатель temp сдвигается на следующий узел списка.
            pos++;
            temp = temp->next;
        }
        return -1;
    }
    //Поиск элемента через позицию.
    int searchByPos(int pos) {
        if (head == NULL) {
            return -1;
        }
        Node *temp = head; //Создается указатель temp, который указывает на головной элемент списка.
        int i = 0;
        while (i < pos && temp != NULL) {
            //Внутри цикла указатель temp переходит к следующему элементу списка и значение i увеличивается на 1.
            temp = temp->next;
            i++;
        }
        if (temp == NULL) { //заданная позиция находится за пределами списка,
            return -1;
        }
        //Если temp указывает на элемент списка, соответствующий заданной позиции pos, то возвращается значение этого элемента
        return temp->data;
    }

    void printList() {
        if (head == NULL) { //проверяем, пуст ли связный список. Если head равен NULL, то список пуст.
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head; //создаём указатель temp, который будет использоваться для обхода списка. Изначально он указывает на голову списка head.
        while (temp != NULL) {
            cout << temp->data << " "; //выводим значение текущего узла на экран консоли.
            temp = temp->next; //переходим к следующему узлу списка, обновляя значение указателя temp.
        }
        cout << endl;
    }
};
    int main() {
        LinkedList list; //создание экземпляра класса LinkedList, который представляет собой связанный список.
        int choice, value, position;
        while (true) {
            cout << "Select an option:" << endl;
            cout << "1. Add element to the end of the list" << endl;
            cout << "2. Add element to the beginning of the list" << endl;
            cout << "3. Add element to a specific position in the list" << endl;
            cout << "4. Remove element by value" << endl;
            cout << "5. Remove element by position" << endl;
            cout << "6. Find element by value" << endl;
            cout << "7. Find element by position" << endl;
            cout << "8. List print" << endl;
            cout << "9. Exit" << endl;
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter a value: ";
                    cin >> value;
                    list.addToEnd(value); //вызывается метод addToEnd объекта list и передается в качестве аргумента value.
                    break;
                case 2:
                    cout << "Enter a value: ";
                    cin >> value;
                    list.addToStart(value);
                    break;
                case 3:
                    cout << "Enter a value: ";
                    cin >> value;
                    cout << "Enter a position: ";
                    cin >> position;
                    list.add(value, position);
                    break;
                case 4:
                    cout << "Enter value to remove: ";
                    cin >> value;
                    list.removeByValue(value);
                    break;
                case 5:
                    cout << "Enter position to remove: ";
                    cin >> position;
                    list.removeByPosition(position);
                    break;
                case 6:
                    cout << "Enter a value to search: ";
                    cin >> value;
                    position = list.searchByValue(value); //вызывает метод searchByValue объекта list с аргументом value и сохраняет результат в переменной
                    //Метод searchByValue ищет первое вхождение элемента с заданным значением в связном списке,
                    // начиная с его головы. Если элемент не найден, метод возвращает -1.
                    if (position == -1) {
                        cout << "Element not found." << endl;
                    } else {
                        cout << "Element found at position " << position << endl;
                    }
                    break;
                case 7:
                    cout << "Enter a position to search: ";
                    cin >> position;
                    value = list.searchByPos(position);
                    if (value == -1) {
                        cout << "Element not found." << endl;
                    } else {
                        cout << "Element found at position " << position << endl;
                        cout << "It is:" << value << endl;
                    }
                    break;
                case 8:
                    cout << "List: ";
                    list.printList();
                    break;
                case 9:
                    return 0;
                default:
                    cout << "There is no such case" << endl;
            }
        }
    }