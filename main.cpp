#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <sstream>

int function(double* arr, int n) //questa funzione ha due obiettivi: il primo è quello di prelevare tutti i valori che stanno nell'intervallo -1,2; il secondo è quello di calcolare la media dei valori nell'intervallo e stamparli in un altro file creato sul momento
//nell'argomento della funzione ho messo double* arr che è un array che contiene tutti i valori presenti nel file, e poi ho messo int n che è il numero di valori all'interno del file (corrisponde quindi a N)
{
    double* mapped = 0; //ho inizializzato un nuovo array in cui metterò i valori che stanno nellintervallo [-1,2]
    mapped = new double[n]; //ho stabilito che la lunghezza dell'array è uguale al massimo valore che può potenzialmente contenere cioè n (i.e. N)
    int j = 0;
    double sum = 0;
    double mean = 0;
    std::ofstream result; //apro nuovo file in modalità scrittura
    result.open("result.csv");
    result << "# N Mean\n";
    for(int i = 0; i < n; i++) { //leggo gli elementi all'interno di arr
        if(arr[i] <= 2 && arr[i] >= - 1){ //se l'elemento è all'interno dell'intervallo
            std::cout << arr[i] << std::endl; //allora stampo il valore
            mapped[j] = arr[i]; //lo metto all'interno di mapped
            j++; //e incremento la posizione all'interno di mapped
            for(int k = 0; k <= j; k++){ //per ogni elemento di mapped
                sum += mapped[k]; //faccio la somma degli elementi di mapped
            }
            mean = sum / j; //faccio la media
            sum = 0; //resetto la somma per evitare che resti memorizzata quella precedente
            result << j << " " << mean << "\n"; //stampo all'interno del file result i valori in colonna
        }
    }
    result.close();
    return 0;
}


int main()
{
    std::string fileName = "data.csv";
    std::ifstream ifstr; //ho aperto il file in modalità lettura per poter accedere ai dati
    ifstr.open(fileName);

    if(ifstr.fail()) //controllo che l'accesso sia andato a buon fine
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    double val = 0; //ho inizializzato una variabile a cui assegnerò i valori che leggerò nel file
    int N = 0; //inizializzo questa varibile per poter contare quanti valori ci sono all'interno del file

    while(ifstr >> val) //conto i valori fin tanto che ci sono valori da leggere
    {
        N++; //incremento il contatore inizializzato in precedenza
    }
    std::cout << "The total N values in the file is: " << N << std::endl; //stampo il numero di valori all'interno del file

    ifstr.close(); //chiudo il file

    double* array = 0; //inizializzo un array all'interno di cui metteremo i singoli valori
    array = new double[N]; //la lunghezza dell'array sarà uguale al numero di valori N, contati in precedenza

    ifstr.open(fileName); //riapro il file
    val = 0; //metto il valore uguale a zero
    unsigned int i = 0;
    while(ifstr >> val) //assegno ad ogni elemento dell'array un valore del file
    {
        array[i] = val;
        i++;
    }
    function(array, N); //uso la funzione definita all'inizio del codice

    ifstr.close(); //chiudo il file
    return 0;
}
