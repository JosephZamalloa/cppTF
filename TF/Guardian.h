#pragma once
#include "Entidad.h"
enum AccionJugador
{
	CaminarArriba, CaminarIzq, CaminarAbajo, CaminarDer,
	DispararArriba, DispararIzq, DispararAbajo, DispararDer
};

class Guardian :public Entidad {
private:
	AccionJugador accion;
public:
	Guardian() {
		x = y = 150;
		dx = dy = 0;
		ancho = alto = 0;
		IDx = 0;

		accion = CaminarAbajo;
	}
	~Guardian() {

	}
	void SetAccion(AccionJugador n)
	{
		accion = n;
	}
	void Disparar() {

	}

	void Mover(Graphics^ g) {
		if (x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width)
			x += dx;
		if (y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height)
			y += dy;
	}
	void Mostrar(Graphics^ g, Bitmap^ img) {
		ancho = img->Width / 7;
		alto = img->Height / 4;
		Rectangle corte = Rectangle(IDx * ancho, accion * alto, ancho, alto);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
		if (accion >= 0 && accion <= 3)
			IDx = (IDx + 1) % 7;
		if (dx == 0 && dy == 0)
		{
			IDx = 0;
		}
		else if (accion >= 4 && accion <= 7)
			IDx = (IDx + 1) % 7;
	}
};