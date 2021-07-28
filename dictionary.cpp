#include <bits/stdc++.h>
using namespace std;

#define alpha 26
struct Meaning
{ //this struct is used to storing the meaning

    string meaning;

    Meaning(string s)
    {
        meaning = s;
    }
};

class TrieNode
{ //this is TrieNode which will be used for,inserting the word and searching it in the tree

    TrieNode *child[alpha];
    bool isEndOfWord;
    Meaning *p;

public:
    TrieNode()
    {

        isEndOfWord = false;
        for (int i = 0; i < alpha; i++)
            child[i] = NULL;
    }
    void insert(TrieNode *root, string word, string meaning)
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        TrieNode *temp = root;

        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (temp->child[index] == NULL)
                temp->child[index] = new TrieNode();
            temp = temp->child[index];
        }
        temp->isEndOfWord = true;
        temp->p = new Meaning(meaning);
    }

    bool search(TrieNode *root, string word)
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        TrieNode *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (temp->child[index] == NULL)
                return false;

            temp = temp->child[index];
        }
        if (temp != NULL && temp->isEndOfWord)
        {
        	
            cout << "\n\nWORD:  "<< " " << word << "   MEANING: " << temp->p->meaning << endl<<endl;
            return true;
        }
        return false;
    }
};

 TrieNode *root=new TrieNode();

class dictionary
{
public:
    char word[15];
    char mean[30];

    dictionary()
    {
        strcpy(word, "no word");
        strcpy(mean, "no meaning");
    }

    void setData(string a,string b)
    {
        strcpy(word, a.c_str());
        strcpy(mean, b.c_str());
        
    }
    
    void show_data()
    {
    	
    	cout<<"          WORD: "<<word<<"  "<<"         MEANING: "<<mean<<endl;
	}

    void make_tree()
    {
        string Word(word);
        string Meaning(mean);
        root->insert(root, Word, Meaning);
    }

    int storeWord()
    {
        ofstream fout;
        fout.open("word.txt", ios::app | ios::binary);
        fout.write((char *)this, sizeof(*this));
        fout.close();
        return 1;
    }

    void setWordToTree()
    {
        ifstream fin;
        fin.open("word.txt", ios::in | ios::binary);
        fin.read((char *)this, sizeof(*this));
        while (!fin.eof())
        {
            make_tree();
            fin.read((char *)this, sizeof(*this));
        }
        fin.close();
    }
    
    void ViewStoredWords()
    {
    	ifstream fin;
        fin.open("word.txt", ios::in | ios::binary);
        fin.read((char *)this, sizeof(*this));
        while (!fin.eof())
        {
            show_data();
            fin.read((char *)this, sizeof(*this));
        }
        fin.close();
	}
};

void insert_new_entry(string word)
{
	string mean;
	cout<<"Enter the meaning for the word"<<endl;
	cin>>mean;
	root->insert(root,word,mean);
	dictionary b;
	b.setData(word,mean);
	b.storeWord();
	
}

void insert_word()
{
    dictionary b;
    b.setWordToTree();
};

int menu()
{
    int ch;
    
    cout<<"_____________________________________________\n";
    cout<<"\nPress 1 for searching word and their meaning"<<endl;
    cout<<"Press 2 to see all the word and meaning"<<endl;
    cout<<"Press 3 to exit"<<endl;
    cout<<"_____________________________________________\n";
    cout<<"enter your choice:";
    cin >> ch;
    return ch;
}

int main()
{
    insert_word();
	string word;
	dictionary b;
	cout<<"####################################\n";
	cout<<"       WELCOME TO DICTIONARY         \n";
	cout<<"####################################\n";
	
   
    while (1)
    {
        
        
       
        switch (menu())
        {
        
        case 1:
          
          	cout<<"\n\nEnter the Word"<<endl;
            cin >> word;
            if (!root->search(root,word))
            {
                cout<<"\nSorry! The word doesn't Exist in the dictionary\n";
                string flag;
                cout<<"\nDo you know the meaning of the word?(Y/N):";
                cin>>flag;
                if(flag=="Y"||flag=="y")
                {
                	insert_new_entry(word);
				}
                
                else{
                	cout<<" \nOK NO PROBLEM ,try something else :)"<<endl; 
				}
                
            }

            break;
        case 2:
        	
        	cout<<endl<<endl<<endl;
        	cout<<"<-----##------WORDS___&___MEANING LIST------##----->\n";
        	cout<<"_____________________________________________\n\n";
        	
        	b.ViewStoredWords();
        	cout<<"_____________________________________________\n";
        	cout<<"_____________________________________________\n\n\n";
        
           
            break;
        case 3:
        	cout<<"<<--------##---------!!! GOOD BYE  !!!---------##-------->\n";
            exit(0);
        default:
            cout << "Invalid entry!\n";
        }
        system("pause");
    }
    return 0;
}
