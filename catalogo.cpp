#include <unordered_map>
using namespace std;
unordered_map<long long, int> catalogo;

void aggiungi(long long id) {
    catalogo[id]++;
}

void togli(long long id) {
    catalogo[id]--;
}

int conta(long long id) {
    return catalogo[id];
}