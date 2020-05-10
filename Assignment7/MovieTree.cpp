#include <iostream>
#include "MovieTree.hpp"

using namespace std; 

MovieTree::MovieTree()
{
	root = NULL; 
}

void destructorHelper(TreeNode *root)
{
	if (root == NULL)
	{
		return;
	}

	destructorHelper(root->leftChild); 
	destructorHelper(root->rightChild); 
	LLMovieNode *temp = root->head; 
	while (temp->next != NULL)
	{
		root->head = root->head->next;
		delete temp; 
		temp = root->head;  
	}
	delete temp; 
	delete root; 


}

MovieTree::~MovieTree()
{
	if(root == NULL)
	{
		return;
	}
	destructorHelper(root);
	root = NULL; 
}


void printMovieHelper(TreeNode *root)
{
	if (root == NULL)
	{
		return; 
	}

	printMovieHelper(root->leftChild);

	LLMovieNode *temp = root->head;
	cout << "Movies starting with letter: " << root->titleChar << endl;
	while (temp -> next != NULL)
	{
		cout << " >> " << temp->title << " " << temp->rating << endl;
		temp = temp->next; 

	}

	cout << " >> " << temp->title << " " << temp->rating << endl;


	printMovieHelper(root->rightChild);

}

void MovieTree::printMovieInventory()
{
	printMovieHelper(root);

}

//have a function that finds the tree node with the first letter
	//if it returns NULL, it creates a new tree node with that first letter -> this will be
	//its own helper function 

TreeNode * findTreeNode(TreeNode *crawler, char firstLetter)
{
	if(crawler == NULL)
	{
		return crawler; 
	}

	if(firstLetter > crawler->titleChar)
	{
		crawler = findTreeNode(crawler->rightChild, firstLetter); 
	}

	else if(firstLetter < crawler->titleChar)
	{
		crawler = findTreeNode(crawler->leftChild, firstLetter); 
	}

	else if (firstLetter == crawler->titleChar)
	{
		return crawler; 
	}


	return crawler; 
 

}

TreeNode *addTreeNode(TreeNode *crawler, TreeNode *newNode, TreeNode *parent)
{
	if(crawler == NULL)
	{
		crawler = newNode; 
		crawler->parent = parent; 
		return crawler;
	}


	else if (newNode->titleChar < crawler->titleChar)
	{
		crawler->leftChild = addTreeNode(crawler->leftChild, newNode, crawler);
	}

	else if (newNode->titleChar > crawler->titleChar)
	{
		crawler->rightChild = addTreeNode(crawler->rightChild, newNode, crawler);
	}


 	return crawler; 
}

void MovieTree::addMovie(int ranking, string title, int year, float rating)
{
	LLMovieNode *newMovie = new LLMovieNode(ranking, title, year, rating);
	//cout << newMovie->title[0] << endl;
	if (root == NULL)
	{
		TreeNode *newTreeNode = new TreeNode;
		newTreeNode->head = newMovie; 
		newTreeNode->titleChar = newMovie->title[0];
		newTreeNode->leftChild = NULL; 
		newTreeNode->rightChild = NULL;
		newTreeNode->parent = NULL;  
		root = newTreeNode; 
		return;   
	}
	TreeNode* desiredNode = findTreeNode(root, newMovie->title[0]);

	if (desiredNode != NULL)
	{
		LLMovieNode *temp = desiredNode->head;
		if (newMovie->title < temp->title)
		{
			newMovie->next = temp; 
			desiredNode->head = newMovie; 
			return; 
		} 
		while (temp->next!= NULL)
		{
			if (newMovie->title < temp->next->title)
			{
				newMovie->next = temp->next; 
				temp->next = newMovie; 
				return; 
			}
			temp = temp->next; 

		}

		if (temp->next == NULL)
		{
			temp->next = newMovie; 
			newMovie->next = NULL; 
			return; 
		}
	}

	else if (desiredNode == NULL)
	{
		TreeNode *newTreeNode = new TreeNode;
		newTreeNode->head = newMovie; 
		newTreeNode->titleChar = newMovie->title[0];
		newTreeNode->leftChild = NULL; 
		newTreeNode->rightChild = NULL; 

		addTreeNode(root, newTreeNode, root);
		


	}
}

TreeNode *getMinValueNode(TreeNode* currNode){

    if(currNode->leftChild == NULL){
      return currNode;
    }
    return getMinValueNode(currNode->leftChild);
}

TreeNode *deleteTreeNode(TreeNode *currNode, char title)
{
	if(currNode == NULL)
	{
		return NULL; 
	}

	else if (title < currNode->titleChar)
	{
		currNode->leftChild = deleteTreeNode(currNode->leftChild, title);
	}

	else if (title > currNode->titleChar)
	{
		currNode->rightChild = deleteTreeNode(currNode->rightChild, title);
	}

	else
	{
		if(currNode->rightChild == NULL && currNode->leftChild == NULL)
		{
			delete currNode;  
			currNode = NULL; 
			
		}

		else if(currNode->leftChild == NULL) //only right child
		{
			TreeNode *temp = currNode; 
			currNode = currNode->rightChild; 
			delete temp; 
			
		}

		else if (currNode->rightChild == NULL) //only left child 
		{
			TreeNode *temp = currNode;
			currNode = currNode->leftChild; 
			delete temp; 
			
		}

		else
		{
			TreeNode *temp = getMinValueNode(currNode->rightChild); 
			currNode->titleChar = temp->titleChar; 
			currNode->head = temp->head; 
			currNode->rightChild = deleteTreeNode(currNode->rightChild, temp->titleChar);
			

		}

	}

	return currNode; 

}

void MovieTree::deleteMovie(string title)
{
	if(root == NULL)
	{
		cout << "Movie: " << title << " not found, cannot delete." << endl;
		return;
	}

	TreeNode *currNode = findTreeNode(root, title[0]);

	if(currNode->head->title == title)
	{
		if(currNode->head->next == NULL)
		{
			delete currNode->head; 
			char title = currNode->titleChar;
			root = deleteTreeNode(root, title);
		}

		else
		{
			LLMovieNode *temp = currNode->head; 
			currNode->head = currNode->head->next;
			delete temp;  
		}
	}

	else
	{
		LLMovieNode *temp = currNode->head; 
		while(temp->next->title != title && temp->next != NULL )
		{
			temp = temp->next; 
		}

		if (temp->next->title == title)
		{
			LLMovieNode *temp2 = temp->next; 
			temp->next = temp2->next; 
			delete temp2; 
		}

		else
		{
			cout << "Movie: " << title << " not found, cannot delete." << endl;

		}

	}

	return; 
	

}