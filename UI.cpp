#include <iostream>
#include "UI.h"
#include "RepositoryMovie.h"
#include "Movie.h"
#include <string>
#include <vector>
#include <iomanip>
#include <Windows.h>

using namespace std;

UI::UI() 
{ 
	csv = false; 
	html = false; 
}

void UI::Upload()
{
	//functie de upload

	unsigned int i;
	ofstream f("MoviesList.txt");

	for (i = 0; i < Repo.Movie_Database.size(); i++)
	{
		f << Repo.Movie_Database[i].Get_Title() << ",";
		f << Repo.Movie_Database[i].Get_Genre() << ",";
		f << Repo.Movie_Database[i].Get_Publishing_Year() << ",";
		f << Repo.Movie_Database[i].Get_Likes() << ",";
		f << Repo.Movie_Database[i].Get_Link();
		f << endl;
	}

	f.close();
}

void UI::Choose_File_Type()
{
	//alegerea unui tip de fisier

	int x;

	while (true)
	{
		cout << "Choose between:" << endl << "1.Html" << endl << "2.Csv" << endl;
		x=Contr.Validate_int();
		
		if (x == 1)
		{
			html = true;
			return;
		}

		if (x == 2)
		{
			csv = true;
			return;
		}
	}
}

void UI::Show_All_Movies()
{

	//functia afiseaza pe ecran toate filmele

	vector<Movie> Movies;
	Movies = Repo.Get_Movies();

	cout << fixed;
	cout << setprecision(2);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Database Movies~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	cout << left << setw(5) << "ID";
	cout << right << setw(15) << "Title";
	cout << right << setw(15) << "Genre";
	cout << right << setw(15) << "Likes";
	cout << right << setw(20) << "Publishing Year";
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << endl;

	for (unsigned int i = 0; i < Movies.size(); i++)
	{
		cout << fixed;
		cout << setprecision(2);
		cout << left << setw(5) << Movies[i].Get_ID();
		cout << right << setw(15) << Movies[i].Get_Title();
		cout << right << setw(15) << Movies[i].Get_Genre();
		cout << right << setw(15) << Movies[i].Get_Likes();
		cout << right << setw(20) << Movies[i].Get_Publishing_Year();
		cout << endl;
	}
}

void UI::Show_Watchlist()
{

	//functia afiseaza pe ecran toate filmele din watchlist

	vector<Movie> Movies;
	Movies = Repo.Get_Watchlist();
	
	if (Movies.size() == 0)
	{
		cout << "Watchlist is empty" << endl;
		return;
	}
	
	cout << fixed;
	cout << setprecision(2);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Database Movies~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	cout << left << setw(5) << "ID";
	cout << right << setw(15) << "Title";
	cout << right << setw(15) << "Genre";
	cout << right << setw(15) << "Likes";
	cout << right << setw(20) << "Publishing Year";
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << endl;
	
	for (unsigned int i = 0; i < Movies.size(); i++)
	{
		cout << fixed;
		cout << setprecision(2);
		cout << left << setw(5) << Movies[i].Get_ID();
		cout << right << setw(15) << Movies[i].Get_Title();
		cout << right << setw(15) << Movies[i].Get_Genre();
		cout << right << setw(15) << Movies[i].Get_Likes();
		cout << right << setw(20) << Movies[i].Get_Publishing_Year();
		cout << endl;
	}
}

void UI::Show_Genre(string Genre)
{
	//functia afiseaza toate filmele de un anumit gen
	//daca nu este nici un film de acel gen se afiseaza mesaj pe ecran

	vector<Movie> Movies;
	Movies = Repo.Get_Movies();
	bool ok = 0;
	
	for (unsigned int i = 0; i < Movies.size(); i++)
	{
		if (Movies[i].Get_Genre() == Genre)
		{
			ok = 1;
			break;
		}
	}
	
	if (ok == 1)
	{
		cout << fixed;
		cout << setprecision(2);
		cout << left << setw(5) << "ID";
		cout << right << setw(15) << "Title";
		cout << right << setw(15) << "Genre";
		cout << right << setw(15) << "Likes";
		cout << right << setw(20) << "Publishing Year";
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << endl;
		
		for (unsigned int i = 0; i < Movies.size(); i++)
		{
			if (Movies[i].Get_Genre() == Genre)
			{
				cout << fixed;
				cout << setprecision(2);
				cout << left << setw(5) << Movies[i].Get_ID();
				cout << right << setw(15) << Movies[i].Get_Title();
				cout << right << setw(15) << Movies[i].Get_Genre();
				cout << right << setw(15) << Movies[i].Get_Likes();
				cout << right << setw(12) << Movies[i].Get_Publishing_Year();
				cout << endl;
			}
		}

		return;
	}
	else
		cout << "There are no movies with this genre" << endl;
	return;
}

void UI::Menu_main()
{
	
	//meniul principal
	//functia afiseaza pe ecran mai multe posibilitati din care utillizatorul poate sa aleaga

	string Options[3] = { "1.Administartor","2.User","3.Exit" };
	int pointer = 0;
	
	system("cls");
	Show_All_Movies();
	
	for (int i = 0; i < 3; ++i)
	{
		cout << Options[i] << endl;
	}
	
	cout << "Enter option:";
	pointer = Contr.Validate_int();
	
	switch (pointer)
	{
		case 1:
		{
			//se deschide meniul administratorului
			Menu_administrator();
		}break;
		
		case 2:
		{
			//se deschide meniul utilizatorului
			Menu_User();
		}break;
		
		case 3:
		{
			//se face upload si se iese din functie si
			Upload();
			return;
		}
		
		default:
		{
			cout << "Wrong Option, try again.";
			Sleep(2000);
			Menu_main();
		}break;
	}
}

void UI::Menu_administrator()
{

	//meniul administrator
	//functia afiseaza pe ecran mai multe posibilitati din care utillizatorul poate sa aleaga

	string Options[7] = { "1.Add Movie", "2.Change Title", "3.Change Genre","4.Change publishing year","5.Change likes","6.Delete","7.Back" };
	string Title, Genre, link;
	int Id, Year, likes, pointer = 0;
	
	system("cls");
	Show_All_Movies();
	
	for (int i = 0; i < 7; ++i)
		cout << Options[i] << endl;
	
	cout << "Enter option:";
	pointer = Contr.Validate_int();
	
	switch (pointer)
	{
		case 1:
		{
			//se adauga un film
			cout << "Title:";
			cin >> Title;
			cout << "Genre:";
			cin >> Genre;
			cout << "Publishing year:";
			Year = Contr.Validate_Year();
			cout << "Likes:";
			likes = Contr.Validate_int();
			cout << "Link:";
			cin >> link;
			Repo.Add_Movie(Title, Genre, Year, likes, link);
			Sleep(1000);
			Menu_administrator();
		} break;

		case 2:
		{
			// se modifica titlul
			cout << "ID:";
			Id = Contr.Validate_int();
			cout << "New Title:";
			cin >> Title;
			Repo.Change_Title(Id, Title);
			Sleep(1000);
			Menu_administrator();
		} break;

		case 3:
		{
			// se modifica genul
			cout << "ID:";
			Id = Contr.Validate_int();
			cout << "New Genre:";
			cin >> Genre;
			Repo.Change_Genre(Id, Genre);
			Sleep(1000);
			Menu_administrator();
		} break;

		case 4:
		{
			// se modifica anul
			cout << "ID:";
			Id = Contr.Validate_int();
			cout << "New publishing year:";
			Year = Contr.Validate_Year();
			Repo.Change_PublishingYear(Id, Year);
			Sleep(1000);
			Menu_administrator();
		}break;

		case 5:
		{
			// se modifica numarul de aprecieri
			cout << "ID:";
			Id = Contr.Validate_int();
			cout << "New likes:";
			likes = Contr.Validate_int();
			Repo.Change_Likes(Id, likes);
			Sleep(1000);
			Menu_administrator();
		}break;

		case 6:
		{
			//se sterge un film
			cout << "ID:";
			Id = Contr.Validate_int();
			Repo.Delete(Id);
			Sleep(1000);
			Menu_administrator();
		}break;

		case 7:
		{
			//se revine la meniul principal
			Menu_main();
			Sleep(1000);
		}break;

		default:
		{
			cout << "Wrong Option, try again.";
			Sleep(2000);
			Menu_administrator();
		}break;
	}
}

void UI::Menu_User()
{

	//meniul utilizator
	//functia afiseaza pe ecran mai multe posibilitati din care utillizatorul poate sa aleaga

	system("cls");
	
	if (html == false && csv == false)
		Choose_File_Type();
	
	system("cls");
	
	int pointer = 0, IdMovie;
	string Options[5] = { "1.Show Genre","2.Delete from watchlist","3.Show Watchlist","4.Display the watchlist in the selected format","5.Back" };
	string Genre;
	
	for (int i = 0; i < 5; i++)
	{
		cout << Options[i] << endl;
	}
	
	cout << "Enter option:";
	pointer = Contr.Validate_int();
	
	switch (pointer)
	{
		case 1:
		{
			//se afiseaza filmele dupa gen, daca nu e precizat, atunci sunt afisate toate
			cout << "Type the genre or press enter to print all Movies:";
			cin.ignore();
			getline(cin, Genre);
			if (Genre.size() == 0)
			{
				Submenu_User();
				Menu_User();
			}
			else
			{
				Show_Genre(Genre);
				Sleep(2000);
				Menu_User();
			}
		}break;

		case 2:
		{
			//stergerea unui film din watchlist
			char ch;
			cout << "Id:";
			IdMovie = Contr.Validate_int();
			cout << "Did you liked the movie? [y/n]:";
			cin >> ch;
			if (ch == 'y')
				Repo.Delete_Movie_Watchlist(IdMovie, true);
			else
				Repo.Delete_Movie_Watchlist(IdMovie, false);
			Menu_User();
		}break;

		case 3:
		{
			//afiseaza watchlist-ul
			Show_Watchlist();
			Sleep(2000);
			Menu_User();
		}break;

		case 4:
		{
			//afiseaza watchlistul in formatul selectat
			if (csv == true)
			{
				Create_Csv();
				//system("Notepad++.exe Watchlist.csv");
				ShellExecute(NULL, "open", "Watchlist.csv", NULL, NULL, SW_SHOWNORMAL);
			}
			else if (html == true)
			{
				Create_Html();
				ShellExecute(NULL, "open", "Webpage.htm", NULL, NULL, SW_SHOWNORMAL);
			}
		}break;

		case 5:
		{
			//se revine la meniul principal
			Menu_main();
		}break;

		default:
		{
			cout << "Wrong options ,try again!" << endl;
			Sleep(2000);
			Menu_User();
		}break;
	}
}

void UI::Submenu_User()
{

	//submeniul utilizator
	//functia afiseaza pe ecran mai multe posibilitati din care utillizatorul poate sa aleaga

	vector<Movie> Movies;
	Movies = Repo.Get_Movies();
	string Options[4] = { "1.Add Movie to Watchlist","2.Play Trailer","3.Next","4.Back to main user menu" };
	int pointer;
	
	cout << endl;
	
	for (unsigned int i = 0; i < Movies.size(); i++)
	{
		cout << "ID: " << Movies[i].Get_ID() << endl;
		cout << "Title: " << Movies[i].Get_Title() << endl;
		cout << "Genre: " << Movies[i].Get_Genre() << endl;
		cout << "Likes: " << Movies[i].Get_Likes() << endl;
		cout << "Publishing Year: " << Movies[i].Get_Publishing_Year() << endl;
		cout << endl;
		
		for (int j = 0; j < 4; j++)
		{
			cout << Options[j] << endl;
		}
		
		cout << "Enter option:";
		pointer = Contr.Validate_int();
		
		switch (pointer)
		{
			case 1:
			{
				//adaugare film la watchlist
				Repo.Add_Movie_Watchlist(Movies[i].Get_ID());
			}break;

			case 2:
			{
				//pornire trailer
				char ch;
				Repo.Play_Trailer(Movies[i].Get_ID());
				cout << "Do you want to add the movie to the watchlist? [y/n]:";
				cin >> ch;
				if (ch == 'y')
					Repo.Add_Movie_Watchlist(Movies[i].Get_ID());
			}break;

			case 3:
			{
				//pass
			}break;

			case 4:
			{
				//reintoarcere la meniul utilizator
				Menu_User();
			}break;

			default:
			{
				cout << "Wrong options ,try again!" << endl;
				Sleep(2000);
			}break;
		}
	}
}

void UI::Create_Html()
{
	//generare html 

	ofstream f("Webpage.htm");

	f << "<html>" << endl;
	f << "<head>" << endl;
	f << "<title>Lab 6 oop</title>" << endl;
	f << "</head>" << endl;
	f << "<body>" << endl;
	f << "<h2 align = 'center'> Lab 6 oop </h2>" << endl;

	f << "<table border='1' style='float: centre' align='center' cellspacing='5'>" << endl;
	f << "<caption>Watchlist</caption>" << endl;
	f << "<tr>";
	f << "<th>Id</th>" << endl;
	f << "<th>Title</th>" << endl;
	f << "<th>Genre</th>" << endl;
	f << "<th>Year</th>" << endl;
	f << "<th>Likes</th>" << endl;
	f << "<th>Trailer</th>" << endl;
	f << "</tr>" << endl;

	for (unsigned int i = 0; i < Repo.Watchlist.size(); i++)
	{
		f << "<tr>" << endl;
		f << "<td>" << Repo.Watchlist[i].Get_ID() << "</td>" << endl;
		f << "<td>" << Repo.Watchlist[i].Get_Title() << "</td>" << endl;
		f << "<td>" << Repo.Watchlist[i].Get_Genre() << "</td>" << endl;
		f << "<td>" << Repo.Watchlist[i].Get_Publishing_Year() << "</td>" << endl;
		f << "<td>" << Repo.Watchlist[i].Get_Likes() << "</td>" << endl;
		f << "<td><a href=" << "'" << Repo.Watchlist[i].Get_Link() << "'>Link</a></td>" << endl;
		f << "</tr>" << endl;
	}

	f << "</table>" << endl;
	f << "</body>" << endl;
	f << "</html>" << endl;
}

void UI::Create_Csv()
{
	//generare csv

	unsigned int i;
	ofstream f("Watchlist.csv");

	for (i = 0; i < Repo.Watchlist.size(); i++)
	{
		f << Repo.Watchlist[i].Get_Title() << ",";
		f << Repo.Watchlist[i].Get_Genre() << ",";
		f << Repo.Watchlist[i].Get_Publishing_Year() << ",";
		f << Repo.Watchlist[i].Get_Likes() << ",";
		f << Repo.Watchlist[i].Get_Link();
		f << endl;
	}

	f.close();
}

