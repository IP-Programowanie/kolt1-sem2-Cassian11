#pragma once

class OknoGraficzene;

enum class Status
{
	widoczne = 0,
	ukryte = 1
};

class Przycisk
{
private:
	char etykieta[17];
public:
	Przycisk() = delete;
	Przycisk(const char* nowa_etykieta);
	void setPrzycisk(const char* nowa_etykieta);
	const char* getPrzycisk() const
	{
		return etykieta;
	}
};


class OknoGraficzne
{
private:
	char tytul[33];
	Status status;
	int szerokosc;
	OknoGraficzne* oknoGraficzne = nullptr;
	Przycisk* przycisk;
	static int dopuszczalne[8];

	friend OknoGraficzne;

public:	
	void przypiszOkno(OknoGraficzne& o);
	void usunOkno();

	const OknoGraficzne* oknoGraf() const
	{
		return oknoGraficzne;
	}

	~OknoGraficzne()
	{
		usunOkno();
	}

	OknoGraficzne() = delete;
	OknoGraficzne(const OknoGraficzne& inne) = delete;
	OknoGraficzne(OknoGraficzne&& inne) = delete;
	OknoGraficzne& operator=(const OknoGraficzne& inne) = delete;
	OknoGraficzne& operator=(OknoGraficzne&& inne) = delete;

	OknoGraficzne(const char* nowy_tytul, Status status, int szerokosc,
	OknoGraficzne* oknoGraficzne, Przycisk* przycisk);

	Status getStatus() const;
	void setSzeroskosc(int nowa_szerokosc);
	void setEtykieta(const char* nowa_etykieta);
	void renderuj();
	void setZbiorczy(const char* nowy_tytul, Status nowy_status, int szerokosc,
		OknoGraficzne* nowe_oknoGraficzne, Przycisk* nowy_przycisk);
};