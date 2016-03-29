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
	//���������� ������ ��������� ����������
	double get_radius() const;
	//���������� x ���������� ������
	double get_x() const;
	//���������� y ���������� ������
	double get_y() const;
	//���������� n
	int get_n() const;

	//�������� �������� ������� n-���������
	double get_side() const;
	
	//�������� ������� n-���������
	double get_area() const;
	//�������� �������� n-���������
	double get_perimeter() const;


	//����������� ����� � ����� ����������
	void move(const double x_, const double y_);
	
	//��������� �������� �� �����-���� �������� (�.�. +- �����-�� �����)
	void resizing_by_side(const double x);
	void resizing_by_rad(const double x);
	
	//���������� ��������� ��������� ���� n-����������
	bool operator== (const n_angle& n);
	
	//����������� ����������� ���� n-����������
	bool crossing(const n_angle& second);
	
	//����������� ��������� n-��������� second � ��� n-��������
	bool accessory(const n_angle& second);

	//���������� ������� ��
	bool is_it_square();
	

	//����������� ������
	n_angle(const double rad, const int n_, const double x_ = 0, const double y_ = 0);
	

	//����� ����������
	void return_parameters();	
};

class ellipse
{
private:
	double major_axis, minor_axis, x = 0, y = 0;

public:
	//���������� major_axis
	double get_major_axis() const;
	//���������� minor_axis
	double get_minor_axis() const;
	//���������� x ���������� ������
	double get_x() const;
	//���������� y ���������� ������
	double get_y() const;

	//�������� ������� �������
	double get_area() const;
	//�������� �������� �������
	double get_perimeter() const;
	

	//����������� ����� � ����� ����������
	void move(const double x_, const double y_);

	//��������� �������� �� �����-���� �������� (�.�. +- �����-�� �����)
	void resizing(const double x, const double y = 0);

	//���������� ��������� ��������� ���� ��������
	bool operator== (const ellipse& second);

	//����������� ����������� ���� ��������
	bool crossing(const ellipse& second);

	//����������� ��������� ������� second � ��� ������
	bool accessory(const ellipse& second);

	//���������� ���� ��
	bool is_it_circle();


	//����������� ������
	ellipse(const double a, const double b, const double x_ = 0, const double y_ = 0);

	//����� ����������
	void return_parameters();




	//���������� �� ������� ��� n-�������� � ������
	friend bool operator== (const n_angle& n, const ellipse& el);
	friend bool operator== (const ellipse& el, const n_angle& n);
	//����������� ����������� ������� � n-���������
	friend bool crossing(const n_angle& n, const ellipse& el);
	friend bool crossing(const ellipse& el, const n_angle& n);
	//����������� ��������� ������� � n-��������
	friend bool accessory(const n_angle& n, const ellipse& el);
	friend bool accessory(const ellipse& el, const n_angle& n);

	//����������� �������������� ����� 
	bool beloning_el(const ellipse& second, const double x, const double y) const;
	bool beloning_n(const n_angle& second, const double x, const double y) const;
};

int Sign(double x);

#endif