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
	double get_radius() const;
	//возвращаем x координату центра
	double get_x() const;
	//возвращаем y координату центра
	double get_y() const;
	//возвращаем n
	int get_n() const;

	//получаем величину стороны n-угольника
	double get_side() const;
	
	//получаем площадь n-угольника
	double get_area() const;
	//получаем периметр n-угольника
	double get_perimeter() const;


	//перемещение ценра в новые координаты
	void move(const double x_, const double y_);
	
	//изменение размеров на какую-либо величину (т.е. +- какое-то число)
	void resizing_by_side(const double x);
	void resizing_by_rad(const double x);
	
	//перегрузка оператора сравнения двух n-угольников
	bool operator== (const n_angle& n);
	
	//определение пересечения двух n-угольников
	bool crossing(const n_angle& second);
	
	//определение вхождения n-угольника second в наш n-угольник
	bool accessory(const n_angle& second);

	//определяем квадрат ли
	bool is_it_square();
	

	//конструктор класса
	n_angle(const double rad, const int n_, const double x_ = 0, const double y_ = 0);
	

	//вывод параметров
	void return_parameters();	
};

class ellipse
{
private:
	double major_axis, minor_axis, x = 0, y = 0;

public:
	//возвращаем major_axis
	double get_major_axis() const;
	//возвращаем minor_axis
	double get_minor_axis() const;
	//возвращаем x координату центра
	double get_x() const;
	//возвращаем y координату центра
	double get_y() const;

	//получаем площадь эллипса
	double get_area() const;
	//получаем периметр эллипса
	double get_perimeter() const;
	

	//перемещение ценра в новые координаты
	void move(const double x_, const double y_);

	//изменение размеров на какую-либо величину (т.е. +- какое-то число)
	void resizing(const double x, const double y = 0);

	//перегрузка оператора сравнения двух эллипсов
	bool operator== (const ellipse& second);

	//определение пересечения двух эллипсов
	bool crossing(const ellipse& second);

	//определения вхождение эллипса second в наш эллипс
	bool accessory(const ellipse& second);

	//определяем круг ли
	bool is_it_circle();


	//конструктор класса
	ellipse(const double a, const double b, const double x_ = 0, const double y_ = 0);

	//вывод параметров
	void return_parameters();




	//сравниваем по площади наш n-угольник и эллипс
	friend bool operator== (const n_angle& n, const ellipse& el);
	friend bool operator== (const ellipse& el, const n_angle& n);
	//определение пересечения эллипса и n-угольника
	friend bool crossing(const n_angle& n, const ellipse& el);
	friend bool crossing(const ellipse& el, const n_angle& n);
	//определение вхождения эллипса в n-угольник
	friend bool accessory(const n_angle& n, const ellipse& el);
	friend bool accessory(const ellipse& el, const n_angle& n);

	//определение принадлежности точек 
	bool beloning_el(const ellipse& second, const double x, const double y) const;
	bool beloning_n(const n_angle& second, const double x, const double y) const;
};

int Sign(double x);

#endif