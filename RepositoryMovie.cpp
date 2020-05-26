#include "RepositoryMovie.h"
#include "Movie.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

RepositoryMovie::RepositoryMovie()
{
	Initializare();
}

int RepositoryMovie::Find_Id()
{
	
	/*
		functia genereaza ID-ul unui film si ii atribuie o valoare
		mai mare ca oricare din cele din baza de date pentru a pastra unicitatea acestuia 
	*/

	int maxim = 0;

	for (unsigned int i = 0; i < Movie_Database.size(); i++)
	{
		if (Movie_Database[i].Get_ID() > maxim)
			maxim = Movie_Database[i].Get_ID();
	}
	
	return maxim + 1;
}

void RepositoryMovie::Initializare()
{
	//initializarea cu date se face cu citirea din fisierul MoviesList.txt

	ifstream f("MoviesList.txt");

	if (!f.is_open())
	{
		cout << "File not open";
		return;
	}

	string line;
	string Title, Genre, Link, YearString, LikesString;
	int Year, Likes;

	while (getline(f, line))
	{
		stringstream ss(line);
		getline(ss, Title, ',');
		getline(ss, Genre, ',');
		getline(ss, YearString, ',');
		Year = stoi(YearString);
		getline(ss, LikesString, ',');
		Likes = stoi(LikesString);
		getline(ss, Link);
		Add_Movie(Title, Genre, Year, Likes, Link);
	}

	f.close();
}


bool RepositoryMovie::Add_Movie(string Title, string Genre, int Publishing_Year, int Likes, string Link)
{

	/*
		functia creeaza un obiect nou de tip Movie caruia ii atribuie datele din parametrii functiei
		se verifica daca exista deja acest film in baza de date, daca da, se returneaza 0
		daca nu, functia returneaza 1
	*/

	Movie newMovie;

	if (Movie_Database.size() != 0)
	{
		for (unsigned int i = 0; i < Movie_Database.size(); i++)
		{
			if (Movie_Database[i].Get_Title() == Title)
			{
				//se afiseaza un mesaj de pe ecran si se iese din functie daca filmul exista deja
				cout << "The movie is already in the list" << endl;
				return 0;
			}
		}
	}

	//se atribuie datele din parametrii obiectului nou si se adauga bazei de date
	newMovie.Set_Title(Title);
	newMovie.Set_Genre(Genre);
	newMovie.Set_Likes(Likes);
	newMovie.Set_Link(Link);
	newMovie.Set_Publishing_Year(Publishing_Year);
	newMovie.Set_ID(Find_Id());
	Movie_Database.push_back(newMovie);

	return 1;
}


bool RepositoryMovie::Change_Title(int ID, string newTitle)
{

	/*
		functia modifica titlul unui film din baza de date
	  cautarea filmului se face pe baza id-ului 
	  daca modificarea a fost facuta cu succes se returneaza 1
		daca nu se returneaza 0
	*/
	for (unsigned int i = 0; i < Movie_Database.size(); i++)
	{
		if (Movie_Database[i].Get_ID() == ID)
		{
			//daca filmul este gasit se efectueaza modificarea si se iese din functie
			Movie_Database[i].Set_Title(newTitle);
			return 1;
		}
	}

	//se afiseaza un mesaj de pe ecran si se iese din functie daca filmul nu exista
	cout << "The movie wasn't found!" << endl;
	return 0;
}


bool RepositoryMovie::Change_Genre(int ID, string newGenre)
{

	/*
		functia modifica genul unui film din baza de date
		cautarea filmului se face pe baza id-ului 
		daca modificarea a fost facuta cu succes se returneaza 1
		daca nu se returneaza 0
	*/

	for (unsigned int i = 0; i < Movie_Database.size(); i++)
	{
		if (Movie_Database[i].Get_ID() == ID)
		{
			//daca filmul este gasit se efectueaza modificarea si se iese din functie
			Movie_Database[i].Set_Genre(newGenre);
			return 1;
		}
	}

	//se afiseaza un mesaj de pe ecran si se iese din functie daca filmul nu exista
	cout << "The movie wasn't found!" << endl;
	return 0;
}


bool RepositoryMovie::Change_PublishingYear(int ID, int newPublishingYear)
{

	/*
		functia modifica anul de publicare a unui film din baza de date
		cautarea filmului se face pe baza id-ului 
		daca modificarea a fost facuta cu succes se returneaza 1
		daca nu se returneaza 0
	*/

	unsigned int i;

	for (i = 0; i < Movie_Database.size(); i++)
	{
		if (Movie_Database[i].Get_ID() == ID)
		{
			//daca filmul este gasit se efectueaza modificarea si se iese din functie
			Movie_Database[i].Set_Publishing_Year(newPublishingYear);
			return 1;
		}
	}

	//se afiseaza un mesaj de pe ecran si se iese din functie daca filmul nu exista
	cout << "The movie wasn't found!" << endl;
	return 0;
}


bool RepositoryMovie::Change_Likes(int ID, int newLikes)
{

	/*
		functia modifica numarul de aprecieri a unui film din baza de date
		cautarea filmului se face pe baza id-ului 
		daca modificarea a fost facuta cu succes se returneaza 1
		daca nu se returneaza 0
	*/

	for (unsigned int i = 0; i < Movie_Database.size(); i++)
	{
		if (Movie_Database[i].Get_ID() == ID)
		{
			//daca filmul este gasit se efectueaza modificarea si se iese din functie
			Movie_Database[i].Set_Likes(newLikes);
			return 1;
		}
	}

	//se afiseaza un mesaj de pe ecran si se iese din functie daca filmul nu exista
	cout << "The movie wasn't found!" << endl;
	return 0;
}


bool RepositoryMovie::Change_Link(int ID, string newLink)
{

	/*
		functia modifica link-ul unui film din baza de date
		cautarea filmului se face pe baza id-ului 
		daca modificarea a fost facuta cu succes se returneaza 1
		daca nu se returneaza 0
	*/

	for (unsigned int i = 0; i < Movie_Database.size(); i++)
	{
		if (Movie_Database[i].Get_ID() == ID)
		{
			Movie_Database[i].Set_Link(newLink);
			return 1;
		}
	}

	cout << "The movie wasn't found!" << endl;

	return 0;
}


bool RepositoryMovie::Delete(int ID)
{

	/*
		functia sterge un film din baza de date
		cautarea filmului se face pe baza id-ului 
		daca modificarea a fost facuta cu succes se returneaza 1
		daca nu se returneaza 0
	*/

	for (unsigned int i = 0; i < Movie_Database.size(); i++)
	{
		if (Movie_Database[i].Get_ID() == ID)
		{
			//daca filmul este gasit se efectueaza modificarea si se iese din functie
			Movie_Database.erase(Movie_Database.begin() + i);
			return 1;
		}
	}

	//se afiseaza un mesaj de pe ecran si se iese din functie daca filmul nu exista
	cout << "The movie wasn't found!" << endl;
	return 0;
}


void RepositoryMovie::Play_Trailer(int ID)
{

	/*
		functia afiseaza pe ecran trailer-ul filmului
	*/

	string url;

	for (unsigned int i = 0; i < Movie_Database.size(); i++)
	{
		if (Movie_Database[i].Get_ID() == ID)
		{
			url = Movie_Database[i].Get_Link().c_str();
			ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
			return;
		}
	}
}


vector<Movie> RepositoryMovie::Get_Movies()
{
	return Movie_Database;
}


bool RepositoryMovie::Add_Movie_Watchlist(int Id)
{

	/*
		functia adauga un film in watchlist
		daca modificarea a fost facuta cu succes se returneaza true
		daca nu se returneaza false
	*/

	for (unsigned int i = 0; i < Watchlist.size(); i++)
	{
		if (Watchlist[i].Get_ID() == Id)
		{
			//daca filmul este deja in watchlist atunci se afiseaza mesaj pe ecran si se iese din functie
			cout << "Movie is already in the Watchlist" << endl;
			return false;
		}
	}

	for (unsigned int i = 0; i < Movie_Database.size(); i++)
	{
		if (Movie_Database[i].Get_ID() == Id)
		{
			//se adauga filmul si se iese din functie
			Watchlist.push_back(Movie_Database[i]);
			return true;
		}
	}

	//se afiseaza un mesaj de pe ecran si se iese din functie daca filmul nu exista
	cout << "The Movie wasn't found" << endl;
	return false;
}


bool RepositoryMovie::Delete_Movie_Watchlist(int Id, bool like)
{

	/*
		functia sterge un film din watchlist
		daca operatia a avut loc cu succes functia returneaza true
		daca nu functia returneaza false
	*/

	for (unsigned int i = 0; i < Watchlist.size(); i++)
	{
		if (Watchlist[i].Get_ID() == Id)
		{
			if (like == true)
			{
				for (unsigned int j = 0; j < Movie_Database.size(); j++)
				{
					if (Movie_Database[j].Get_ID() == Id)
					{
						Movie_Database[j].Set_Likes(Movie_Database[j].Get_Likes() + 1);
					}
				}
			}
			//filmul este sters cu succes si functia returneaza true
			Watchlist.erase(Watchlist.begin() + i);
			return true;
		}
	}

	//daca filmul nu este in watchlist atunci se afiseaza mesaj pe ecran si se iese din functie
	cout << "The Movie wasn't found" << endl;
	return false;
}


vector<Movie> RepositoryMovie::Get_Watchlist()
{
	return Watchlist;
}