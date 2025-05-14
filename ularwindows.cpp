#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> // Untuk Sleep()

using namespace std;

const int width = 20; // Lebar area game
const int height = 20; // Tinggi area game
int x, y, foodX, foodY, score;
int tailX[100], tailY[100]; // Posisi tubuh ular
int nTail; // Panjang tubuh ular
bool gameOver;
int dir; // Arah gerakan (0 = kiri, 1 = atas, 2 = kanan, 3 = bawah)
int speed = 100; // Kecepatan permainan (lebih kecil lebih cepat)

// Fungsi untuk setup permainan
void Setup() {
    gameOver = false;
    dir = 2; // Mulai bergerak ke kanan
    x = width / 2; // Posisi awal kepala ular
    y = height / 2;
    foodX = rand() % width; // Posisi makanan
    foodY = rand() % height;
    score = 0;
    nTail = 0; // Panjang tubuh ular mulai dari 0
}

// Fungsi untuk menggambar tampilan game
void Draw() {
    system("cls"); // Hapus layar (di Windows, pakai "clear" di Linux)
    
    // Gambar border atas
    for (int i = 0; i < width + 2; i++)
        cout << "#";
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
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    // Tampilan skor
    cout << "\nScore: " << score << endl;

    // Tambahkan jeda untuk memperlambat refresh
    Sleep(100); // 100 ms delay (sesuaikan)
}


// Fungsi untuk input arah gerakan
void Input() {
    // Deteksi arah gerakan, tapi hanya satu kali
    if (GetAsyncKeyState(VK_LEFT) && dir != 2) 
        dir = 0; // Kiri
    else if (GetAsyncKeyState(VK_UP) && dir != 3) 
        dir = 1; // Atas
    else if (GetAsyncKeyState(VK_RIGHT) && dir != 0) 
        dir = 2; // Kanan
    else if (GetAsyncKeyState(VK_DOWN) && dir != 1) 
        dir = 3; // Bawah

    // Deteksi tombol Q untuk keluar (harus ditekan)
    if (GetAsyncKeyState('Q') & 0x8000) 
        gameOver = true;

    Sleep(50); // Sedikit delay untuk mencegah input berlebihan
}


// Fungsi untuk update posisi ular
void Logic() {
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

    // Gerakan ular
    switch (dir) {
        case 0: x--; break; // Kiri
        case 1: y--; break; // Atas
        case 2: x++; break; // Kanan
        case 3: y++; break; // Bawah
    }

    // Jika ular keluar dari area, game over
    if (x >= width || x < 0 || y >= height || y < 0)
        gameOver = true;

    // Cek tabrakan dengan tubuh ular sendiri
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    // Jika ular makan makanan
    if (x == foodX && y == foodY) {
        score += 10;
        foodX = rand() % width;
        foodY = rand() % height;
        nTail++; // Tambah panjang tubuh
    }
}

// Fungsi utama
int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();

        // Update kecepatan permainan berdasarkan skor
        if (score % 50 == 0 && score != 0) {
            speed = speed - 10; // Mengurangi delay, makin cepat
            if (speed < 10) speed = 10; // Jangan biarkan kecepatan lebih dari batas minimum
        }
        Sleep(speed); // Delay dalam milidetik
    }

    return 0;
}