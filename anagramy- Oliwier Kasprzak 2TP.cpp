#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class anagramy{

bool czy_anagram = true;

ifstream plik1;
ofstream plik2;

public:
    anagramy();
    ~anagramy();

    void sprawdz();

};

anagramy::anagramy()
{
    plik1.open("plik1.txt");
    plik2.open("plik2.txt");
}

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

	void anagramy::sprawdz()
	{
		string s1, s2;
		plik2<<"[\n";
		while(!plik1.eof())
            {
			plik1>>s1>>s2;
			if(s1.length() != s2.length())
			{
				czy_anagram = false;
			}
			int t1[s1.length()];
			int t2[s2.length()];

			for(int i = 0; i<=s1.length();i++)
            {
				t1[i] = 0;
				t2[i] = 0;
			}

			for(int i = 0;i<=s1.length()-1; i++)
            {
				t1[i] = int(s1[i]);
				t2[i] = int(s2[i]);
			}

			qsort(t1,s1.length(),sizeof(int),compare);
			qsort(t2,s2.length(),sizeof(int),compare);
			for(int i = 0; i<=s1.length();i++)
            {
				if(t1[i] != t2[i])
            {
                czy_anagram = false;
            }
			}
			 string napis;
			 if(czy_anagram)
            {
				napis = "TAK";
			}
			 else
			{
				napis = "NIE";
			}
			plik2<<"{\"slowo1\":\""<<s1<<"\", \"slowo2\":\""<<s2<<"\", \"anagram\":\""<<napis<<"\"}\n";
			czy_anagram = true;

		}
		plik2<<"]";
	}

anagramy::~anagramy()
{
    plik1.close();
    plik2.close();
}


int main(int argc, char** argv) {

	anagramy t1;
	t1.sprawdz();
	return 0;
}
