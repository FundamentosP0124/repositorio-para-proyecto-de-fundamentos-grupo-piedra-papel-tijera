#include <iostream>
#include <ctime>

using namespace std;

char eleccionUsuario();
char eleccionComputadora();
void mostrarEleccion(char eleccion);
void elegirGanador(char jugador, char computadora, int &victorias, int &derrotas, int &empates);

int main()
{
    char seguir;
    char jugador;
    char computadora;
    int victorias = 0;
    int derrotas = 0;
    int empates = 0;
    string name;

cout<<"Ingrese un nombre de jugador: ";
cin>>name;
    do
    {
        jugador = eleccionUsuario();
        cout << "Jugador: "<<name<<" ""Eligio"" ";
        mostrarEleccion(jugador);

        computadora = eleccionComputadora();
        cout << "Computadora: ";
        mostrarEleccion(computadora);

        elegirGanador(jugador, computadora, victorias, derrotas, empates);
        cout << "Victorias: " << victorias << ", Derrotas: " << derrotas << ", Empates: " << empates << endl;

        cout << "Quieres seguir jugando? (si/no): ";
        cin >> seguir;
    } while (seguir == 's' || seguir == 'S');
}

char eleccionUsuario()
{

    char jugador;

    do
    {
        cout << "****************************\n";
        cout << "Roca-Papel-Tijera | Jugador\n";
        cout << "****************************\n";

        cout << "'r' para roca\n";
        cout << "'p' para papel\n";
        cout << "'t' para tijera\n";
        cout << "Elige uno: " << endl;
        cin >> jugador;
    } while (jugador != 'r' && jugador != 'p' && jugador != 't');

    return jugador;
}

char eleccionComputadora()
{
    srand(time(0));
    int num = rand() % 3 + 1; // 0 1 2 -> 1 2 3

    switch (num)
    {
    case 1:
        return 'r';
    case 2:
        return 'p';
    case 3:
        return 't';
    }

    return 0; // Esta línea es innecesaria porque siempre se devolverá 'r', 'p' o 't'.
}

void mostrarEleccion(char eleccion)
{
    switch (eleccion)
    {
    case 'r':
        cout << "Roca\n";
        break;
    case 'p':
        cout << "Papel\n";
        break;
    case 't':
        cout << "Tijera\n";
        break;
    default:
        cout << "Selección inválida\n";
    }
}

void elegirGanador(char jugador, char computadora, int &victorias, int &derrotas, int &empates)
{
    if (jugador == computadora)
    {
        cout << "Empate!\n";
        empates++;
    }
    else if ((jugador == 'r' && computadora == 't') ||
             (jugador == 'p' && computadora == 'r') ||
             (jugador == 't' && computadora == 'p'))
    {
        cout << "Ganaste!\n";
        victorias++;
    }
    else
    {
        cout << "Perdiste!\n";
        derrotas++;
    }
}
