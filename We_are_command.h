#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

#ifndef WE_ARE_COMMAND_H
#define WE_ARE_COMMAND_H

class n_angle
{
private:
	double radius, x = 0, y = 0;
	int n;

public:
	//возвращаем радиус описанной окружности
	double get_radius();
	//возвращаем x координату центра
	double get_x();
	//возвращаем y координату центра
	double get_y();
	//возвращаем n
	int get_n();

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
	bool operator== (n_angle n);
	
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
};

class ellipse
{
private:
	double major_axis, minor_axis, x = 0, y = 0;

public:
	//возвращаем major_axis
	double get_major_axis();
	//возвращаем minor_axis
	double get_minor_axis();
	//возвращаем x координату центра
	double get_x();
	//возвращаем y координату центра
	double get_y();

	//получаем площадь эллипса
	double get_area();
	//получаем периметр эллипса
	double get_perimeter();
	

	//перемещение ценра в новые координаты
	void move(double x_, double y_);

	//изменение размеров на какую-либо величину (т.е. +- какое-то число)
	void resizing(double x, double y = 0);

	//перегрузка оператора сравнения двух эллипсов
	bool operator== (ellipse second);

	//определение пересечения двух эллипсов
	bool crossing(ellipse second);

	//определения вхождение эллипса second в наш эллипс
	bool accessory(ellipse second);

	//определяем круг ли
	bool is_it_circle();


	//конструктор класса
	ellipse(double a, double b, double x_ = 0, double y_ = 0);

	//вывод параметров
	void return_parameters();




	//сравниваем по площади наш n-угольник и эллипс
	friend bool operator== (n_angle n, ellipse el);
	friend bool operator== (ellipse el, n_angle n);
	//определение пересечения эллипса и n-угольника
	friend bool crossing(n_angle n, ellipse el);
	friend bool crossing(ellipse el, n_angle n);
	//определение вхождения эллипса в n-угольник
	friend bool accessory(n_angle n, ellipse el);
	friend bool accessory(ellipse el, n_angle n);

	//определение принадлежности точек 
	bool beloning_el(ellipse second, double x, double y);
	bool beloning_n(n_angle second, double x, double y);
};

int Sign(double x);

#endif