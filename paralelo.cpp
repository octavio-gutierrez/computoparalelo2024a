#include <iostream>
#include <omp.h>
using namespace std;

int main() {

    int nthreads; 
    int thread_id;

    omp_set_num_threads(4);
    #pragma omp parallel private(thread_id) 
    {
        thread_id = omp_get_thread_num();
        cout << " Hola soy el hilo " << thread_id << "\n";    

        // solo lo ejecuta el hilo maestro
        if (thread_id == 0) {
            nthreads = omp_get_num_threads(); 
            cout << "Hay " << nthreads << " hilos \n";
        }
    }

    return 0;
}