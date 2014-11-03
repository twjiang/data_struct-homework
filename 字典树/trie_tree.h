#ifndef trie_tree_H_INCLUDED
#define trie_tree_H_INCLUDED
#define max 26
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class trie_tree
{
public:
	struct trie_node
	{
		int count;
		string word;
		trie_node *next[max];
	};
	trie_tree()
	{
		root = new trie_node;
		for(int i = 0; i < max; i++)
			root->next[i] = NULL;
		words = 0;
		fcout.open("word_frequency.txt");
	}
	~trie_tree()
	{

	}

	void insert_word(string s)
	{
		int i = 0, k;
		trie_node *p = root;
		string temp_word;
		int j = 0;
		while(s[i] != '\0')
		{
			if( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') )
			{
				if(s[i] < 'a')
					s[i] += 32;
				k = s[i] - 'a';
				temp_word.append(1, s[i]);
				if(p->next[k] == NULL)
				{
					trie_node *q = new trie_node;
					q->count = 0;
					for(int i = 0; i < max; i++)
						q->next[i] = NULL;
					p->next[k] = q; 
				}
				p = p->next[k];
			}
			i++;
		}
		temp_word.append(1, '\0');
		if(p->count == 0)
		{
			p->word = temp_word;
			words_vector.push_back(p);
		}
		p->count++;
		words++;
	}
	int search_word(string s)
	{
		trie_node *p = root;
		int k, i = 0;
		int flag = 0;
		while(s[i] != '\0')
		{
			if( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') )
			{
				flag = 1;
				if(s[i] < 'a')
					s[i] += 32;
				k = s[i]-'a';
				if(p->next[k] == NULL)
					return 0;
				else
					p = p->next[k];
			}
			i++;
		}
		if(flag == 1)
			return p->count;	
		else
			return 0;
	}
	void statistics()
	{
		quick_sort(words_vector);
		for(int i = words_vector.size()-1; i >= 0; i--)
		{
			fcout << words_vector[i]->word <<":" << (float)words_vector[i]->count / num_of_words() << endl;
		}
		cout << endl;
	}
	int num_of_words()
	{
		return words;
	}
	void preorder(trie_node* p)
	{
		if(p->word != "\0")
			_fcout << p->word << endl;
		for(int i = 0; i < 26; i++)
		{
			if(p->next[i] != NULL)
				preorder(p->next[i]);
		}
	}
	void sort()
	{
		_fcout.open("word_sort.txt");
		preorder(root);
		_fcout.close();
	}
private:
	ofstream fcout;
	ofstream _fcout;

	std::vector<trie_node*> words_vector;
	trie_node *root;
	int words;

	int partition(vector<trie_node*> &A, int p, int r)
	{
		int x = A[r]->count;
		int i = p - 1;
		for(int j = p; j <= r-1; j++)
		{
			if(A[j]->count <= x)
			{
				i = i + 1;
				trie_node* temp1 = A[i];
				A[i] = A[j];
				A[j] = temp1;
			}
		}
		trie_node* temp2 = A[i+1];
		A[i+1] = A[r];
		A[r] = temp2;
		return (i + 1);
	}

	void quick_sort(vector<trie_node*> &A, int p, int r)
	{
		if(p < r)
		{
			int q = partition(A, p, r);
			quick_sort(A, p, q-1);
			quick_sort(A, q+1, r);
		}
	}

	void quick_sort(vector<trie_node*> &A)
	{
		int q = partition(A, 0, A.size()-1);
		quick_sort(A, 0, q-1);
		quick_sort(A, q+1, A.size()-1);
	}
};

#endif