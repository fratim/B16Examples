#include <iostream>
#include <vector>


using namespace std;

template <class T >
class Image {

    public:
        Image(int height_, int width_) : height(height_), width(width_) {};

        T get_pixel(const unsigned int x, const int y) const {
            return pixels[x][y];
        }

        void set_pixel(unsigned int x, unsigned int y, T value) {
            pixels[x][y] = value;
        }

        unsigned int get_height() {
            return height;
        }

        unsigned int get_width() {
            return width;
        }

    private:
        unsigned int height;
        unsigned int width;

        vector<vector<T> > pixels{width, vector<T>(height, 0)};

};

int main() {
    Image<char> image(10, 10);   
    image.set_pixel(9, 1, 1);
    cout << int(image.get_pixel(9, 1)) << endl;
    cout << image.get_pixel(10, 10) << endl;
    cout << image.get_pixel(10, 10);
}


// compile with:
// g++ Q1_image.cpp -std=c++17 -o Q1tim

// to insert:
// void validate_position(const unsigned int x, const unsigned int y) const {
//     if (x > width or y > height) { 
//         throw invalid_argument("Invalid position");
//     }
// }
