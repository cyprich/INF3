class Generator  
{  
private:  
   int* pole;  
   int velkost_pola;  
public:  
   Generator();  
   ~Generator();  
   int generuj_cislo(int min, int max);  
   int generuj_cislo(int limit);
   int* generuj_zoznam(int min, int max, int pocet_prvkov);  
   void vypis_zoznam();
   int get_velkost_pola() { return velkost_pola; }
};
