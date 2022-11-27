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
	this->x = x; // this-> - óêàçûâàåò, ÷òî ìû îáğàùàåìñÿ ê ïåğåìííîé â êëàññå (÷åğåç ctrl + ëåâàÿ êíîïêà ìûøè, ìîæíî ïğîâåğèòü, ãäå ıòà ïåğåìåííàÿ)
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
		std::cout << "ÔÀÉË ÓÑÏÅØÍÎ ÎÒÊĞÛÒ";

		// ÇÀÏÈÑÜ ÊÎÎĞÄÈÍÀÒ Â ÔÀÉË
		save_coordinates << this->get_x() << std::endl << this->get_y() << std::endl << this->get_z();

		save_coordinates.close(); // çàêğûòèå ïîòîêà ofstream save_coordinates
		return 1;
	}
	else
	{
		std::cerr << "ÎØÈÁÊÀ: ÔÀÉË ÍÅ ÑÌÎÃ ÎÒÊĞÛÒÜÑß";

		save_coordinates.close(); // çàêğûòèå ïîòîêà ofstream save_coordinates
		return 0;
	}
}


bool Point::read_coordinates_from_file()
{
	std::ifstream read_coordinates(this->file_name);
	if (read_coordinates.is_open())
	{
		std::cout << std::endl << "ÔÀÉË ÓÑÏÅØÍÎ Ñ×ÈÒÀÍ" << std::endl;

		// Ñ×ÈÒÛÂÀÍÈÅ ÊÎÎĞÄÈÍÀÒ ÈÇ ÔÀÉËÀ
		int x;
		int y;
		int z;

		while (!read_coordinates.eof()) // ïîêà íå êîíåö ôàéëà
		{
			read_coordinates >> x >> y >> z;
			this->set_x(x); this->set_y(y); this->set_z(z);

		}

		read_coordinates.close(); // çàêğûòèå ïîòîêà ifstream read_coordinates
		return 1;
	}
	else
	{
		std::cerr << std::endl << "ÎØÈÁÊÀ: ÔÀÉË ÍÅ ÑÌÎÃ Ñ×ÈÒÀÒÜÑß" << std::endl;

		read_coordinates.close(); // çàêğûòèå ïîòîêà ifstream read_coordinates
		return 0;
	}
}