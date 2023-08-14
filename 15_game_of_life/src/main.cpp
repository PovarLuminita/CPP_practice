#include <iostream>
#include <vector>

using namespace std;

int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

enum Shapes
{
	BLOCK,
	BOAT,
	BLINKER
};

class Matrice
{
private:
	int inaltime, latime;
	std::vector < std::vector < bool > > matrice; 
	void setCelula(int x, int y, int valoare) //vedem daca x si y sunt intre limite
	{
		if (x < 0 || x >= latime)
		{
			return;
		}
		if (y < 0 || y >= inaltime)
		{
			return;
		}

		matrice[y][x] = valoare ? true : false; //conversie din int in bool
	}

	int getCelula(int x, int y)
	{
		if (x < 0 || x >= latime) return 0;

		if (y < 0 || y >= inaltime) return 0;

		return matrice[y][x] ? 1 : 0; //conversie din bool in int
	}

public:
	Matrice(int height, int width)
	{
		inaltime = height;
		latime = width;
		matrice.assign(height, std::vector<bool>(width));
	}

	void Cadru() 
	{
		std::vector < std::vector <bool> > matrice_noua(inaltime, std::vector <bool>(latime));

		for (int y = 0; y < inaltime; y++)
			for (int x = 0; x < latime; x++)
			{
				int counter = 0; //numara vecinii vii

				for (int k = 0; k < 8; k++)
				{
					int nx = x + dx[k];
					int ny = y + dy[k];

					counter += getCelula(nx, ny);
				}
				if (matrice[y][x] == true)
				{
					if (counter == 2 || counter == 3)
						matrice_noua[y][x] = true;
					else
						matrice_noua[y][x] = false;

				}
				else 
					if (counter == 3)
						matrice_noua[y][x] = true;
					else
						matrice_noua[y][x] = false;

			}
		matrice.clear();
		matrice = matrice_noua;
	}

	void Desen(Shapes shape, int start_x, int start_y) 
	{
		int size_x, size_y;
		std::vector < std::vector <int> > shape_matrice;

		switch (shape)
		{
		case BLOCK:
			size_x = 2, size_y = 2;
			shape_matrice = { {1, 1},
							  {1, 1} };
			break;

		case BOAT:
			size_x = 3, size_y = 3;
			shape_matrice = { {1, 1, 0},
							  {1, 0, 1},
							  {0, 1, 0} };
			break;

		case BLINKER:
			size_x = 3, size_y = 1;
			shape_matrice = { {1, 1, 1} };

			break;
		};

		for (int y = 0; y < size_y; y++)
		{
			for (int x = 0; x < size_x; x++)
			{
				setCelula(start_x + x, start_y + y, shape_matrice[y][x]);
			}
		}
	}

	void print()
	{
		for (int y = 0; y < inaltime; y++)
			for (int x = 0; x < latime; x++)
			{
				std::cout << (matrice[y][x] ? 'X' : '-') << " \n"[x == latime - 1];
			}
		std::cout << std::endl;
	}
};

int main()
{
	int n = 10, m = 10;
	int frame_count = 15;
	Matrice matrice = Matrice(n, m);
	matrice.Desen(BLINKER, n - 5, 3);
	matrice.print();

	for (int i = 0; i < frame_count; ++i)
	{
		matrice.Cadru();
		matrice.print();
	}
	return 0;
}