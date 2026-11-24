#include <iostream>
#include <iomanip>
#include <string>
#include <clocale>

using namespace std;

// Перелік спеціальностей
enum Specialty
{
    ComputerScience,
    Informatics,
    MathematicsEconomics,
    PhysicsInformatics,
    LaborTraining
};

// Структура студента
struct Student
{
    string surname;
    int course;
    Specialty specialty;
    int physics;
    int mathematics;
    int informatics;
};

// Функція отримання назви спеціальності
string getSpecialtyName(Specialty specialty)
{
    switch (specialty)
    {
    case ComputerScience: return "Kompiuterni nauky";
    case Informatics: return "Informatyka";
    case MathematicsEconomics: return "Matematyka ta ekonomika";
    case PhysicsInformatics: return "Fizyka ta informatyka";
    case LaborTraining: return "Trudove navchannia";
    default: return "Nevidomo";
    }
}

// Функція введення даних студентів
void inputStudents(Student* students, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;

        cout << "Prizvyshche: ";
        cin >> students[i].surname;

        cout << "Kurs: ";
        cin >> students[i].course;

        cout << "\nSpecialnist:\n";
        cout << "0 - Kompiuterni nauky\n";
        cout << "1 - Informatyka\n";
        cout << "2 - Matematyka ta ekonomika\n";
        cout << "3 - Fizyka ta informatyka\n";
        cout << "4 - Trudove navchannia\n";

        int choice;

        do
        {
            cout << "Vyberit specialnist (0-4): ";
            cin >> choice;
        } while (choice < 0 || choice > 4);

        students[i].specialty = static_cast<Specialty>(choice);

        cout << "Otsinka z fizyky (2-5): ";
        cin >> students[i].physics;

        cout << "Otsinka z matematyky (2-5): ";
        cin >> students[i].mathematics;

        cout << "Otsinka z informatyky (2-5): ";
        cin >> students[i].informatics;
    }
}

// Функція перевірки відсутності трійок
bool hasNoThrees(const Student& student)
{
    return student.physics >= 4 &&
        student.mathematics >= 4 &&
        student.informatics >= 4;
}

// Функція обчислення відсотка студентів без трійок
double calculatePercentage(const Student* students, int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (hasNoThrees(students[i]))
        {
            count++;
        }
    }

    return (double)count / n * 100;
}

// Функція виведення таблиці студентів
void printStudents(const Student* students, int n)
{
    cout << "\n\t\tSPYSOK STUDENTIV\n\n";

    cout << left
        << setw(5) << "No"
        << setw(15) << "Prizvyshche"
        << setw(8) << "Kurs"
        << setw(30) << "Specialnist"
        << setw(12) << "Fizyka"
        << setw(15) << "Matematyka"
        << setw(15) << "Informatyka"
        << endl;

    cout << string(100, '-') << endl;

    for (int i = 0; i < n; i++)
    {
        cout << left
            << setw(5) << i + 1
            << setw(15) << students[i].surname
            << setw(8) << students[i].course
            << setw(30) << getSpecialtyName(students[i].specialty)
            << setw(12) << students[i].physics
            << setw(15) << students[i].mathematics
            << setw(15) << students[i].informatics
            << endl;
    }
}

// Функція виведення прізвищ студентів,
// які отримали з фізики оцінку 5 або 4
void printStudentsWithGoodPhysics(const Student* students, int n)
{
    cout << "\nStudenty, yaki otrymaly z fizyky 5 abo 4:\n";

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (students[i].physics == 5 ||
            students[i].physics == 4)
        {
            cout << students[i].surname << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "Takykh studentiv nemaie.\n";
    }
}

// Головна функція
int main()
{
    setlocale(LC_ALL, "");

    int n;

    cout << "VARIANT 26 - RIVEN A\n";
    cout << "Vvedit kilkist studentiv: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Pomylka! Kilkist povynna buty bilshe 0.\n";
        return 1;
    }

    // Створення динамічного масиву структур
    Student* students = new Student[n];

    // Введення інформації
    inputStudents(students, n);

    // Виведення таблиці
    printStudents(students, n);

    // Обчислення відсотка студентів без трійок
    double percentage = calculatePercentage(students, n);

    cout << "\nVidstok studentiv bez triok: "
        << fixed << setprecision(2)
        << percentage << "%\n";

    // Виведення прізвищ студентів з оцінкою 4 або 5 з фізики
    printStudentsWithGoodPhysics(students, n);

    // Звільнення пам'яті
    delete[] students;

    return 0;
}