// lab 1322 lab 1

#include <iostream>
#include <vector>

using namespace std;

// functions prototypes
vector<vector<char>> make_foward();
vector<vector<char>> make_mirror(vector<vector<char>>);
char reverse(char);
// print functions overloaded 
void printVector(vector<vector<char>>);
void printVector(vector<vector<char>>, vector<vector<char>>);

int main()
{
	// variables of 2d char vectors 
	vector<vector<char>> art, rev;

	art = make_foward();

	printVector(art);

	rev = make_mirror(art);

	printVector(rev);

	printVector(art, rev);
}

// creates and 2d vector called pixel and added the elements to the pixel 2d vector 
vector<vector<char>> make_foward()
{
	vector<vector<char>> pixel;

	vector<char> temp;

	// index 0
	temp.push_back(' '); // 0
	temp.push_back(' '); // 1
	temp.push_back('_'); // 2
	temp.push_back('_'); // 3
	temp.push_back('_'); // 4
	temp.push_back('_'); // 5
	temp.push_back('_'); // 6
	temp.push_back('_'); // 7
	temp.push_back(' '); // 8
	temp.push_back(' '); // 9
	temp.push_back(' '); // 10
	temp.push_back(' '); // 11
	temp.push_back(' '); // 12

	// index 0 into pixel vector 
	pixel.push_back(temp);
	temp.clear();

	// index 1
	temp.push_back(' ');  // 0
	temp.push_back('/');  // 1
	temp.push_back('|');  // 2
	temp.push_back('_');  // 3
	temp.push_back('|');  // 4
	temp.push_back('|');  // 5
	temp.push_back('_');  // 6
	temp.push_back('\\'); // 7
	temp.push_back('\''); // 8
	temp.push_back('.');  // 9
	temp.push_back('_');  // 10
	temp.push_back('_');  // 11
	temp.push_back(' ');  // 12

	// index 1 into pixel vector 
	pixel.push_back(temp);
	temp.clear();

	// index 2
	temp.push_back('(');  // 0
	temp.push_back(' ');  // 1
	temp.push_back(' ');  // 2
	temp.push_back(' ');  // 3
	temp.push_back('_');  // 4
	temp.push_back(' ');  // 5
	temp.push_back(' ');  // 6
	temp.push_back(' ');  // 7
	temp.push_back(' ');  // 8
	temp.push_back('_');  // 9
	temp.push_back(' ');  // 10
	temp.push_back('_');  // 11
	temp.push_back('\\'); // 12

	// index 2 into pixel vector 
	pixel.push_back(temp);
	temp.clear();

	// index 3
	temp.push_back('=');  // 0
	temp.push_back('\''); // 1
	temp.push_back('-');  // 2
	temp.push_back('(');  // 3
	temp.push_back('_');  // 4
	temp.push_back(')');  // 5
	temp.push_back('-');  // 6
	temp.push_back('-');  // 7
	temp.push_back('\''); // 8
	temp.push_back('(');  // 9
	temp.push_back('_');  // 10
	temp.push_back(')');  // 11
	temp.push_back('-');  // 12
	
	// index 3 into pixel vector 
	pixel.push_back(temp);
	temp.clear();

	return pixel;
}

// make_mirror function - used to flip the elements of the 2d vector like seeing a mirror 
vector<vector<char>> make_mirror(vector<vector<char>> pixel)
{
	char temp = ' ';

	// nested for loop to loop theough the elements of the 2d vector one by one to swap them as deem neccessary
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			// break after the 6 elements in the nested part of the array because 6 is the middle and all other elements have been reversed
			if (j == 6)
			{
				break;
			}

			// switch case for j the count element to loop through the elements of the 2d vectors and begin mirroring them and sending them to reverse() if need be 
			switch (j)
			{
			case 0:
			{
				temp = reverse(pixel[i][12]);
				pixel[i][12] = reverse(pixel[i][j]);
				pixel[i][j] = temp;
				break;
			}
			case 1:
			{
				temp = reverse(pixel[i][11]);
				pixel[i][11] = reverse(pixel[i][j]);
				pixel[i][j] = temp;
				break;
			}
			case 2:
			{
				temp = reverse(pixel[i][10]);
				pixel[i][10] = reverse(pixel[i][j]);
				pixel[i][j] = temp;
				break;
			}
			case 3:
			{
				temp = reverse(pixel[i][9]);
				pixel[i][9] = reverse(pixel[i][j]);
				pixel[i][j] = temp;
				break;
			}
			case 4:
			{
				temp = reverse(pixel[i][8]);
				pixel[i][8] = reverse(pixel[i][j]);
				pixel[i][j] = temp;
				break;
			}
			case 5:
			{
				temp = reverse(pixel[i][7]);
				pixel[i][7] = reverse(pixel[i][j]);
				pixel[i][j] = temp;
				break;
			}
			default:
				break;
			}
		}
	}

	return pixel;
}

// reverse function - used to reverse some elemtns of the 2d vectors that are special characters 
char reverse(char currentPixel)
{
	// switch case for current pixel to see what the mirror verse of the current pixel will be and return it as the new current pixel
	switch (currentPixel)
	{
	case '(':
	{
		currentPixel = ')';
		break;
	}
	case ')':
	{
		currentPixel = '(';
		break;
	}
	case '\\':
	{
		currentPixel = '/';
		break;
	}
	case '/':
	{
		currentPixel = '\\';
		break;
	}
	default:
		break;
	}

	return currentPixel;
}

// printVector function - used to print the 2D vector 
void printVector(vector<vector<char>> pixelArt)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			cout << pixelArt[i][j];
		}
		cout << endl;
	}
}

// overloaded printVector Function - used to print two 2d vetors 
void printVector(vector<vector<char>> pixelArt, vector<vector<char>> pixelArtReverse)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			cout << pixelArt[i][j];
		}
		for (int j = 0; j < 13; j++)
		{
			cout << pixelArtReverse[i][j];
		}
		cout << endl;
	}
}
