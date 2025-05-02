#include "Notare.h"

Notare::Notare(std::vector<Evaluare> evals, const float finala)
{
	for (Evaluare e : evals)
	{
		evaluari.push_back(e);
	}
	nota_finala = finala;
}

std::vector<Evaluare> Notare::getEvals() const
{
	return evaluari;
}

float Notare::getNotaFinala() const
{
	return nota_finala;
}

void Notare::calculNotaFinala()
{
	nota_finala = 0;
	for (Evaluare e : evaluari)
	{
		nota_finala += (e.getParteFinal() / 10) * (e.getNota() / e.getMaxim());
	}
}
