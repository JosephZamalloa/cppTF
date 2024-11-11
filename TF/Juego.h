#pragma once
#include "Guardian.h"
class Juego
{
private:
	Guardian* jugador;
public:
	Juego() {
		jugador = new Guardian();
	};
	~Juego();

	Guardian* GetJugador()
	{
		return jugador;
	}

	void Mover(Graphics^ g)
	{
		jugador->Mover(g);
	}
	void Mostrar(Graphics^ g, Bitmap^ jug)
	{
		jugador->Mostrar(g, jug);
	}
};

