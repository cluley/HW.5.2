#include <iostream> 

class Figure {
public:
	void virtual print_sides() {}
	void virtual print_angles() {}
	int get_sides() { return sides; }
	std::string get_intro() { return intro; }
protected:
	int sides = 0;
	std::string intro = "Фигура: ";
};

class Triangle : public Figure {
public:
	Triangle(int a, int b, int c, int A, int B, int C);
	void print_sides() override;
	void print_angles() override;
protected:
	int side_a;
	int side_b;
	int side_c;
	int angle_A;
	int angle_B;
	int angle_C;
};

Triangle::Triangle(int a, int b, int c, int A, int B, int C) {
	sides = 3;
	intro = "Треугольник: ";
	side_a = a;
	side_b = b;
	side_c = c;
	angle_A = A;
	angle_B = B;
	angle_C = C;
}

void Triangle::print_sides() {
	std::cout << "Стороны: a = " << side_a << " b = " << side_b << " c = " << side_c << std::endl;
}

void Triangle::print_angles() {
	std::cout << "Углы: A = " << angle_A << " B = " << angle_B << " C = " << angle_C << std::endl;
}

class R_Triangle : public Triangle {
public:
	R_Triangle(int a, int b, int c, int A, int B);
};

R_Triangle::R_Triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
	intro = "Прямоугольный треугольник: ";
	side_a = a;
	side_b = b;
	side_c = c;
	angle_A = A;
	angle_B = B;
	angle_C = 90;
}

class I_Triangle : public Triangle {
public:
	I_Triangle(int a, int b, int A, int B);
};

I_Triangle::I_Triangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
	intro = "Равнобедренный треугольник: ";
	side_a = a;
	side_b = b;
	side_c = a;
	angle_A = A;
	angle_B = B;
	angle_C = A;
}

class E_Triangle : public Triangle {
public:
	E_Triangle(int a, int A);
};

E_Triangle::E_Triangle(int a, int A) : Triangle(a, a, a, A, A, A) {
	intro = "Равносторонний треугольник: ";
	side_a = a;
	side_b = a;
	side_c = a;
	angle_A = A;
	angle_B = A;
	angle_C = A;
}

class Quadrangle : public Figure {
public:
	Quadrangle();
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);
	void print_sides() override;
	void print_angles() override;
protected:
	int side_a;
	int side_b;
	int side_c;
	int side_d;
	int angle_A;
	int angle_B;
	int angle_C;
	int angle_D;
};

Quadrangle::Quadrangle() {
	sides = 4;
	intro = "Четырехугольник: ";
	side_a = 10;
	side_b = 20;
	side_c = 30;
	side_d = 40;
	angle_A = 50;
	angle_B = 60;
	angle_C = 70;
	angle_D = 80;
}

Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
	sides = 4;
	intro = "Четырехугольник: ";
	side_a = a;
	side_b = b;
	side_c = c;
	side_d = d;
	angle_A = A;
	angle_B = B;
	angle_C = C;
	angle_D = D;
}

void Quadrangle::print_sides() {
	std::cout << "Стороны: a = " << side_a << " b = " << side_b << " c = " << side_c << " d = " << side_d << std::endl;
}

void Quadrangle::print_angles() {
	std::cout << "Углы: A = " << angle_A << " B = " << angle_B << " C = " << angle_C << " D = " << angle_D << std::endl;
}

class Rectangle : public Quadrangle {
public:
	Rectangle(int a, int b);
};

Rectangle::Rectangle(int a, int b) : Quadrangle(a, a, a, a, 90, 90, 90, 90) {
	intro = "Прямоугольник: ";
	side_a = a;
	side_b = b;
	side_c = a;
	side_d = b;
	angle_A = 90;
	angle_B = 90;
	angle_C = 90;
	angle_D = 90;
}

class Square : public Quadrangle {
public:
	Square(int a);
};

Square::Square(int a) {
	intro = "Квадрат: ";
	side_a = a;
	side_b = a;
	side_c = a;
	side_d = a;
	angle_A = 90;
	angle_B = 90;
	angle_C = 90;
	angle_D = 90;
}

class Parallelogram : public Quadrangle {
public:
	Parallelogram(int a, int b, int A, int B);
};

Parallelogram::Parallelogram(int a, int b, int A, int B) {
	intro = "Параллелограмм: ";
	side_a = a;
	side_b = b;
	side_c = a;
	side_d = b;
	angle_A = A;
	angle_B = B;
	angle_C = A;
	angle_D = B;
}

class Rhombus : public Quadrangle {
public:
	Rhombus(int a, int A, int B);
};

Rhombus::Rhombus(int a, int A, int B) {
	intro = "Ромб: ";
	side_a = a;
	side_b = a;
	side_c = a;
	side_d = a;
	angle_A = A;
	angle_B = B;
	angle_C = A;
	angle_D = B;
}

void print_info(Figure* figure) {
	std::cout << figure->get_intro() << std::endl;
	figure->print_sides();
	figure->print_angles();
	std::cout << std::endl;
}

int main(int argc, char** argv) {
	Triangle triangle(10, 20, 30, 50, 60, 70);
	R_Triangle r_triangle(10, 20, 30, 40, 50);
	I_Triangle i_triangle(10, 20, 40, 80);
	E_Triangle e_triangle(30, 60);
	Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	Rectangle rectangle(20, 40);
	Square square(20);
	Parallelogram parallelogram(20, 30, 40, 50);
	Rhombus rhombus(30, 40, 50);

	print_info(&triangle);
	print_info(&r_triangle);
	print_info(&i_triangle);
	print_info(&e_triangle);
	print_info(&quadrangle);
	print_info(&rectangle);
	print_info(&square);
	print_info(&parallelogram);
	print_info(&rhombus);

	return 0;
}