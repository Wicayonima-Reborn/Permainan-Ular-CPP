#include <iostream>
#include <unistd.h> // usleep() untuk Linux
#include <termios.h> // Untuk kbhit() di Linux
#include <sys/ioctl.h>
#include <string>
#include <vector>
using namespace std;

// Ukuran lapangan
const int width = 30;
const int height = 30;

// Posisi ular dan makanan
int x, y, foodX, foodY, score;
int tailX[100], tailY[100];
int nTail;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

// Fungsi untuk deteksi keyboard tanpa blocking (kbhit)
int kbhit() {
    termios term;
    tcgetattr(0, &term);

    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);
    tcsetattr(0, TCSANOW, &term);

    return byteswaiting;
}

// Fungsi untuk setup game
void Setup() {
    x = width / 2;
    y = height / 2;
    foodX = rand() % width;
    foodY = rand() % height;
    score = 0;
    dir = STOP;
}

// Fungsi menggambar lapangan
void Draw() {
    system("clear"); // Untuk Linux

    // Gambar border atas
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    // Gambar lapangan
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "#"; // Border kiri

            if (i == y && j == x)
                cout << "O"; // Kepala ular
            else if (i == foodY && j == foodX)
                cout << "*"; // Makanan
            else {
                bool printTail = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        printTail = true;
                    }
                }
                if (!printTail) cout << " ";
            }

            if (j == width - 1) cout << "#"; // Border kanan
        }
        cout << endl;
    }

    // Gambar border bawah
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << "\nScore: " << score << endl;
}

// Fungsi untuk input arah (Arrow Keys)
void Input() {
    if (kbhit()) {
        char ch = getchar();
        if (ch == 27) { // Deteksi arrow key (ESC = 27)
            getchar(); // Skip [
            switch (getchar()) {
                case 'A': dir = UP; break;    // Up arrow
                case 'B': dir = DOWN; break;  // Down arrow
                case 'C': dir = RIGHT; break; // Right arrow
                case 'D': dir = LEFT; break;  // Left arrow
            }
        } else if (ch == 'q') {
            exit(0); // Keluar dengan Q
        }
    }
}

// Fungsi untuk logika permainan
void Logic() {
    // Simpan posisi kepala sebagai ekor
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Game over jika nabrak tembok
    if (x >= width || x < 0 || y >= height || y < 0)

        exit(0);
	// Gerakan berdasarkan arah
	switch (dir) {
    	case STOP: break;        // Tidak bergerak
    	case LEFT: x--; break;
    	case RIGHT: x++; break;
    	case UP: y--; break;
    	case DOWN: y++; break;
	}
    // Game over jika nabrak ekor sendiri
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            exit(0);
    }

    // Jika makan makanan
    if (x == foodX && y == foodY) {
        score += 10;
        foodX = rand() % width;
        foodY = rand() % height;
        nTail++;
    }
}

// Fungsi utama
int main() {
    Setup();
    while (true) {
        Draw();
        Input();
        Logic();
        usleep(100000); // 100 ms delay untuk stabilitas
    }
    return 0;
}
