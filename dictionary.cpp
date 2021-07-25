#include<iostream>
#include<fstream>
#include<malloc.h>
#include<string.h>
#define MAX 50
using namespace std;
void wow(char *data,char * meaning);
//////////////////////////////////////////////////
struct MNode//this structure is created in order to insert the meaning of the particular words
{
		
	char meaning[50];
		
};
struct MNode* create_MNode(char *Meaning) //this will return a new node of meaning type;
{
	struct MNode *temp;
	temp=(struct MNode*)malloc(sizeof(MNode));
	strcpy(temp->meaning,Meaning);
	return temp;
}



class TTree
{
public:
    class Node
    {
    public:
        char data;
        bool isEndOfString;
        MNode *meaningPtr;
        Node *left, *eq, *right;
        Node(char c)
        {
            data = c;
            isEndOfString = false;
            left = nullptr;
            eq = nullptr;
            right = nullptr;
        }
    };

    Node *root;

    //void Insert1(Node **root, char *word);
        void Insert1(Node **root, char *word,char *meaning);
    bool Search1(Node *root, char *word);
    void Traverse1(Node *root, char *buffer, int depth);

public:
    TTree()
    {
        root = nullptr;
    }

    void Insert(char *word,char *meaning);
    void Search(char *word);
    void Traverse();

};

//void TTree::Insert1(Node **r, char *word)
void TTree::Insert1(Node **r, char *word,char *meaning)
{
    Node *node = new Node(*word);

    if (!(*r))
        (*r) = node;

    if ((*word) < (*r)->data)
        //Insert1(&((*r)->left), word);
             Insert1(&((*r)->left), word,meaning);

    else if ((*word) > (*r)->data)
      //  Insert1(&((*r)->right), word);
      Insert1(&((*r)->right), word,meaning);

    else
    {
        if (*(word + 1))
          //  Insert1(&((*r)->eq), word + 1);
          Insert1(&((*r)->eq), word + 1,meaning);

        else
           {
			 	(*r)->isEndOfString = true;
				//(*r)->meaningPtr=create_MNode();//here if the word is entered then its meaning will also be stored in the node
				(*r)->meaningPtr=create_MNode(meaning);
			}
    }
}

//void TTree::Insert(char *word)
void TTree::Insert(char *word,char *meaning)
{
    for(size_t i = 0; i < strlen(word); i++)
        word[i] = tolower(word[i]);
  //  Insert1(&root, word);
  Insert1(&root, word,meaning);
    cout << "Saved:)\n";
}

bool TTree::Search1(Node *r, char *word)
{
    if (!r)
    {
        return false;
    }

    if (*word < r->data)
        return Search1(r->left, word);

    else if (*word > r->data)
        return Search1(r->right, word);

    else
    {
        if (*(word + 1) == '\0')
            return r->isEndOfString;

        return Search1(r->eq, word + 1);
    }
}

void TTree::Search(char *word)
{
    for(size_t i = 0; i < strlen(word); i++)
        word[i] = tolower(word[i]);
    bool b = Search1(root, word);
    if(!b)
    {
        cout << "Not Found..!\n" << "Do you want to save it..?(Y/N)\n";
        char c[2];
        while(1)
        {
            cin >> c;
            c[0] = toupper(c[0]);
            if(c[0] == 'Y')
            {
               
             	
             	cout<<"\n please enter the meaning also";
			char meaning[50];
			cin.ignore();
			cin.getline(meaning,50);
             	wow(word,meaning);
      				Insert((char*)word,meaning);
             	 break;
        	}
            else if(c[0] == 'N')
            {
                cout << "Not Saved..\n";
                break;
            }

            else
                cout << "Invalid Entry..!\n" << "Choose correct option(Y/N)\n";
        }
    }
    else
        cout << "Found..!\n";
}

void TTree::Traverse1(Node* r, char* buffer, int depth)
{
    if (r)
    {
        Traverse1(r->left, buffer, depth);
        buffer[depth] = r->data;
        if (r->isEndOfString)
        {
            buffer[depth + 1] = '\0';
            
            cout << buffer <<" "<<r->meaningPtr->meaning<<endl;
        }

        Traverse1(r->eq, buffer, depth + 1);

        Traverse1(r->right, buffer, depth);
    }
}

void TTree::Traverse()
{
    char buffer[MAX];
    Traverse1(root, buffer, 0);
}
TTree t;
///////////////////////////////////////////////////////////////

class dictionary
{
	public:
		char word[15];
		char meaning[50];	
		void getword_and_meaning(char *Word,char *Meaning)
			{
				strcpy(word,Word);
				strcpy(meaning,Meaning);
				
			}
		void show_word()
			{
				t.Insert((char*)word,(char*)meaning);
			}
		int storeWord();
		void viewAllwords();
	
		
};
void dictionary::viewAllwords()
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

int dictionary::storeWord()
{
	ofstream fout;
	fout.open("word.txt",ios::app|ios::binary);
	fout.write((char*)this,sizeof(*this));
	fout.close();
	return 1;
}
void insert_word()
{
	dictionary b;
	b.viewAllwords();
} 
 void wow(char *data,char * meaning)//this fucntion is used when during search the word is not found
 
{
	dictionary b1;
	
	
	b1.getword_and_meaning(data,meaning);
	
	b1.storeWord();
}


int menu()
{
    int ch;
    cout << "1.Insert" << endl;
    cout << "2.Search" << endl;
    cout << "3.Traverse" << endl;
    cout << "4.Exit" << endl;
    cout << "Enter Your Choice :";
    cin >> ch;
    return ch;
}
int main()
{
	insert_word();
    
    char word[MAX];
    while(1)
    {
      system("cls");
        switch(menu())
        {
            case 1:
             //  cout << "Enter a word :";
              
               // cin >> word;
               // t.Insert((char*)word);
              //  break;
            case 2:
                cout << "Enter a word :";
                cin >> word;
                t.Search((char*)word);
                break;
            case 3:
                t.Traverse();
                break;
            case 4:
                exit(0);
            default:
                cout<<"Invalid entry!\n";
        }
       system("pause");
    }
    return 0;
}
