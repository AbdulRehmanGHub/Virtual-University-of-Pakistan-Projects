/*	Name:	Abdul Rehman.
	VU ID:	BC220424444.	*/

#include<iostream>
#include<conio.h>

using namespace std;

// starting the class Artist.
class Artist
{
	private:
		string artistName;
	public:
		Artist()
		{
			artistName="";
		}
	void SetArtistName()
	{
		cout<<endl;
		cout<<"Enter Artist Name : ";
		cin>>artistName;	
	}
	void Display()
	{
		cout<<endl<<endl;
		cout<<"Artist Name : "<<artistName;
	}
	~Artist()
	{
	}
};

// starting the class MusicBand.
class MusicBand
{
	private:
		string bandName;
		Artist A;
	public:
		MusicBand()
		{
			bandName="";
		}
		void SetBandName()
		{
			A.SetArtistName();
			cout<<"Enter Music Band Name : ";
			cin>>bandName;
		}
		void Display()
		{
			A.Display();
			cout<<endl;
			cout<<"Music Band Name : "<<bandName;
		}
		~MusicBand()
		{
		}
};

// starting the class MusicCategory.
class MusicCategory
{
	private:
		string categoryName, inst;
		MusicBand M;
	public:
		MusicCategory()
		{
			categoryName="";
			inst="";
		}
		void SetCategoryName()
		{
			M.SetBandName();
			cout<<"Enter Music Category Name : ";
			cin>>categoryName;
		}
		void SetInstrument()
		{
			cout<<"Enter Instrument Name : ";
			cin>>inst;
		}
		void Display()
		{
			M.Display();
			cout<<endl;
			cout<<"Music Category Name : "<<categoryName;
			cout<<endl;
			cout<<"Instrument Name : "<<inst;
		}
		~MusicCategory()
		{
		}
};

// starting the class for Pop Music.
class Pop: public MusicCategory
{
};

// starting the class for Classic Music.
class Classic: public MusicCategory
{
};

// Starting the main function.
int main()
{
	Pop P;
	Classic C;
	cout<<"VUID: BC220424444";
	 cout<<endl;
	P.SetCategoryName();
	P.SetInstrument();
	C.SetCategoryName();
	C.SetInstrument();
	 cout<<endl<<endl;
	cout<<"Data of First Artist";
	P.Display();
	 cout<<endl<<endl;
	cout<<"Data of Second Artist";
	C.Display();
	getch();
	return 0;
}
