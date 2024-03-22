# include <iostream>
# include <fstream>
# include <iomanip>

double mappedValues(double val, int a, int b, int c, int d) //funzione che associa i punti appartenenti a [1,5] all'intervallo [-1,2]
{
    double valmapped = d + (val-b)*(d-c)/(b-a); //è l'equazione della retta che passa per i punti (b,d) e (a,c), che in questo caso sono (5,2) e (1,-1)
    return valmapped;
}

double meanFunction(double sum, int num) // funzione che calcola la media
{
    double mean = sum/num;
    return mean;
}


int main()
{
    int x1 = 1;
    int x2 = 5;
    int y1 = -1;
    int y2 = 2;
    std::string datiInput = "data.csv";
    std::ifstream ifstr(datiInput); // crea istream object e apre il file in modalità scrittura
    std::string fileResult = "result.csv";
    std::ofstream ofs(fileResult); // dichiaro il file su cui voglio mettere la stringa, che viene creato sul momento perchè non esisteva precedentenmente

    if (ifstr.fail()) //controllo che l'accesso al file di testo sia andato a buon fine
    {
        std::cerr << "File not exist" << std::endl;
        return 1;
    }


    double sum = 0;
    int j = 0;
    double val;
    ofs << "# N Mean" << std::endl; //stampo l'intestazione all'interno del nuovo file fileResult

    while(ifstr >> val) //leggo ogni riga del file e la assegno alla variabile val
    {
        double mvalue = mappedValues(val, x1, x2, y1, y2); //calcolo il valore associato (mappato)
        sum += mvalue; //sommo il nuovo valore di
        j += 1; //incremento j
        double mean = meanFunction(sum,j); //calcolo la media
        ofs << j << " " << std::fixed << std::setprecision(16) << std::scientific << mean << std::endl;//stampo all'interno del file di scrittura il valore con le seguenti caratteristiche: 16 cifre significative e in formato scientifico
    }

    ifstr.close(); // chiudo i file
    ofs.close();

    return 0;
}
