#include "point.h"

Point::Point()
{

}

Point::Point(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

// SET FUNCTIONS
void Point::set_x(int x)
{
	this->x = x; // this-> - ���������, ��� �� ���������� � ��������� � ������ (����� ctrl + ����� ������ ����, ����� ���������, ��� ��� ����������)
}

void Point::set_y(int y)
{
	this->y = y;
}

void Point::set_z(int z)
{
	this->z = z;
}


// GET FUNCTIONS
int Point::get_x()
{
	return this->x;
}

int Point::get_y()
{
	return this->y;
}

int Point::get_z()
{
	return this->z;
}


bool Point::save_coordinates_to_file()
{
	std::ofstream save_coordinates(this->file_name);
	if (save_coordinates.is_open())
	{
		std::cout << "���� ������� ������";

		// ������ ��������� � ����
		save_coordinates << this->get_x() << std::endl << this->get_y() << std::endl << this->get_z();

		save_coordinates.close(); // �������� ������ ofstream save_coordinates
		return 1;
	}
	else
	{
		std::cerr << "������: ���� �� ���� ���������";

		save_coordinates.close(); // �������� ������ ofstream save_coordinates
		return 0;
	}
}


bool Point::read_coordinates_from_file()
{
	std::ifstream read_coordinates(this->file_name);
	if (read_coordinates.is_open())
	{
		std::cout << std::endl << "���� ������� ������" << std::endl;

		// ���������� ��������� �� �����
		int x;
		int y;
		int z;

		while (!read_coordinates.eof()) // ���� �� ����� �����
		{
			read_coordinates >> x >> y >> z;
			this->set_x(x); this->set_y(y); this->set_z(z);

		}

		read_coordinates.close(); // �������� ������ ifstream read_coordinates
		return 1;
	}
	else
	{
		std::cerr << std::endl << "������: ���� �� ���� ���������" << std::endl;

		read_coordinates.close(); // �������� ������ ifstream read_coordinates
		return 0;
	}
}