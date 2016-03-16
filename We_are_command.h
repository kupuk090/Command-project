#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <math.h>

class n_angle
{
private:
	double radius, x = 0, y = 0;
	double angle = 0;
	int n;

public:
	//возвращаем радиус описанной окружности
	double get_radius()
	{
		return radius;
	}
	//возвращаем x координату центра
	double get_x()
	{
		return x;
	}
	//возвращаем y координату центра
	double get_y()
	{
		return y;
	}
	//возвращаем n
	int get_n()
	{
		return n;
	}
	//возвращаем угол поворота первой вершины относительно оси Ох
	double get_angle()
	{
		return angle;
	}

	//получаем величину стороны n-угольника
	double get_side();
	
	//получаем площадь n-угольника
	double get_area();
	//получаем периметр n-угольника
	double get_perimeter();


	//перемещение ценра в новые координаты
	void move(double x_, double y_);
	
	//изменение размеров на какую-либо величину (т.е. +- какое-то число)
	void resizing_by_side(double x);
	void resizing_by_rad(double x);
	
	//перегрузка оператора сравнения двух n-угольников
	n_angle operator== (n_angle n);
	
	//определение пересечения двух n-угольников
	bool crossing(n_angle second);
	
	//определение вхождения n-угольника second в наш n-угольник
	bool accessory(n_angle second);

	//определяем квадрат ли
	bool is_it_square();
	

	//конструктор класса
	n_angle(double rad, int n_, double x_ = 0, double y_ = 0);

	//вывод параметров
	void return_parameters();



	//сравниваем по площади наш n-угольник и эллипс
	friend n_angle operator== (n_angle n, ellipse el);
	friend n_angle operator== (ellipse el, n_angle n);
	//определение пересечения эллипса и n-угольника
	friend crossing(n_angle n, ellipse el);
	friend crossing(ellipse el, n_angle n);
	//определение вхождения эллипса в n-угольник
	friend accessory(n_angle n, ellipse el);
	friend crossing(ellipse el, n_angle n);
};

class ellipse
{
private:
	double major_axis, minor_axis, x = 0, y = 0;
	double angle = 0;

public:
	//возвращаем major_axis
	double get_major_axis()
	{
		return major_axis;
	}
	//возвращаем minor_axis
	double get_minor_axis()
	{
		return minor_axis;
	}
	//возвращаем x координату центра
	double get_x()
	{
		return x;
	}
	//возвращаем y координату центра
	double get_y()
	{
		return y;
	}
	//возвращаем угол поворота major_axis относительно оси Ох
	double get_angle()
	{
		return angle;
	}

	//получаем площадь эллипса
	double get_area();
	//получаем периметр эллипса
	double get_perimeter();
	//получаем радиус эллипса
	double get_radius();


	//перемещение ценра в новые координаты
	void move(double x_, double y_);

	//изменение размеров на какую-либо величину (т.е. +- какое-то число)
	void resizing(double x, double y = 0)
	{
		major_axis += x;
		minor_axis += y;
	}

	//перегрузка оператора сравнения двух эллипсов
	ellipse operator== (ellipse second);

	//определение пересечения двух эллипсов
	bool crossing(ellipse second);

	//определения вхождение эллипса second в наш эллипс
	bool accessory(ellipse second);

	//определяем круг ли
	bool is_it_circle();


	//конструктор класса
	ellipse(double a, double b, double x_ = 0, double y_ = 0)
	{
		major_axis = a;
		minor_axis = b;
		x = x_;
		y = y_;
	}

	//вывод параметров
	void return_parameters();
};

//их надо проверить, в них я что-то не уверен

n_angle operator== (n_angle n, ellipse el)
{
	if (n.get_area() == el.get_area()) return true;
	else return false;
}
ellipse operator== (ellipse el, n_angle n)
{
	if (n.get_area() == el.get_area()) return true;
	else return false;
}

