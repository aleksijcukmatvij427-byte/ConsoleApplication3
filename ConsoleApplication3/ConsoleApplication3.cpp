#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Book {
    string title;
    string author;
};

int main() {

    // ==================== Задача 1 ====================

    cout << "Введіть 4 продукти:" << endl;

    ofstream shoppingFile("shopping_list.txt");

    if (!shoppingFile.is_open()) {
        cout << "Помилка відкриття файлу shopping_list.txt" << endl;
        return 1;
    }

    string product;

    for (int i = 0; i < 4; i++) {
        getline(cin, product);
        shoppingFile << product << endl;
    }

    shoppingFile.close();

    ifstream shoppingRead("shopping_list.txt");

    if (!shoppingRead.is_open()) {
        cout << "Файл shopping_list.txt не знайдено!" << endl;
        return 1;
    }

    cout << "\nСписок покупок:" << endl;

    int num = 1;

    while (getline(shoppingRead, product)) {
        cout << num++ << ". " << product << endl;
    }

    shoppingRead.close();


    // ==================== Задача 2 ====================

    ofstream numbersFile("numbers.txt");

    if (!numbersFile.is_open()) {
        cout << "Помилка відкриття файлу numbers.txt" << endl;
        return 1;
    }

    int number;

    cout << "\nВведіть 3 улюблені числа:" << endl;

    for (int i = 0; i < 3; i++) {
        cin >> number;
        numbersFile << number << endl;
    }

    numbersFile.close();

    ifstream numbersRead("numbers.txt");

    if (!numbersRead.is_open()) {
        cout << "Файл numbers.txt не знайдено!" << endl;
        return 1;
    }

    int sum = 0;

    while (numbersRead >> number) {
        sum += number;
    }

    cout << "Сума чисел = " << sum << endl;

    numbersRead.close();


    // ==================== Задача 3 ====================

    vector<Book> books = {
        { "Kobzar", "Taras Shevchenko" },
        { "Tiger Trappers", "Ivan Bahrianyi" },
        { "Forest Song", "Lesya Ukrainka" }
    };

    ofstream booksFile("books.txt");

    if (!booksFile.is_open()) {
        cout << "Помилка відкриття файлу books.txt" << endl;
        return 1;
    }

    for (const auto& book : books) {
        booksFile << book.title << ";" << book.author << endl;
    }

    booksFile.close();

    cout << "\nКолекцію книг записано у файл." << endl;


    // ==================== Задача 4 ====================

    ifstream booksRead("books.txt");

    if (!booksRead.is_open()) {
        cout << "Файл books.txt не знайдено!" << endl;
        return 1;
    }

    string title, author;

    cout << "\nСписок книг:" << endl;

    while (getline(booksRead, title, ';') &&
        getline(booksRead, author)) {

        cout << "Назва: " << title
            << ", Автор: " << author << endl;
    }

    booksRead.close();

    return 0;
}