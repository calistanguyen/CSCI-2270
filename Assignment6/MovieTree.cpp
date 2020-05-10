#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST

MovieTree::MovieTree() {
	root = NULL;  
  
}

void destructorHelper(MovieNode *root)
{
	if (root==NULL)
	{
		return;
	}

	destructorHelper(root->left);
	destructorHelper(root->right);
	delete root;

	return;
}

MovieTree::~MovieTree() {
	
    if (root == NULL)
    {
        return; 
    }
    
    destructorHelper(root);
    root = NULL; 
}

void printMovieHelper(MovieNode *root)
{
	if (root == NULL)
	{
		return; 
	}
	printMovieHelper(root->left); 
	cout << "Movie: " << root->title << " " << root->rating << endl;
	printMovieHelper(root->right);
}


void MovieTree::printMovieInventory() {
   //write your code

	if (root == NULL)
	{
		cout << "Tree is Empty. Cannot print" << endl;
		return;
	}

	printMovieHelper(root);


}

MovieNode* addMovieHelper(MovieNode *crawler, MovieNode *newMovie)
{
	if(crawler == NULL)
	{
		//MovieNode *newMovie = new MovieNode(ranking, title, year, rating);
		crawler = newMovie; 
		crawler->right = NULL; 
		crawler->left = NULL; 

	}

	else if(crawler->title >= newMovie ->title)
	{
		crawler->left = addMovieHelper(crawler->left, newMovie);
	}

	else if(crawler->title <= newMovie->title)
	{
		crawler->right = addMovieHelper(crawler->right, newMovie);
	}

	return crawler; 

}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {

	MovieNode *newMovie = new MovieNode(ranking, title, year, rating);

	if (root == NULL)
	{
		root = newMovie;
		return;
	}

	addMovieHelper(root, newMovie);
	

}

void findMovieHelper(MovieNode *root, string title)
{
	if (root == NULL)
	{
		cout << "Movie not found." << endl;
		return;
	}

	if(title > root->title)
	{
		findMovieHelper(root->right, title);
	}

	else if (title < root->title)
	{
		findMovieHelper(root->left, title);
	}

	else if (title==root->title)
	{
		cout << "Movie Info:" << endl;
		cout << "==================" << endl;
		cout << "Ranking:" << root->ranking << endl;
		cout << "Title :" << root->title << endl;
		cout << "Year :" << root->year << endl;
		cout << "rating :" << root->rating << endl;
		return; 
	}
	return; 
}

void MovieTree::findMovie(string title) {
  //write your code
	if(root == NULL)
	{
		cout << "Movie not found." << endl;
		return;
	}

	findMovieHelper(root, title);

}

void queryHelper(MovieNode*root, float rating, int year)
{
	if(root == NULL)
	{
		return;
	}

	if (root->rating>= rating && root->year > year)
	{
		cout << root->title << "(" << root->year << ") " << root->rating << endl;
	}
	queryHelper(root->left, rating, year);
	queryHelper(root->right, rating, year);
	return;

}

void MovieTree::queryMovies(float rating, int year) {
  //write your code
	if (root == NULL)
	{
		cout << "Tree is Empty. Cannot query Movies" << endl;
		return;
	}
	cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl ;
	queryHelper(root, rating, year);

}


float addRatings(MovieNode *root)
{
	if(root == NULL)
	{
		return 0; 
	}

	return root->rating + addRatings(root->right)+addRatings(root->left); 
	
}

int numNodes(MovieNode *crawler)
{
	if (crawler==NULL)
	{
		return 0; 
	}

	return (numNodes(crawler->left) + numNodes(crawler->right) + 1);


}

void MovieTree::averageRating() {
  //write your code
	if (root == NULL)
	{
		cout << "Average rating:0.0" << endl;
		return;
	}

	float numRatings = addRatings(root);
	int numMovies = numNodes(root);

	cout <<"Average rating:"<< numRatings/numMovies << endl; 

	
}



