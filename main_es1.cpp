#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <sstream>

unsigned int sumFirstNSquare(unsigned int N) //creo una funzione che svolge l'operazione
{
    return N * (N + 1) * (2 * N +1) / 6;
}

int main()
{
    std::string nameFile = "data.csv";
    std::ifstream fstr; //apro il file che voglio utilizzare in modalità lettura
    fstr.open(nameFile);

    if(fstr.fail()) //controllo che l'accesso sia andato a buon fine
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    unsigned int val = 0;
    unsigned int sumValues = 0;
    unsigned int N = 0;

    std::string header = ""; //creo la stringa header che corrisponde l'intestazione che si trova all'interno del file prima dei valori che utilizzo nel programma
    fstr >> header; //qua legge la prima riga e l'assegna a header

    while(fstr >> val) //mentre ad una riga è assegnato un valore
    {
        sumValues += val * val; //elevo al quadrato e sommo a sumValues
        N++; //ed incremento N che è il numero di valori nel file
    }

    fstr.close(); //chiudo file

    std::cout << "sumValues: " << sumValues << std::endl; //stampo il risultato trovato dal while

    unsigned int S = sumFirstNSquare(N); //associo S con il risultato della funzione sumFirstNSquare definita in precedenza, a cui passo il numero di elementi del file
    std::cout << "S: " << S << std::endl; //stampo il valore trovato di S

    if(sumValues < S) { //con questa serie di if comparo i due risultati (sumFirstNSquare e S)
        std::cout << sumValues << "is lower than " << S << std::endl;
    }
    else {
        if(sumValues > S) {
            std::cout << sumValues << "is bigger than " << S << std::endl;
        }
        std::cout << "The sum of square of the first N = " << N << " values is: " << sumValues << ". This sum is equal to: N * (N + 1) * (2 * N +1) / 6, i.e. " << S << std::endl;
    }

    return 0;
}
