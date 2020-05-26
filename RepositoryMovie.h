#ifndef REPOSITORYMOVIE_H
#define REPOSITORYMOVIE_H
#include "Movie.h"
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

class RepositoryMovie
{
private:
	
public:
	vector<Movie> Movie_Database;
	vector<Movie> Watchlist;
	RepositoryMovie();
	int Find_Id();
	void Initializare();
	bool Add_Movie(string Title, string Genre, int Publishing_Year, int Likes, string Link);
	bool Change_Title(int ID, string newTitle);
	bool Change_Genre(int ID, string newGenre);
	bool Change_PublishingYear(int ID, int newPublishingYear);
	bool Change_Likes(int ID, int newLikes);
	bool Change_Link(int ID, string newLink);
	bool Delete(int ID);
	void Play_Trailer(int ID);
	vector<Movie> Get_Movies();
	bool Add_Movie_Watchlist(int Id);
	bool Delete_Movie_Watchlist(int Id,bool like);
	vector<Movie> Get_Watchlist();
};
#endif