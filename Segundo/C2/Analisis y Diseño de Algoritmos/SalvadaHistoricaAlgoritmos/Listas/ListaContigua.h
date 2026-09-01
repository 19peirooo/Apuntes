
class ListaContigua {

    private:
        int n;
        int inc;
        int cap;
        int* lista;

    public:
        ListaContigua(int incremento);
        ~ListaContigua();
        int getValor(int pos);
        void setValor(int pos, int valor);
        int getN();
        int getCapacidad();
        void insertar(int pos, int val);
        void eliminar(int pos);
        void concatenar(ListaContigua *listaAConcatenar);
        int buscar(int pos);
    
};