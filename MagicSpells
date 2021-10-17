#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

  /* Enter your code here */
  if (Fireball *fb = dynamic_cast<Fireball*>(spell))
    {
        fb->revealFirepower();
    }
    else if (Frostbite *fb = dynamic_cast<Frostbite*>(spell))
    {
        fb->revealFrostpower();
    }
    else if (Thunderstorm *ts = dynamic_cast<Thunderstorm*>(spell))
    {
        ts->revealThunderpower();
    }
    else if (Waterbolt *wb = dynamic_cast<Waterbolt*>(spell))
    {
        wb->revealWaterpower();
    }
    else
    {
        std::string strA = spell->revealScrollName();
        std::string strB = SpellJournal::read();
   
    int m = strA.length();
    int n = strB.length();

    std::vector<std::vector<int>> vLCSMatrix(m + 1, std::vector<int>(n + 1));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (strA[i - 1] == strB[j - 1])
            {
                vLCSMatrix[i][j] = 1 + vLCSMatrix[i - 1][j - 1];
            }
            else
            {
                vLCSMatrix[i][j] = std::max(vLCSMatrix[i - 1][j], vLCSMatrix[i][j - 1]);
            }
        }
    }

     std::cout << vLCSMatrix[m][n] << std::endl;
    }

}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
