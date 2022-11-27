#include <iostream>
#include "point.h"

int main()
{
    setlocale(LC_ALL, "rus");

    //// С SET
    //Point* point = new Point; // так как у нас перегрузка, то без скобочек мы обращаемся к конструктору Point() без аргументов

    //point->set_x(5);
    //point->set_y(4);
    //point->set_z(0);

    //std::cout << "Координата x: " << point->get_x() << std::endl;
    //std::cout << "Координата y: " << point->get_y() << std::endl;
    //std::cout << "Координата z: " << point->get_z() << std::endl;


    // БЕЗ SET
    Point* point = new Point(5, 4, 0); // так как у нас перегрузка, то со скобочками (в скобочках можно написать аргументы) мы обращаемся к конструктору Point(int x, int y, int z) с аргументов

    // так можно не использовать функции set 

    std::cout << "Координата x: " << point->get_x() << std::endl;
    std::cout << "Координата y: " << point->get_y() << std::endl;
    std::cout << "Координата z: " << point->get_z() << std::endl;


    std::cout << std::endl;

    // ФАЙЛЫ
    point->save_coordinates_to_file(); // запись в файл
    point->read_coordinates_from_file(); // чтение из файла

    std::cout << "Координата x: " << point->get_x() << std::endl;
    std::cout << "Координата y: " << point->get_y() << std::endl;
    std::cout << "Координата z: " << point->get_z() << std::endl;

    return 0;
}
