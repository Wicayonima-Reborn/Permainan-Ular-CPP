# Snake Game in C++ (Windows & Linux)

## Deskripsi
Ini adalah game ular sederhana yang dibuat menggunakan bahasa pemrograman C++. Game ini dapat dimainkan di platform **Windows** dan **Linux**.

## Persyaratan Sistem
- **Windows**: Windows 7 atau lebih baru
- **Linux**: Ubuntu atau distribusi Linux lainnya

## Menginstal Compiler C++

### Untuk Windows
1. **Install MinGW**:
   - Unduh MinGW dari situs resminya [MinGW Download](https://sourceforge.net/projects/mingw-w64/).
   - Pilih versi 64-bit dan ikuti petunjuk instalasi.
   - Tambahkan folder `bin` dari MinGW ke dalam **Path Environment Variable** (misalnya `C:\MinGW\bin`).
   
2. **Install Code Editor**:
   - Gunakan editor kode seperti **Visual Studio Code** atau **Code::Blocks**. Visual Studio Code dapat diunduh di [sini](https://code.visualstudio.com/).
   
3. **Verifikasi Instalasi**:
   - Buka Command Prompt dan ketikkan perintah:
     ```bash
     g++ --version
     ```
     Jika instalasi berhasil, Anda akan melihat versi dari g++ yang terinstal.

### Untuk Linux
1. **Install GCC**:
   - Di terminal, jalankan perintah berikut untuk menginstal GCC (GNU Compiler Collection):
     ```bash
     sudo apt update
     sudo apt install build-essential
     ```
   
2. **Verifikasi Instalasi**:
   - Setelah instalasi selesai, pastikan GCC sudah terinstal dengan perintah:
     ```bash
     g++ --version
     ```

## Cara Menjalankan Game

### Untuk Windows
1. Setelah Anda menginstal MinGW dan editor kode, buka **Command Prompt**.
2. Navigasi ke folder tempat Anda menyimpan file game `snake_game.cpp`.
3. Kompilasi program dengan perintah:
   ```bash
   g++ ularwindows.cpp -o snake_game.exe
4. ```bash
   .\snake_game.exe

### Untuk Linux
1. Setelah menginstal Compiler C++ buka **Terminal**
2. Navigasi ke folder tempat Anda menyimpan file game `snake_game.cpp`.
3. Kompilasi program dengan perintah:
   ```bash
   g++ ular.cpp -o snake_game.exe
4. ```bash
   .\snake_game