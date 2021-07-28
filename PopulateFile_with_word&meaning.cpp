#include<bits/stdc++.h>
using namespace std;
// THIS IS THE FUCTIONALITY TO POPULATE THE FILE WITH WORD AND MEANING


class dictionary
{
	public:
		char word[15];
		char mean[30];
		
		dictionary()
		{
			strcpy(word,"no word");
			strcpy(mean,"no meaning");
		}
		
	void getword_and_meaning()
	{
		cout<<"enter the word and corresponding meaning: ";
		cin.getline(word,15);
		cin.getline(mean,30);


	}
	void show_word()
	{
		cout<<"word:"<< word<<"  meaning :"<<mean<<endl;
	}
	
	
int storeWord()
{
	ofstream fout;
	fout.open("word.txt",ios::app|ios::binary);
	fout.write((char*)this,sizeof(*this));
	fout.close();
	return 1;
}

void viewAllwords()
{
	ifstream fin;
	fin.open("word.txt",ios::in|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		show_word();
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
}



	
		
};



int main()
{
	
	for(int i=0;i<14;i++)
	{
	dictionary b1;
	b1.getword_and_meaning();
	b1.show_word();
	b1.storeWord();
	}
		
	dictionary b;
	b.viewAllwords();

}





