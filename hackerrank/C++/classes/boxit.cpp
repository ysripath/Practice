
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
class Box {
  private:
        int l;
        int b;
        int h;
  public:
        Box() {
            l = 0;
            b = 0;
            h = 0;
        }
        Box(int a, int B, int c) {
            l = a;
            b = B;
            h = c;
        }
        Box(const Box& B)
            {
            l = B.l;
            b = B.b;
            h = B.h;
        }
        bool operator < (const Box& B) {
            if (l < B.l)
                return true;
            else if (l == B.l && b < B.b)
                return true;
            else if (l == B.l && b == B.b && h < B.h)
                return true;
            else
                return false;
        }
        friend ostream &operator << (ostream &output, const Box& B) {
            output << B.l <<" "<<B.b<<" "<<B.h;
            return output;
        }
        // int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box
        int getLength() {
            return l;
        }
        int getBreadth() {
            return b;
        }
        int getHeight() {
            return h;
        }
        long long CalculateVolume() {
            return l*b*h;
        }
};

