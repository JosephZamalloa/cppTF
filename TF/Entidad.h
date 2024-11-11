#pragma once
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;
using namespace System;
using namespace System::Drawing;

class Entidad {
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int IDx;
public:
	Entidad() {}
	~Entidad() {}
	void setDX(int n) {
		dx = n;
	}
	void setDY(int n) {
		dy = n;
	}
	Rectangle Area() {
		return Rectangle(x, y, ancho, alto);
	}
	virtual void Mover(Graphics^ g) {

	}
	virtual void Mostrar(Graphics^ g, Bitmap^ img) {

	}
};
