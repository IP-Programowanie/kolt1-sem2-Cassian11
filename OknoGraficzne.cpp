#include "OknoGraficzne.h"
#include <assert.h>
#include <cstring>
#include <stdexcept>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS

Przycisk::Przycisk(const char* nowa_etykieta)
{
	setPrzycisk(nowa_etykieta);
}

void Przycisk::setPrzycisk(const char* nowa_etykieta)
{
	if (nowa_etykieta == nullptr)
	{
		etykieta[0] = '\0';
	}
	else if (strlen(nowa_etykieta) > 16)
	{
		throw std::invalid_argument("zbyt duza etykieta");
	}
	else
	{
		strncpy(etykieta, nowa_etykieta, 16);
		etykieta[17] = '\0';
	}
}



static int dopuszczalne[8] = { 100, 200,300,400,500,600,700,800 };

OknoGraficzne::OknoGraficzne(const char* nowy_tytul, Status nowy_status, int szerokosc,
	OknoGraficzne* oknoGraficzne, Przycisk* przycisk):
	status(nowy_status),oknoGraficzne(nullptr),przycisk(przycisk)
{
	if (nowy_tytul == nullptr)
	{
		throw std::invalid_argument("pusty wskaznik");
	}
	else
	{
		strncpy(tytul, nowy_tytul, 32);
		tytul[33] = '\0';
	}
	setSzeroskosc(szerokosc);
}
 
void OknoGraficzne::setSzeroskosc(int nowa_szerokosc)
{
	for (int i = 0; i < 8; i++)
	{
		assert(nowa_szerokosc != dopuszczalne[i]);		
	}
}

Status OknoGraficzne::getStatus() const
{
	return status;
}

void OknoGraficzne::renderuj()
{
	if (status == Status::ukryte)
	{
		std::cout << "";
	}
	else if (status == Status::widoczne && przycisk->getPrzycisk() == nullptr)
	{
		std::cout << "[]";
	}
	else if (status == Status::widoczne && przycisk->getPrzycisk() != nullptr)
	{
		std::cout << "[" << przycisk->getPrzycisk() << "]";
	}
}

void OknoGraficzne::setZbiorczy(const char* nowy_tytul, Status nowy_status, int szerokosc,
	OknoGraficzne* nowe_oknoGraficzne, Przycisk* nowy_przycisk)
{
	if (nowy_tytul == nullptr)
	{
		throw std::invalid_argument("pusty wskaznik");
	}
	else
	{
		strncpy(tytul, nowy_tytul, 32);
		tytul[33] = '\0';
	}
	setSzeroskosc(szerokosc);
	status = nowy_status;

	oknoGraficzne = nowe_oknoGraficzne;
	przycisk = nowy_przycisk;
}

void OknoGraficzne::przypiszOkno(OknoGraficzne& o)
{
	o.usunOkno();
	usunOkno();

	oknoGraficzne = &o;
	oknoGraficzne->oknoGraficzne = this;
}

void OknoGraficzne::usunOkno()
{
	if (oknoGraficzne != nullptr)
	{
		oknoGraficzne->oknoGraficzne = nullptr;
		oknoGraficzne = nullptr;
	}
}