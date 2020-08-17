#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
void parseCSV()
{
    ifstream data("Book1.csv"); //abre y lee los archivos del archivo con nombre book1.csv
    string line;       // esto crea una variable que guarda datos
    vector<vector<string>> parsedCsv;  //esto es un vector que creamos y almacena la variable anterior
    int rowcount=0; //crea una constante con el nombre rowcount y le da un valor de cero
    int colcount=0; //crea una constante con el nombre colcount y le da un valor de cero
    while (getline(data,line))//con este ciclo lo que vamos a hacer es ingresar los datos creados anterior mente creados con las variables
    {
        stringstream lineStream(line);
        string cell; 
        vector<string> parsedRow;
        colcount=0; //llamamos la variable anteriormente creada
        while (getline(lineStream,cell,','))//con esto se mira cada renglon del archivo que esta leyendo y guarda los datos cada ves que encuentra una coma
        {
            parsedRow.push_back(cell); 
            colcount++; //esta es la variable creada en el inicio que le dimos valor cero, entonces cada ves que esta pase por aca se sumara de a uno hasta que se termine el ciclo esto es un contador
        }
        rowcount++;//esta es la variable creada en el inicio que le dimos valor cero, entonces cada ves que esta pase por aca se sumara de a uno hasta que se termine el ciclo esto es un contador
        parsedCsv.push_back(parsedRow);



    }
    for(int i=0; i<rowcount; i++){ //esto mira los datos de la matrix i=0 hasta i<rowcount  y esto lo hace aumentando de uno en uno
        for(int j=0; j<colcount;j++){//esto mira los datos de la matrix desde j=0 hasta j<colcount y esto lo hace aumentando de uno en uno
        cout <<parsedCsv[i][j]<<" - "; //nos lanza la operacion parsedCsv[i][j] en el terminal y antes de terminarla genera un menos para separar las operaciones
        }
        cout<< '\n'; //en la la salida de la pantalla que en nuestro caso es el terminal hace un espacio o salto
    }
}
int main()
{
    parseCSV();
    return 0;
}