
class triangle
{
    public:
        triangle(int a, int b, int c);
        void set(int a, int b, int c);
        void print();
        int perimeter();
        virtual ~triangle();

    protected:

    private:
        int sideA;
        int sideB;
        int sideC;

};
