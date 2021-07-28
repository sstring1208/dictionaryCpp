#include<bits/stdc++.h>

using namespace std;

#define alpha 26


struct Meaning{  //this struct is used to storing the meaning
	
	string meaning;
	
	Meaning(string s)
	{
		meaning=s;
	}
	
	
};


class TrieNode{           //this is TrieNode which will be used for,inserting the word and searching it in the tree
     
     
     TrieNode *child[alpha];
     bool isEndOfWord;
     Meaning *p;
    
     public:
     TrieNode()
     {
     	
		isEndOfWord=false;
		for(int i=0;i<alpha;i++)
		child[i]=NULL;

	 }
	void insert(struct TrieNode *root,string key,string meaning)
			{
				transform(key.begin(),key.end(),key.begin(),::tolower);
				TrieNode *temp=root;
				
				for(int i=0;i<key.length();i++)
					{
						int index=key[i]-'a';
					    if(temp->child[index]==NULL)
						temp->child[index]=new TrieNode();
						temp=temp->child[index];
					}
				temp->isEndOfWord=true;
				temp->p=new Meaning(meaning);
				
			}
		
   	bool search(struct TrieNode *root,string key)
			{
				transform(key.begin(),key.end(),key.begin(),::tolower);
				TrieNode *temp=root;
				for(int i=0;i<key.length();i++)
					{
						int index=key[i]-'a';
						if(temp->child[index]==NULL)
						return false;
						
						temp=temp->child[index];
					}
				if(temp!=NULL&&temp->isEndOfWord)
				{
					cout<<"word is "<<" "<<key<<" meaning is: "<<temp->p->meaning<<endl;
					return true;
				}
				return false;
			}
			


     
     
     
};







int main()
{
	
    
    TrieNode *root=new TrieNode();
    
  
  
	
	
	
	
		
}



