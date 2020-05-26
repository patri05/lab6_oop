#include "Movie.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;

Movie::Movie()
{
	//constructor pentru film

	Title = "";
	Genre = "";
	Publishing_Year = 0;
	Likes = 0;
	Link = "";
	ID = 0;
}

void Movie::Set_Title(string title)
{
	Title = title;
}

void Movie::Set_Genre(string genre)
{
	Genre = genre;
}

void Movie::Set_Publishing_Year(int pub)
{
	Publishing_Year = pub;
}

void Movie::Set_Likes(int likes)
{
	Likes = likes;
}

void Movie::Set_Link(string link)
{
	Link = link;
}

void Movie::Set_ID(int id)
{
	ID = id;
}

void Movie::Add_Like()
{
	//functia incrementeaza numarul de aprecieri
	Likes = Likes + 1;
}

string Movie::Get_Title()
{
	return Title;
}

string Movie::Get_Genre()
{
	return Genre;
}

int Movie::Get_Publishing_Year()
{
	return Publishing_Year;
}

int Movie::Get_Likes()
{
	return Likes;
}

string Movie::Get_Link()
{
	return Link;
}

int Movie::Get_ID()
{
	return ID;
}