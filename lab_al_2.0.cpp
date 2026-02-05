#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <utility> // para usar tie
#include <cstdlib> // para usar random
#include <ctime>

using namespace std;

struct Celda { int y,x; };
vector<pair<int,int>> movimientos = {{0,2},{0,-2},{2,0},{-2,0}}; // derecha, izquierda, abajo, arriba

// ---------------- GENERAR LABERINTO PERFECTO ----------------
int** generarLaberinto(int filas, int columnas){
    int **lab = new int*[filas];
    for(int i=0;i<filas;i++) lab[i]=new int[columnas];

    // inicializar todo con paredes

    for(int i=0;i<filas;i++)
        for(int j=0;j<columnas;j++)
            lab[i][j]=1;

    srand(time(NULL));

    // DFS con backtracking
    stack<Celda> pila;
    pila.push({1,1}); // se añade la celda de inicio a la pila
    lab[1][1]=0; // se define la celda inicial como camino

    while(!pila.empty()){ // mientras la pila no este vacia
        Celda actual=pila.top(); // se visualiza el ultimo elemento de la pila 
        vector<Celda> vecinos; // se crea el vector vecinos
        for(auto &m: movimientos){ // ciclo for que recorre el vector movimientos - se usa & para apuntar directamente al elemento real dentro del vector
            int ny=actual.y+m.first, nx=actual.x+m.second; // se calculan coordenadas candidatas - (actual.y, actual.x = posicion actual en el laberinto) (m.first, m.second = desplazamiento que queremos probar, ej: mover 2 pasos arriba)
            if(ny>0 && ny<filas-1 && nx>0 && nx<columnas-1 && lab[ny][nx]==1) // si la nueva posicion esta dentro del laberinto y si la celda es una pared
                vecinos.push_back({ny,nx}); // añade esa posicion como vecino valido en el vector vecinos
        }
        if(!vecinos.empty()){ // mientras el vector vecinos no este vacio
            Celda elegido=vecinos[rand()%vecinos.size()]; //
            lab[(actual.y+elegido.y)/2][(actual.x+elegido.x)/2]=0; // quitar pared
            lab[elegido.y][elegido.x]=0;
            pila.push(elegido);
        } else pila.pop();
    }

    // entrada y salida
    lab[1][1]=0;
    lab[filas-2][columnas-2]=0;

    return lab;
}

// ---------------- RESOLVER LABERINTO (BFS) ----------------
void resolverLaberinto(int **lab,int filas,int columnas){
    vector<vector<bool>> visitado(filas,vector<bool>(columnas,false));
    vector<vector<pair<int,int>>> padre(filas,vector<pair<int,int>>(columnas,{-1,-1}));

    queue<pair<int,int>> colaExplorar;
    colaExplorar.push({1,1});
    visitado[1][1]=true;

    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};

    while(!colaExplorar.empty()){
        auto [y,x]=colaExplorar.front(); colaExplorar.pop();
        if(y==filas-2 && x==columnas-2) break;

        for(int i=0;i<4;i++){
            int ny=y+dy[i], nx=x+dx[i];
            if(ny>=0 && ny<filas && nx>=0 && nx<columnas && lab[ny][nx]==0 && !visitado[ny][nx]){
                visitado[ny][nx]=true;
                padre[ny][nx]={y,x};
                colaExplorar.push({ny,nx});
            }
        }
    }

    // reconstruir camino
    int y=filas-2, x=columnas-2;
    while(!(y==1 && x==1)){
        if(!(y==filas-2 && x==columnas-2)) lab[y][x]=2; // marcar camino con 2
        tie(y,x)=padre[y][x];
    }
    lab[1][1]=2; // marcar inicio
}

// ---------------- IMPRIMIR LABERINTO ----------------
void imprimirLaberinto(int **lab,int filas,int columnas){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(i==1 && j==1) cout<<"EE ";             // entrada
            else if(i==filas-2 && j==columnas-2) cout<<"SS "; // salida
            else if(lab[i][j]==1) cout<<"## ";       // pared
            else if(lab[i][j]==2) cout<<".  ";       // camino
            else cout<<"   ";                         // camino vacío
        }
        cout<<"\n";
    }
}

// ---------------- LIBERAR MEMORIA ----------------
void liberarLaberinto(int **lab,int filas){
    for(int i=0;i<filas;i++) delete[] lab[i];
    delete[] lab;
}

// ---------------- MAIN ----------------
int main(){

    int filas,columnas;

    cout << "Ingrese un tamanho impar para el laberinto: (>=5)\n";
    cout << "Filas: ";
    cin >> filas;
    cout << "Columnas: ";
    cin >> columnas;

    if (filas % 2==0){
        filas += 1;
    }
    else if (columnas % 2 == 0)
    {
        columnas += 1;
    }
    
    int **lab=generarLaberinto(filas,columnas);
    resolverLaberinto(lab,filas,columnas);
    imprimirLaberinto(lab,filas,columnas);

    liberarLaberinto(lab,filas);
    return 0;
}
