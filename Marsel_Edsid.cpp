/*Projektna naloga
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Orozje
{
	protected:
		float napad;
		float hitrost;
		float kriticni_napad; // v procentih
	public:
		void vpis(float n, float h, float k)
		{
			napad = n;
			hitrost = h;
			kriticni_napad = k;
		}
		void izpis();
};
class Oklep
{
	protected:
		float zascita;
		float zivljenje;
	public:
		void vpis(float s, float z)
		{
			zascita = s;
			zivljenje = z;
		}
		void izpis();
};
class Heroj: public Orozje, public Oklep
{
	private:
		string ime;
		int level;
	public:
		void vpis(float n, float h, float k, float s, float z, string i, int l)
		{
			ime = i;
			level = l;
			Orozje::vpis(n, h, k);
			Oklep::vpis(s, z);
		}
			void izpis();
};
void Orozje::izpis()
{
	cout << "Napad: " << napad << " DPS" << endl;
	cout << "Hitrost: " << hitrost << endl;
	cout << "Kriticni napad: " << kriticni_napad << " %" << endl;
}
void Oklep::izpis()
{
	cout << "Zascita: " << zascita << " ARM" << endl;
	cout << "Zivljenje: " << zivljenje << " HP" << endl;
}
void Heroj::izpis()
{
	Orozje::izpis();
	Oklep::izpis();
	cout << "Ime heroja: " << ime << endl;	
	cout << "Level: " << level << " lvl" << endl;
}
int main()
{
	float a, b, c, d, e, rezultat1, rezultat2;
	string f;
	int g;
	ofstream datoteka;
	datoteka.open("Igra.txt");
	cout << "Heroj 1" << endl;
	cout << "*********************************" << endl;
	cout << "Vnesi napad orozja: " << endl;	
	cin >> a;
	cout << "Vnesi hitrost orozja: " << endl;
	cin >> b;
	cout << "Vnesi kriticni napad orozja: " << endl;
	cin >> c;
	cout << "Vnesi zascito oklepa: " << endl;
	cin >> d;
	cout << "Vnesi zivljenje oklepa: " << endl;
	cin >> e;
	cin.ignore();
	cout << "Vnesi ime heroja: " << endl;
	getline(cin, f);
	cout << "Vnesi level heroja: " << endl;
	cin >> g;
	cout << "\n";
	Heroj heroj1;
	heroj1.vpis(a, b, c, d, e, f, g);
	rezultat1 = (a*b*c)+(d*e)+g;
	
	datoteka << "**************IZPIS**************" << endl;
	datoteka << "Heroj 1: " << endl;
	datoteka << "Napad heroja: " << a << endl;
	datoteka << "Hitrost heroja: " << b << endl;
	datoteka << "Kriticni napad heroja: " << c << endl;
	datoteka << "Zascita heroja: " << d << endl;
	datoteka << "Zivljenje heroja: " << e << endl;
	datoteka << "Ime heroja: " << f << endl;
	datoteka << "Level heroja: " << g << endl;
	datoteka << "*********************************" << endl;
	
	cout << "Heroj 2" << endl;
	cout << "*********************************" << endl;
	cout << "Vnesi napad orozja: " << endl;	
	cin >> a;
	cout << "Vnesi hitrost orozja: " << endl;
	cin >> b;
	cout << "Vnesi kriticni napad orozja: " << endl;
	cin >> c;
	cout << "Vnesi zascito oklepa: " << endl;
	cin >> d;
	cout << "Vnesi zivljenje oklepa: " << endl;
	cin >> e;
	cin.ignore();
	cout << "Vnesi ime heroja: " << endl;
	getline(cin, f);
	cout << "Vnesi level heroja: " << endl;
	cin >> g;
	cout << "\n";
	Heroj heroj2;
	heroj2.vpis(a, b, c, d, e, f, g);
	rezultat2 = (a*b*c)+(d*e)+g;
	
	datoteka << "Heroj 2: " << endl;
	datoteka << "Napad heroja: " << a << endl;
	datoteka << "Hitrost heroja: " << b << endl;
	datoteka << "Kriticni napad heroja: " << c << endl;
	datoteka << "Zascita heroja: " << d << endl;
	datoteka << "Zivljenje heroja: " << e << endl;
	datoteka << "Ime heroja: " << f << endl;
	datoteka << "Level heroja: " << g << endl;
	
	if (rezultat1 > rezultat2)
	{
		datoteka << "***************************************************" << endl;
		datoteka << "Zmagovalec igre je heroj 1 z tockami: " << rezultat1 << endl;
		datoteka << "***************************************************" << endl;
	}else{
		datoteka << "***************************************************" << endl;
		datoteka << "Zmagovalec igre je heroj 2 z tockami: " << rezultat2 << endl;
		datoteka << "***************************************************" << endl;
	}
	
	cout << "Heroj 1: " << endl;
	heroj1.izpis();
	cout << "\nHeroj 2: " << endl;
	heroj2.izpis();
	datoteka.close();
	
	return 0;
}
