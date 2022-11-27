#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Point
{
public:
	Point(); // конструктор
	Point(int x, int y, int z); // перегрузка (можно будет сразу указывать переменные, чтобы не использовать функции set)


public:
	// SET FUNCTIONS
	void set_x(int x);
	void set_y(int y);
	void set_z(int y);

	// GET FUNCTIONS
	int get_x();
	int get_y();
	int get_z();

	bool save_coordinates_to_file();
	bool read_coordinates_from_file();

private:
	int x = 0;
	int y = 0;
	int z = 0;

	std::string file_name = "file_with_coordinates.txt";
};

